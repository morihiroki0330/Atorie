#include "stdafx.h"
#include "Game.h"
#include "©“®¶¬–À˜H/Dungeon.h"
Game::Game()
{
	S_GameClass.P_Dungeon = NewGO<Dungeon>(0, "dungeon");
}
Game::~Game()
{
	DeleteGO(S_GameClass.P_Dungeon);
}