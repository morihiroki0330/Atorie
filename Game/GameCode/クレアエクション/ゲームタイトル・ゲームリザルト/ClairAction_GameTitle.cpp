#include "stdafx.h"
#include "Game.h"
#include "ClairAction_GameTitle.h"

#include "GameCode/クレアエクション/ClairAction.h"

#include "Operation/Operation.h"
#include "DimensionalEffect/DimensionalEffect.h"
#include "DimensionalElement/DimensionalElement.h"
#include "DimensionalStorage/NumberStorage.h"
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
	P_Collision = FindGO<DimensionalCollision>("collision");
	P_Fade = FindGO<Fade>("fade");
	P_Mouse = FindGO<Mouse>("mouse");

	P_Collision->DecisionDataSet(S_Button.M_StartButton.GetWideAndHeight().x, S_Button.M_StartButton.GetWideAndHeight().y, S_Button.M_StartButtonPosition.x, S_Button.M_StartButtonPosition.y, COLLISION_STARTBUTTON, TAG_NON);
	P_Collision->DecisionDataSet(S_Button.M_OptionButton.GetWideAndHeight().x, S_Button.M_OptionButton.GetWideAndHeight().y, S_Button.M_OptionButtonPosition.x, S_Button.M_OptionButtonPosition.y, COLLISION_OPTIONBUTTON, TAG_NON);
	P_Collision->DecisionDataSet(S_Button.M_ExitButton.GetWideAndHeight().x, S_Button.M_ExitButton.GetWideAndHeight().y, S_Button.M_ExitButtonPosition.x, S_Button.M_ExitButtonPosition.y, COLLISION_EXITBUTTON, TAG_NON);
	return true;
}
void ClairAction_GameTitle::Update()
{
	Button();
	ButtonAfter();

	P_Collision->DecisionSetPosition(S_Button.M_StartButtonPosition.x, S_Button.M_StartButtonPosition.y, COLLISION_STARTBUTTON);
	P_Collision->DecisionSetPosition(S_Button.M_OptionButtonPosition.x, S_Button.M_OptionButtonPosition.y, COLLISION_OPTIONBUTTON);
	P_Collision->DecisionSetPosition(S_Button.M_ExitButtonPosition.x, S_Button.M_ExitButtonPosition.y, COLLISION_EXITBUTTON);

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

void ClairAction_GameTitle::Button()
{
	if (P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_STARTBUTTON) && P_Mouse->GetMouseFlag(LEFTBUTTON))
	{
		if (!M_StartFlag && !M_OptionFlag && !M_ExitFlag)
		{
			P_Fade->StartFadeOut();
			M_StartFlag = true;
		}
	}else {
		if (P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_OPTIONBUTTON) && P_Mouse->GetMouseFlag(LEFTBUTTON))
		{
			if (!M_StartFlag && !M_OptionFlag && !M_ExitFlag)
			{
				M_OptionFlag = true;
			}
		}else {
			if (P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_EXITBUTTON) && P_Mouse->GetMouseFlag(LEFTBUTTON))
			{
				if (!M_StartFlag && !M_OptionFlag && !M_ExitFlag)
				{
					P_Fade->StartFadeOut();
					M_ExitFlag = true;
				}
			}
		}
	}
}
void ClairAction_GameTitle::ButtonAfter()
{
	if (!P_Fade->IsFade())
	{
		if (M_StartFlag)
		{
			P_Clair->Create(0);
		}else {
			if (M_OptionFlag)
			{

			}else {
				if (M_ExitFlag)
				{
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}