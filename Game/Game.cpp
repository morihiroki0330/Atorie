#include "stdafx.h"
#include "Game.h"
#include "�����������H/Dungeon.h"
#include "�A�N�V����/Action.h"

#include "�}�E�X�E�R���g���[���[/Mouse.h"
#include "�}�E�X�E�R���g���[���[/Controller.h"
Game::Game()
{
	//S_GameClass.P_Dungeon = NewGO<Dungeon>(0, "dungeon");
	S_GameClass.P_Action = NewGO<Action>(0, "action");

	S_Operation.P_Mouse = NewGO<Mouse>(0, "mouse");
	S_Operation.P_Controller = NewGO<Controller>(0, "controller");
}
Game::~Game()
{
	//DeleteGO(S_GameClass.P_Dungeon);
	DeleteGO(S_GameClass.P_Action);

	DeleteGO(S_Operation.P_Mouse);
	DeleteGO(S_Operation.P_Controller);
}