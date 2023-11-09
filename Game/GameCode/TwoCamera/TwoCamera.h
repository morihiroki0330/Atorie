#pragma once
class TwoCamera_Gametitle;
class TwoCamera_Charatcrer;
class TwoCamera_Stage;
struct CameraClass
{
	TwoCamera_Gametitle* P_GameTitle   = nullptr;
	TwoCamera_Charatcrer* P_Character  = nullptr;
	TwoCamera_Stage* P_Stage           = nullptr;
	DimensionCollision* P_Collision    = nullptr;
	TwoDimensionalCamera* P_Camera     = nullptr;
};
class TwoCamera : public IGameObject
{
public:
	TwoCamera();
	~TwoCamera();
	void Create(int Number);

	float GetGravity()
	{return M_Gravity;}
private:
	CameraClass S_TwoCamera;

	int M_Number = 0;

	float M_Gravity = 10.0f;
};

