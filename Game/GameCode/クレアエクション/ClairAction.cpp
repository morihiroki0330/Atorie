#include "stdafx.h"
#include "Game.h"
#include "ClairAction.h"

#include "�Q�[���^�C�g���E�Q�[�����U���g/ClairAction_GameTitle.h"
#include "�Q�[���^�C�g���E�Q�[�����U���g/ClairAction_GameResult.h"
#include "�L�����N�^�[/ClairAction_Character.h"
#include "�X�e�[�W/ClairAction_Stage.h"
#include "�M�~�b�N/ClairAction_Gimmick.h"

#include "Operation/Operation.h"
#include "DimensionalEffect/DimensionalEffect.h"
#include "DimensionalElement/DimensionalElement.h"
#include "DimensionalStorage/NumberStorage.h"

ClairAction::ClairAction()
{
	S_Clair.P_GameTitle = NewGO<ClairAction_GameTitle>(0, "gametitle");
}
ClairAction::~ClairAction()
{
	
}
bool ClairAction::Start()
{
	S_Clair.P_Collision = FindGO<DimensionalCollision>("collision");
	S_Clair.P_Fade = FindGO<Fade>("fade");
	S_Clair.P_Mouse = FindGO<Mouse>("mouse");
	S_Clair.P_Mouse->MouseCursorTextureSet("Assets/Sprite/ClairAction/MouseCursor.DDS", 90.0f, 90.0f, false);
	S_Clair.P_Collision->DecisionDataSet(35.0f, 35.0f, S_Clair.P_Mouse->GetMousePosition().x, S_Clair.P_Mouse->GetMousePosition().y, COLLISION_CURSOR, TAG_CURSOR);
	return true;
}
void ClairAction::Update()
{
	S_Clair.P_Collision->DecisionSetPosition(S_Clair.P_Mouse->GetMousePosition().x-27.0f, S_Clair.P_Mouse->GetMousePosition().y+27.0f, COLLISION_CURSOR);
}
void ClairAction::Create(int Number)
{
	switch(Number) {
	case 0:
		DeleteGO(S_Clair.P_GameTitle);
		S_Clair.P_Fade->StartFadeIn();
		S_Clair.P_Stage = NewGO<ClairAction_Stage>(0, "stage");
		S_Clair.P_Gimmick = NewGO<ClairAction_Gimmick>(0, "gimmick");
		S_Clair.P_Character = NewGO<ClairAction_Character>(0, "character");
		break;
	case 1:
		DeleteGO(S_Clair.P_Stage);
		DeleteGO(S_Clair.P_Character);
		S_Clair.P_GameResult = NewGO<ClairAction_GameResult>(0, "gameresult");
		break;
	case 2:
		DeleteGO(S_Clair.P_GameResult);
		S_Clair.P_GameTitle = NewGO<ClairAction_GameTitle>(0, "gametitle");
		break;
	}
}