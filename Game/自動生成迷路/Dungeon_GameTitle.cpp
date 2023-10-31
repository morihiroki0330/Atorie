#include "stdafx.h"
#include "Game.h"
#include "Dungeon_GameTitle.h"
#include "Dungeon.h"
Dungeon_GameTitle::Dungeon_GameTitle()
{
	M_GameTitleTexture.Init("Assets/Sprite/Dungeon/GameTitle.DDS", 1920.0f, 1080.0f);
}
bool Dungeon_GameTitle::Start()
{
	P_Dungeon = FindGO<Dungeon>("dungeon");
	return true;
}
void Dungeon_GameTitle::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		P_Dungeon->Create(FIRST);
	}
	M_GameTitleTexture.Update();
}
void Dungeon_GameTitle::Render(RenderContext& rc)
{
	M_GameTitleTexture.Draw(rc);
}
