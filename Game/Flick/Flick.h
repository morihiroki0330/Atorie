#pragma once
class Mouse;
class Flick_GameTitle;
class Flick_GameResult;
class Flick_Stage;
class Flick_Box;
struct FlickClass
{
	Flick_GameTitle* P_GameTitle;
	Flick_GameResult* P_GameResult;
	Flick_Stage* P_Stage;
	Flick_Box* P_Box;
	DimensionCollision* P_Collision;
	Mouse* P_Mouse;
};
enum 
{
	FLICK_COLLISION_CURSOR = 1,
	FLICK_COLLISION_TITLEBUTTON = 2,
	FLICK_COLLISION_GROUND = 3,
	FLICK_COLLISION_BOX = 4,
	FLICK_COLLISION_ERRORBOX = 5,
	FLICK_COLLISION_GOAL =6
};
enum 
{
	FLICK_TAG_CURSOR = 1,
	FLICK_TAG_GROUND = 2,
	FLICK_TAG_ERRORBOX = 3,
	FLICK_TAG_BOX = 4,
	FLICK_TAG_GOAL = 5,
	FLICK_TAG_NON = 6
};
enum
{
	FLICK_MAP_GROUND = 1,
	FLICK_MAP_GOAL = 2,
	FLICK_MAP_ERRORBOX = 3
};
class Flick : public IGameObject
{
public:
	Flick();
	~Flick();
	bool Start();
	void Update();
	void Create(int Number);
	float GetGravity()
	{return M_Gravity;}
private:
	FlickClass S_Flick;
	int M_Number = 0;
	float M_Gravity = 10.0f;
};

