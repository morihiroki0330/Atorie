#include "stdafx.h"
#include "Game.h"
#include "DungeonOdyssey_GameTitle.h"

#include "GameCode/ダンジョンオデッセイ/DungeonOdyssey.h"

DungeonOdyssey_GameTitle::DungeonOdyssey_GameTitle()
{
	M_GameTitleTexture.Init("Assets/Sprite/DungeonOdyssey/GameTitle.DDS", 1920.0f, 1080.0f);
}
bool DungeonOdyssey_GameTitle::Start()
{
	P_Dungeon = FindGO<DungeonOdyssey>("dungeon");
	return true;
}
void DungeonOdyssey_GameTitle::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{P_Dungeon->Create(FIRST);}
	M_GameTitleTexture.Update();
}
void DungeonOdyssey_GameTitle::Render(RenderContext& rc)
{
	M_GameTitleTexture.Draw(rc);
}
