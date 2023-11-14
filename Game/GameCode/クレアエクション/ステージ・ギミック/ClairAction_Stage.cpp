#include "stdafx.h"
#include "GameCode/クレアエクション/ClairAction.h"
#include "ClairAction_Stage.h"
#include "DimensionCollision.h"
ClairAction_Stage::ClairAction_Stage()
{
	M_BackGroundTexture.Init("Assets/Sprite/ClairAction/StageBackGround.DDS", 1920.0f, 1080.0f, true);
}
bool ClairAction_Stage::Start()
{
	P_Collision = FindGO<DimensionCollision>("collision");
	//MapSet();
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
	M_FilePath = "Assets/Sprite/PuzzleBoxPath/StageTile.txt";
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
		}
		else {
			if (X == 99)
			{
				if (M_Value[0] != '\n')
				{
					int Count = atoi(M_Value);
					X = Count;
				}
			}
			else {
				if (Y == 99)
				{
					if (M_Value[0] != '\n')
					{
						int Count = atoi(M_Value);
						Y = Count;
					}
				}
				else {
					if (MapType == 99)
					{
						if (M_Value[0] != '\n')
						{
							int Count = atoi(M_Value);
							MapType = Count;
							switch (MapType)
							{
							case CA_MAP_GROUND:
								//Ground(X, Y);
								break;
							case CA_MAP_WALL:
								//Goal(X, Y);
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