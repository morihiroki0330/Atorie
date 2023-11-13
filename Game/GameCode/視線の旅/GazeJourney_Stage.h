#pragma once
class GazeJourney_Stage : public IGameObject
{
public:
	GazeJourney_Stage();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_StageTexture;
	Vector3 M_StagePosition;
	DimensionCollision* P_Collision = nullptr;
	TwoDimensionalCamera* P_Camera = nullptr;
};

