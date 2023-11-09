#pragma once
class Mouse;
class Controller;
class Dungeon;
class Action;
class DragAndDraw;
struct GameClass
{
	Dungeon* P_Dungeon;
	Action* P_Action;
	DragAndDraw* P_DragAndDraw;
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
	FORTH
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

