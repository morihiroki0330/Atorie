#include "stdafx.h"
#include "Game.h"
#include "Dungeon.h"
#include "Dungeon_Character.h"
#include "Dungeon_Stage.h"
Dungeon_Character::Dungeon_Character()
{
	M_CharacterTexture.Init("Assets/Sprite/Dungeon/AnyModel.DDS", 120.0f, 120.0f, true);
}
bool Dungeon_Character::Start()
{
	P_Stage   = FindGO<Dungeon_Stage>("dungeon_stage");
	P_Dungeon = FindGO<Dungeon>("dungeon");

	M_PositionX         = P_Stage->GetNumber(DUNGEON_NUMBER_StartX);
	M_PositionY         = P_Stage->GetNumber(DUNGEON_NUMBER_StartY);
	M_CharacterPosition = P_Stage->GetMapPosition(M_PositionX,M_PositionY);
	return true;
}
void Dungeon_Character::Update()
{
	Move();
	M_CharacterTexture.SetPosition(M_CharacterPosition);
	M_CharacterTexture.Update();
	Goal();
}
void Dungeon_Character::Render(RenderContext& rc)
{
	M_CharacterTexture.Draw(rc);
}

void Dungeon_Character::Move()
{
	if (g_pad[0]->IsTrigger(enButtonUp))
	{
		if (P_Stage->GetMapData(M_PositionX,M_PositionY,DUNGEON_NUMBER_MapDataUp) == DUNGEON_GROUND)
		{M_PositionY--;}
	}else {
		if (g_pad[0]->IsTrigger(enButtonDown))
		{
			if (P_Stage->GetMapData(M_PositionX,M_PositionY,DUNGEON_NUMBER_MapDataDown) == DUNGEON_GROUND)
			{M_PositionY++;}
		}else {
			if (g_pad[0]->IsTrigger(enButtonRight))
			{
				if (P_Stage->GetMapData(M_PositionX,M_PositionY,DUNGEON_NUMBER_MapDataRight) == DUNGEON_GROUND)
				{M_PositionX++;}
			}else {
				if (g_pad[0]->IsTrigger(enButtonLeft))
				{
					if (P_Stage->GetMapData(M_PositionX, M_PositionY, DUNGEON_NUMBER_MapDataLeft) == DUNGEON_GROUND)
					{M_PositionX--;}
				}
			}
		}
	}
	M_CharacterPosition = P_Stage->GetMapPosition(M_PositionX,M_PositionY);
}
void Dungeon_Character::Goal()
{
	if (M_PositionX == P_Stage->GetNumber(DUNGEON_NUMBER_GoalX) && M_PositionY == P_Stage->GetNumber(DUNGEON_NUMBER_GoalY))
	{P_Dungeon->Create(SECOND);}
}