#include "stdafx.h"
#include "Action.h"
#include "Action_WindowFrame.h"
Action_WindowFrame::Action_WindowFrame()
{
	M_FrameTexture.Init("Assets/Sprite/Action/WindowFrame.DDS", 1920.0f, 1080.0f,true);
}
void Action_WindowFrame::Render(RenderContext& rc)
{
	M_FrameTexture.Draw(rc);
}