#pragma once
class Action;
class Action_Stage;
class Action_Character : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	bool GetGoalFlag() { return GoalFlag; }
	void Goal();

	void Move();
private:
	SpriteRender M_CharacterTexture;
	Vector3 M_CharacterPosition = {0.0f,150.0f,0.0f};
	Action* P_Action = nullptr;
	Action_Stage* P_Stage = nullptr;
	DimensionCollision* P_Collision;
	bool GoalFlag = false;
};

