#include "stdafx.h"
#include "Game.h"
#include "GameCode/�_���W�����I�f�b�Z�C/DungeonOdyssey.h"
#include "GameCode/���u���b�N�̖`��/LivblockAdventure.h"
#include "GameCode/�p�Y���{�b�N�X�p�X/PuzzleBoxPath.h"
#include "GameCode/�t���b�N�u���C�h/FlickBlade.h"
#include "GameCode/�����̗�/GazeJourney.h"

#include "Mouse�EController/Mouse.h"
#include "Mouse�EController/Controller.h"
Game::Game()
{
	//S_GameClass.P_DO = NewGO<DungeonOdyssey>(0, "dungeon");
	//S_GameClass.P_LA = NewGO<LivblockAdventure>(0, "livblock");
	//S_GameClass.P_PBP = NewGO<PuzzleBoxPath>(0, "puzzle");
	//S_GameClass.P_FB = NewGO<FlickBlade>(0, "flick");
	S_GameClass.P_GJ = NewGO<GazeJourney>(0, "gaze");

	S_Operation.P_Mouse = NewGO<Mouse>(1, "mouse");
	S_Operation.P_Controller = NewGO<Controller>(1, "controller");
}
Game::~Game()
{
	//DeleteGO(S_GameClass.P_DO);
	//DeleteGO(S_GameClass.P_Livblock);
	//DeleteGO(S_GameClass.P_PBP);
	//DeleteGO(S_GameClass.P_FB);
	DeleteGO(S_GameClass.P_GJ);

	DeleteGO(S_Operation.P_Mouse);
	DeleteGO(S_Operation.P_Controller);
}