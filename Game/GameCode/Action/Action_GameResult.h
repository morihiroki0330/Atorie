#pragma once
class Action;
class Action_GameResult : public IGameObject
{
public:
	Action_GameResult();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameResultTexture;
	Action* P_Action = nullptr;
};

