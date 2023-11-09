#pragma once
class Dungeon_GameTitle;
class Dungeon_GameResult;
class Dungeon_Character;
class Dungeon_Stage;
struct DungeonClass
{
	Dungeon_GameTitle* P_GameTitle   = nullptr;
	Dungeon_GameResult* P_GameResult = nullptr;
	Dungeon_Character* P_Character   = nullptr;
	Dungeon_Stage* P_Stage           = nullptr;
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