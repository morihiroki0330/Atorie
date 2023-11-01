#include "k2EngineLowPreCompile.h"
#include "SpriteRender.h"

namespace nsK2EngineLow
{

	void SpriteRender::Init
	(
		const char* Sprite,
		const float w,
		const float h,
		bool ColorOut,
		AlphaBlendMode alphaBlendMode
	)
	{
		if (ColorOut)
		{
			InitData.m_fxFilePath = "Assets/shader/ColorOut.fx";
		}else {
		if (!ColorOut)
		{
			InitData.m_fxFilePath = "Assets/shader/sprite.fx";
		}
		}
		InitData.m_vsEntryPointFunc = "VSMain";
		InitData.m_psEntryPoinFunc = "PSMain";
		
		InitData.m_ddsFilePath[0] = Sprite;

		InitData.m_width = static_cast<UINT>(w);
		InitData.m_height = static_cast<UINT>(h);

		InitData.m_alphaBlendMode = alphaBlendMode;

		M_InitFlag = true;

		m_sprite.Init(InitData);
	}

	void SpriteRender::WeatherInit
	(
		const char* Sprite,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		InitData.m_fxFilePath = "Assets/shader/Weather.fx";

		InitData.m_vsEntryPointFunc = "VSMain";
		InitData.m_psEntryPoinFunc = "PSMain";

		InitData.m_ddsFilePath[0] = Sprite;

		InitData.m_width = static_cast<UINT>(w);
		InitData.m_height = static_cast<UINT>(h);

		InitData.m_alphaBlendMode = alphaBlendMode;

		m_sprite.Init(InitData);
	}

	void SpriteRender::Draw(RenderContext& rc)
	{
		g_renderingEngine->InRenderObject(this);
	}
	
	void SpriteRender::OnRender2D(RenderContext& rc)
	{
		m_sprite.Draw(rc);
	}
}

