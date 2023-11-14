#pragma once
class ClairAction;
class Controller;
struct ClairActionMotionFlag
{
	bool M_WalkFlag = false;
	bool M_JumpFlag = false;
	bool M_GoalFlag = false;
	bool M_PositionJustFlag = false;
	bool M_FallFlag = false;
};
class ClairAction_Character : public IGameObject
{
public:
	ClairAction_Character();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Move();
	void Walk();
	void Jump();
	void Fall();
	void Goal();
private:
	SpriteRender M_CharacterTexture;

	Vector3 M_CharacterPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_CharacterSpeed = { 0.0f,10.0f,0.0f };

	ClairAction* P_Clair = nullptr;
	DimensionCollision* P_Collision = nullptr;
	Controller* P_Controller = nullptr;
	TwoDimensionalCamera* P_Camera = nullptr;

	ClairActionMotionFlag S_Flag;
};

