#include "stdafx.h"
#include "Game.h"
#include "GameCode/ダンジョンオデッセイ/DungeonOdyssey.h"
#include "DungeonOdyssey_Character.h"
#include "GameCode/ダンジョンオデッセイ/ステージ/DungeonOdyssey_Stage.h"
DungeonOdyssey_Character::DungeonOdyssey_Character()
{
	M_CharacterTexture.Init("Assets/Sprite/DungeonOdyssey/AnyModel.DDS", 120.0f, 120.0f, true);
}
bool DungeonOdyssey_Character::Start()
{
	P_Stage   = FindGO<DungeonOdyssey_Stage>("stage");
	P_Dungeon = FindGO<DungeonOdyssey>("dungeon");

	M_PositionX         = P_Stage->GetNumber(DO_NUMBER_StartX);
	M_PositionY         = P_Stage->GetNumber(DO_NUMBER_StartY);
	M_CharacterPosition = P_Stage->GetMapPosition(M_PositionX,M_PositionY);
	return true;
}
void DungeonOdyssey_Character::Update()
{
	Move();
	M_CharacterTexture.SetPosition(M_CharacterPosition);
	M_CharacterTexture.Update();
	Goal();
}
void DungeonOdyssey_Character::Render(RenderContext& rc)
{
	M_CharacterTexture.Draw(rc);
}

void DungeonOdyssey_Character::Move()
{
	if (g_pad[0]->IsTrigger(enButtonUp))
	{
		if (P_Stage->GetMapData(M_PositionX,M_PositionY,DO_NUMBER_MapDataUp) == DO_GROUND)
		{M_PositionY--;}
	}else {
		if (g_pad[0]->IsTrigger(enButtonDown))
		{
			if (P_Stage->GetMapData(M_PositionX,M_PositionY,DO_NUMBER_MapDataDown) == DO_GROUND)
			{M_PositionY++;}
		}else {
			if (g_pad[0]->IsTrigger(enButtonRight))
			{
				if (P_Stage->GetMapData(M_PositionX,M_PositionY,DO_NUMBER_MapDataRight) == DO_GROUND)
				{M_PositionX++;}
			}else {
				if (g_pad[0]->IsTrigger(enButtonLeft))
				{
					if (P_Stage->GetMapData(M_PositionX, M_PositionY, DO_NUMBER_MapDataLeft) == DO_GROUND)
					{M_PositionX--;}
				}
			}
		}
	}
	M_CharacterPosition = P_Stage->GetMapPosition(M_PositionX,M_PositionY);
}
void DungeonOdyssey_Character::Goal()
{
	if (M_PositionX == P_Stage->GetNumber(DO_NUMBER_GoalX) && M_PositionY == P_Stage->GetNumber(DO_NUMBER_GoalY))
	{P_Dungeon->Create(SECOND);}
}