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
	DUNGEON_NON = 0,
	DUNGEON_GROUND = 1,
	DUNGEON_GROUNDFORMAL = 2,
	DUNGEON_WALL = 3,
	DUNGEON_WALLFORMAL = 4,
	DUNGEON_WALLFIXED = 5
};
enum
{
	DUNGEON_DIRECTION_UP = 1,
	DUNGEON_DIRECTION_RIGHT = 2,
	DUNGEON_DIRECTION_DOWN = 3,
	DUNGEON_DIRECTION_LEFT = 4
};
enum
{
	DUNGEON_NUMBER_SquareX = 0,
	DUNGEON_NUMBER_SquareY = 1,
	DUNGEON_NUMBER_StageUpperLeftX = 2,
	DUNGEON_NUMBER_StageUpperLeftY = 3,
	DUNGEON_NUMBER_StageLowerRightX = 4,
	DUNGEON_NUMBER_StageLowerRightY = 5,
	DUNGEON_NUMBER_StartX = 6,
	DUNGEON_NUMBER_StartY = 7,
	DUNGEON_NUMBER_GoalX = 8,
	DUNGEON_NUMBER_GoalY = 9,
	DUNGEON_NUMBER_MapDataUp = 10,
	DUNGEON_NUMBER_MapDataRight = 11,
	DUNGEON_NUMBER_MapDataDown = 12,
	DUNGEON_NUMBER_MapDataLeft = 13,
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