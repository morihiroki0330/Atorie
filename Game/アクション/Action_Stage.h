#pragma once
enum MapType
{
	GROUND,
	WALL,
};
class Action_Stage : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Ground(int X,int Y);
	void Wall(int X,int Y);
private:
	SpriteRender M_StageTexture[10][10];
	Vector3 M_StagePosition[10][10];
	DimensionCollision M_Collision;
	const char* M_FilePath = nullptr;
	char M_Value[256];
	int X = 99;
	int Y = 99;
	int GroundType = 99;
};

