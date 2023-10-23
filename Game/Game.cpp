#include "stdafx.h"
#include "Game.h"
#include "GameResult.h"
#include "Mouse.h"
Game::~Game()
{
	
}

bool Game::Start()
{
	as.Init("Assets/Sprite/Flick/Cursor.DDS", 120.0f, 120.0f);
	return true;
}

void Game::Update()
{
	
}

void Game::Render(RenderContext& rc)
{
	as.Draw(rc);
}
