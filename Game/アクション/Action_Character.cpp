#include "stdafx.h"
#include "Game.h"
#include "Action.h"
#include "Action_Character.h"
#include "Action_Stage.h"
#include "DimensionCollision.h"
bool Action_Character::Start()
{
	P_Action = FindGO<Action>("action");
	P_Stage = FindGO<Action_Stage>("action_stage");
	P_Collision = FindGO<DimensionCollision>("collision");

	M_CharacterTexture.Init("Assets/Sprite/Action/Riblock.DDS", 90.0f, 90.0f, true);

	P_Collision->DecisionDataSet(90, 90, M_CharacterPosition.x, M_CharacterPosition.y, COLLISION_CHARACTER, TAG_NON);
	P_Collision->DecisionLeg(COLLISION_CHARACTER, COLLISION_CHARACTERLEG, TAG_NON);
	return true;
}
void Action_Character::Goal()
{
	P_Action->Create(SECOND);
}

void Action_Character::Update()
{
	if (!P_Collision->GroundCollision(COLLISION_CHARACTERLEG,TAG_GROUND))
	{
		M_CharacterPosition.y -= 5.0f;
	}
	P_Collision->DecisionSetPosition(M_CharacterPosition.x, M_CharacterPosition.y, COLLISION_CHARACTER);
	P_Collision->DecisionLegSetPosition(M_CharacterPosition.x, M_CharacterPosition.y, COLLISION_CHARACTER, COLLISION_CHARACTERLEG);

	M_CharacterTexture.SetPosition(M_CharacterPosition);
	M_CharacterTexture.Update();
}
void Action_Character::Move()
{

}
void Action_Character::Render(RenderContext& rc)
{
	M_CharacterTexture.Draw(rc);
}