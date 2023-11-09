#pragma once
class Action;
class Controller;
struct MotionFlag
{
	bool M_WalkFlag         = false;
	bool M_JumpFlag         = false;
	bool M_GoalFlag         = false;
	bool M_PositionJustFlag = false;
	bool M_FallFlag         = false;
};
class Action_Character : public IGameObject
{
public:
	Action_Character();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Move();
	void Walk();
	void Jump();
	void Fall();
	void Goal();

	void WallCollision();
	void GroundCollision();
private:
	SpriteRender M_CharacterTexture;

	Vector3 M_CharacterPosition = {0.0f,-150.0f,0.0f};
	Vector3 M_CharacterSpeed    = { 0.0f,10.0f,0.0f };

	Action* P_Action                = nullptr;
	DimensionCollision* P_Collision = nullptr;
	Controller* P_Controller        = nullptr;

	MotionFlag S_Flag;

	int M_JumpCoolTime = 0;
};

