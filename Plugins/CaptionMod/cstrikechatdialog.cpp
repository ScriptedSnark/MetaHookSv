#include <metahook.h>
#include "cstrikechatdialog.h"

#include <IGameUI.h>

extern int m_iIntermission;
extern IGameUI *g_pGameUI;

using namespace vgui;

CCSChatDialog::CCSChatDialog(Panel *parent) : BaseClass(parent)
{
	m_PreviousAppModal = NULL;

	SetProportional(true);
	SetSizeable(false);
}

void CCSChatDialog::ApplySchemeSettings(vgui::IScheme *pScheme)
{
	BaseClass::ApplySchemeSettings(pScheme);

	LoadControlSettings("captionmod/ChatDialog.res");
	GetPos(m_iSaveX, m_iSaveY);
	SetVisible(true);
}

void CCSChatDialog::CreateChatInputLine(void)
{
	//BaseClass::CreateChatInputLine();
	m_pChatInput = new CChatDialogInputLine(this, "ChatInputLine");
	m_pChatInput->SetVisible(false);
}

void CCSChatDialog::CreateChatLines(void)
{
	//BaseClass::CreateChatLines();
	m_ChatLine = new CChatDialogLine(this, "ChatLine");
	m_ChatLine->SetVisible(false);
}

void CCSChatDialog::Init(void)
{
	BaseClass::Init();
}

void CCSChatDialog::VidInit(void)
{
	BaseClass::VidInit();
}

void CCSChatDialog::Reset(void)
{
	BaseClass::Reset();
}

void CCSChatDialog::OnThink(void)
{
	SetPos(m_iSaveX, m_iSaveY);

	if (!m_PreviousAppModal && IsMouseInputEnabled())
	{
		m_PreviousAppModal = input()->GetAppModalSurface();
		input()->SetAppModalSurface(GetVPanel());
	}
	else if (m_PreviousAppModal && !IsMouseInputEnabled())
	{
		input()->SetAppModalSurface(m_PreviousAppModal);
		m_PreviousAppModal = NULL;
	}

	if (m_iIntermission && IsMouseInputEnabled())
	{
		StopMessageMode();
	}
	else if (g_pGameUI && g_pGameUI->IsGameUIActive())
	{
		StopMessageMode();
	}

	BaseClass::OnThink();
}

int CCSChatDialog::GetChatInputOffset(void)
{
	if (m_pChatInput->IsVisible())
		return m_iFontHeight;

	return 0;
}

void CCSChatDialog::SetVisible(bool state)
{
	BaseClass::SetVisible(state);

	if (state && !IsMouseInputEnabled())
	{
		if (GetChatHistory())
		{
			GetChatHistory()->SetPaintBorderEnabled(false);
			GetChatHistory()->GotoTextEnd();
			GetChatHistory()->SetMouseInputEnabled(false);
			GetChatHistory()->SetVerticalScrollbar(false);
			GetChatHistory()->ResetAllFades(false, true, CHAT_HISTORY_FADE_TIME);
			GetChatHistory()->SelectNoText();
			GetChatHistory()->SetCursor(vgui::dc_none);
		}
	}
}