#include "stdafx.h"
#include "Game.h"
#include "Action.h"
#include "Action_GameTitle.h"
#include "Action_GameResult.h"
#include "Action_Character.h"
#include "Action_Stage.h"
#include "Action_WindowFrame.h"
#include "DimensionCollision.h"
Action::Action()
{
	S_Action.P_Collision = NewGO<DimensionCollision>(0, "collision");
	S_Action.P_WindowFrame = NewGO<Action_WindowFrame>(0, "action_windowframe");
	S_Action.P_GameTitle = NewGO<Action_GameTitle>(0, "action_gametitle");
}
Action::~Action()
{
	DeleteGO(S_Action.P_GameTitle);
	DeleteGO(S_Action.P_GameResult);
	DeleteGO(S_Action.P_Stage);
	DeleteGO(S_Action.P_Character);
	DeleteGO(S_Action.P_WindowFrame);
	DeleteGO(S_Action.P_Collision);
}
void Action::Create(int Number)
{
	switch (Number)
	{
	case FIRST:
		DeleteGO(S_Action.P_GameTitle);
		S_Action.P_Stage = NewGO<Action_Stage>(0, "action_stage");
		S_Action.P_Character = NewGO<Action_Character>(0, "action_character");
		break;
	case SECOND:
		DeleteGO(S_Action.P_Stage);
		DeleteGO(S_Action.P_Character);
		S_Action.P_Collision->Reset();
		S_Action.P_GameResult = NewGO<Action_GameResult>(0, "action_gameresult");
		break;
	case THIRD:
		DeleteGO(S_Action.P_GameResult);
		S_Action.P_GameTitle = NewGO<Action_GameTitle>(0, "action_gametitle");
		break;
	}
}