#include "stdafx.h"
#include "Game.h"
#include "GazeJourney.h"

#include "�L�����N�^�[/GazeJourney_Character.h"
#include "�X�e�[�W/GazeJourney_Stage.h"

#include "Tool/DimensionalCollision.h"
#include "Tool/DimensionalCamera.h"

GazeJourney::GazeJourney()
{
	S_Gaze.P_Stage = NewGO<GazeJourney_Stage>(0, "stage");
	S_Gaze.P_Character = NewGO<GazeJourney_Character>(0, "character");
}
GazeJourney::~GazeJourney()
{

}