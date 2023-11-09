#pragma once
class Dungeon;
class Dungeon_GameResult : public IGameObject
{
public:
	Dungeon_GameResult();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameResultTexture;

	Dungeon* P_Dungeon = nullptr;
};

