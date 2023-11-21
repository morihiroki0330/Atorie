#pragma once
class ClairAction;

class DimensionalCollision;
class DimensionalCamera;
class Controller;

struct ClairActionMotionFlag
{
	bool M_WalkFlag = true;
	bool M_JumpFlag = false;
	bool M_GoalFlag = false;
	bool M_FallFlag = false;
	bool M_RightFlag = false;
	bool M_LeftFlag = false;
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
	void Rotation();
	void Jump();
	void Fall();
	void Goal();

	void TextureSet();
private:
	SpriteRender M_CharacterTexture;

	Vector3 M_CharacterPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_CharacterSpeed = { 0.0f,10.0f,0.0f };

	ClairAction* P_Clair = nullptr;
	DimensionalCollision* P_Collision = nullptr;
	DimensionalCamera* P_Camera = nullptr;
	Controller* P_Controller = nullptr;

	ClairActionMotionFlag S_Flag;

	int M_JumpCoolTime = 0;

	FontRender FR;
	wchar_t R[256];

	FontRender FL;
	wchar_t L[256];

	FontRender FX;
	wchar_t X[256];
};

