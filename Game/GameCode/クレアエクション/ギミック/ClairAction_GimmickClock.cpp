#include "stdafx.h"
#include "ClairAction_GimmickClock.h"

#include "DimensionalElement/DimensionalCollision.h"
#include "MouseÅEController/Mouse.h"

ClairAction_GimmickClock::ClairAction_GimmickClock()
{
	S_Clock.ClockInit();
}
void ClairAction_GimmickClock::Upadte()
{
	S_Clock.ClockUpdate();
}
void ClairAction_GimmickClock::Render(RenderContext& rc)
{
	S_Clock.ClockRender(rc);
}