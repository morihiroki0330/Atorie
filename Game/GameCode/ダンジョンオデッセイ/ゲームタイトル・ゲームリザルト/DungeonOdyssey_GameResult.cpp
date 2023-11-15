#include "stdafx.h"
#include "Game.h"
#include "GameCode/ダンジョンオデッセイ/DungeonOdyssey.h"
#include "DungeonOdyssey_GameResult.h"
DungeonOdyssey_GameResult::DungeonOdyssey_GameResult()
{
	M_GameResultTexture.Init("Assets/Sprite/DungeonOdyssey/GameResult.DDS", 1920.0f, 1080.0f);
}
bool DungeonOdyssey_GameResult::Start()
{
	P_Dungeon = FindGO<DungeonOdyssey>("dungeon");
	return true;
}
void DungeonOdyssey_GameResult::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{P_Dungeon->Create(THIRD);}
	M_GameResultTexture.Update();
}
void DungeonOdyssey_GameResult::Render(RenderContext& rc)
{
	M_GameResultTexture.Draw(rc);
}
