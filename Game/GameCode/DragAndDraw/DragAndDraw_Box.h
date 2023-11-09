#pragma once
class DragAndDraw;
class Mouse;
class DragAndDraw_Box : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Fall();
	void Move();

	void Goal();
	void Over();
private:
	SpriteRender M_BoxTexture;

	Vector3 M_BoxPosition = { -725.0f,0.0f,0.0f };

	DimensionCollision* P_Collision = nullptr;
	DragAndDraw* P_DragAndDraw      = nullptr;
	Mouse* P_Mouse                  = nullptr;
	
	bool M_FallFlag = false;
};

