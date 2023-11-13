#pragma once
class GazeJourney;
class GazeJourney_GameTitle : public IGameObject
{
public:
	GazeJourney_GameTitle();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameTitleTexture;
	GazeJourney* P_Gaze = nullptr;
};

