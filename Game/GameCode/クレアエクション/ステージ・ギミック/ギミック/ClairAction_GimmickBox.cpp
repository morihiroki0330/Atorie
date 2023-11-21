#include "stdafx.h"
#include "ClairAction_GimmickBox.h"

#include "GameCode/クレアエクション/ClairAction.h"

#include "Tool/DimensionalCollision.h"
#include "Mouse・Controller/Mouse.h"

bool ClairAction_GimmickBox::Start()
{
	M_BoxTexture.Init("Assets/Sprite/ClairAction/GimmickBox.DDS", 120.0f, 120.0f, true);
	P_Collision = FindGO<DimensionalCollision>("collision");
	P_Clair = FindGO<ClairAction>("clair");
	P_Mouse = FindGO<Mouse>("mouse");
	P_Collision->DecisionDataSet(120, 120, M_BoxPosition.x, M_BoxPosition.y, CA_COLLISION_BOX, CA_TAG_BOX, M_CollisionNumner);
	return true;
}
void ClairAction_GimmickBox::Update()
{
	Move();
	Fall();
	Reset();
	P_Collision->DecisionSetPosition(M_BoxPosition.x, M_BoxPosition.y, CA_COLLISION_BOX, M_CollisionNumner);
	M_BoxTexture.SetPosition(M_BoxPosition);
	M_BoxTexture.Update();
}
void ClairAction_GimmickBox::Render(RenderContext& rc)
{
	M_BoxTexture.Draw(rc);
}

void ClairAction_GimmickBox::Fall()
{
	if (!P_Collision->EmptysAndEmptysCollision(CA_TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, CA_TAG_GROUND, DIRECTION_UP) && !P_Collision->EmptysAndEmptysCollision(CA_TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, CA_TAG_BOX, DIRECTION_UP) && !P_Mouse->GetMouseFlag(LEFTBUTTON))
	{
		M_FallFlag = true;
	}else {
		if (P_Collision->EmptysAndEmptysCollision(CA_TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, CA_TAG_GROUND, DIRECTION_UP) || P_Collision->EmptysAndEmptysCollision(CA_TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, CA_TAG_BOX, DIRECTION_UP))
		{
			if (P_Collision->EmptysAndEmptysCollision(CA_TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, CA_TAG_GROUND, DIRECTION_UP))
			{
				M_OnGround = true;
				M_OnBox = false;
			}else {
			if (P_Collision->EmptysAndEmptysCollision(CA_TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, CA_TAG_BOX, DIRECTION_UP))
			{
				M_OnGround = false;
				M_OnBox = true;
			}
			}
			M_FallFlag = false;
		}
	}

	if (M_FallFlag)
	{M_BoxPosition.y -= P_Clair->GetGravity();}
}
void ClairAction_GimmickBox::Move()
{
	if (P_Collision->DecisionAndDecisionsCollision(CA_COLLISION_CURSOR, CA_TAG_BOX, M_CollisionNumner) || M_OnBox)
	{
		M_BoxPosition += P_Mouse->GetMouseMoveSpeed();
		M_FallFlag = false;
	}else {
		if (!P_Collision->DecisionAndDecisionsCollision(CA_COLLISION_CURSOR, CA_TAG_BOX, M_CollisionNumner))
		{
			M_FallFlag = true;
			M_OnGround = false;
			M_OnBox = false;
		}
	}
}

void ClairAction_GimmickBox::Reset()
{
	if (P_Collision->EmptysAndEmptysCollision(CA_TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, CA_TAG_GROUND, DIRECTION_UP))
	{
		M_OnGround = true;
		M_OnBox = false;
	}
}