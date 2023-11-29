#pragma once
class ClairAction;
class DimensionalCollision;
enum WarpType
{
	BLACKHOLE,
	WHITEHOLE
};
class ClairAction_GimmickWarp : public IGameObject
{
public:
	ClairAction_GimmickWarp();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_WarpTexture[2];
	Vector3 M_WarpPosition[2];
	DimensionalCollision* P_Collision = nullptr;
	ClairAction* P_Clair = nullptr;
	int M_CollisionNumner[2];
	int M_CoolTime = 0;
	bool M_WarpFlag = false;
};

