#include "stdafx.h"
#include "Stage.h"
bool Stage::Start()
{
	
	for (int X = 0 ; X < M_SquareX ; X++)
	{
		for (int Y = 0 ; Y < M_SquareY ; Y++)
		{
			M_MapPosition[X][Y].x = ((-M_Wide / 2) + (M_SquareWide / 2)) + (M_SquareWide * X);
			M_MapPosition[X][Y].y = (((M_Height / 2) - (M_SquareHeight / 2)) + (-M_SquareHeight * Y));
		}
	}
	FirstMapDataSet();
	return true;
}
bool Stage::WallCheck(int X,int Y,int Direction)
{
	switch (Direction)
	{
	case UP:
		if (M_MapData[X][Y - 1] == WALLFORMAL || M_MapData[X][Y - 1] == WALLFIXED)
		{
			return true;
		}else {
			return false;
		}
		break;
	case RIGHT:
		if (M_MapData[X + 1][Y] == WALLFORMAL || M_MapData[X + 1][Y] == WALLFIXED)
		{
			return true;
		}else {
			return false;
		}
		break;
	case DOWN:
		if (M_MapData[X][Y + 1] == WALLFORMAL || M_MapData[X][Y + 1] == WALLFIXED)
		{
			return true;
		}else {
			return false;
		}
		break;
	case LEFT:
		if (M_MapData[X - 1][Y] == WALLFORMAL || M_MapData[X - 1][Y] == WALLFIXED)
		{
			return true;
		}else {
			return false;
		}
		break;
	}
}
bool Stage::GroundCheck(int X, int Y, int Direction)
{
	switch (Direction)
	{
	case UP:
		if (M_MapData[X][Y - 1] == GROUNDFORMAL)
		{
			return true;
		}else {
			return false;
		}
		break;
	case RIGHT:
		if (M_MapData[X + 1][Y] == GROUNDFORMAL)
		{
			return true;
		}else {
			return false;
		}
		break;
	case DOWN:
		if (M_MapData[X][Y + 1] == GROUNDFORMAL)
		{
			return true;
		}else {
			return false;
		}
		break;
	case LEFT:
		if (M_MapData[X - 1][Y] == GROUNDFORMAL)
		{
			return true;
		}else {
			return false;
		}
		break;
	}
}

void Stage::FirstMapDataSet()
{
	for (int X = 0 ; X < M_SquareX ; X++)
	{
		for (int Y = 0 ; Y < M_SquareY ; Y++)
		{
			if ((X > M_StageX && X < M_Stage_X) && (Y > M_StageY && Y < M_Stage_Y))
			{
				if (X % 2 == 0 && Y % 2 == 0)
				{
					M_MapData[X][Y] = WALL;
				}else {
					M_MapData[X][Y] = GROUND;
				}
			}else {
				M_MapData[X][Y] = WALLFIXED;
			}
		}
	}
	M_MapData[M_GoalX][M_GoalY] = GROUNDFORMAL;
	SecondMapDataSet();
}
void Stage::SecondMapDataSet()
{
	srand((unsigned int)time(NULL));
	
	for (int X = 1; X < M_SquareX - 1; X++)
	{
		for (int Y = 1; Y < M_SquareY - 1; Y++)
		{
			if (M_MapData[X][Y] == WALL)
			{
				M_RandCheck = false;
				do 
				{
					M_RandDirection = rand() % 4;
					switch (M_RandDirection)
					{
					case UP:
						if (!WallCheck(X, Y, M_RandDirection))
						{
							if (!GroundCheck(X, Y, M_RandDirection))
							{
								M_MapData[X][Y - 1] = WALLFORMAL;
							}
							M_RandCheck = true;
						}
						break;
					case RIGHT:
						if (!WallCheck(X, Y, M_RandDirection))
						{
							if (!GroundCheck(X, Y, M_RandDirection))
							{
								M_MapData[X + 1][Y] = WALLFORMAL;
							}
							M_RandCheck = true;
						}
						break;
					case DOWN: 
						if (!WallCheck(X, Y, M_RandDirection))
						{
							if (!GroundCheck(X, Y, M_RandDirection))
							{
								M_MapData[X][Y + 1] = WALLFORMAL;
							}
							M_RandCheck = true;
						}
						break;
					case LEFT:
						if (!WallCheck(X, Y, M_RandDirection))
						{
							if (!GroundCheck(X, Y, M_RandDirection))
							{
								M_MapData[X - 1][Y] = WALLFORMAL;
							}
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
void Stage::ThirdMapDataSet()
{
	for (int X = 0; X < M_SquareX; X++)
	{
		for (int Y = 0; Y < M_SquareY; Y++)
		{
			if (M_MapData[X][Y] == WALLFIXED || M_MapData[X][Y] == WALL || M_MapData[X][Y] == WALLFORMAL)
			{
				M_MapTexture[X][Y].Init("Assets/Sprite/Wall.DDS",M_SquareWide, M_SquareHeight);
			}else {
				if (M_MapData[X][Y] == GROUND)
				{
					M_MapTexture[X][Y].Init("Assets/Sprite/Ground.DDS", M_SquareWide, M_SquareHeight);
				}else {
					if (M_MapData[X][Y] == GROUNDFORMAL)
					{
						M_MapTexture[X][Y].Init("Assets/Sprite/Goal.DDS", M_SquareWide, M_SquareHeight);
					}
				}
			}
		}
	}
	ForthMapDataSet();
}
void Stage::ForthMapDataSet()
{
	for (int X = 0; X < M_SquareX; X++)
	{
		for (int Y = 0; Y < M_SquareY; Y++)
		{
			if (M_MapData[X][Y] == WALLFORMAL)
			{
				M_MapData[X][Y] = WALL;
			}

			if (M_MapData[X][Y] == GROUNDFORMAL)
			{
				M_MapData[X][Y] = GROUND;
			}
		}
	}
}

void Stage::Reset()
{
	FirstMapDataSet();
}

void Stage::Update()
{
	for (int X = 0; X < M_SquareX; X++)
	{
		for (int Y = 0; Y < M_SquareY; Y++)
		{
			M_MapTexture[X][Y].Update();
			M_MapTexture[X][Y].SetPosition(M_MapPosition[X][Y]);
		}
	}
}
void Stage::Render(RenderContext& rc)
{
	for (int X = 0; X < M_SquareX; X++)
	{
		for (int Y = 0; Y < M_SquareY; Y++)
		{
			M_MapTexture[X][Y].Draw(rc);
		}
	}
}
