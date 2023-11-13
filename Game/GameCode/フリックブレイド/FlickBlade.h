#pragma once
class Mouse;
class FlickBlade : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_Texture;
	Quaternion M_TextureRot;
	Mouse* P_Mouse;
	bool M_Flick = false;
};