#pragma once
class GameTitle;
class GameResult;

class Stage;

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

	Stage* P_Stage;

	Mouse* P_Mouse;
};

