#include "stdafx.h"
#include "Game.h"
#include "TwoCamera.h"
#include "TwoCamera_GameTitle.h"
#include "TwoCamera_Character.h"
#include "TwoCamera_Stage.h"
#include "DimensionCollision.h"
#include "TwoDimensionalCamera.h"
TwoCamera::TwoCamera()
{
	S_TwoCamera.P_Collision = NewGO<DimensionCollision>(0, "collision");
	S_TwoCamera.P_Camera = NewGO<TwoDimensionalCamera>(0, "camera");
}
TwoCamera::~TwoCamera()
{

}