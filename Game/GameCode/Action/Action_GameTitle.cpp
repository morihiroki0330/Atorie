#include "stdafx.h"
#include "Game.h"
#include "Action.h"
#include "Action_GameTitle.h"
Action_GameTitle::Action_GameTitle()
{
	M_GameTitleTexture.Init("Assets/Sprite/Action/GameTitle.DDS", 1000.0f, 1000.0f);
}
bool Action_GameTitle::Start()
{
	P_Action = FindGO<Action>("action");
	return true;
}
void Action_GameTitle::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{P_Action->Create(FIRST);}

	M_GameTitleTexture.Update();
}
void Action_GameTitle::Render(RenderContext& rc)
{
	M_GameTitleTexture.Draw(rc);
}
