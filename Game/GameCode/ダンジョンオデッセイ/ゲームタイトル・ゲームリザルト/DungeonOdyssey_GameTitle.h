#pragma once
class DungeonOdyssey;
class DungeonOdyssey_GameTitle : public IGameObject
{
public:
	DungeonOdyssey_GameTitle();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameTitleTexture;

	DungeonOdyssey* P_Dungeon = nullptr;
};

