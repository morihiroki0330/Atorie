#pragma once
class Dungeon_GameTitle;
class Dungeon_GameResult;
class Dungeon_Character;
class Dungeon_Stage;
struct DungeonClass
{
	Dungeon_GameTitle* P_GameTitle;
	Dungeon_GameResult* P_GameResult;
	Dungeon_Character* P_Character;
	Dungeon_Stage* P_Stage;
};
enum Class
{
	FIRST,
	SECOND,
	THIRD,
};
class Dungeon : public IGameObject
{
public:
	Dungeon();
	~Dungeon();
	void Create(int Number);
private:
	DungeonClass S_Dungeon;
	int M_Number = FIRST;
};