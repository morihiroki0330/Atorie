#include "stdafx.h"
#include "Game.h"
#include "GameCode/�_���W�����I�f�b�Z�C/DungeonOdyssey.h"
#include "GameCode/���u���b�N�̖`��/LivblockAdventure.h"
#include "GameCode/�p�Y���{�b�N�X�p�X/PuzzleBoxPath.h"
#include "GameCode/�t���b�N�u���C�h/FlickBlade.h"
#include "GameCode/�����̗�/GazeJourney.h"
#include "GameCode/�A�j���g�����@�[�X/AnimeTraverse.h"
#include "GameCode/�N���A�G�N�V����/ClairAction.h"

#include "Mouse�EController/Mouse.h"
#include "Mouse�EController/Controller.h"

#include "Tool/DimensionalCamera.h"
#include "Tool/DimensionalCollision.h"
#include "Tool/MapCreate.h"
#include "Tool/Weather.h"
#include "Tool/Fade.h"
Game::Game()
{
	S_GameClass.P_DO = NewGO<DungeonOdyssey>(0, "dungeon");
	//S_GameClass.P_LA = NewGO<LivblockAdventure>(0, "livblock");
	//S_GameClass.P_PBP = NewGO<PuzzleBoxPath>(0, "puzzle");
	//S_GameClass.P_FB = NewGO<FlickBlade>(0, "flick");
	//S_GameClass.P_GJ = NewGO<GazeJourney>(0, "gaze");
	//S_GameClass.P_AT = NewGO<AnimeTraverse>(0, "anime");
	//S_GameClass.P_CA = NewGO<ClairAction>(0, "clair");

	S_Operation.P_Mouse = NewGO<Mouse>(1, "mouse");
	S_Operation.P_Controller = NewGO<Controller>(1, "controller");

	S_Tool.P_Camera = NewGO<DimensionalCamera>(1, "camera");
	S_Tool.P_Collision = NewGO<DimensionalCollision>(1, "collision");
	S_Tool.P_MapCreate = NewGO<MapCreate>(1, "create");
	S_Tool.P_Weather = NewGO<Weather>(1, "weather");
	S_Tool.P_Fade = NewGO<Fade>(1, "fade");
}
Game::~Game()
{
	DeleteGO(S_GameClass.P_DO);
	//DeleteGO(S_GameClass.P_LA);
	//DeleteGO(S_GameClass.P_PBP);
	//DeleteGO(S_GameClass.P_FB);
	//DeleteGO(S_GameClass.P_GJ);
	//DeleteGO(S_GameClass.P_AT);
	//DeleteGO(S_GameClass.P_CA);

	DeleteGO(S_Operation.P_Mouse);
	DeleteGO(S_Operation.P_Controller);

	DeleteGO(S_Tool.P_Camera);
	DeleteGO(S_Tool.P_Collision);
	DeleteGO(S_Tool.P_MapCreate);
	DeleteGO(S_Tool.P_Weather);
	DeleteGO(S_Tool.P_Fade);
}