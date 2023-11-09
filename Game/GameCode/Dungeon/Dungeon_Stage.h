#pragma once
enum
{
	DUNGEON_NON          = 0,
	DUNGEON_GROUND       = 1,
	DUNGEON_GROUNDFORMAL = 2,
	DUNGEON_WALL         = 3,
	DUNGEON_WALLFORMAL   = 4,
	DUNGEON_WALLFIXED    = 5
};
enum
{
	DUNGEON_DIRECTION_UP    = 1,
	DUNGEON_DIRECTION_RIGHT = 2,
	DUNGEON_DIRECTION_DOWN  = 3,
	DUNGEON_DIRECTION_LEFT  = 4
};
enum
{
	DUNGEON_NUMBER_SquareX          = 0,
	DUNGEON_NUMBER_SquareY          = 1,
	DUNGEON_NUMBER_StageUpperLeftX  = 2,
	DUNGEON_NUMBER_StageUpperLeftY  = 3,
	DUNGEON_NUMBER_StageLowerRightX = 4,
	DUNGEON_NUMBER_StageLowerRightY = 5,
	DUNGEON_NUMBER_StartX           = 6,
	DUNGEON_NUMBER_StartY           = 7,
	DUNGEON_NUMBER_GoalX            = 8,
	DUNGEON_NUMBER_GoalY            = 9,
	DUNGEON_NUMBER_MapDataUp        = 10,
	DUNGEON_NUMBER_MapDataRight     = 11,
	DUNGEON_NUMBER_MapDataDown      = 12,
	DUNGEON_NUMBER_MapDataLeft      = 13,
};
class Dungeon_Stage : public IGameObject
{
public:
	Dungeon_Stage();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void FirstMapDataSet();
	void SecondMapDataSet();
	void ThirdMapDataSet();
	void ForthMapDataSet();

	int GetNumber(int Number);
	int GetMapData(int X, int Y, int Number);
	bool WallCheck(int X, int Y, int Direction);
	bool GroundCheck(int X, int Y, int Direction);
	Vector3 GetMapPosition(int X, int Y)
	{return M_MapPosition[X][Y];}
private:
	struct IntVector2
	{
		int x = 0;
		int y = 0;
	};

	SpriteRender M_MapTexture[16][9];

	Vector3 M_MapPosition[16][9];

	int M_MapData[16][9];
	
	Vector2 M_Width       = {0.0f,0.0f};//マップの縦横幅
	Vector2 M_SquareWidth = { 0.0f,0.0f };//マスの縦横幅

	IntVector2 M_Square          = { 0,0 };//マス数
	IntVector2 M_StageUpperLeft  = { 0,0 };//マスの左上頂点
	IntVector2 M_StageLowerRight = { 0,0 };//マスの右下頂点
	IntVector2 M_Start           = { 0,0 };//スタート地点
	IntVector2 M_Goal            = { 0,0 };//ゴール地点

	int M_RandDirection = 0;
	bool M_RandCheck = false;
};

