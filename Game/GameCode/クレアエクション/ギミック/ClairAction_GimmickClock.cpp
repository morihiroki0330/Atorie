#include "stdafx.h"
#include "ClairAction_GimmickClock.h"

#include "Operation/Operation.h"
#include "DimensionalEffect/DimensionalEffect.h"
#include "DimensionalElement/DimensionalElement.h"
#include "DimensionalStorage/NumberStorage.h"

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