#pragma once
class Flick;
class Mouse;
class Flick_Box : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Fall();
	void Move();
private:
	SpriteRender M_BoxTexture;
	Vector3 M_BoxPosition ={-740.0f,0.0f,0.0f};
	DimensionCollision* P_Collision;
	Flick* P_Flick;
	Mouse* P_Mouse;
	
	bool M_FallFlag = false;
};

