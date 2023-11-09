#include "stdafx.h"
#include "Game.h"
#include "DragAndDraw.h"
#include "DragAndDraw_GameTitle.h"
#include "DragAndDraw_GameResult.h"
#include "DragAndDraw_Stage.h"
#include "DragAndDraw_Box.h"
#include "DimensionCollision.h"
#include "MouseÅEController/Mouse.h"
DragAndDraw::DragAndDraw()
{
	S_DragAndDraw.P_Collision = NewGO<DimensionCollision>(0, "collision");
	S_DragAndDraw.P_GameTitle = NewGO<DragAndDraw_GameTitle>(0, "dad_gametitle");
}
DragAndDraw::~DragAndDraw()
{
	DeleteGO(S_DragAndDraw.P_GameTitle);
	DeleteGO(S_DragAndDraw.P_GameResult);
	DeleteGO(S_DragAndDraw.P_Collision);
}
bool DragAndDraw::Start()
{
	S_DragAndDraw.P_Mouse = FindGO<Mouse>("mouse");
	S_DragAndDraw.P_Mouse->MouseCursorTextureSet("Assets/Sprite/DragAndDraw/MouseCursor.DDS", 90.0f, 90.0f, true);
	S_DragAndDraw.P_Collision->DecisionDataSet(100.0f, 100.0f, S_DragAndDraw.P_Mouse->GetMousePosition().x, S_DragAndDraw.P_Mouse->GetMousePosition().y, DAD_COLLISION_CURSOR, DAD_TAG_NON);
	return true;
}
void DragAndDraw::Update()
{
	S_DragAndDraw.P_Collision->DecisionSetPosition(S_DragAndDraw.P_Mouse->GetMousePosition().x, S_DragAndDraw.P_Mouse->GetMousePosition().y, DAD_COLLISION_CURSOR);
}

void DragAndDraw::Create(int Number)
{
	switch (Number)
	{
	case FIRST:
		DeleteGO(S_DragAndDraw.P_GameTitle);
		S_DragAndDraw.P_Stage = NewGO<DragAndDraw_Stage>(0, "dad_stage");
		S_DragAndDraw.P_Box = NewGO<DragAndDraw_Box>(0, "dad_box");
		break;
	case SECOND:
		DeleteGO(S_DragAndDraw.P_Stage);
		DeleteGO(S_DragAndDraw.P_Box);
		S_DragAndDraw.P_GameResult = NewGO<DragAndDraw_GameResult>(0, "dad_gameresult");
		break;
	}
}

void DragAndDraw::SetFlag(int Number)
{
	switch (Number)
	{
	case DAD_FLAG_Goal:
		M_GoalFlag = true;
		break;
	case DAD_FLAG_Over:
		M_OverFlag = true;
		break;
	}
}
bool DragAndDraw::GetFlag(int Number)
{
	switch (Number)
	{
	case DAD_FLAG_Goal:
		return M_GoalFlag;
		break;
	case DAD_FLAG_Over:
		return M_OverFlag;
		break;
	}
}