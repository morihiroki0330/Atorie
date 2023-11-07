#pragma once
class Flick;
class Flick_GameResult : public IGameObject
{
public:
	Flick_GameResult();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameResultTexture;
	Flick* P_Flick;
};

