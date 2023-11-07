#include "stdafx.h"
#include "Game.h"
#include "Flick_GameResult.h"
#include "Flick.h"
Flick_GameResult::Flick_GameResult()
{
	M_GameResultTexture.Init("Assets/Sprite/Action/GameResult.DDS", 1000.0f, 1000.0f);
}
bool Flick_GameResult::Start()
{
	P_Flick = FindGO<Flick>("flick");
	return true;
}
void Flick_GameResult::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		P_Flick->Create(THIRD);
	}
	M_GameResultTexture.Update();
}
void Flick_GameResult::Render(RenderContext& rc)
{
	M_GameResultTexture.Draw(rc);
}