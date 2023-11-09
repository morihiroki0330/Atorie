#pragma once
class Dungeon;
class Dungeon_Stage;
class Dungeon_Character : public IGameObject
{
public:
	Dungeon_Character();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Move();
	void Goal();
private:
	SpriteRender M_CharacterTexture;

	Vector3 M_CharacterPosition = { 0.0f,0.0f,0.0f };

	Dungeon_Stage* P_Stage = nullptr;
	Dungeon* P_Dungeon     = nullptr;

	int M_PositionX = 0;
	int M_PositionY = 0;
};

