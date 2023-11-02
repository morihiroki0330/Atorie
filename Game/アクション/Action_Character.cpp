#include "stdafx.h"
#include "Game.h"
#include "Action.h"
#include "Action_Character.h"
#include "Action_Stage.h"
#include "DimensionCollision.h"
#include "Controller.h"
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
	
	if (g_pad[0]->IsTrigger(enButtonB))
	{
		S_Flag.M_GoalFlag = true;
	}
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
	P_Action->Create(SECOND);
}
void Action_Character::Move()
{
	if (!P_Collision->EmptyAndDecisionsCollision(COLLISION_CHARACTER, DIRECTION_DOWN, TAG_GROUND))
	{
		Fall();
	}

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		Jump();
	}
	Walk();
}
void Action_Character::Walk()
{
	M_CharacterSpeed.x = P_Controller->GetLStick().x;
	if (P_Collision->EmptyAndDecisionsCollision(COLLISION_CHARACTER, DIRECTION_LEFT, TAG_WALL) || P_Collision->EmptyAndDecisionsCollision(COLLISION_CHARACTER, DIRECTION_LEFT, TAG_GROUND))
	{
		if (M_CharacterSpeed.x < 0.0f)
		{
			M_CharacterSpeed.x = 0.0f;
		}
	}
	if (P_Collision->EmptyAndDecisionsCollision(COLLISION_CHARACTER, DIRECTION_RIGHT, TAG_WALL) || P_Collision->EmptyAndDecisionsCollision(COLLISION_CHARACTER, DIRECTION_RIGHT, TAG_GROUND))
	{
		if (M_CharacterSpeed.x > 0.0f)
		{
			M_CharacterSpeed.x = 0.0f;
		}
	}
	M_CharacterPosition.x += M_CharacterSpeed.x;
}
void Action_Character::Jump()
{
	M_CharacterPosition.y += 150.0f;
}
void Action_Character::Fall()
{
	M_CharacterPosition.y -= P_Action->GetGravity();
}
void Action_Character::PositionJust(int Direction)
{
	if (!S_Flag.M_PositionJustFlag)
	{
		M_CharacterPosition.y = P_Collision->GetWidth().x;
		S_Flag.M_PositionJustFlag = true;
	}
}