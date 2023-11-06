#pragma once
class Action_Stage : public IGameObject
{
public:
	bool Start();
	void Render(RenderContext& rc);

	bool MapSet();
	void Ground(int X,int Y);
	void Wall(int X,int Y);
	void Goal(int X,int Y);
private:
	SpriteRender M_StageTexture[10][10];
	SpriteRender M_BackGroundTexture;
	SpriteRender M_GoalFlagTexture;
	Vector3 M_StagePosition;
	DimensionCollision* P_Collision = nullptr;
	const char* M_FilePath = nullptr;
	char M_Value[256];
	int X = 99;
	int Y = 99;
	int GroundType = 99;
};

