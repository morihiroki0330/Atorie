#pragma once
class DimensionalAnimation : public IGameObject
{
public:
	DimensionalAnimation();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_Animation;
	Texture M_Animations[16];
	int M_AnimationFrame = 0;
	int M_AnimationCount = 0;
};

