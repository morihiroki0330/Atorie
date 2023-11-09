#include "stdafx.h"
#include "Game.h"
#include "Dungeon.h"
#include "Dungeon_GameResult.h"
Dungeon_GameResult::Dungeon_GameResult()
{
	M_GameResultTexture.Init("Assets/Sprite/Dungeon/GameResult.DDS", 1920.0f, 1080.0f);
}
bool Dungeon_GameResult::Start()
{
	P_Dungeon = FindGO<Dungeon>("dungeon");
	return true;
}
void Dungeon_GameResult::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{P_Dungeon->Create(THIRD);}
	M_GameResultTexture.Update();
}
void Dungeon_GameResult::Render(RenderContext& rc)
{
	M_GameResultTexture.Draw(rc);
}
