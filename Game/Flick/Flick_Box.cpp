#include "stdafx.h"
#include "Flick.h"
#include "Flick_Box.h"
#include "DimensionCollision.h"
#include "MouseÅEController/Mouse.h"
bool Flick_Box::Start()
{
	M_BoxTexture.Init("Assets/Sprite/Flick/Box.DDS", 90.0f, 90.0f, true);
	P_Collision = FindGO<DimensionCollision>("collision");
	P_Flick = FindGO<Flick>("flick");
	P_Mouse = FindGO<Mouse>("mouse");
	P_Collision->DecisionDataSet(90, 90, M_BoxPosition.x, M_BoxPosition.y, FLICK_COLLISION_BOX, FLICK_TAG_BOX);
	return true;
}
void Flick_Box::Update()
{
	Move();
	Fall();
	P_Collision->DecisionSetPosition(M_BoxPosition.x, M_BoxPosition.y, FLICK_COLLISION_BOX);
	M_BoxTexture.SetPosition(M_BoxPosition);
	M_BoxTexture.Update();
}
void Flick_Box::Render(RenderContext& rc)
{
	M_BoxTexture.Draw(rc);
}

void Flick_Box::Fall()
{
	if (!P_Collision->EmptyAndEmptysCollision(FLICK_COLLISION_BOX, DIRECTION_DOWN, FLICK_TAG_GROUND, DIRECTION_UP) && !P_Mouse->GetLeftButton())
	{
		M_FallFlag = true;
	}else {
		if (P_Collision->EmptyAndEmptysCollision(FLICK_COLLISION_BOX, DIRECTION_DOWN, FLICK_TAG_GROUND, DIRECTION_UP))
		{
			M_FallFlag = false;
		}
	}

	if (M_FallFlag)
	{M_BoxPosition.y -= P_Flick->GetGravity();}
}
void Flick_Box::Move()
{
	if (P_Collision->DecisionAndDecisionCollision(FLICK_COLLISION_BOX, FLICK_COLLISION_CURSOR) && P_Mouse->GetLeftButton())
	{
		M_BoxPosition = P_Mouse->GetMousePosition();
		M_FallFlag = false;
	}
}