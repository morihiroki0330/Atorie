#include "stdafx.h"
#include "Flick.h"
#include "Flick_Stage.h"
#include "DimensionCollision.h"
bool Flick_Stage::Start()
{
	P_Collision = FindGO<DimensionCollision>("collision");
	M_BackGroundTexture.Init("Assets/Sprite/Flick/Sky.DDS", 1920.0f, 1080.0f, true);
	MapSet();
	return true;
}
void Flick_Stage::Render(RenderContext& rc)
{
	M_BackGroundTexture.Draw(rc);
	for (int X = 0; X < 16; X++)
	{
		for (int Y = 0; Y < 9; Y++)
		{
			if (M_StageTexture[X][Y].GetInitFlag())
			{
				M_StageTexture[X][Y].Draw(rc);
			}
		}
	}
}
bool Flick_Stage::MapSet()
{
	M_FilePath = "Assets/Sprite/Flick/StageTile.txt";
	FILE* M_FilePointer = nullptr;
	fopen_s(&M_FilePointer, M_FilePath, "r");
	if (M_FilePointer == NULL)
	{
		return 0;
	}

	while (fgets(M_Value, 3, M_FilePointer) != NULL)
	{
		if (M_Value[0] == 'X')
		{
			X = 99;
			Y = 99;
			GroundType = 99;
		}else {
			if (X == 99)
			{
				if (M_Value[0] != '\n')
				{
					int Count = atoi(M_Value);
					X = Count;
				}
			}else {
				if (Y == 99)
				{
					if (M_Value[0] != '\n')
					{
						int Count = atoi(M_Value);
						Y = Count;
					}
				}else {
					if (GroundType == 99)
					{
						if (M_Value[0] != '\n')
						{
							int Count = atoi(M_Value);
							GroundType = Count;
							switch (GroundType)
							{
							case FLICK_MAP_GROUND:
								Ground(X, Y);
								break;
							case FLICK_MAP_GOAL:
								Goal(X, Y);
								break;
							case FLICK_MAP_ERRORBOX:
								ErrorBox(X, Y);
								break;
							default:
								break;
							}
						}
					}
				}
			}
		}
	}
	fclose(M_FilePointer);
	return true;
}

void Flick_Stage::Ground(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/Flick/Ground.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, FLICK_COLLISION_GROUND, FLICK_TAG_GROUND);
}
void Flick_Stage::Goal(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/Flick/Goal.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, FLICK_COLLISION_GOAL, FLICK_TAG_GOAL);
}
void Flick_Stage::ErrorBox(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/Flick/ErrorBox.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, FLICK_COLLISION_ERRORBOX, FLICK_TAG_ERRORBOX);
}
