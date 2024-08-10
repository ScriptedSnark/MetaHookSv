#include <metahook.h>
#include <studio.h>
#include <r_studioint.h>
#include <com_model.h>
#include <cl_entity.h>

extern cl_enginefunc_t gEngfuncs;
extern cl_exportfuncs_t gExportfuncs;
extern engine_studio_api_t IEngineStudio;
extern r_studio_interface_t** gpStudioInterface;

extern model_t* r_worldmodel;
extern cl_entity_t* r_worldentity;

extern int* cl_max_edicts;
extern cl_entity_t** cl_entities;

extern int* cl_numvisedicts;
extern cl_entity_t** cl_visedicts;

int HUD_AddEntity(int type, cl_entity_t *ent, const char *model);
int HUD_GetStudioModelInterface(int version, struct r_studio_interface_s **ppinterface, struct engine_studio_api_s *pstudio);
void HUD_TempEntUpdate(
	double frametime,   // Simulation time
	double client_time, // Absolute time on client
	double cl_gravity,  // True gravity on client
	TEMPENTITY **ppTempEntFree,   // List of freed temporary ents
	TEMPENTITY **ppTempEntActive, // List 
	int(*Callback_AddVisibleEntity)(cl_entity_t *pEntity),
	void(*Callback_TempEntPlaySound)(TEMPENTITY *pTemp, float damp));
void HUD_DrawTransparentTriangles(void);
void HUD_Init(void);
void V_CalcRefdef(struct ref_params_s *pparams);
void HUD_Frame(double frametime);
void HUD_Shutdown(void);
void HUD_CreateEntities(void);

msurface_t* GetWorldSurfaceByIndex(int index);
int GetWorldSurfaceIndex(msurface_t* surf);

entity_state_t* R_GetPlayerState(int index);

bool AllowCheats();

bool IsPhysicWorldEnabled();
bool IsDebugDrawEnabled();
bool ShouldSyncronizeView();
int GetRagdollObjectDebugDrawLevel();
int GetStaticObjectDebugDrawLevel();
int GetDynamicObjectDebugDrawLevel();
int GetConstraintDebugDrawLevel();
float GetSimulationTickRate();

int EngineGetNumKnownModel();
int EngineGetMaxKnownModel();
int EngineGetModelIndex(model_t* mod);
model_t* EngineGetModelByIndex(int index);
int StudioGetSequenceActivityType(model_t* mod, entity_state_t* entstate);

int EngineGetMaxClientEdicts(void);
cl_entity_t* EngineGetClientEntitiesBase(void);
int EngineGetMaxTempEnts(void);