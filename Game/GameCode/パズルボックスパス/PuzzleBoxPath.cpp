#include "stdafx.h"
#include "Game.h"
#include "PuzzleBoxPath.h"
#include "PuzzleBoxPath_GameTitle.h"
#include "PuzzleBoxPath_GameResult.h"
#include "PuzzleBoxPath_Stage.h"
#include "PuzzleBoxPath_Box.h"
#include "DimensionCollision.h"
#include "MouseÅEController/Mouse.h"
PuzzleBoxPath::PuzzleBoxPath()
{
	S_PuzzleBoxPath.P_Collision = NewGO<DimensionCollision>(0, "collision");
	S_PuzzleBoxPath.P_GameTitle = NewGO<PuzzleBoxPath_GameTitle>(0, "dad_gametitle");
}
PuzzleBoxPath::~PuzzleBoxPath()
{
	DeleteGO(S_PuzzleBoxPath.P_GameTitle);
	DeleteGO(S_PuzzleBoxPath.P_GameResult);
	DeleteGO(S_PuzzleBoxPath.P_Collision);
}
bool PuzzleBoxPath::Start()
{
	S_PuzzleBoxPath.P_Mouse = FindGO<Mouse>("mouse");
	S_PuzzleBoxPath.P_Mouse->MouseCursorTextureSet("Assets/Sprite/PuzzleBoxPath/MouseCursor.DDS", 90.0f, 90.0f, true);
	S_PuzzleBoxPath.P_Collision->DecisionDataSet(100.0f, 100.0f, S_PuzzleBoxPath.P_Mouse->GetMousePosition().x, S_PuzzleBoxPath.P_Mouse->GetMousePosition().y, PBP_COLLISION_CURSOR, PBP_TAG_NON);
	return true;
}
void PuzzleBoxPath::Update()
{
	S_PuzzleBoxPath.P_Collision->DecisionSetPosition(S_PuzzleBoxPath.P_Mouse->GetMousePosition().x, S_PuzzleBoxPath.P_Mouse->GetMousePosition().y, PBP_COLLISION_CURSOR);
}

void PuzzleBoxPath::Create(int Number)
{
	switch (Number)
	{
	case FIRST:
		DeleteGO(S_PuzzleBoxPath.P_GameTitle);
		S_PuzzleBoxPath.P_Stage = NewGO<PuzzleBoxPath_Stage>(0, "stage");
		S_PuzzleBoxPath.P_Box = NewGO<PuzzleBoxPath_Box>(0, "box");
		break;
	case SECOND:
		DeleteGO(S_PuzzleBoxPath.P_Stage);
		DeleteGO(S_PuzzleBoxPath.P_Box);
		S_PuzzleBoxPath.P_GameResult = NewGO<PuzzleBoxPath_GameResult>(0, "gameresult");
		break;
	}
}

void PuzzleBoxPath::SetFlag(int Number)
{
	switch (Number)
	{
	case PBP_FLAG_Goal:
		M_GoalFlag = true;
		break;
	case PBP_FLAG_Over:
		M_OverFlag = true;
		break;
	}
}
bool PuzzleBoxPath::GetFlag(int Number)
{
	switch (Number)
	{
	case PBP_FLAG_Goal:
		return M_GoalFlag;
		break;
	case PBP_FLAG_Over:
		return M_OverFlag;
		break;
	}
}