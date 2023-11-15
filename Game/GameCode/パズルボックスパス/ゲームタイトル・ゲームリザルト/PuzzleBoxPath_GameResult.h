#pragma once
class PuzzleBoxPath;
class Mouse;
class PuzzleBoxPath_GameResult : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameResultTexture;

	DimensionCollision* P_Collision = nullptr;
	PuzzleBoxPath* P_Puzzle      = nullptr;
};

