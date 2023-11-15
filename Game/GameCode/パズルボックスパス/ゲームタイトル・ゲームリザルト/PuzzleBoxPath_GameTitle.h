#pragma once
class PuzzleBoxPath;
class Mouse;
class PuzzleBoxPath_GameTitle : public IGameObject
{
public:
	PuzzleBoxPath_GameTitle();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameTitleTexture;
	SpriteRender M_GameTitleButtonTexture;

	Vector3 M_GameTitleButtonPosition = { 0.0f,-150.0f,0.0f };

	DimensionCollision* P_Collision = nullptr;
	PuzzleBoxPath* P_Puzzle      = nullptr;
	Mouse* P_Mouse                  = nullptr;
};

