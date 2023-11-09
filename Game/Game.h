#pragma once
class Mouse;
class Controller;
class Dungeon;
class Action;
class DragAndDraw;
class TwoCamera;
struct GameClass
{
	Dungeon* P_Dungeon         = nullptr;
	Action* P_Action           = nullptr;
	DragAndDraw* P_DragAndDraw = nullptr;
	TwoCamera* P_TwoCamera     = nullptr;
};
struct Operation
{
	Mouse* P_Mouse           = nullptr;
	Controller* P_Controller = nullptr;
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

