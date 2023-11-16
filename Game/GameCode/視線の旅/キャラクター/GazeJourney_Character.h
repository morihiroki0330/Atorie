#pragma once
class GazeJourney;

class DimensionalCollision;
class DimensionalCamera;
class Controller;

struct GJ_MotionFlag
{
	bool M_WalkFlag = false;
	bool M_JumpFlag = false;
	bool M_GoalFlag = false;
	bool M_PositionJustFlag = false;
	bool M_FallFlag = false;
};
class GazeJourney_Character : public IGameObject
{
public:
	GazeJourney_Character();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Move();
	void Walk();
	void Fall();
private:
	SpriteRender M_CharacterTexture;

	Vector3 M_CharacterPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_CharacterSpeed = { 0.0f,10.0f,0.0f };

	GazeJourney* P_Gaze = nullptr;
	DimensionalCollision* P_Collision = nullptr;
	Controller* P_Controller = nullptr;
	DimensionalCamera* P_Camera = nullptr;

	GJ_MotionFlag S_Flag;
};

