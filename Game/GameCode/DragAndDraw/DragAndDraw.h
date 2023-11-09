#pragma once
class Mouse;
class DragAndDraw_GameTitle;
class DragAndDraw_GameResult;
class DragAndDraw_Stage;
class DragAndDraw_Box;
struct DragAndDrawClass
{
	DragAndDraw_GameTitle* P_GameTitle   = nullptr;
	DragAndDraw_GameResult* P_GameResult = nullptr;
	DragAndDraw_Stage* P_Stage           = nullptr;
	DragAndDraw_Box* P_Box               = nullptr;
	DimensionCollision* P_Collision      = nullptr;
	Mouse* P_Mouse                       = nullptr;
};
enum 
{
	DAD_COLLISION_CURSOR = 1,
	DAD_COLLISION_TITLEBUTTON = 2,
	DAD_COLLISION_RESULTBUTTON = 3,
	DAD_COLLISION_GROUND = 4,
	DAD_COLLISION_BOX = 5,
	DAD_COLLISION_ERRORBOX = 6,
	DAD_COLLISION_DRAWERRORBOX = 7,
	DAD_COLLISION_GOAL = 8
};
enum 
{
	DAD_TAG_CURSOR = 1,
	DAD_TAG_GROUND = 2,
	DAD_TAG_ERRORBOX = 3,
	DAD_TAG_DRAWERRORBOX = 4,
	DAD_TAG_BOX = 5,
	DAD_TAG_GOAL = 6,
	DAD_TAG_NON = 7
};
enum
{
	DAD_MAP_GROUND = 1,
	DAD_MAP_GOAL = 2,
	DAD_MAP_ERRORBOX = 3,
	DAD_MAP_DRAWERRORBOX = 4
};
enum
{
	DAD_FLAG_Goal = 0,
	DAD_FLAG_Over = 1,
};
class DragAndDraw : public IGameObject
{
public:
	DragAndDraw();
	~DragAndDraw();
	bool Start();
	void Update();

	void Create(int Number);

	void SetFlag(int Number);
	bool GetFlag(int Number);

	float GetGravity()
	{return M_Gravity;}
private:
	DragAndDrawClass S_DragAndDraw;

	int M_Number = 0;

	float M_Gravity = 10.0f;

	bool M_GoalFlag = false;
	bool M_OverFlag = false;
};

