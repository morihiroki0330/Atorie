#include "stdafx.h"
#include "Game.h"
#include "GameCode/ダンジョンオデッセイ/DungeonOdyssey.h"
#include "GameCode/リブロックの冒険/LivblockAdventure.h"
#include "GameCode/パズルボックスパス/PuzzleBoxPath.h"
#include "GameCode/フリックブレイド/FlickBlade.h"
#include "GameCode/視線の旅/GazeJourney.h"

#include "Mouse・Controller/Mouse.h"
#include "Mouse・Controller/Controller.h"
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