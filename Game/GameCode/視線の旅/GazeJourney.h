#pragma once
class GazeJourney_GameTitle;
class GazeJourney_GameResult;
class GazeJourney_Character;
class GazeJourney_Stage;
struct GazeJourneyClass
{
	GazeJourney_GameTitle* P_GameTitle   = nullptr;
	GazeJourney_GameResult* P_GameResult   = nullptr;
	GazeJourney_Character* P_Character = nullptr;
	GazeJourney_Stage* P_Stage           = nullptr;
	DimensionCollision* P_Collision    = nullptr;
	TwoDimensionalCamera* P_Camera     = nullptr;
};
enum
{
	GJ_COLLISION_CHARACTER = 1,
	GJ_COLLISION_GROUND = 2,
	GJ_COLLISION_GOAL = 3,
};
enum
{
	GJ_TAG_GROUND = 1,
	GJ_TAG_GOAL = 2,
	GJ_TAG_NON = 3
};
class GazeJourney : public IGameObject
{
public:
	GazeJourney();
	~GazeJourney();
	void Create(int Number);

	float GetGravity()
	{return M_Gravity;}
	Vector3 GetCameraTarget()
	{return M_CameraTarget;}
private:
	GazeJourneyClass S_Gaze;

	int M_Number = 0;

	float M_Gravity = 10.0f;

	Vector3 M_CameraTarget = { 0.0f,0.0f,0.0f };
};

