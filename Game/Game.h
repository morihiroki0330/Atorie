#pragma once
class GameTitle;

class Mouse;
class Game : public IGameObject
{
public:
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	GameTitle* P_GameTitle;

	Mouse* P_Mouse;
};

