#pragma once
class Weather : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_SkyTexture;
	int Hour;
	int Minute;
	int Second;
};

