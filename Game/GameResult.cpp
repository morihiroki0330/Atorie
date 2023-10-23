#include "stdafx.h"
#include "GameResult.h"
#include "GameTitle.h"
GameResult::GameResult()
{
	M_GameResultTexture.Init("Assets/Sprite/GameResult.DDS", 1920.0f, 1080.0f);
}
void GameResult::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<GameTitle>(0, "gametitle");
		DeleteGO(this);
	}
	M_GameResultTexture.Update();
}
void GameResult::Render(RenderContext& rc)
{
	M_GameResultTexture.Draw(rc);
}
