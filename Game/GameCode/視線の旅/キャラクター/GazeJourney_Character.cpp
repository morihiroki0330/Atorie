#include "stdafx.h"
#include "Game.h"
#include "GazeJourney_Character.h"

#include "GameCode/�����̗�/GazeJourney.h"

#include "Tool/DimensionalCollision.h"
#include "Tool/DimensionalCamera.h"
#include "Mouse�EController/Controller.h"

GazeJourney_Character::GazeJourney_Character()
{
	M_CharacterTexture.Init("Assets/Sprite/GazeJourney/Character.DDS", 150.0f, 150.0f, true);
}
bool GazeJourney_Character::Start()
{
	P_Gaze = FindGO<GazeJourney>("gaze");
	P_Collision = FindGO<DimensionalCollision>("collision");
	P_Controller = FindGO<Controller>("controller");
	P_Camera = FindGO<DimensionalCamera>("camera");
	P_Collision->DecisionDataSet(150.0f, 150.0f, M_CharacterPosition.x, M_CharacterPosition.y, GJ_COLLISION_CHARACTER, GJ_TAG_NON);
	P_Camera->SetObjectData(M_CharacterPosition);
	return true;
}
void GazeJourney_Character::Update()
{
	Move();
	P_Collision->DecisionSetPosition(0.0f, M_CharacterPosition.y, GJ_COLLISION_CHARACTER);
	P_Camera->CenterObjectMoveX(M_CharacterPosition);
	M_CharacterTexture.SetPositionY(M_CharacterPosition);
	M_CharacterTexture.Update();
}
void GazeJourney_Character::Render(RenderContext& rc)
{
	M_CharacterTexture.Draw(rc);
}

void GazeJourney_Character::Move()
{
	Fall();
	Walk();
}
void GazeJourney_Character::Walk()
{
	M_CharacterSpeed.x = P_Controller->GetLStick().x;

	if (P_Collision->EmptyAndEmptyCollision(GJ_COLLISION_CHARACTER, DIRECTION_DOWN, GJ_COLLISION_GROUND, DIRECTION_UP))
	{S_Flag.M_WalkFlag = true;}

	if (S_Flag.M_WalkFlag)
	{M_CharacterPosition.x += M_CharacterSpeed.x;}
}
void GazeJourney_Character::Fall()
{
	if (!P_Collision->EmptyAndEmptysCollision(GJ_COLLISION_CHARACTER, DIRECTION_DOWN, GJ_TAG_GROUND, DIRECTION_UP) && !S_Flag.M_JumpFlag)
	{
		S_Flag.M_FallFlag = true;
	}else {
		if (P_Collision->EmptyAndEmptysCollision(GJ_COLLISION_CHARACTER, DIRECTION_DOWN, GJ_TAG_GROUND, DIRECTION_UP))
		{
			S_Flag.M_FallFlag = false;
			S_Flag.M_JumpFlag = false;
		}
	}

	if (S_Flag.M_FallFlag)
	{M_CharacterPosition.y -= P_Gaze->GetGravity();}
}