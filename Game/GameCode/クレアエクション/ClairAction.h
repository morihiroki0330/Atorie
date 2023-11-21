#pragma once
class ClairAction_GameTitle;
class ClairAction_GameResult;

class ClairAction_Character;
class ClairAction_Stage;
class ClairAction_Gimmick;

class DimensionalCollision;
class DimensionalCamera;
class Fade;
class Mouse;

struct ClairActionClass
{
	ClairAction_GameTitle* P_GameTitle = nullptr;
	ClairAction_GameResult* P_GameResult = nullptr;

	ClairAction_Character* P_Character = nullptr;
	ClairAction_Stage* P_Stage = nullptr;
	ClairAction_Gimmick* P_Gimmick = nullptr;
	
	DimensionalCollision* P_Collision = nullptr;
	DimensionalCamera* P_Camera = nullptr;
	Fade* P_Fade = nullptr;
	Mouse* P_Mouse = nullptr;
};
enum
{
	CA_COLLISION_CURSOR,

	CA_COLLISION_STARTBUTTON,
	CA_COLLISION_OPTIONBUTTON,
	CA_COLLISION_EXITBUTTON,

	CA_COLLISION_CHARACTER,

	CA_COLLISION_GROUND,
	CA_COLLISION_WALL,
	CA_COLLISION_GOAL,

	CA_COLLISION_BOX,

	CA_COLLISION_NON
};
enum
{
	CA_TAG_CURSOR,

	CA_TAG_GROUND,
	CA_TAG_WALL,

	CA_TAG_BOX,

	CA_TAG_NON
};
enum
{
	CA_MAP_GROUND = 1,
	CA_MAP_WALL = 2,

	CA_GIMMICK_BOX,

	CA_MAP_NON
};
class ClairAction : public IGameObject
{
public:
	ClairAction();
	~ClairAction();
	bool Start();
	void Update();
	void Create(int Number);

	float GetGravity()
	{return M_Gravity;}
private:
	ClairActionClass S_Clair;
	int M_Number = 0;
	float M_Gravity = 10.0f;
};

