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
	
}

void FlickBlade::Render(RenderContext& rc)
{
	if (P_Mouse->GetFlick())
	{
		M_Texture.Draw(rc);
	}
}
