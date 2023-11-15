#include "stdafx.h"
#include "FlickBlade.h"
#include "MouseÅEController/Mouse.h"
bool FlickBlade::Start()
{
	P_Mouse = FindGO<Mouse>("mouse");
	M_Texture.Init("Assets/Sprite/DungeonOdyssey/GameTitle.DDS", 1920.0f, 1080.0f);
	return true;
}

void FlickBlade::Update()
{
	M_Texture.SetRotation(M_TextureRot);
	M_Texture.Update();
}

void FlickBlade::Render(RenderContext& rc)
{
	if (P_Mouse->GetMouseFlag(FLICK))
	{M_Texture.Draw(rc);}
}
