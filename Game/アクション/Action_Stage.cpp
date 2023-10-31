#include "stdafx.h"
#include "Action_Stage.h"
bool Action_Stage::Start()
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
							case GROUND:
								Ground(X, Y);
								break;
							case WALL:
								Wall(X, Y);
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

void Action_Stage::Update()
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_StageTexture[Y][X].SetPosition(M_StagePosition[Y][X]);
			M_StageTexture[Y][X].Update();
		}
	}
}

void Action_Stage::Render(RenderContext& rc)
{
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			M_StageTexture[Y][X].Draw(rc);
		}
	}
}

void Action_Stage::Ground(int X, int Y)
{

}

void Action_Stage::Wall(int X, int Y)
{

}