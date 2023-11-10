#pragma once
class LivblockAdventure;
class LivblockAdventure_GameTitle : public IGameObject
{
public:
	LivblockAdventure_GameTitle();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameTitleTexture;

	LivblockAdventure* P_Livblock = nullptr;
};

