#include "stdafx.h"
#include "Game.h"
#include "PuzzleBoxPath_GameResult.h"

#include "GameCode/パズルボックスパス/PuzzleBoxPath.h"

#include "Tool/DimensionalCollision.h"
#include "Mouse・Controller/Mouse.h"

bool PuzzleBoxPath_GameResult::Start()
{
	P_Puzzle = FindGO<PuzzleBoxPath>("puzzle");
	P_Collision   = FindGO<DimensionalCollision>("collision");

	if (P_Puzzle->GetFlag(PBP_FLAG_Goal))
	{
		M_GameResultTexture.Init("Assets/Sprite/PuzzleBoxPath/GameResult.DDS", 1920.0f, 1080.0f);
	}else {
		if (P_Puzzle->GetFlag(PBP_FLAG_Over))
		{
			M_GameResultTexture.Init("Assets/Sprite/PuzzleBoxPath/GameOver.DDS", 1920.0f, 1080.0f);
		}
	}
	return true;
}
void PuzzleBoxPath_GameResult::Update()
{
	M_GameResultTexture.Update();
}
void PuzzleBoxPath_GameResult::Render(RenderContext& rc)
{
	M_GameResultTexture.Draw(rc);
}