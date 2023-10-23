#include "stdafx.h"
#include "Character.h"
#include "Stage.h"
bool Character::Start()
{
	P_Stage = FindGO<Stage>("stage");
	M_CharacterTexture.ColorOutInit("Assets/Sprite/AnyModel.DDS","Assets/Sprite/AnyModelColor.DDS", "Assets/Sprite/AnyModelGreenBack.DDS",120.0f,120.0f);
	M_PositionX = P_Stage->M_StartX;
	M_PositionY = P_Stage->M_StartY;
	M_CharacterPosition = P_Stage->M_MapPosition[M_PositionX][M_PositionY];
	return true;
}
void Character::Goal()
{
	if (M_PositionX == P_Stage->M_GoalX && M_PositionY == P_Stage->M_GoalY)
	{
		GoalFlag = true;
	}
}

void Character::Update()
{
	if (g_pad[0]->IsTrigger(enButtonUp))
	{
		if (P_Stage->M_MapData[M_PositionX][M_PositionY - 1] == GROUND)
		{
			M_PositionY--;
		}
	}else {
		if (g_pad[0]->IsTrigger(enButtonDown))
		{
			if (P_Stage->M_MapData[M_PositionX][M_PositionY + 1] == GROUND)
			{
				M_PositionY++;
			}
		}else {
			if (g_pad[0]->IsTrigger(enButtonRight))
			{
				if (P_Stage->M_MapData[M_PositionX + 1][M_PositionY] == GROUND)
				{
					M_PositionX++;
				}
			}else {
				if (g_pad[0]->IsTrigger(enButtonLeft))
				{
					if (P_Stage->M_MapData[M_PositionX - 1][M_PositionY] == GROUND)
					{
						M_PositionX--;
					}
				}
			}
		}
	}
	M_CharacterPosition = P_Stage->M_MapPosition[M_PositionX][M_PositionY];
	M_CharacterTexture.SetPosition(M_CharacterPosition);
	M_CharacterTexture.Update();
	Goal();
}
void Character::Render(RenderContext& rc)
{
	M_CharacterTexture.Draw(rc);
}