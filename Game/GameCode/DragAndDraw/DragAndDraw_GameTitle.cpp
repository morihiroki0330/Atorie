#include "stdafx.h"
#include "Game.h"
#include "DragAndDraw.h"
#include "DragAndDraw_GameTitle.h"
#include "DimensionCollision.h"
#include "MouseÅEController/Mouse.h"
DragAndDraw_GameTitle::DragAndDraw_GameTitle()
{
	M_GameTitleTexture.Init("Assets/Sprite/DragAndDraw/GameTitle.DDS", 1920.0f, 1080.0f,true);
	M_GameTitleButtonTexture.Init("Assets/Sprite/DragAndDraw/GameTitleButton.DDS", 600.0f, 200.f, true);
}
bool DragAndDraw_GameTitle::Start()
{
	P_DragAndDraw = FindGO<DragAndDraw>("dad");
	P_Collision   = FindGO<DimensionCollision>("collision");
	P_Mouse       = FindGO<Mouse>("mouse");

	P_Collision->DecisionDataSet(600.0f, 200.0f, M_GameTitleButtonPosition.x, M_GameTitleButtonPosition.y, DAD_COLLISION_TITLEBUTTON, DAD_TAG_NON);
	return true;
}
void DragAndDraw_GameTitle::Update()
{
	if (P_Collision->DecisionAndDecisionCollision(DAD_COLLISION_CURSOR,DAD_COLLISION_TITLEBUTTON) && P_Mouse->GetLeftButton())
	{P_DragAndDraw->Create(FIRST);}

	M_GameTitleTexture.Update();
	M_GameTitleButtonTexture.SetPosition(M_GameTitleButtonPosition);
	M_GameTitleButtonTexture.Update();
}
void DragAndDraw_GameTitle::Render(RenderContext& rc)
{
	M_GameTitleTexture.Draw(rc);
	M_GameTitleButtonTexture.Draw(rc);
}