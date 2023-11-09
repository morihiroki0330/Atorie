#pragma once
class DragAndDraw;
class Mouse;
class DragAndDraw_GameTitle : public IGameObject
{
public:
	DragAndDraw_GameTitle();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameTitleTexture;
	SpriteRender M_GameTitleButtonTexture;

	Vector3 M_GameTitleButtonPosition = { 0.0f,-150.0f,0.0f };

	DimensionCollision* P_Collision = nullptr;
	DragAndDraw* P_DragAndDraw = nullptr;
	Mouse* P_Mouse = nullptr;
};

