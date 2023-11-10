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
	LA_COLLISION_CHARACTER = 1,
	LA_COLLISION_GROUND = 2,
	LA_COLLISION_WALL = 3,
	LA_COLLISION_GOAL = 4,
};
enum 
{
	LA_TAG_GROUND = 1,
	LA_TAG_WALL = 2,
	LA_TAG_BOX = 3,
	LA_TAG_GOAL = 4,
	LA_TAG_NON = 5
};
enum 
{
	LA_MAP_GROUND = 1,
	LA_MAP_WALL = 2,
	LA_MAP_GOAL = 3,
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

