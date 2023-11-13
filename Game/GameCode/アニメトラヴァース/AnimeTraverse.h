#pragma once
class AnimeTraverse_Character;
class AnimeTraverse_Stage;
struct AnimeTraverseClass
{
	AnimeTraverse_Character* P_Character = nullptr;
	AnimeTraverse_Stage* P_Stage = nullptr;
	DimensionCollision* P_Collision = nullptr;
};
class AnimeTraverse : public IGameObject
{
public:
	AnimeTraverse();
	~AnimeTraverse();

	float GetGravity()
	{return M_Gravity;}
private:
	AnimeTraverseClass S_Livblock;

	float M_Gravity = 10.0f;
};

