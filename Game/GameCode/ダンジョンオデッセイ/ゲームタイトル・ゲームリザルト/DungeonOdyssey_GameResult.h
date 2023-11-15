#pragma once
class DungeonOdyssey;
class DungeonOdyssey_GameResult : public IGameObject
{
public:
	DungeonOdyssey_GameResult();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameResultTexture;

	DungeonOdyssey* P_Dungeon = nullptr;
};

