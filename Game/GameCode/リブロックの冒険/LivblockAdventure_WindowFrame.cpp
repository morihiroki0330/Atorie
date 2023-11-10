#include "stdafx.h"
#include "LivblockAdventure.h"
#include "LivblockAdventure_WindowFrame.h"
LivblockAdventure_WindowFrame::LivblockAdventure_WindowFrame()
{
	M_FrameTexture.Init("Assets/Sprite/LivblockAdventure/WindowFrame.DDS", 1920.0f, 1080.0f,true);
}
void LivblockAdventure_WindowFrame::Render(RenderContext& rc)
{
	M_FrameTexture.Draw(rc);
}