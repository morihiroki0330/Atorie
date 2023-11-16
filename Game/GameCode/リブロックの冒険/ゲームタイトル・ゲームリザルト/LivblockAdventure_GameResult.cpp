#include "stdafx.h"
#include "Game.h"
#include "LivblockAdventure_GameResult.h"

#include "GameCode/ƒŠƒuƒƒbƒN‚Ì–`Œ¯/LivblockAdventure.h"

LivblockAdventure_GameResult::LivblockAdventure_GameResult()
{
	M_GameResultTexture.Init("Assets/Sprite/LivblockAdventure/GameResult.DDS", 1000.0f, 1000.0f);
}
bool LivblockAdventure_GameResult::Start()
{
	P_Livblock = FindGO<LivblockAdventure>("livblock");
	return true;
}
void LivblockAdventure_GameResult::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{P_Livblock->Create(THIRD);}

	M_GameResultTexture.Update();
}
void LivblockAdventure_GameResult::Render(RenderContext& rc)
{
	M_GameResultTexture.Draw(rc);
}