#include "stdafx.h"
#include "Game.h"
#include "GameTitle.h"
#include "GameResult.h"
#include "Mouse.h"
Game::~Game()
{
	
}

bool Game::Start()
{
	P_GameTitle = NewGO<GameTitle>(0, "gametitle");

	P_Mouse = NewGO<Mouse>(0, "mouse");
	return true;
}

void Game::Update()
{
	
}

void Game::Render(RenderContext& rc)
{
}
