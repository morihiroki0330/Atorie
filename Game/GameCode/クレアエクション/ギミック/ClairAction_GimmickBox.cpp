#include "stdafx.h"
#include "ClairAction_GimmickBox.h"

#include "GameCode/クレアエクション/ClairAction.h"

#include "DimensionalElement/DimensionalCollision.h"
#include "DimensionalStorage/NumberStorage.h"
#include "Mouse・Controller/Mouse.h"

bool ClairAction_GimmickBox::Start()
{
	M_BoxTexture.Init("Assets/Sprite/ClairAction/GimmickBox.DDS", 120.0f, 120.0f, true);
	P_Collision = FindGO<DimensionalCollision>("collision");
	P_Clair = FindGO<ClairAction>("clair");
	P_Mouse = FindGO<Mouse>("mouse");
	P_Collision->DecisionDataSet(120, 120, M_BoxPosition.x, M_BoxPosition.y, COLLISION_BOX, TAG_BOX, M_CollisionNumner);
	return true;
}
void ClairAction_GimmickBox::Update()
{
	Collision();
	Move();
	Fall();
	Reset();
	P_Collision->DecisionSetPosition(M_BoxPosition.x, M_BoxPosition.y, COLLISION_BOX, M_CollisionNumner);
	M_BoxTexture.SetPosition(M_BoxPosition);
	M_BoxTexture.Update();
}
void ClairAction_GimmickBox::Render(RenderContext& rc)
{
	M_BoxTexture.Draw(rc);
}

void ClairAction_GimmickBox::Fall()
{
	if (!M_OnBox && !M_OnGround)
	{
		if (!M_MoveFlag)
		{
			M_FallFlag = true;
		}else {
		if (M_MoveFlag)
		{
			M_FallFlag = false;
		}
		}
	}else {
	if (M_OnBox || M_OnGround)
	{
		M_FallFlag = false;
	}
	}

	if (M_FallFlag)
	{M_BoxPosition.y -= P_Clair->GetGravity();}
}
void ClairAction_GimmickBox::Move()
{
	if (!M_MoveFlag)
	{
		if (M_OnBox)
		{
			M_BoxPosition += P_Mouse->GetMouseMoveSpeed();
		}
	}

	if (M_MoveFlag)
	{M_BoxPosition += P_Mouse->GetMouseMoveSpeed();}
}
void ClairAction_GimmickBox::Collision()
{
	if (!P_Collision->EmptysAndEmptysCollision(TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, TAG_GROUND, DIRECTION_UP) && !P_Collision->EmptysAndEmptysCollision(TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, TAG_BOX, DIRECTION_UP))
	{
		//両方衝突していない
		M_OnBox = false;
		M_OnGround = false;
	}else {
		if (P_Collision->EmptysAndEmptysCollision(TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, TAG_GROUND, DIRECTION_UP) && P_Collision->EmptysAndEmptysCollision(TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, TAG_BOX, DIRECTION_UP))
		{
			//両方衝突している
			M_OnBox = true;
			M_OnGround = true;
		}
		else {
			if (P_Collision->EmptysAndEmptysCollision(TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, TAG_GROUND, DIRECTION_UP))
			{
				//地面と衝突している
				M_OnBox = false;
				M_OnGround = true;
			}
			else {
				if (P_Collision->EmptysAndEmptysCollision(TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, TAG_BOX, DIRECTION_UP))
				{
					//箱と衝突している
					M_OnBox = true;
					M_OnGround = false;
				}
			}
		}
	}

	if (!P_Collision->DecisionAndDecisionsCollision(COLLISION_CURSOR, TAG_BOX, M_CollisionNumner))
	{
		//カーソルと衝突していない
		M_MoveFlag = false;
	}else {
		if (P_Collision->DecisionAndDecisionsCollision(COLLISION_CURSOR, TAG_BOX, M_CollisionNumner))
		{
			//カーソルと衝突している
			if (!P_Mouse->GetMouseFlag(LEFTBUTTON))
			{
				//左クリックを押していない
				M_MoveFlag = false;
			}else {
			if (P_Mouse->GetMouseFlag(LEFTBUTTON))
			{
				//左クリックを押している
				M_MoveFlag = true;
			}
			}
		}
	}
}

void ClairAction_GimmickBox::Reset()
{
	if (P_Collision->EmptysAndEmptysCollision(TAG_BOX, DIRECTION_DOWN, M_CollisionNumner, TAG_GROUND, DIRECTION_DOWN))
	{M_BoxPosition.y = 0.0f;}
}