#include "stdafx.h"
#include "Game.h"
#include "GazeJourney.h"
#include "キャラクター/GazeJourney_Character.h"
#include "ステージ/GazeJourney_Stage.h"
#include "DimensionCollision.h"
#include "TwoDimensionalCamera.h"
GazeJourney::GazeJourney()
{
	S_Gaze.P_Collision = NewGO<DimensionCollision>(0, "collision");
	S_Gaze.P_Camera = NewGO<TwoDimensionalCamera>(0, "camera");
	S_Gaze.P_Stage = NewGO<GazeJourney_Stage>(0, "stage");
	S_Gaze.P_Character = NewGO<GazeJourney_Character>(0, "character");
}
GazeJourney::~GazeJourney()
{

}