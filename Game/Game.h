#pragma once
class Mouse;
class Dungeon;
class Action;
struct GameClass
{
	Dungeon* P_Dungeon;
	Action* P_Action;
};
enum Class
{
	FIRST,
	SECOND,
	THIRD,
};
class Game : public IGameObject
{
public:
	Game();
	~Game();
private:
	GameClass S_GameClass;
};

