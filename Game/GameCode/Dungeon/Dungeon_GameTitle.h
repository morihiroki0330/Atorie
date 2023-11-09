#pragma once
class Dungeon;
class Dungeon_GameTitle : public IGameObject
{
public:
	Dungeon_GameTitle();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameTitleTexture;

	Dungeon* P_Dungeon = nullptr;
};

