#pragma once
class Dungeon_Stage;
class Dungeon;
class Dungeon_Character : public IGameObject
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
	Dungeon_Stage* P_Stage;
	Dungeon* P_Dungeon;
	int M_PositionX;
	int M_PositionY;
	bool GoalFlag = false;
};

