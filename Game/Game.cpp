#include "stdafx.h"
#include "Game.h"
#include "©“®¶¬–À˜H/Dungeon.h"
#include "ƒAƒNƒVƒ‡ƒ“/Action.h"
Game::Game()
{
	//S_GameClass.P_Dungeon = NewGO<Dungeon>(0, "dungeon");
	S_GameClass.P_Action = NewGO<Action>(0, "action");
}
Game::~Game()
{
	//DeleteGO(S_GameClass.P_Dungeon);
	DeleteGO(S_GameClass.P_Action);
}