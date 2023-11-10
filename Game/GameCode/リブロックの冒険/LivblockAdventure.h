#pragma once
class LivblockAdventure_GameTitle;
class LivblockAdventure_GameResult;
class LivblockAdventure_Character;
class LivblockAdventure_Stage;
class LivblockAdventure_WindowFrame;
struct LivblockAdventureClass
{
	LivblockAdventure_GameTitle* P_GameTitle     = nullptr;
	LivblockAdventure_GameResult* P_GameResult   = nullptr;
	LivblockAdventure_Character* P_Character     = nullptr;
	LivblockAdventure_Stage* P_Stage             = nullptr;
	LivblockAdventure_WindowFrame* P_WindowFrame = nullptr;
	DimensionCollision* P_Collision              = nullptr;
};
enum 
{
	LIVBLOCK_COLLISION_CHARACTER = 1,
	LIVBLOCK_COLLISION_GROUND = 2,
	LIVBLOCK_COLLISION_WALL = 3,
	LIVBLOCK_COLLISION_GOAL = 4,
};
enum 
{
	LIVBLOCK_TAG_GROUND = 1,
	LIVBLOCK_TAG_WALL = 2,
	LIVBLOCK_TAG_BOX = 3,
	LIVBLOCK_TAG_GOAL = 4,
	LIVBLOCK_TAG_NON = 5
};
enum 
{
	LIVBLOCK_MAP_GROUND = 1,
	LIVBLOCK_MAP_WALL = 2,
	LIVBLOCK_MAP_GOAL = 3,
};
class LivblockAdventure : public IGameObject
{
public:
	LivblockAdventure();
	~LivblockAdventure();

	void Create(int Number);

	float GetGravity()
	{return M_Gravity;}
private:
	LivblockAdventureClass S_Livblock;

	int M_Number = 0;

	float M_Gravity = 10.0f;

};

