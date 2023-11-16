#include "stdafx.h"
#include "Game.h"
#include "PuzzleBoxPath_GameTitle.h"

#include "GameCode/パズルボックスパス/PuzzleBoxPath.h"

#include "Tool/DimensionalCollision.h"
#include "Mouse・Controller/Mouse.h"

PuzzleBoxPath_GameTitle::PuzzleBoxPath_GameTitle()
{
	M_GameTitleTexture.Init("Assets/Sprite/PuzzleBoxPath/GameTitle.DDS", 1920.0f, 1080.0f,true);
	M_GameTitleButtonTexture.Init("Assets/Sprite/PuzzleBoxPath/GameTitleButton.DDS", 600.0f, 200.f, true);
}
bool PuzzleBoxPath_GameTitle::Start()
{
	P_Puzzle = FindGO<PuzzleBoxPath>("puzzle");
	P_Collision   = FindGO<DimensionalCollision>("collision");
	P_Mouse       = FindGO<Mouse>("mouse");

	P_Collision->DecisionDataSet(600.0f, 200.0f, M_GameTitleButtonPosition.x, M_GameTitleButtonPosition.y, PBP_COLLISION_TITLEBUTTON, PBP_TAG_NON);
	return true;
}
void PuzzleBoxPath_GameTitle::Update()
{
	if (P_Collision->DecisionAndDecisionCollision(PBP_COLLISION_CURSOR,PBP_COLLISION_TITLEBUTTON) && P_Mouse->GetMouseFlag(LEFTBUTTON))
	{P_Puzzle->Create(FIRST);}

	M_GameTitleTexture.Update();
	M_GameTitleButtonTexture.SetPosition(M_GameTitleButtonPosition);
	M_GameTitleButtonTexture.Update();
}
void PuzzleBoxPath_GameTitle::Render(RenderContext& rc)
{
	M_GameTitleTexture.Draw(rc);
	M_GameTitleButtonTexture.Draw(rc);
}