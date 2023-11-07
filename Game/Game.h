#pragma once
class Mouse;
class Controller;
class Dungeon;
class Action;
class Flick;
struct GameClass
{
	Dungeon* P_Dungeon;
	Action* P_Action;
	Flick* P_Flick;
};
struct Operation
{
	Mouse* P_Mouse;
	Controller* P_Controller;
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
	Operation S_Operation;
};

