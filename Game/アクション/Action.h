#pragma once
class Action_GameTitle;
class Action_GameResult;
class Action_Character;
class Action_Stage;
class Action_WindowFrame;
struct ActionClass
{
	Action_GameTitle* P_GameTitle;
	Action_GameResult* P_GameResult;
	Action_Character* P_Character;
	Action_Stage* P_Stage;
	Action_WindowFrame* P_WindowFrame;
	DimensionCollision* P_Collision;
};
enum CollisionData
{
	COLLISION_CHARACTER = 1,
	COLLISION_CHARACTERLEG = 2,
	COLLISION_GROUND = 3,
	COLLISION_WALL = 4,
	COLLISION_BOX = 5
};
enum TagType
{
	TAG_GROUND = 1,
	TAG_WALL = 2,
	TAG_BOX = 3,
	TAG_NON = 4
};
enum MapType
{
	MAP_GROUND = 1,
	MAP_WALL = 2,
	MAP_BOX = 3,
};
class Action : public IGameObject
{
public:
	Action();
	~Action();
	void Create(int Number);
private:
	ActionClass S_Action;
	SpriteRender M_BackTexture;
	int M_Number = 0;
};

