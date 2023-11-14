#pragma once
class Mouse;
class Controller;
class DungeonOdyssey;
class LivblockAdventure;
class PuzzleBoxPath;
class FlickBlade;
class GazeJourney;
class AnimeTraverse;
class ClairAction;
struct GameClass
{
	DungeonOdyssey* P_DO        = nullptr;
	LivblockAdventure* P_LA = nullptr;
	PuzzleBoxPath* P_PBP = nullptr;
	FlickBlade* P_FB = nullptr;
	GazeJourney* P_GJ     = nullptr;
	AnimeTraverse* P_AT = nullptr;
	ClairAction* P_CA = nullptr;
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

