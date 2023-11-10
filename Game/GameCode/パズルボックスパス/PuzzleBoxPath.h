#pragma once
class Mouse;
class PuzzleBoxPath_GameTitle;
class PuzzleBoxPath_GameResult;
class PuzzleBoxPath_Stage;
class PuzzleBoxPath_Box;
struct PuzzleBoxPathClass
{
	PuzzleBoxPath_GameTitle* P_GameTitle   = nullptr;
	PuzzleBoxPath_GameResult* P_GameResult = nullptr;
	PuzzleBoxPath_Stage* P_Stage           = nullptr;
	PuzzleBoxPath_Box* P_Box               = nullptr;
	DimensionCollision* P_Collision      = nullptr;
	Mouse* P_Mouse                       = nullptr;
};
enum 
{
	PBP_COLLISION_CURSOR = 1,
	PBP_COLLISION_TITLEBUTTON = 2,
	PBP_COLLISION_RESULTBUTTON = 3,
	PBP_COLLISION_GROUND = 4,
	PBP_COLLISION_BOX = 5,
	PBP_COLLISION_ERRORBOX = 6,
	PBP_COLLISION_DRAWERRORBOX = 7,
	PBP_COLLISION_GOAL = 8
};
enum 
{
	PBP_TAG_CURSOR = 1,
	PBP_TAG_GROUND = 2,
	PBP_TAG_ERRORBOX = 3,
	PBP_TAG_DRAWERRORBOX = 4,
	PBP_TAG_BOX = 5,
	PBP_TAG_GOAL = 6,
	PBP_TAG_NON = 7
};
enum
{
	PBP_MAP_GROUND = 1,
	PBP_MAP_GOAL = 2,
	PBP_MAP_ERRORBOX = 3,
	PBP_MAP_DRAWERRORBOX = 4
};
enum
{
	PBP_FLAG_Goal = 0,
	PBP_FLAG_Over = 1,
};
class PuzzleBoxPath : public IGameObject
{
public:
	PuzzleBoxPath();
	~PuzzleBoxPath();
	bool Start();
	void Update();

	void Create(int Number);

	void SetFlag(int Number);
	bool GetFlag(int Number);

	float GetGravity()
	{return M_Gravity;}
private:
	PuzzleBoxPathClass S_PuzzleBoxPath;

	int M_Number = 0;

	float M_Gravity = 10.0f;

	bool M_GoalFlag = false;
	bool M_OverFlag = false;
};

