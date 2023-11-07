#include "stdafx.h"
#include "Game.h"
#include "Action.h"
#include "Action_Character.h"
#include "Action_Stage.h"
#include "DimensionCollision.h"
#include "マウス・コントローラー/Controller.h"
bool Action_Character::Start()
{
	P_Action = FindGO<Action>("action");
	P_Stage = FindGO<Action_Stage>("action_stage");
	P_Collision = FindGO<DimensionCollision>("collision");
	P_Controller = FindGO<Controller>("controller");

	M_CharacterTexture.Init("Assets/Sprite/Action/Riblock.DDS", 90.0f, 90.0f, true);

	P_Collision->DecisionDataSet(90.0f, 90.0f, M_CharacterPosition.x, M_CharacterPosition.y, COLLISION_CHARACTER, TAG_NON);
	return true;
}
void Action_Character::Update()
{
	Move();
	P_Collision->DecisionSetPosition(M_CharacterPosition.x, M_CharacterPosition.y, COLLISION_CHARACTER);
	M_CharacterTexture.SetPosition(M_CharacterPosition);
	M_CharacterTexture.Update();
}
void Action_Character::Render(RenderContext& rc)
{
	M_CharacterTexture.Draw(rc);
}

void Action_Character::Goal()
{
	if (P_Collision->DecisionAndDecisionCollision(COLLISION_CHARACTER, COLLISION_GOAL))
	{
		P_Action->Create(SECOND);
	}
}
void Action_Character::Move()
{
	Fall();
	Jump();
	Walk();
	Goal();
}
void Action_Character::Walk()
{
	M_CharacterSpeed.x = P_Controller->GetLStick().x;

	WallCollision();
	GroundCollision();

	if (S_Flag.M_WalkFlag)
	{M_CharacterPosition.x += M_CharacterSpeed.x;}
}
void Action_Character::Jump()
{
	if (g_pad[0]->IsTrigger(enButtonA) && !S_Flag.M_FallFlag && !S_Flag.M_JumpFlag)
	{
		S_Flag.M_JumpFlag = true;
	}else {
		if (S_Flag.M_JumpFlag)
		{
			M_JumpCoolTime++;
			if (M_JumpCoolTime > 60)
			{
				M_JumpCoolTime = 0;
				S_Flag.M_JumpFlag = false;
			}else {
				if (P_Collision->EmptyAndEmptysCollision(COLLISION_CHARACTER, DIRECTION_UP, TAG_WALL, DIRECTION_DOWN) || P_Collision->EmptyAndEmptysCollision(COLLISION_CHARACTER, DIRECTION_UP, TAG_GROUND, DIRECTION_DOWN))
				{
					M_JumpCoolTime = 0;
					S_Flag.M_JumpFlag = false;
				}
			}
		}
	}

	if (S_Flag.M_JumpFlag)
	{
		M_CharacterPosition.y += M_CharacterSpeed.y;
	}
}
void Action_Character::Fall()
{
	if (!P_Collision->EmptyAndEmptysCollision(COLLISION_CHARACTER, DIRECTION_DOWN, TAG_GROUND, DIRECTION_UP) && !S_Flag.M_JumpFlag)
	{
		S_Flag.M_FallFlag = true;
	}else {
		if (P_Collision->EmptyAndEmptysCollision(COLLISION_CHARACTER, DIRECTION_DOWN, TAG_GROUND, DIRECTION_UP))
		{
			S_Flag.M_FallFlag = false;
			S_Flag.M_JumpFlag = false;
		}
	}

	if (S_Flag.M_FallFlag)
	{M_CharacterPosition.y -= P_Action->GetGravity();}
}

void Action_Character::WallCollision()
{
	if (!P_Collision->EmptyAndEmptysCollision(COLLISION_CHARACTER, DIRECTION_RIGHT, TAG_WALL, DIRECTION_LEFT) && !P_Collision->EmptyAndEmptysCollision(COLLISION_CHARACTER, DIRECTION_LEFT, TAG_WALL, DIRECTION_RIGHT))
	{
		S_Flag.M_WalkFlag = true;
	}else {
		if (P_Collision->EmptyAndEmptysCollision(COLLISION_CHARACTER, DIRECTION_RIGHT, TAG_WALL, DIRECTION_LEFT))
		{
			if (M_CharacterSpeed.x > 0.0f)
			{
				S_Flag.M_WalkFlag = false;
			}else {
				S_Flag.M_WalkFlag = true;
			}
		}else {
			if (P_Collision->EmptyAndEmptysCollision(COLLISION_CHARACTER, DIRECTION_LEFT, TAG_WALL, DIRECTION_RIGHT))
			{
				if (M_CharacterSpeed.x < 0.0f)
				{
					S_Flag.M_WalkFlag = false;
				}else {
					S_Flag.M_WalkFlag = true;
				}
			}
		}
	}
}
void Action_Character::GroundCollision()
{
	if (S_Flag.M_FallFlag || S_Flag.M_JumpFlag)
	{
		if (P_Collision->EmptyAndEmptysCollision(COLLISION_CHARACTER, DIRECTION_LEFT, TAG_GROUND, DIRECTION_RIGHT))
		{
			if (M_CharacterSpeed.x < 0.0f)
			{
				S_Flag.M_WalkFlag = false;
			}else {
				S_Flag.M_WalkFlag = true;
			}
		}else {
			if (P_Collision->EmptyAndEmptysCollision(COLLISION_CHARACTER, DIRECTION_RIGHT, TAG_GROUND, DIRECTION_LEFT))
			{
				if (M_CharacterSpeed.x > 0.0f)
				{
					S_Flag.M_WalkFlag = false;
				}else {
					S_Flag.M_WalkFlag = true;
				}
			}
		}
	}
}