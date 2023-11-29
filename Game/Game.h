#pragma once

class DungeonOdyssey;
class LivblockAdventure;
class PuzzleBoxPath;
class ClairAction;

class Mouse;
class Controller;

class DimensionalCamera;
class DimensionalCollision;
class MapCreate;
class Weather;
class Fade;

struct GameClass
{
	DungeonOdyssey* P_DO        = nullptr;
	LivblockAdventure* P_LA = nullptr;
	PuzzleBoxPath* P_PBP = nullptr;
	ClairAction* P_Clair = nullptr;
};
struct Operation
{
	Mouse* P_Mouse           = nullptr;
	Controller* P_Controller = nullptr;
};
struct Tool
{
	DimensionalCamera* P_Camera =nullptr;
	DimensionalCollision* P_Collision = nullptr;
	MapCreate* P_MapCreate = nullptr;
	Weather* P_Weather;
	Fade* P_Fade;
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
	Tool S_Tool;
};

