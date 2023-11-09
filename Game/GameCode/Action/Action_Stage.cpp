#include "stdafx.h"
#include "Action.h"
#include "Action_Stage.h"
#include "DimensionCollision.h"
Action_Stage::Action_Stage()
{
	M_BackGroundTexture.Init("Assets/Sprite/Action/Sky.DDS", 1000.0f, 1000.0f, true);
}
bool Action_Stage::Start()	
{
	P_Collision = FindGO<DimensionCollision>("collision");

	MapSet();
	return true;
}
void Action_Stage::Render(RenderContext& rc)
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

bool Action_Stage::MapSet()
{
	M_FilePath = "Assets/Sprite/Action/StageTile.txt";
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
							case ACTION_MAP_GROUND:
								Ground(X, Y);
								break;
							case ACTION_MAP_WALL:
								Wall(X, Y);
								break;
							case ACTION_MAP_GOAL:
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

void Action_Stage::Ground(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/Action/Ground.DDS", 100.0f, 100.0f,true);
	M_StagePosition.x = -450.0f + (X * 100.0f);
	M_StagePosition.y = -450.0f + (Y * 100.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(100, 100, M_StagePosition.x, M_StagePosition.y, ACTION_COLLISION_GROUND, ACTION_TAG_GROUND);
}
void Action_Stage::Wall(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/Action/Wall.DDS", 100.0f, 100.0f,true);
	M_StagePosition.x = -450.0f + (X * 100.0f);
	M_StagePosition.y = -450.0f + (Y * 100.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(100, 100, M_StagePosition.x, M_StagePosition.y, ACTION_COLLISION_WALL, ACTION_TAG_WALL);
}
void Action_Stage::Goal(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/Action/Goal.DDS", 100.0f, 100.0f, true);
	M_StagePosition.x = -450.0f + (X * 100.0f);
	M_StagePosition.y = -450.0f + (Y * 100.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(100, 100, M_StagePosition.x, M_StagePosition.y, ACTION_COLLISION_GOAL, ACTION_TAG_GOAL);
}