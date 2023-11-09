#pragma once
class DragAndDraw;
class Mouse;
class DragAndDraw_GameResult : public IGameObject
{
public:
	DragAndDraw_GameResult();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameResultTexture;
	DimensionCollision* P_Collision = nullptr;
	DragAndDraw* P_DragAndDraw = nullptr;
};

