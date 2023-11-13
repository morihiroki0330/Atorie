#include "stdafx.h"
#include "Game.h"
#include "GazeJourney.h"
#include "GazeJourney_Character.h"
#include "DimensionCollision.h"
#include "TwoDimensionalCamera.h"
#include "MouseÅEController/Controller.h"
GazeJourney_Character::GazeJourney_Character()
{
	M_CharacterTexture.Init("Assets/Sprite/GazeJourney/Character.DDS", 150.0f, 150.0f, true);
}
bool GazeJourney_Character::Start()
{
	P_Gaze = FindGO<GazeJourney>("gaze");
	P_Collision = FindGO<DimensionCollision>("collision");
	P_Controller = FindGO<Controller>("controller");
	P_Camera = FindGO<TwoDimensionalCamera>("camera");
	P_Collision->DecisionDataSet(150.0f, 150.0f, M_CharacterPosition.x, M_CharacterPosition.y, GJ_COLLISION_CHARACTER, GJ_TAG_NON);
	P_Camera->SetObjectData(M_CharacterPosition);
	return true;
}
void GazeJourney_Character::Update()
{
	Move();
	P_Collision->DecisionSetPosition(M_CharacterPosition.x, M_CharacterPosition.y, GJ_COLLISION_CHARACTER);
	P_Camera->CenterObjectMove(M_CharacterPosition);
	if (S_Flag.M_FallFlag)
	{M_CharacterTexture.SetPosition(M_CharacterPosition);}
	/*M_CharacterTexture.SetPosition(M_CharacterPosition);*/
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
	Goal();
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
void GazeJourney_Character::Goal()
{
	if (P_Collision->DecisionAndDecisionCollision(GJ_COLLISION_CHARACTER, GJ_COLLISION_GOAL))
	{P_Gaze->Create(SECOND);}
}