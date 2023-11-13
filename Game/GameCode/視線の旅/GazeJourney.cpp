#include "stdafx.h"
#include "Game.h"
#include "GazeJourney.h"
#include "GazeJourney_GameTitle.h"
#include "GazeJourney_GameResult.h"
#include "GazeJourney_Character.h"
#include "GazeJourney_Stage.h"
#include "DimensionCollision.h"
#include "TwoDimensionalCamera.h"
GazeJourney::GazeJourney()
{
	S_Gaze.P_Collision = NewGO<DimensionCollision>(0, "collision");
	S_Gaze.P_Camera = NewGO<TwoDimensionalCamera>(0, "camera");
	S_Gaze.P_GameTitle = NewGO<GazeJourney_GameTitle>(0, "gametitle");
}
GazeJourney::~GazeJourney()
{

}
void GazeJourney::Create(int Number)
{
	switch (Number)
	{
	case FIRST:
		DeleteGO(S_Gaze.P_GameTitle);
		S_Gaze.P_Stage = NewGO<GazeJourney_Stage>(0, "stage");
		S_Gaze.P_Character = NewGO<GazeJourney_Character>(0, "character");
		break;
	case SECOND:
		DeleteGO(S_Gaze.P_Stage);
		DeleteGO(S_Gaze.P_Character);
		S_Gaze.P_Collision->Reset();
		S_Gaze.P_GameResult = NewGO<GazeJourney_GameResult>(0, "gameresult");
		break;
	case THIRD:
		DeleteGO(S_Gaze.P_GameResult);
		S_Gaze.P_GameTitle = NewGO<GazeJourney_GameTitle>(0, "gametitle");
		break;
	}
}