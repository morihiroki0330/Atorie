#pragma once
class DungeonOdyssey;
class DungeonOdyssey_Stage;
class DungeonOdyssey_Character : public IGameObject
{
public:
	DungeonOdyssey_Character();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Move();
	void Goal();
private:
	SpriteRender M_CharacterTexture;

	Vector3 M_CharacterPosition = { 0.0f,0.0f,0.0f };

	DungeonOdyssey_Stage* P_Stage = nullptr;
	DungeonOdyssey* P_Dungeon     = nullptr;

	int M_PositionX = 0;
	int M_PositionY = 0;
};

