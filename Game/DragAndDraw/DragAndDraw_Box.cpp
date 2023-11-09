#include "stdafx.h"
#include "Game.h"
#include "DragAndDraw.h"
#include "DragAndDraw_Box.h"
#include "DimensionCollision.h"
#include "MouseÅEController/Mouse.h"
bool DragAndDraw_Box::Start()
{
	M_BoxTexture.Init("Assets/Sprite/DragAndDraw/Box.DDS", 90.0f, 90.0f, true);
	P_Collision = FindGO<DimensionCollision>("collision");
	P_DragAndDraw = FindGO<DragAndDraw>("dad");
	P_Mouse = FindGO<Mouse>("mouse");
	P_Collision->DecisionDataSet(90, 90, M_BoxPosition.x, M_BoxPosition.y, DAD_COLLISION_BOX, DAD_TAG_BOX);
	return true;
}
void DragAndDraw_Box::Update()
{
	Move();
	Fall();
	Goal();
	Over();
	P_Collision->DecisionSetPosition(M_BoxPosition.x, M_BoxPosition.y, DAD_COLLISION_BOX);
	M_BoxTexture.SetPosition(M_BoxPosition);
	M_BoxTexture.Update();
}
void DragAndDraw_Box::Render(RenderContext& rc)
{
	M_BoxTexture.Draw(rc);
}

void DragAndDraw_Box::Fall()
{
	if (!P_Collision->EmptyAndEmptysCollision(DAD_COLLISION_BOX, DIRECTION_DOWN, DAD_TAG_GROUND, DIRECTION_UP) && !P_Mouse->GetLeftButton())
	{
		M_FallFlag = true;
	}else {
		if (P_Collision->EmptyAndEmptysCollision(DAD_COLLISION_BOX, DIRECTION_DOWN, DAD_TAG_GROUND, DIRECTION_UP))
		{
			M_FallFlag = false;
		}
	}

	if (M_FallFlag)
	{M_BoxPosition.y -= P_DragAndDraw->GetGravity();}
}
void DragAndDraw_Box::Move()
{
	if (P_Collision->DecisionAndDecisionCollision(DAD_COLLISION_BOX, DAD_COLLISION_CURSOR) && !P_Collision->DecisionAndDecisionCollision(DAD_COLLISION_CURSOR, DAD_COLLISION_DRAWERRORBOX))
	{
		M_BoxPosition += P_Mouse->GetMouseMoveSpeed();
		M_FallFlag = false;
	}else {
		if (!P_Collision->DecisionAndDecisionCollision(DAD_COLLISION_BOX, DAD_COLLISION_CURSOR) || P_Collision->DecisionAndDecisionCollision(DAD_COLLISION_CURSOR,DAD_COLLISION_DRAWERRORBOX))
		{
			M_FallFlag = true;
		}
	}
}
void DragAndDraw_Box::Goal()
{
	if (P_Collision->DecisionAndDecisionCollision(DAD_COLLISION_BOX, DAD_COLLISION_GOAL))
	{
		P_DragAndDraw->Goal();
		P_DragAndDraw->Create(SECOND);
	}
}
void DragAndDraw_Box::Over()
{
	if (P_Collision->DecisionAndDecisionsCollision(DAD_COLLISION_BOX, DAD_TAG_ERRORBOX))
	{
		P_DragAndDraw->Over();
		P_DragAndDraw->Create(SECOND);
	}
}