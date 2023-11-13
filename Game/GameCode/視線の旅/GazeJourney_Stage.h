#pragma once
class GazeJourney_Stage : public IGameObject
{
public:
	GazeJourney_Stage();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_StageTexture[2];
	Vector3 M_StagePosition[2];
	DimensionCollision* P_Collision = nullptr;
	TwoDimensionalCamera* P_Camera = nullptr;
};

