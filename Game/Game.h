#pragma once
class Game : public IGameObject
{
public:
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender as;
};

