#include "stdafx.h"
#include "Game.h"
#include "Flick.h"
#include "Flick_GameTitle.h"
#include "DimensionCollision.h"
#include "MouseÅEController/Mouse.h"
Flick_GameTitle::Flick_GameTitle()
{
	M_GameTitleTexture.Init("Assets/Sprite/Flick/GameTitle.DDS", 1920.0f, 1080.0f,true);
	M_GameTitleButtonTexture.Init("Assets/Sprite/Flick/GameTitleButton.DDS", 600.0f, 200.f, true);
}
bool Flick_GameTitle::Start()
{
	P_Flick = FindGO<Flick>("flick");
	P_Collision = FindGO<DimensionCollision>("collision");
	P_Mouse = FindGO<Mouse>("mouse");
	P_Collision->DecisionDataSet(600.0f, 200.0f, M_GameTitleButtonPosition.x, M_GameTitleButtonPosition.y, FLICK_COLLISION_TITLEBUTTON, FLICK_TAG_NON);
	return true;
}
void Flick_GameTitle::Update()
{
	if (P_Collision->DecisionAndDecisionCollision(FLICK_COLLISION_CURSOR,FLICK_COLLISION_TITLEBUTTON) && P_Mouse->GetLeftButton())
	{
		P_Flick->Create(FIRST);
	}
	M_GameTitleTexture.Update();
	M_GameTitleButtonTexture.SetPosition(M_GameTitleButtonPosition);
	M_GameTitleButtonTexture.Update();
}
void Flick_GameTitle::Render(RenderContext& rc)
{
	M_GameTitleTexture.Draw(rc);
	M_GameTitleButtonTexture.Draw(rc);
}