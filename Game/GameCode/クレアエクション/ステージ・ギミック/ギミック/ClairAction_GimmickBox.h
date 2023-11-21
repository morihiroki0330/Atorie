#pragma once
class ClairAction;

class DimensionalCollision;
class Mouse;

class ClairAction_GimmickBox : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Fall();
	void Move();

	void SetPosition(Vector3 Position)
	{M_BoxPosition = Position;}
private:
	SpriteRender M_BoxTexture;

	Vector3 M_BoxPosition = { 0.0f,0.0f,0.0f };

	DimensionalCollision* P_Collision = nullptr;
	ClairAction* P_Clair = nullptr;
	Mouse* P_Mouse = nullptr;

	bool M_FallFlag = false;
	bool M_OnGround = false;
	bool M_OnBox = false;

	int M_CollisionNumner = 0;
};

