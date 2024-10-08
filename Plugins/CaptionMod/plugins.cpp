#include <metahook.h>
#include "exportfuncs.h"
#include "privatefuncs.h"
#include "VGUI2ExtensionImport.h"

cl_exportfuncs_t gExportfuncs = {0};
mh_interface_t *g_pInterface = NULL;
metahook_api_t *g_pMetaHookAPI = NULL;
mh_enginesave_t *g_pMetaSave = NULL;
IFileSystem *g_pFileSystem = NULL;
IFileSystem_HL25 *g_pFileSystem_HL25 = NULL;

int g_iVideoWidth = 0;
int g_iVideoHeight = 0;

int g_iEngineType = 0;
PVOID g_dwEngineBase = NULL;
DWORD g_dwEngineSize = 0;
PVOID g_dwEngineTextBase = NULL;
DWORD g_dwEngineTextSize = 0;
PVOID g_dwEngineDataBase = NULL;
DWORD g_dwEngineDataSize = 0;
PVOID g_dwEngineRdataBase = NULL;
DWORD g_dwEngineRdataSize = 0;
DWORD g_dwEngineBuildnum = 0;

PVOID g_dwClientBase = NULL;
DWORD g_dwClientSize = NULL;
PVOID g_dwClientTextBase = NULL;
DWORD g_dwClientTextSize = NULL;
PVOID g_dwClientDataBase = NULL;
DWORD g_dwClientDataSize = NULL;
PVOID g_dwClientRdataBase = NULL;
DWORD g_dwClientRdataSize = NULL;

bool g_bIsSvenCoop = false;
bool g_bIsCounterStrike = false;

extern IFileSystem* g_pFullFileSystem;
extern IFileSystem_HL25* g_pFullFileSystem_HL25;

ICommandLine *CommandLine(void)
{
	return g_pInterface->CommandLine;
}

void IPluginsV4::Init(metahook_api_t *pAPI, mh_interface_t *pInterface, mh_enginesave_t *pSave)
{
	g_pInterface = pInterface;
	g_pMetaHookAPI = pAPI;
	g_pMetaSave = pSave;
}

void IPluginsV4::Shutdown(void)
{
	g_pMetaHookAPI->UnregisterLoadDllNotificationCallback(DllLoadNotification);
}

void IPluginsV4::LoadEngine(cl_enginefunc_t *pEngfuncs)
{
	g_pFileSystem = g_pInterface->FileSystem;
	g_pFullFileSystem = g_pFileSystem;

	if (!g_pFileSystem)
	{
		g_pFileSystem_HL25 = g_pInterface->FileSystem_HL25;
		g_pFullFileSystem_HL25 = g_pFullFileSystem_HL25;
	}

	g_pMetaHookAPI->GetVideoMode(&g_iVideoWidth, &g_iVideoHeight, NULL, NULL);

	g_iEngineType = g_pMetaHookAPI->GetEngineType();
	g_dwEngineBuildnum = g_pMetaHookAPI->GetEngineBuildnum();
	g_dwEngineBase = g_pMetaHookAPI->GetEngineBase();
	g_dwEngineSize = g_pMetaHookAPI->GetEngineSize();
	g_dwEngineTextBase = g_pMetaHookAPI->GetSectionByName(g_dwEngineBase, ".text\x0\x0\x0", &g_dwEngineTextSize);
	g_dwEngineDataBase = g_pMetaHookAPI->GetSectionByName(g_dwEngineBase, ".data\x0\x0\x0", &g_dwEngineDataSize);
	g_dwEngineRdataBase = g_pMetaHookAPI->GetSectionByName(g_dwEngineBase, ".rdata\x0\x0", &g_dwEngineRdataSize);

	memcpy(&gEngfuncs, pEngfuncs, sizeof(gEngfuncs));

	gPrivateFuncs.pfnTextMessageGet = pEngfuncs->pfnTextMessageGet;
	gPrivateFuncs.pfnServerCmdUnreliable = pEngfuncs->pfnServerCmdUnreliable;

	ULONG_PTR addr = (ULONG_PTR)g_pMetaHookAPI->SearchPattern((void *)gEngfuncs.GetClientTime, 0x20, "\xDD\x05", sizeof("\xDD\x05") - 1);
	Sig_AddrNotFound("cl_time");
	cl_time = (double *)*(ULONG_PTR*)(addr + 2);
	cl_oldtime = cl_time + 1;

	Engine_FillAddress();

	Engine_InstallHooks();

	VGUI2Extension_Init();

	BaseUI_InstallHooks();

	ClientVGUI_InstallHooks();

	GameUI_InstallHooks();

	g_pMetaHookAPI->RegisterLoadDllNotificationCallback(DllLoadNotification);
}

void IPluginsV4::LoadClient(cl_exportfuncs_t *pExportFunc)
{
	//Get video settings again since width and height might have been changed during initialization.
	g_pMetaHookAPI->GetVideoMode(&g_iVideoWidth, &g_iVideoHeight, NULL, NULL);

	memcpy(&gExportfuncs, pExportFunc, sizeof(gExportfuncs));

	pExportFunc->HUD_Init = HUD_Init;
	pExportFunc->HUD_VidInit = HUD_VidInit;
	pExportFunc->HUD_Frame = HUD_Frame;
	pExportFunc->HUD_Redraw = HUD_Redraw;
	pExportFunc->HUD_Shutdown = HUD_Shutdown;
	pExportFunc->IN_MouseEvent = IN_MouseEvent;
	pExportFunc->IN_Accumulate = IN_Accumulate;
	pExportFunc->CL_CreateMove = CL_CreateMove;

	Client_FillAddress();
	Client_InstallHooks();
}

void IPluginsV4::ExitGame(int iResult)
{
	ClientVGUI_UninstallHooks();
	GameUI_UninstallHooks();
	BaseUI_UninstallHooks();

	VGUI2Extension_Shutdown();
}

const char completeVersion[] =
{
	BUILD_YEAR_CH0, BUILD_YEAR_CH1, BUILD_YEAR_CH2, BUILD_YEAR_CH3,
	'-',
	BUILD_MONTH_CH0, BUILD_MONTH_CH1,
	'-',
	BUILD_DAY_CH0, BUILD_DAY_CH1,
	'T',
	BUILD_HOUR_CH0, BUILD_HOUR_CH1,
	':',
	BUILD_MIN_CH0, BUILD_MIN_CH1,
	':',
	BUILD_SEC_CH0, BUILD_SEC_CH1,
	'\0'
};

void Cap_Version_f(void)
{
	gEngfuncs.Con_Printf("CaptionMod version : %s\n", completeVersion);
}

const char *IPluginsV4::GetVersion(void)
{
	return completeVersion;
}

EXPOSE_SINGLE_INTERFACE(IPluginsV4, IPluginsV4, METAHOOK_PLUGIN_API_VERSION_V4);