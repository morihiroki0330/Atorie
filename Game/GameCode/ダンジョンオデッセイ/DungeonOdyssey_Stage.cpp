#include "stdafx.h"
#include "DungeonOdyssey.h"
#include "DungeonOdyssey_Stage.h"
DungeonOdyssey_Stage::DungeonOdyssey_Stage()
{
	M_Square.x = 16;
	M_Square.y = 9;

	M_Width.x = 1920.0f;
	M_Width.y = 1080.0f;

	M_SquareWidth.x = M_Width.x / M_Square.x;
	M_SquareWidth.y = M_Width.y / M_Square.y;

	M_StageUpperLeft.x = 0;
	M_StageUpperLeft.y = 0;

	M_StageLowerRight.x = M_Square.x - 1;
	M_StageLowerRight.y = M_Square.y - 1;

	M_Start.x = 1;
	M_Start.y = 1;

	M_Goal.x = M_Square.x - 2;
	M_Goal.y = M_Square.y - 2;
}
bool DungeonOdyssey_Stage::Start()
{
	for (int X = 0; X < M_Square.x; X++)
	{
		for (int Y = 0; Y < M_Square.y; Y++)
		{
			M_MapPosition[X][Y].x = ((-M_Width.x / 2) + (M_SquareWidth.x / 2)) + (M_SquareWidth.x * X);
			M_MapPosition[X][Y].y = (((M_Width.y / 2) - (M_SquareWidth.y / 2)) + (-M_SquareWidth.y * Y));
		}
	}
	FirstMapDataSet();
	return true;
}
void DungeonOdyssey_Stage::Update()
{
	for (int X = 0; X < M_Square.x; X++)
	{
		for (int Y = 0; Y < M_Square.y; Y++)
		{
			M_MapTexture[X][Y].Update();
			M_MapTexture[X][Y].SetPosition(M_MapPosition[X][Y]);
		}
	}
}
void DungeonOdyssey_Stage::Render(RenderContext& rc)
{
	for (int X = 0; X < M_Square.x; X++)
	{
		for (int Y = 0; Y < M_Square.y; Y++)
		{
			M_MapTexture[X][Y].Draw(rc);
		}
	}
}

bool DungeonOdyssey_Stage::WallCheck(int X, int Y, int Direction)
{
	switch (Direction)
	{
	case DUNGEON_DIRECTION_UP:
		if (M_MapData[X][Y - 1] == DUNGEON_WALLFORMAL || M_MapData[X][Y - 1] == DUNGEON_WALLFIXED)
		{
			return true;
		}else {
			return false;
		}
		break;
	case DUNGEON_DIRECTION_RIGHT:
		if (M_MapData[X + 1][Y] == DUNGEON_WALLFORMAL || M_MapData[X + 1][Y] == DUNGEON_WALLFIXED)
		{
			return true;
		}else {
			return false;
		}
		break;
	case DUNGEON_DIRECTION_DOWN:
		if (M_MapData[X][Y + 1] == DUNGEON_WALLFORMAL || M_MapData[X][Y + 1] == DUNGEON_WALLFIXED)
		{
			return true;
		}else {
			return false;
		}
		break;
	case DUNGEON_DIRECTION_LEFT:
		if (M_MapData[X - 1][Y] == DUNGEON_WALLFORMAL || M_MapData[X - 1][Y] == DUNGEON_WALLFIXED)
		{
			return true;
		}else {
			return false;
		}
		break;
	}
}
bool DungeonOdyssey_Stage::GroundCheck(int X, int Y, int Direction)
{
	switch (Direction)
	{
	case DUNGEON_DIRECTION_UP:
		if (M_MapData[X][Y - 1] == DUNGEON_GROUNDFORMAL)
		{
			return true;
		}else {
			return false;
		}
		break;
	case DUNGEON_DIRECTION_RIGHT:
		if (M_MapData[X + 1][Y] == DUNGEON_GROUNDFORMAL)
		{
			return true;
		}else {
			return false;
		}
		break;
	case DUNGEON_DIRECTION_DOWN:
		if (M_MapData[X][Y + 1] == DUNGEON_GROUNDFORMAL)
		{
			return true;
		}else {
			return false;
		}
		break;
	case DUNGEON_DIRECTION_LEFT:
		if (M_MapData[X - 1][Y] == DUNGEON_GROUNDFORMAL)
		{
			return true;
		}else {
			return false;
		}
		break;
	}
}

void DungeonOdyssey_Stage::FirstMapDataSet()
{
	for (int X = 0; X < M_Square.x; X++)
	{
		for (int Y = 0; Y < M_Square.y; Y++)
		{
			if ((X > M_StageUpperLeft.x && X < M_StageLowerRight.x) && (Y > M_StageUpperLeft.y && Y < M_StageLowerRight.y))
			{
				if (X % 2 == 0 && Y % 2 == 0)
				{
					M_MapData[X][Y] = DUNGEON_WALL;
				}else {
					M_MapData[X][Y] = DUNGEON_GROUND;
				}
			}else {
				M_MapData[X][Y] = DUNGEON_WALLFIXED;
			}
		}
	}
	M_MapData[M_Goal.x][M_Goal.y] = DUNGEON_GROUNDFORMAL;
	SecondMapDataSet();
}
void DungeonOdyssey_Stage::SecondMapDataSet()
{
	srand((unsigned int)time(NULL));

	for (int X = 1; X < M_Square.x - 1; X++)
	{
		for (int Y = 1; Y < M_Square.y - 1; Y++)
		{
			if (M_MapData[X][Y] == DUNGEON_WALL)
			{
				M_RandCheck = false;
				do
				{
					M_RandDirection = rand() % 4;
					switch (M_RandDirection)
					{
					case DUNGEON_DIRECTION_UP:
						if (!WallCheck(X, Y, M_RandDirection))
						{
							if (!GroundCheck(X, Y, M_RandDirection))
							{M_MapData[X][Y - 1] = DUNGEON_WALLFORMAL;}
							M_RandCheck = true;
						}
						break;
					case DUNGEON_DIRECTION_RIGHT:
						if (!WallCheck(X, Y, M_RandDirection))
						{
							if (!GroundCheck(X, Y, M_RandDirection))
							{M_MapData[X + 1][Y] = DUNGEON_WALLFORMAL;}
							M_RandCheck = true;
						}
						break;
					case DUNGEON_DIRECTION_DOWN:
						if (!WallCheck(X, Y, M_RandDirection))
						{
							if (!GroundCheck(X, Y, M_RandDirection))
							{M_MapData[X][Y + 1] = DUNGEON_WALLFORMAL;}
							M_RandCheck = true;
						}
						break;
					case DUNGEON_DIRECTION_LEFT:
						if (!WallCheck(X, Y, M_RandDirection))
						{
							if (!GroundCheck(X, Y, M_RandDirection))
							{M_MapData[X - 1][Y] = DUNGEON_WALLFORMAL;}
							M_RandCheck = true;
						}
						break;
					}
				} while (!M_RandCheck);
			}
		}
	}

	ThirdMapDataSet();
}
void DungeonOdyssey_Stage::ThirdMapDataSet()
{
	for (int X = 0; X < M_Square.x; X++)
	{
		for (int Y = 0; Y < M_Square.y; Y++)
		{
			if (M_MapData[X][Y] == DUNGEON_WALLFIXED || M_MapData[X][Y] == DUNGEON_WALL || M_MapData[X][Y] == DUNGEON_WALLFORMAL)
			{
				M_MapTexture[X][Y].Init("Assets/Sprite/DungeonOdyssey/Wall.DDS", M_SquareWidth.x, M_SquareWidth.y);
			}else {
				if (M_MapData[X][Y] == DUNGEON_GROUND)
				{
					M_MapTexture[X][Y].Init("Assets/Sprite/DungeonOdyssey/Ground.DDS", M_SquareWidth.x, M_SquareWidth.y);
				}else {
					if (M_MapData[X][Y] == DUNGEON_GROUNDFORMAL)
					{
						M_MapTexture[X][Y].Init("Assets/Sprite/DungeonOdyssey/Goal.DDS", M_SquareWidth.x, M_SquareWidth.y);
					}
				}
			}
		}
	}
	ForthMapDataSet();
}
void DungeonOdyssey_Stage::ForthMapDataSet()
{
	for (int X = 0; X < M_Square.x; X++)
	{
		for (int Y = 0; Y < M_Square.y; Y++)
		{
			if (M_MapData[X][Y] == DUNGEON_WALLFORMAL)
			{M_MapData[X][Y] = DUNGEON_WALL;}

			if (M_MapData[X][Y] == DUNGEON_GROUNDFORMAL)
			{M_MapData[X][Y] = DUNGEON_GROUND;}
		}
	}
}

int DungeonOdyssey_Stage::GetNumber(int Number)
{
	switch (Number)
	{
	case DUNGEON_NUMBER_SquareX:
		return M_Square.x;
		break;
	case DUNGEON_NUMBER_SquareY:
		return M_Square.y;
		break;
	case DUNGEON_NUMBER_StageUpperLeftX:
		return M_StageUpperLeft.x;
		break;
	case DUNGEON_NUMBER_StageUpperLeftY:
		return M_StageUpperLeft.y;
		break;
	case DUNGEON_NUMBER_StageLowerRightX:
		return M_StageLowerRight.x;
		break;
	case DUNGEON_NUMBER_StageLowerRightY:
		return M_StageLowerRight.y;
		break;
	case DUNGEON_NUMBER_StartX:
		return M_Start.x;
		break;
	case DUNGEON_NUMBER_StartY:
		return M_Start.y;
		break;
	case DUNGEON_NUMBER_GoalX:
		return M_Goal.x;
		break;
	case DUNGEON_NUMBER_GoalY:
		return M_Goal.y;
		break;
	}
}
int DungeonOdyssey_Stage::GetMapData(int X, int Y, int Number)
{
	switch (Number)
	{
	case DUNGEON_NUMBER_MapDataUp:
		return M_MapData[X][Y - 1];
		break;
	case DUNGEON_NUMBER_MapDataRight:
		return M_MapData[X + 1][Y];
		break;
	case DUNGEON_NUMBER_MapDataDown:
		return M_MapData[X][Y + 1];
		break;
	case DUNGEON_NUMBER_MapDataLeft:
		return M_MapData[X - 1][Y];
		break;
	}
}
