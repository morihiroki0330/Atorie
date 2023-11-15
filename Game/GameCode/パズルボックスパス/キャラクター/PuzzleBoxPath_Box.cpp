#include "stdafx.h"
#include "Game.h"
#include "GameCode/パズルボックスパス/PuzzleBoxPath.h"
#include "PuzzleBoxPath_Box.h"
#include "DimensionCollision.h"
#include "Mouse・Controller/Mouse.h"
bool PuzzleBoxPath_Box::Start()
{
	M_BoxTexture.Init("Assets/Sprite/PuzzleBoxPath/Box.DDS", 90.0f, 90.0f, true);
	P_Collision = FindGO<DimensionCollision>("collision");
	P_Puzzle = FindGO<PuzzleBoxPath>("puzzle");
	P_Mouse = FindGO<Mouse>("mouse");
	P_Collision->DecisionDataSet(90, 90, M_BoxPosition.x, M_BoxPosition.y, PBP_COLLISION_BOX, PBP_TAG_BOX);
	return true;
}
void PuzzleBoxPath_Box::Update()
{
	Move();
	Fall();
	Goal();
	Over();
	P_Collision->DecisionSetPosition(M_BoxPosition.x, M_BoxPosition.y, PBP_COLLISION_BOX);
	M_BoxTexture.SetPosition(M_BoxPosition);
	M_BoxTexture.Update();
}
void PuzzleBoxPath_Box::Render(RenderContext& rc)
{
	M_BoxTexture.Draw(rc);
}

void PuzzleBoxPath_Box::Fall()
{
	if (!P_Collision->EmptyAndEmptysCollision(PBP_COLLISION_BOX, DIRECTION_DOWN, PBP_TAG_GROUND, DIRECTION_UP) && !P_Mouse->GetMouseFlag(LEFTBUTTON))
	{
		M_FallFlag = true;
	}else {
		if (P_Collision->EmptyAndEmptysCollision(PBP_COLLISION_BOX, DIRECTION_DOWN, PBP_TAG_GROUND, DIRECTION_UP))
		{
			M_FallFlag = false;
		}
	}

	if (M_FallFlag)
	{M_BoxPosition.y -= P_Puzzle->GetGravity();}
}
void PuzzleBoxPath_Box::Move()
{
	if (P_Collision->DecisionAndDecisionCollision(PBP_COLLISION_BOX, PBP_COLLISION_CURSOR) && !P_Collision->DecisionAndDecisionCollision(PBP_COLLISION_CURSOR, PBP_COLLISION_DRAWERRORBOX))
	{
		M_BoxPosition += P_Mouse->GetMouseMoveSpeed();
		M_FallFlag = false;
	}else {
		if (!P_Collision->DecisionAndDecisionCollision(PBP_COLLISION_BOX, PBP_COLLISION_CURSOR) || P_Collision->DecisionAndDecisionCollision(PBP_COLLISION_CURSOR,PBP_COLLISION_DRAWERRORBOX))
		{
			M_FallFlag = true;
		}
	}
}
void PuzzleBoxPath_Box::Goal()
{
	if (P_Collision->DecisionAndDecisionCollision(PBP_COLLISION_BOX, PBP_COLLISION_GOAL))
	{
		P_Puzzle->SetFlag(PBP_FLAG_Goal);
		P_Puzzle->Create(SECOND);
	}
}
void PuzzleBoxPath_Box::Over()
{
	if (P_Collision->DecisionAndDecisionsCollision(PBP_COLLISION_BOX, PBP_TAG_ERRORBOX))
	{
		P_Puzzle->SetFlag(PBP_FLAG_Over);
		P_Puzzle->Create(SECOND);
	}
}