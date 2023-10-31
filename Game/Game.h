#pragma once
class Mouse;
class Dungeon;
struct GameClass
{
	Dungeon* P_Dungeon;
};
class Game : public IGameObject
{
public:
	Game();
	~Game();
private:
	GameClass S_GameClass;
};

