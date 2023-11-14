#pragma once
class ClairAction;
class Mouse;
struct ClairActionButton
{
	SpriteRender M_StartButton;
	SpriteRender M_OptionButton;
	SpriteRender M_ExitButton;

	Vector3 M_StartButtonPosition = { 0.0f,100.0f,0.0f };
	Vector3 M_OptionButtonPosition = { 0.0f,-80.0f,0.0f };
	Vector3 M_ExitButtonPosition = { 0.0f,-260.0f,0.0f };
};
class ClairAction_GameTitle : public IGameObject
{
public:
	ClairAction_GameTitle();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_GameTitleTexture;
	ClairActionButton S_Button;

	ClairAction* P_Clair = nullptr;
	DimensionCollision* P_Collision = nullptr;
	Mouse* P_Mouse = nullptr;
};

