#pragma once
class DragAndDraw;
class DragAndDraw_Stage : public IGameObject
{
public:
	DragAndDraw_Stage();
	bool Start();
	void Render(RenderContext& rc);

	bool MapSet();
	void Ground(int X, int Y);
	void Goal(int X, int Y);
	void ErrorBox(int X, int Y);
	void DrawErrorBox(int X, int Y);
private:
	SpriteRender M_StageTexture[16][9];
	SpriteRender M_BackGroundTexture;

	Vector3 M_StagePosition = { 0.0f,0.0f,0.0f };

	DimensionCollision* P_Collision = nullptr;

	const char* M_FilePath = nullptr;

	char M_Value[256];

	int X          = 99;
	int Y          = 99;
	int GroundType = 99;
};

