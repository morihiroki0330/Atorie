#pragma once
class Action;
class Action_GameTitle : public IGameObject
{
public:
	Action_GameTitle();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameTitleTexture;
	Action* P_Action;
};

