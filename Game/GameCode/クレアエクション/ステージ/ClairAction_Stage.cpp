#include "stdafx.h"
#include "ClairAction_Stage.h"

#include "GameCode/クレアエクション/ギミック/ClairAction_Gimmick.h"

#include "DimensionalElement/DimensionalCollision.h"

#include "DimensionalStorage/NumberStorage.h"

ClairAction_Stage::ClairAction_Stage()
{
	M_BackGroundTexture.Init("Assets/Sprite/ClairAction/StageBackGround.DDS", 1920.0f, 1080.0f, true);
}
bool ClairAction_Stage::Start()
{
	P_Collision = FindGO<DimensionalCollision>("collision");
	P_Gimmick = FindGO<ClairAction_Gimmick>("gimmick");
	MapSet();
	return true;
}
void ClairAction_Stage::Render(RenderContext& rc)
{
	M_BackGroundTexture.Draw(rc);
	for (int X = 0; X < 16; X++)
	{
		for (int Y = 0; Y < 9; Y++)
		{
			if (M_StageTileTexture[X][Y].GetInitFlag())
			{
				M_StageTileTexture[X][Y].Draw(rc);
			}
		}
	}
}

bool ClairAction_Stage::MapSet()
{
	M_FilePath = "Assets/Sprite/ClairAction/StageTile.txt";
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
			MapType = 99;
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
					if (MapType == 99)
					{
						if (M_Value[0] != '\n')
						{
							int Count = atoi(M_Value);
							MapType = Count;
							switch (MapType)
							{
							case MAP_GROUND:
								Ground(X, Y);
								break;
							case MAP_WALL:
								Wall(X, Y);
								break;
							case GIMMICK_BOX:
								Box(X, Y);
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

void ClairAction_Stage::Ground(int X, int Y)
{
	M_StageTileTexture[X][Y].Init("Assets/Sprite/ClairAction/Ground.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTileTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTileTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, COLLISION_GROUND, TAG_GROUND);
}
void ClairAction_Stage::Wall(int X, int Y)
{
	M_StageTileTexture[X][Y].Init("Assets/Sprite/ClairAction/Ground.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTileTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTileTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, COLLISION_WALL, TAG_WALL);
}
void ClairAction_Stage::Goal(int X, int Y)
{
	M_StageTileTexture[X][Y].Init("Assets/Sprite/ClairAction/Ground.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTileTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTileTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, COLLISION_GOAL, TAG_NON);
}

void ClairAction_Stage::Box(int X, int Y)
{
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	P_Gimmick->Create(GIMMICK_BOX, X, Y, M_StagePosition);
}