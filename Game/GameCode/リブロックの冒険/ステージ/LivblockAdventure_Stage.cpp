#include "stdafx.h"
#include "GameCode/ÉäÉuÉçÉbÉNÇÃñ`åØ/LivblockAdventure.h"
#include "LivblockAdventure_Stage.h"
#include "DimensionCollision.h"
LivblockAdventure_Stage::LivblockAdventure_Stage()
{
	M_BackGroundTexture.Init("Assets/Sprite/LivblockAdventure/Sky.DDS", 1000.0f, 1000.0f, true);
}
bool LivblockAdventure_Stage::Start()	
{
	P_Collision = FindGO<DimensionCollision>("collision");

	MapSet();
	return true;
}
void LivblockAdventure_Stage::Render(RenderContext& rc)
{
	M_BackGroundTexture.Draw(rc);
	for (int X = 0; X < 10; X++)
	{
		for (int Y = 0; Y < 10; Y++)
		{
			if (M_StageTexture[X][Y].GetInitFlag())
			{M_StageTexture[X][Y].Draw(rc);}
		}
	}
}

bool LivblockAdventure_Stage::MapSet()
{
	M_FilePath = "Assets/Sprite/LivblockAdventure/StageTile.txt";
	FILE* M_FilePointer = nullptr;
	fopen_s(&M_FilePointer, M_FilePath, "r");
	if (M_FilePointer == NULL)
	{return 0;}

	while (fgets(M_Value, 2, M_FilePointer) != NULL)
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
							case LA_MAP_GROUND:
								Ground(X, Y);
								break;
							case LA_MAP_WALL:
								Wall(X, Y);
								break;
							case LA_MAP_GOAL:
								Goal(X, Y);
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

void LivblockAdventure_Stage::Ground(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/LivblockAdventure/Ground.DDS", 100.0f, 100.0f,true);
	M_StagePosition.x = -450.0f + (X * 100.0f);
	M_StagePosition.y = -450.0f + (Y * 100.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(100, 100, M_StagePosition.x, M_StagePosition.y, LA_COLLISION_GROUND, LA_TAG_GROUND);
}
void LivblockAdventure_Stage::Wall(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/LivblockAdventure/Wall.DDS", 100.0f, 100.0f,true);
	M_StagePosition.x = -450.0f + (X * 100.0f);
	M_StagePosition.y = -450.0f + (Y * 100.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(100, 100, M_StagePosition.x, M_StagePosition.y, LA_COLLISION_WALL, LA_TAG_WALL);
}
void LivblockAdventure_Stage::Goal(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/LivblockAdventure/Goal.DDS", 100.0f, 100.0f, true);
	M_StagePosition.x = -450.0f + (X * 100.0f);
	M_StagePosition.y = -450.0f + (Y * 100.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(100, 100, M_StagePosition.x, M_StagePosition.y, LA_COLLISION_GOAL, LA_TAG_GOAL);
}