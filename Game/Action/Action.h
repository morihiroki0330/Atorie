#pragma once
class Action_GameTitle;
class Action_GameResult;
class Action_Character;
class Action_Stage;
class Action_WindowFrame;
struct ActionClass
{
	Action_GameTitle* P_GameTitle;
	Action_GameResult* P_GameResult;
	Action_Character* P_Character;
	Action_Stage* P_Stage;
	Action_WindowFrame* P_WindowFrame;
	DimensionCollision* P_Collision;
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
	SpriteRender M_BackTexture;
	int M_Number = 0;
	float M_Gravity = 10.0f;
};

