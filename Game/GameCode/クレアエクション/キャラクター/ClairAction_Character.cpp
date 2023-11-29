#include "stdafx.h"
#include "Game.h"
#include "GameCode/クレアエクション/ClairAction.h"

#include "ClairAction_Character.h"

#include "DimensionalElement/DimensionalAnimation.h"
#include "DimensionalElement/DimensionalCollision.h"
#include "DimensionalElement/DimensionalCamera.h"
#include "Mouse・Controller/Controller.h"

ClairAction_Character::ClairAction_Character()
{
	//P_Animation = NewGO<DimensionalAnimation>(0, "Animation");

	M_CharacterTexture.Init("Assets/Sprite/ClairAction/Character1.DDS", 256.0f, 256.0f, true);
}
bool ClairAction_Character::Start()
{
	P_Clair = FindGO<ClairAction>("clair");
	P_Collision = FindGO<DimensionalCollision>("collision");
	P_Controller = FindGO<Controller>("controller");
	P_Camera = FindGO<DimensionalCamera>("camera");
	P_Collision->DecisionDataSet(256.0f, 256.0f, M_CharacterPosition.x, M_CharacterPosition.y, CA_COLLISION_CHARACTER, CA_TAG_NON);
	return true;
}
void ClairAction_Character::Update()
{
	Move();
	TextureSet();
	P_Collision->DecisionSetPosition(M_CharacterPosition.x, M_CharacterPosition.y, CA_COLLISION_CHARACTER);
	M_CharacterTexture.SetPosition(M_CharacterPosition);
	M_CharacterTexture.Update();
}
void ClairAction_Character::Render(RenderContext& rc)
{
	M_CharacterTexture.Draw(rc);
}

void ClairAction_Character::Move()
{
	Fall();
	Jump();
	Walk();
	//Goal();
}
void ClairAction_Character::Fall()
{
	if (!P_Collision->EmptyAndEmptysCollision(CA_COLLISION_CHARACTER, DIRECTION_DOWN, CA_TAG_GROUND, DIRECTION_UP) && !P_Collision->EmptyAndEmptysCollision(CA_COLLISION_CHARACTER, DIRECTION_DOWN, CA_TAG_BOX, DIRECTION_UP) && !S_Flag.M_JumpFlag)
	{
		S_Flag.M_FallFlag = true;
	}else {
		if (P_Collision->EmptyAndEmptysCollision(CA_COLLISION_CHARACTER, DIRECTION_DOWN, CA_TAG_GROUND, DIRECTION_UP)|| P_Collision->EmptyAndEmptysCollision(CA_COLLISION_CHARACTER, DIRECTION_DOWN, CA_TAG_BOX, DIRECTION_UP))
		{
			S_Flag.M_FallFlag = false;
			S_Flag.M_JumpFlag = false;
		}
	}

	if (S_Flag.M_FallFlag)
	{M_CharacterPosition.y -= P_Clair->GetGravity();}
}
void ClairAction_Character::Jump()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000 && !S_Flag.M_FallFlag && !S_Flag.M_JumpFlag)
	{
		S_Flag.M_JumpFlag = true;
	}else {
		if (S_Flag.M_JumpFlag)
		{
			M_JumpCoolTime++;
			if (M_JumpCoolTime > 30)
			{
				M_JumpCoolTime = 0;
				S_Flag.M_JumpFlag = false;
			}
		}
	}

	if (S_Flag.M_JumpFlag)
	{M_CharacterPosition.y += M_CharacterSpeed.y;}
}
void ClairAction_Character::Walk()
{
	M_CharacterSpeed.x = P_Controller->GetLStick().x;
	Rotation();

	BoxCollision();
	

	if (S_Flag.M_WalkFlag)
	{
		if (S_Flag.M_JumpFlag || S_Flag.M_FallFlag)
		{
			M_CharacterPosition.x += M_CharacterSpeed.x / 2.0f;
		}else {
			if (!S_Flag.M_JumpFlag)
			{
				M_CharacterPosition.x += M_CharacterSpeed.x;
			}
		}
	}
}
void ClairAction_Character::Rotation()
{
	if (M_CharacterSpeed.x > 0.0f)
	{
		S_Flag.M_RightFlag = true;
		S_Flag.M_LeftFlag = false;
	}else {
	if (M_CharacterSpeed.x < 0.0f)
	{
		S_Flag.M_RightFlag = false;
		S_Flag.M_LeftFlag = true;
	}
	}
}
void ClairAction_Character::Goal()
{
	
}

void ClairAction_Character::BoxCollision()
{
	if (P_Collision->EmptyAndEmptysCollision(CA_COLLISION_CHARACTER, DIRECTION_LEFT, CA_TAG_BOX, DIRECTION_RIGHT))
	{
		if (M_CharacterSpeed.x < 0.0f)
		{
			S_Flag.M_WalkFlag = false;
		}else {
			S_Flag.M_WalkFlag = true;
		}
	}else {
		if (P_Collision->EmptyAndEmptysCollision(CA_COLLISION_CHARACTER, DIRECTION_RIGHT, CA_TAG_BOX, DIRECTION_LEFT))
		{
			if (M_CharacterSpeed.x > 0.0f)
			{
				S_Flag.M_WalkFlag = false;
			}else {
				S_Flag.M_WalkFlag = true;
			}
		}else {
			S_Flag.M_WalkFlag = true;
		}
	}
}

void ClairAction_Character::TextureSet()
{
	if (S_Flag.M_RightFlag)
	{
		M_CharacterTexture.TextureSet("Assets/Sprite/ClairAction/Character1.DDS");
	}else {
	if (S_Flag.M_LeftFlag)
	{
		M_CharacterTexture.TextureSet("Assets/Sprite/ClairAction/Character4.DDS");
	}
	}
}
