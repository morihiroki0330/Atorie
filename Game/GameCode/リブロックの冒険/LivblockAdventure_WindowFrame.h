#pragma once
class LivblockAdventure_WindowFrame : public IGameObject
{
public:
	LivblockAdventure_WindowFrame();
	void Render(RenderContext& rc);
private:
	SpriteRender M_FrameTexture;
};

