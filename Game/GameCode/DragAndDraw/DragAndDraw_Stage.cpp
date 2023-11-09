#include "stdafx.h"
#include "DragAndDraw.h"
#include "DragAndDraw_Stage.h"
#include "DimensionCollision.h"
bool DragAndDraw_Stage::Start()
{
	P_Collision = FindGO<DimensionCollision>("collision");
	M_BackGroundTexture.Init("Assets/Sprite/DragAndDraw/Sky.DDS", 1920.0f, 1080.0f, true);
	MapSet();
	return true;
}
void DragAndDraw_Stage::Render(RenderContext& rc)
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
bool DragAndDraw_Stage::MapSet()
{
	M_FilePath = "Assets/Sprite/DragAndDraw/StageTile.txt";
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
							case DAD_MAP_GROUND:
								Ground(X, Y);
								break;
							case DAD_MAP_GOAL:
								Goal(X, Y);
								break;
							case DAD_MAP_ERRORBOX:
								ErrorBox(X, Y);
								break;
							case DAD_MAP_DRAWERRORBOX:
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

void DragAndDraw_Stage::Ground(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/DragAndDraw/Ground.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, DAD_COLLISION_GROUND, DAD_TAG_GROUND);
}
void DragAndDraw_Stage::Goal(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/DragAndDraw/Goal.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, DAD_COLLISION_GOAL, DAD_TAG_GOAL);
}
void DragAndDraw_Stage::ErrorBox(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/DragAndDraw/ErrorBox.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, DAD_COLLISION_ERRORBOX, DAD_TAG_ERRORBOX);
}
void DragAndDraw_Stage::DrawErrorBox(int X, int Y)
{
	M_StageTexture[X][Y].Init("Assets/Sprite/DragAndDraw/DrawErrorBox.DDS", 120.0f, 120.0f, true);
	M_StagePosition.x = -900.0f + (X * 120.0f);
	M_StagePosition.y = -480.0f + (Y * 120.0f);
	M_StageTexture[X][Y].SetPosition(M_StagePosition);
	M_StageTexture[X][Y].Update();
	P_Collision->DecisionDataSet(120, 120, M_StagePosition.x, M_StagePosition.y, DAD_COLLISION_DRAWERRORBOX, DAD_TAG_DRAWERRORBOX);
}
