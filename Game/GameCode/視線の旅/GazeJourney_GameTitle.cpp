#include "stdafx.h"
#include "Game.h"
#include "GazeJourney.h"
#include "GazeJourney_GameTitle.h"
GazeJourney_GameTitle::GazeJourney_GameTitle()
{
	M_GameTitleTexture.Init("Assets/Sprite/GazeJourney/GameTitle.DDS", 1920.0f, 1080.0f,true);
}
bool GazeJourney_GameTitle::Start()
{
	P_Gaze = FindGO<GazeJourney>("gaze");
	return true;
}
void GazeJourney_GameTitle::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{P_Gaze->Create(FIRST);}
	M_GameTitleTexture.Update();
}
void GazeJourney_GameTitle::Render(RenderContext& rc)
{
	M_GameTitleTexture.Draw(rc);
}