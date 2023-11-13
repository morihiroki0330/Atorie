#include "stdafx.h"
#include "GazeJourney.h"
#include "GazeJourney_Stage.h"
#include "DimensionCollision.h"
#include "TwoDimensionalCamera.h"
GazeJourney_Stage::GazeJourney_Stage()
{
	M_StageTexture.Init("Assets/Sprite/GazeJourney/Stage.DDS", 1920.0f, 1080.0f, true);
}
bool GazeJourney_Stage::Start()
{
	P_Camera = FindGO<TwoDimensionalCamera>("camera");
	P_Collision = FindGO<DimensionCollision>("collision");
	P_Collision->DecisionDataSet(1920.0f, 150.0f, 0.0f, -465.0f, GJ_COLLISION_GROUND, GJ_TAG_GROUND);
	return true;
}
void GazeJourney_Stage::Update()
{
	P_Camera->CenterOffObjectMove(M_StagePosition);
	M_StageTexture.SetPosition(M_StagePosition);
	M_StageTexture.Update();
}
void GazeJourney_Stage::Render(RenderContext& rc)
{
	M_StageTexture.Draw(rc);
}