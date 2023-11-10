#include "stdafx.h"
#include "Game.h"
#include "LivblockAdventure.h"
#include "LivblockAdventure_GameTitle.h"
LivblockAdventure_GameTitle::LivblockAdventure_GameTitle()
{
	M_GameTitleTexture.Init("Assets/Sprite/LivblockAdventure/GameTitle.DDS", 1000.0f, 1000.0f);
}
bool LivblockAdventure_GameTitle::Start()
{
	P_Livblock = FindGO<LivblockAdventure>("livblock");
	return true;
}
void LivblockAdventure_GameTitle::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{P_Livblock->Create(FIRST);}

	M_GameTitleTexture.Update();
}
void LivblockAdventure_GameTitle::Render(RenderContext& rc)
{
	M_GameTitleTexture.Draw(rc);
}
