#pragma once
enum
{
	NON = 0,
	GROUND = 1,
	GROUNDFORMAL = 2,
	WALL = 3,
	WALLFORMAL = 4,
	WALLFIXED = 5
};
enum
{
	UP = 1,
	RIGHT = 2,
	DOWN = 3,
	LEFT = 4
};
class Dungeon_Stage : public IGameObject
{
public:
	bool Start();
	bool WallCheck(int X, int Y, int Direction);
	bool GroundCheck(int X, int Y, int Direction);

	void FirstMapDataSet();
	void SecondMapDataSet();
	void ThirdMapDataSet();
	void ForthMapDataSet();
	void Reset();

	void Update();
	void Render(RenderContext& rc);

	static const int M_SquareX = 16;//Xのマス数
	static const int M_SquareY = 9;//Yのマス数

	const float M_Wide = 1920.0f;
	const float M_Height = 1080.0f;

	const float M_SquareWide = M_Wide / M_SquareX;
	const float M_SquareHeight = M_Height / M_SquareY;

	SpriteRender M_MapTexture[M_SquareX][M_SquareY];
	Vector3 M_MapPosition[M_SquareX][M_SquareY];
	int M_MapData[M_SquareX][M_SquareY];

	//マスの左上頂点
	static const int M_StageX = 0;
	static const int M_StageY = 0;

	//マスの右下頂点
	static const int M_Stage_X = M_SquareX - 1;
	static const int M_Stage_Y = M_SquareY - 1;

	//スタート地点
	static const int M_StartX = 1;
	static const int M_StartY = 1;

	//ゴール地点
	static const int M_GoalX = M_SquareX - 2;
	static const int M_GoalY = M_SquareY - 2;

	int M_RandDirection = 0;
	bool M_RandCheck = false;
};

