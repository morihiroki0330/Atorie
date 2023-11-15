#include "stdafx.h"
#include "Game.h"
#include "ClairAction.h"
#include "ゲームタイトル・ゲームリザルト/ClairAction_GameTitle.h"
#include "ゲームタイトル・ゲームリザルト/ClairAction_GameResult.h"
#include "キャラクター/ClairAction_Character.h"
#include "ステージ・ギミック/ClairAction_Stage.h"
#include "ステージ・ギミック/ClairAction_Gimmick.h"
#include "DimensionCollision.h"
#include "TwoDimensionalCamera.h"
#include "Mouse・Controller/Mouse.h"
ClairAction::ClairAction()
{
	S_Clair.P_Collision = NewGO<DimensionCollision>(0, "collision");
	S_Clair.P_Camera = NewGO<TwoDimensionalCamera>(0, "camera");
	S_Clair.P_GameTitle = NewGO<ClairAction_GameTitle>(0, "gametitle");
}
ClairAction::~ClairAction()
{
	
}
bool ClairAction::Start()
{
	S_Clair.P_Mouse = FindGO<Mouse>("mouse");
	S_Clair.P_Mouse->MouseCursorTextureSet("Assets/Sprite/ClairAction/MouseCursor.DDS", 90.0f, 90.0f, false);
	S_Clair.P_Collision->DecisionDataSet(90.0f, 90.0f, S_Clair.P_Mouse->GetMousePosition().x, S_Clair.P_Mouse->GetMousePosition().y, CA_COLLISION_CURSOR, CA_TAG_CURSOR);
	return true;
}
void ClairAction::Update()
{
	S_Clair.P_Collision->DecisionSetPosition(S_Clair.P_Mouse->GetMousePosition().x, S_Clair.P_Mouse->GetMousePosition().y, CA_COLLISION_CURSOR);
}
void ClairAction::Create(int Number)
{
	switch(Number) {
	case FIRST:
		DeleteGO(S_Clair.P_GameTitle);
		S_Clair.P_Stage = NewGO<ClairAction_Stage>(0, "stage");
		S_Clair.P_Character = NewGO<ClairAction_Character>(0, "character");
		break;
	case SECOND:
		DeleteGO(S_Clair.P_Stage);
		DeleteGO(S_Clair.P_Character);
		S_Clair.P_Collision->Reset();
		S_Clair.P_GameResult = NewGO<ClairAction_GameResult>(0, "gameresult");
		break;
	case THIRD:
		DeleteGO(S_Clair.P_GameResult);
		S_Clair.P_GameTitle = NewGO<ClairAction_GameTitle>(0, "gametitle");
		break;
	}
}