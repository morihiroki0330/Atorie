#include "stdafx.h"
#include "DimensionalAnimation.h"
DimensionalAnimation::DimensionalAnimation()
{

}
void DimensionalAnimation::Update()
{

	M_Animation.Update();
}
void DimensionalAnimation::Render(RenderContext& rc)
{
	M_Animation.Draw(rc);
}