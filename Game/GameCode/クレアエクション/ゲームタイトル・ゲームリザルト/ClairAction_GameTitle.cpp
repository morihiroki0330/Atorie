#include "stdafx.h"
#include "Game.h"
#include "GameCode/クレアエクション/ClairAction.h"
#include "ClairAction_GameTitle.h"
#include "DimensionCollision.h"
#include "Mouse・Controller/Mouse.h"
ClairAction_GameTitle::ClairAction_GameTitle()
{
	M_GameTitleTexture.Init("Assets/Sprite/ClairAction/GameTitle.DDS", 1920.0f, 1080.0f, true);
	S_Button.M_StartButton.Init("Assets/Sprite/ClairAction/StartButton.DDS", 300.0f, 150.0f, true);
	S_Button.M_OptionButton.Init("Assets/Sprite/ClairAction/OptionButton.DDS", 300.0f, 150.0f, true);
	S_Button.M_ExitButton.Init("Assets/Sprite/ClairAction/ExitButton.DDS", 300.0f, 150.0f, true);
}
bool ClairAction_GameTitle::Start()
{
	P_Clair = FindGO<ClairAction>("clair");
	P_Collision = FindGO<DimensionCollision>("collision");
	P_Mouse = FindGO<Mouse>("mouse");

	P_Collision->DecisionDataSet(S_Button.M_StartButton.GetWideAndHeight().x, S_Button.M_StartButton.GetWideAndHeight().y, S_Button.M_StartButtonPosition.x, S_Button.M_StartButtonPosition.y, CA_COLLISION_STARTBUTTON, CA_TAG_NON);
	P_Collision->DecisionDataSet(S_Button.M_OptionButton.GetWideAndHeight().x, S_Button.M_OptionButton.GetWideAndHeight().y, S_Button.M_OptionButtonPosition.x, S_Button.M_OptionButtonPosition.y, CA_COLLISION_OPTIONBUTTON, CA_TAG_NON);
	P_Collision->DecisionDataSet(S_Button.M_ExitButton.GetWideAndHeight().x, S_Button.M_ExitButton.GetWideAndHeight().y, S_Button.M_ExitButtonPosition.x, S_Button.M_ExitButtonPosition.y, CA_COLLISION_EXITBUTTON, CA_TAG_NON);
	return true;
}
void ClairAction_GameTitle::Update()
{
	if (P_Collision->DecisionAndDecisionCollision(CA_COLLISION_CURSOR, CA_COLLISION_STARTBUTTON) && P_Mouse->GetLeftButton())
	{
		P_Clair->Create(FIRST);
	}else {
		if (P_Collision->DecisionAndDecisionCollision(CA_COLLISION_CURSOR, CA_COLLISION_OPTIONBUTTON) && P_Mouse->GetLeftButton())
		{

		}else {
			if (P_Collision->DecisionAndDecisionCollision(CA_COLLISION_CURSOR, CA_COLLISION_EXITBUTTON) && P_Mouse->GetLeftButton())
			{
				exit(EXIT_FAILURE);
			}
		}
	}

	P_Collision->DecisionSetPosition(S_Button.M_StartButtonPosition.x, S_Button.M_StartButtonPosition.y, CA_COLLISION_STARTBUTTON);
	P_Collision->DecisionSetPosition(S_Button.M_OptionButtonPosition.x, S_Button.M_OptionButtonPosition.y, CA_COLLISION_OPTIONBUTTON);
	P_Collision->DecisionSetPosition(S_Button.M_ExitButtonPosition.x, S_Button.M_ExitButtonPosition.y, CA_COLLISION_EXITBUTTON);

	S_Button.M_StartButton.SetPosition(S_Button.M_StartButtonPosition);
	S_Button.M_OptionButton.SetPosition(S_Button.M_OptionButtonPosition);
	S_Button.M_ExitButton.SetPosition(S_Button.M_ExitButtonPosition);

	M_GameTitleTexture.Update();
	S_Button.M_StartButton.Update();
	S_Button.M_OptionButton.Update();
	S_Button.M_ExitButton.Update();
}
void ClairAction_GameTitle::Render(RenderContext& rc)
{
	M_GameTitleTexture.Draw(rc);
	S_Button.M_StartButton.Draw(rc);
	S_Button.M_OptionButton.Draw(rc);
	S_Button.M_ExitButton.Draw(rc);
}