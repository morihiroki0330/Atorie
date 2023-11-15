#pragma once
class LivblockAdventure;
class Controller;
struct LA_MotionFlag
{
	bool M_WalkFlag         = false;
	bool M_JumpFlag         = false;
	bool M_GoalFlag         = false;
	bool M_PositionJustFlag = false;
	bool M_FallFlag         = false;
};
class LivblockAdventure_Character : public IGameObject
{
public:
	LivblockAdventure_Character();
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

	Vector3 M_CharacterPosition = { 0.0f,-150.0f,0.0f };
	Vector3 M_CharacterSpeed    = { 0.0f,10.0f,0.0f };

	LivblockAdventure* P_Livblock              = nullptr;
	DimensionCollision* P_Collision = nullptr;
	Controller* P_Controller        = nullptr;

	LA_MotionFlag S_Flag;

	int M_JumpCoolTime = 0;
};

