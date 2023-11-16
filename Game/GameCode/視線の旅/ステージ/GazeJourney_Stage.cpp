#include "stdafx.h"
#include "GazeJourney_Stage.h"

#include "GameCode/éãê¸ÇÃó∑/GazeJourney.h"

#include "Tool/DimensionalCollision.h"
#include "Tool/DimensionalCamera.h"

GazeJourney_Stage::GazeJourney_Stage()
{
	M_StageTexture[0].Init("Assets/Sprite/GazeJourney/Stage.DDS", 1920.0f, 1080.0f, true);
	M_StageTexture[1].Init("Assets/Sprite/GazeJourney/Stage1.DDS", 1920.0f, 1080.0f, true);
}
bool GazeJourney_Stage::Start()
{
	P_Camera = FindGO<DimensionalCamera>("camera");
	P_Collision = FindGO<DimensionalCollision>("collision");
	P_Collision->DecisionDataSet(1920.0f, 150.0f, 0.0f, -450.0f, GJ_COLLISION_GROUND, GJ_TAG_GROUND);
	M_StagePosition[1].x = 1920.0f;
	return true;
}
void GazeJourney_Stage::Update()
{
	for (int i = 0; i < 2; i++)
	{
		P_Camera->CenterOffObjectMove(M_StagePosition[i]);
		P_Collision->DecisionSetPosition(M_StagePosition[0].x, -450.0f, GJ_COLLISION_GROUND);
		M_StageTexture[i].SetPosition(M_StagePosition[i]);
		M_StageTexture[i].Update();
	}
}
void GazeJourney_Stage::Render(RenderContext& rc)
{
	M_StageTexture[0].Draw(rc);
	M_StageTexture[1].Draw(rc);
}