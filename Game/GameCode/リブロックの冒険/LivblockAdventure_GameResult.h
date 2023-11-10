#pragma once
class LivblockAdventure;
class LivblockAdventure_GameResult : public IGameObject
{
public:
	LivblockAdventure_GameResult();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameResultTexture;
	LivblockAdventure* P_Livblock = nullptr;
};

