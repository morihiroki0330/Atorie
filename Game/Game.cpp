#include "stdafx.h"
#include "Game.h"
#include "GameCode/Dungeon/Dungeon.h"
#include "GameCode/Action/Action.h"
#include "GameCode/DragAndDraw/DragAndDraw.h"
#include "GameCode/TwoCamera/TwoCamera.h"

#include "MouseÅEController/Mouse.h"
#include "MouseÅEController/Controller.h"
Game::Game()
{
	//S_GameClass.P_Dungeon = NewGO<Dungeon>(0, "dungeon");
	//S_GameClass.P_Action = NewGO<Action>(0, "action");
	//S_GameClass.P_DragAndDraw = NewGO<DragAndDraw>(0, "dad");
	S_GameClass.P_TwoCamera = NewGO<TwoCamera>(0, "twocamera");

	S_Operation.P_Mouse = NewGO<Mouse>(1, "mouse");
	S_Operation.P_Controller = NewGO<Controller>(1, "controller");
}
Game::~Game()
{
	//DeleteGO(S_GameClass.P_Dungeon);
	//DeleteGO(S_GameClass.P_Action);
	//DeleteGO(S_GameClass.P_DragAndDraw);
	DeleteGO(S_GameClass.P_TwoCamera);

	DeleteGO(S_Operation.P_Mouse);
	DeleteGO(S_Operation.P_Controller);
}