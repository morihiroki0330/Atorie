#pragma once
struct StageGimmick
{

};
class ClairAction_Stage : public IGameObject
{
public:
	ClairAction_Stage();
	bool Start();
	void Render(RenderContext& rc);

	bool MapSet();
private:
	SpriteRender M_BackGroundTexture;
	SpriteRender M_StageTileTexture[16][9];
	Vector3 M_StagePosition = { 0.0f,0.0f,0.0f };
	DimensionCollision* P_Collision = nullptr;
	const char* M_FilePath = nullptr;
	char M_Value[256];
	int X = 99;
	int Y = 99;
	int MapType = 99;
};

