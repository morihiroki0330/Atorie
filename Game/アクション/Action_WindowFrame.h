#pragma once
class Action_WindowFrame : public IGameObject
{
public:
	Action_WindowFrame();
	void Render(RenderContext& rc);
private:
	SpriteRender M_FrameTexture;
	DimensionCollision* P_Collision = nullptr;
};

