#pragma once
class GameResult : public IGameObject
{
public:
	GameResult();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameResultTexture;
};

