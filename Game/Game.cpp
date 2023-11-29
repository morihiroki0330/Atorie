#include "stdafx.h"
#include "Game.h"
#include "GameCode/クレアエクション/ClairAction.h"

#include "Mouse・Controller/Mouse.h"
#include "Mouse・Controller/Controller.h"

#include "DimensionalElement/DimensionalCamera.h"
#include "DimensionalElement/DimensionalCollision.h"
#include "DimensionalElement/MapCreate.h"

#include "DimensionalEffect/Weather.h"
#include "DimensionalEffect/Fade.h"
Game::Game()
{
	S_GameClass.P_Clair = NewGO<ClairAction>(0, "clair");

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
	DeleteGO(S_GameClass.P_Clair);

	DeleteGO(S_Operation.P_Mouse);
	DeleteGO(S_Operation.P_Controller);

	DeleteGO(S_Tool.P_Camera);
	DeleteGO(S_Tool.P_Collision);
	DeleteGO(S_Tool.P_MapCreate);
	DeleteGO(S_Tool.P_Weather);
	DeleteGO(S_Tool.P_Fade);
}