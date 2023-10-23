#pragma once
class Stage;
class Character : public IGameObject
{
public:
	bool Start();
	bool GetGoalFlag() { return GoalFlag; }
	void Goal();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_CharacterTexture;
	Vector3 M_CharacterPosition;
	Stage* P_Stage;
	int M_PositionX;
	int M_PositionY;
	bool GoalFlag = false;
};

