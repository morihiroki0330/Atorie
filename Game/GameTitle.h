#pragma once
class Mouse;
class GameTitle : public IGameObject
{
public:
	GameTitle();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	DimensionCollision M_StartButtonCollision;
private:
	SpriteRender M_GameTitleTexture;
	SpriteRender M_StartButtonTexture;
	Vector3 M_StartButtonPosition = { 0.0f,-50.0f,0.0f };

	Mouse* P_Mouse;
};

