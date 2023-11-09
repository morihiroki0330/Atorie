#include "stdafx.h"
#include "Game.h"
#include "DragAndDraw.h"
#include "DragAndDraw_GameResult.h"
#include "MouseÅEController/Mouse.h"
bool DragAndDraw_GameResult::Start()
{
	P_DragAndDraw = FindGO<DragAndDraw>("dad");
	P_Collision   = FindGO<DimensionCollision>("collision");

	if (P_DragAndDraw->GetFlag(DAD_FLAG_Goal))
	{
		M_GameResultTexture.Init("Assets/Sprite/DragAndDraw/GameResult.DDS", 1920.0f, 1080.0f);
	}else {
		if (P_DragAndDraw->GetFlag(DAD_FLAG_Over))
		{
			M_GameResultTexture.Init("Assets/Sprite/DragAndDraw/GameOver.DDS", 1920.0f, 1080.0f);
		}
	}
	return true;
}
void DragAndDraw_GameResult::Update()
{
	M_GameResultTexture.Update();
}
void DragAndDraw_GameResult::Render(RenderContext& rc)
{
	M_GameResultTexture.Draw(rc);
}