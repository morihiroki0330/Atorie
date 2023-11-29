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
	Fade* P_Fade = nullptr;
	Mouse* P_Mouse = nullptr;
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

