#pragma once
class DungeonOdyssey_GameTitle;
class DungeonOdyssey_GameResult;
class DungeonOdyssey_Character;
class DungeonOdyssey_Stage;
struct DungeonOdysseyClass
{
	DungeonOdyssey_GameTitle* P_GameTitle   = nullptr;
	DungeonOdyssey_GameResult* P_GameResult = nullptr;
	DungeonOdyssey_Character* P_Character   = nullptr;
	DungeonOdyssey_Stage* P_Stage           = nullptr;
};
enum
{
	DO_NON = 0,
	DO_GROUND = 1,
	DO_GROUNDFORMAL = 2,
	DO_WALL = 3,
	DO_WALLFORMAL = 4,
	DO_WALLFIXED = 5
};
enum
{
	DO_DIRECTION_UP = 1,
	DO_DIRECTION_RIGHT = 2,
	DO_DIRECTION_DOWN = 3,
	DO_DIRECTION_LEFT = 4
};
enum
{
	DO_NUMBER_SquareX = 0,
	DO_NUMBER_SquareY = 1,
	DO_NUMBER_StageUpperLeftX = 2,
	DO_NUMBER_StageUpperLeftY = 3,
	DO_NUMBER_StageLowerRightX = 4,
	DO_NUMBER_StageLowerRightY = 5,
	DO_NUMBER_StartX = 6,
	DO_NUMBER_StartY = 7,
	DO_NUMBER_GoalX = 8,
	DO_NUMBER_GoalY = 9,
	DO_NUMBER_MapDataUp = 10,
	DO_NUMBER_MapDataRight = 11,
	DO_NUMBER_MapDataDown = 12,
	DO_NUMBER_MapDataLeft = 13,
};
class DungeonOdyssey : public IGameObject
{
public:
	DungeonOdyssey();
	~DungeonOdyssey();

	void Create(int Number);
private:
	DungeonOdysseyClass S_Dungeon;

	int M_Number = 0;
};