#include "stdafx.h"
#include "PuzzleBoxPath.h"
#include "PuzzleBoxPath_Stage.h"
#include "DimensionCollision.h"
PuzzleBoxPath_Stage::PuzzleBoxPath_Stage()
{
	M_BackGroundTexture.Init("Assets/Sprite/PuzzleBoxPath/Sky.DDS", 1920.0f, 1080.0f, true);
}
bool PuzzleBoxPath_Stage::Start()
{
	P_Collision = FindGO<DimensionCollision>("collision");
	MapSet();
	return true;
}
void PuzzleBoxPath_Stage::Render(RenderContext& rc)
{
	M_BackGroundTexture.Draw(rc);
	for (int X = 0; X < 16; X++)
	{
		for (int Y = 0; Y < 9; Y++)
		{
			if (M_StageTexture[X][Y].GetInitFlag())
			{M_StageTexture[X][Y].Draw(rc);}
		}
	}
}

bool PuzzleBoxPath_Stage::MapSet()
{
	M_FilePath = "Assets/Sprite/PuzzleBoxPath/StageTile.txt";
	FILE* M_FilePointer = nullptr;
	fopen_s(&M_FilePointer, M_FilePath, "r");
	if (M_FilePointer == NULL)
	{return 0;}

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
							case PBP_MAP_GROUND:
								Ground(X, Y);
								break;
							case PBP_MAP_GOAL:
								Goal(X, Y);
								break;
							case PBP_MAP_ERRORBOX:
								ErrorBox(X, Y);
								break;
							case PBP_MAP_DRAWERRORBOX:
								DrawErrorBox(X, Y);
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
void PuzzleBoxPath_Stage::Ground(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/PuzzleBoxPath/Ground.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, PBP_COLLISION_GROUND, PBP_TAG_GROUND);
}
void PuzzleBoxPath_Stage::Goal(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/PuzzleBoxPath/Goal.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, PBP_COLLISION_GOAL, PBP_TAG_GOAL);
}
void PuzzleBoxPath_Stage::ErrorBox(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/PuzzleBoxPath/ErrorBox.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, PBP_COLLISION_ERRORBOX, PBP_TAG_ERRORBOX);
}
void PuzzleBoxPath_Stage::DrawErrorBox(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/PuzzleBoxPath/DrawErrorBox.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, PBP_COLLISION_DRAWERRORBOX, PBP_TAG_DRAWERRORBOX);
}
