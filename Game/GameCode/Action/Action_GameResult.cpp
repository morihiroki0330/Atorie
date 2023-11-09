#include "stdafx.h"
#include "Game.h"
#include "Action.h"
#include "Action_GameResult.h"
Action_GameResult::Action_GameResult()
{
	M_GameResultTexture.Init("Assets/Sprite/Action/GameResult.DDS", 1000.0f, 1000.0f);
}
bool Action_GameResult::Start()
{
	P_Action = FindGO<Action>("action");
	return true;
}
void Action_GameResult::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{P_Action->Create(THIRD);}

	M_GameResultTexture.Update();
}
void Action_GameResult::Render(RenderContext& rc)
{
	M_GameResultTexture.Draw(rc);
}