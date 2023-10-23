#include "stdafx.h"
#include "Weather.h"
bool Weather::Start()
{
	M_SkyTexture.WeatherInit("Assets/Sprite/Weather.DDS", 1920.0f, 1080.0f);
	return true;
}

void Weather::Update()
{

	M_SkyTexture.Update();
}

void Weather::Render(RenderContext& rc)
{
	M_SkyTexture.Draw(rc);
}