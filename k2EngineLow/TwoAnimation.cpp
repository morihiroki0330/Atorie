#include "k2EngineLowPreCompile.h"
#include "TwoAnimation.h"
namespace nsK2EngineLow
{
	void TwoAnimation::SetPosition(Vector3 Pos)
	{
		M_Animation.SetPosition(Pos);
	}

	void TwoAnimation::Update()
	{
		M_Animation.Update();
		Animation();
	}

	void TwoAnimation::Render(RenderContext& rc)
	{
		M_Animation.Draw(rc);
	}

	void TwoAnimation::Animation()
	{

	}
}