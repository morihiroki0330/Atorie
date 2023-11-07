#include "stdafx.h"
#include "Game.h"
#include "Dungeon/Dungeon.h"
#include "Action/Action.h"
#include "Flick/Flick.h"

#include "MouseÅEController/Mouse.h"
#include "MouseÅEController/Controller.h"
Game::Game()
{
	//S_GameClass.P_Dungeon = NewGO<Dungeon>(0, "dungeon");
	//S_GameClass.P_Action = NewGO<Action>(0, "action");
	S_GameClass.P_Flick = NewGO<Flick>(0, "flick");

	S_Operation.P_Mouse = NewGO<Mouse>(1, "mouse");
	S_Operation.P_Controller = NewGO<Controller>(1, "controller");
}
Game::~Game()
{
	//DeleteGO(S_GameClass.P_Dungeon);
	//DeleteGO(S_GameClass.P_Action);
	DeleteGO(S_GameClass.P_Flick);

	DeleteGO(S_Operation.P_Mouse);
	DeleteGO(S_Operation.P_Controller);
}