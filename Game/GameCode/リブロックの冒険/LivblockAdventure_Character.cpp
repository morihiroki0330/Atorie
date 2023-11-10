#include "stdafx.h"
#include "Game.h"
#include "LivblockAdventure.h"
#include "LivblockAdventure_Character.h"
#include "DimensionCollision.h"
#include "MouseÅEController/Controller.h"
LivblockAdventure_Character::LivblockAdventure_Character()
{
	M_CharacterTexture.Init("Assets/Sprite/LivblockAdventure/Riblock.DDS", 90.0f, 90.0f, true);
	
}
bool LivblockAdventure_Character::Start()
{
	P_Livblock   = FindGO<LivblockAdventure>("livblock");
	P_Collision  = FindGO<DimensionCollision>("collision");
	P_Controller = FindGO<Controller>("controller");
	P_Collision->DecisionDataSet(90.0f, 90.0f, M_CharacterPosition.x, M_CharacterPosition.y, LA_COLLISION_CHARACTER, LA_TAG_NON);
	return true;
}
void LivblockAdventure_Character::Update()
{
	Move();
	P_Collision->DecisionSetPosition(M_CharacterPosition.x, M_CharacterPosition.y, LA_COLLISION_CHARACTER);
	M_CharacterTexture.SetPosition(M_CharacterPosition);
	M_CharacterTexture.Update();
}
void LivblockAdventure_Character::Render(RenderContext& rc)
{
	M_CharacterTexture.Draw(rc);
}

void LivblockAdventure_Character::Move()
{
	Fall();
	Jump();
	Walk();
	Goal();
}
void LivblockAdventure_Character::Fall()
{
	if (!P_Collision->EmptyAndEmptysCollision(LA_COLLISION_CHARACTER, DIRECTION_DOWN, LA_TAG_GROUND, DIRECTION_UP) && !S_Flag.M_JumpFlag)
	{
		S_Flag.M_FallFlag = true;
	}else {
		if (P_Collision->EmptyAndEmptysCollision(LA_COLLISION_CHARACTER, DIRECTION_DOWN, LA_TAG_GROUND, DIRECTION_UP))
		{
			S_Flag.M_FallFlag = false;
			S_Flag.M_JumpFlag = false;
		}
	}

	if (S_Flag.M_FallFlag)
	{M_CharacterPosition.y -= P_Livblock->GetGravity();}
}
void LivblockAdventure_Character::Jump()
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
				if (P_Collision->EmptyAndEmptysCollision(LA_COLLISION_CHARACTER, DIRECTION_UP, LA_TAG_WALL, DIRECTION_DOWN) || P_Collision->EmptyAndEmptysCollision(LA_COLLISION_CHARACTER, DIRECTION_UP, LA_TAG_GROUND, DIRECTION_DOWN))
				{
					M_JumpCoolTime = 0;
					S_Flag.M_JumpFlag = false;
				}
			}
		}
	}

	if (S_Flag.M_JumpFlag)
	{M_CharacterPosition.y += M_CharacterSpeed.y;}
}
void LivblockAdventure_Character::Walk()
{
	M_CharacterSpeed.x = P_Controller->GetLStick().x;

	WallCollision();
	GroundCollision();

	if (S_Flag.M_WalkFlag)
	{M_CharacterPosition.x += M_CharacterSpeed.x;}
}
void LivblockAdventure_Character::Goal()
{
	if (P_Collision->DecisionAndDecisionCollision(LA_COLLISION_CHARACTER, LA_COLLISION_GOAL))
	{P_Livblock->Create(SECOND);}
}

void LivblockAdventure_Character::WallCollision()
{
	if (!P_Collision->EmptyAndEmptysCollision(LA_COLLISION_CHARACTER, DIRECTION_RIGHT, LA_TAG_WALL, DIRECTION_LEFT) && !P_Collision->EmptyAndEmptysCollision(LA_COLLISION_CHARACTER, DIRECTION_LEFT, LA_TAG_WALL, DIRECTION_RIGHT))
	{
		S_Flag.M_WalkFlag = true;
	}else {
		if (P_Collision->EmptyAndEmptysCollision(LA_COLLISION_CHARACTER, DIRECTION_RIGHT, LA_TAG_WALL, DIRECTION_LEFT))
		{
			if (M_CharacterSpeed.x > 0.0f)
			{
				S_Flag.M_WalkFlag = false;
			}else {
				S_Flag.M_WalkFlag = true;
			}
		}else {
			if (P_Collision->EmptyAndEmptysCollision(LA_COLLISION_CHARACTER, DIRECTION_LEFT, LA_TAG_WALL, DIRECTION_RIGHT))
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
void LivblockAdventure_Character::GroundCollision()
{
	if (S_Flag.M_FallFlag || S_Flag.M_JumpFlag)
	{
		if (P_Collision->EmptyAndEmptysCollision(LA_COLLISION_CHARACTER, DIRECTION_LEFT, LA_TAG_GROUND, DIRECTION_RIGHT))
		{
			if (M_CharacterSpeed.x < 0.0f)
			{
				S_Flag.M_WalkFlag = false;
			}else {
				S_Flag.M_WalkFlag = true;
			}
		}else {
			if (P_Collision->EmptyAndEmptysCollision(LA_COLLISION_CHARACTER, DIRECTION_RIGHT, LA_TAG_GROUND, DIRECTION_LEFT))
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