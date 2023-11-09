#pragma once
class Action_GameTitle;
class Action_GameResult;
class Action_Character;
class Action_Stage;
class Action_WindowFrame;
struct ActionClass
{
	Action_GameTitle* P_GameTitle     = nullptr;
	Action_GameResult* P_GameResult   = nullptr;
	Action_Character* P_Character     = nullptr;
	Action_Stage* P_Stage             = nullptr;
	Action_WindowFrame* P_WindowFrame = nullptr;
	DimensionCollision* P_Collision   = nullptr;
};
enum 
{
	ACTION_COLLISION_CHARACTER = 1,
	ACTION_COLLISION_GROUND = 2,
	ACTION_COLLISION_WALL = 3,
	ACTION_COLLISION_GOAL = 4,
};
enum 
{
	ACTION_TAG_GROUND = 1,
	ACTION_TAG_WALL = 2,
	ACTION_TAG_BOX = 3,
	ACTION_TAG_GOAL = 4,
	ACTION_TAG_NON = 5
};
enum 
{
	ACTION_MAP_GROUND = 1,
	ACTION_MAP_WALL = 2,
	ACTION_MAP_GOAL = 3,
};
class Action : public IGameObject
{
public:
	Action();
	~Action();

	void Create(int Number);

	float GetGravity()
	{return M_Gravity;}
private:
	ActionClass S_Action;

	int M_Number = 0;

	float M_Gravity = 10.0f;

};

