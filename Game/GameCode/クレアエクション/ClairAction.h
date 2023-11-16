#pragma once
class ClairAction_GameTitle;
class ClairAction_GameResult;

class ClairAction_Character;
class ClairAction_Stage;
class ClairAction_Gimmick;

class DimensionalCollision;
class DimensionalCamera;
class Mouse;

struct ClairActionClass
{
	ClairAction_GameTitle* P_GameTitle = nullptr;
	ClairAction_GameResult* P_GameResult = nullptr;

	ClairAction_Character* P_Character = nullptr;
	ClairAction_Stage* P_Stage = nullptr;
	ClairAction_Gimmick* P_Gimmic = nullptr;
	
	DimensionalCollision* P_Collision = nullptr;
	DimensionalCamera* P_Camera = nullptr;
	Mouse* P_Mouse = nullptr;
};
enum
{
	CA_COLLISION_CURSOR = 1,

	CA_COLLISION_STARTBUTTON = 2,
	CA_COLLISION_OPTIONBUTTON = 3,
	CA_COLLISION_EXITBUTTON = 4,
};
enum
{
	CA_TAG_CURSOR = 1,

	CA_TAG_NON = 2
};
enum
{
	CA_MAP_GROUND = 1,
	CA_MAP_WALL = 2,
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

