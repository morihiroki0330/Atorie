#pragma once

class ClairAction_Gimmick;

class DimensionalCollision;

class ClairAction_Stage : public IGameObject
{
public:
	ClairAction_Stage();
	bool Start();
	void Render(RenderContext& rc);

	bool MapSet();

	void Ground(int X,int Y);
	void Wall(int X, int Y);
	void Goal(int X, int Y);

	void Box(int X, int Y);
private:
	SpriteRender M_BackGroundTexture;
	SpriteRender M_StageTileTexture[16][9];
	Vector3 M_StagePosition = { 0.0f,0.0f,0.0f };
	ClairAction_Gimmick* P_Gimmick = nullptr;
	DimensionalCollision* P_Collision = nullptr;

	const char* M_FilePath = nullptr;
	char M_Value[256];
	int X = 99;
	int Y = 99;
	int MapType = 99;
};

