#include "stdafx.h"
#include "GameTitle.h"
#include "Game.h"
#include "Mouse.h"
GameTitle::GameTitle()
{
	M_GameTitleTexture.Init("Assets/Sprite/Flick/GameTitle.DDS", 1920.0f, 1080.0f);
	M_StartButtonTexture.Init("Assets/Sprite/Flick/StartButton.DDS", 500.0f, 150.0f);
	M_StartButtonCollision.DecisionDataSet(500.0f, 150.0f, M_StartButtonPosition.x, M_StartButtonPosition.y, 1);

}
bool GameTitle::Start()
{
	P_Mouse = FindGO<Mouse>("mouse");
	M_StartButtonCollision.DecisionDataSet(P_Mouse->M_MouseCollision.GetDecisionData(1), 2);
	return true;
}
void GameTitle::Update()
{
	if (M_StartButtonCollision.DecisionCollision(2, 1) && GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		DeleteGO(this);
	}
	M_StartButtonCollision.DecisionSetPosition(M_StartButtonPosition.x, M_StartButtonPosition.y, 1);
	M_StartButtonCollision.DecisionSetPosition(P_Mouse->GetMousePosition().x, P_Mouse->GetMousePosition().y, 2);
	
	M_StartButtonTexture.SetPosition(M_StartButtonPosition);
	M_StartButtonTexture.Update();
	M_GameTitleTexture.Update();
}
void GameTitle::Render(RenderContext& rc)
{
	M_GameTitleTexture.Draw(rc);
	M_StartButtonTexture.Draw(rc);
}
