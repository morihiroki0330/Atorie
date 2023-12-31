#include "stdafx.h"
#include "ClairAction_Gimmick.h"

#include "ClairAction_GimmickBox.h"
#include "ClairAction_GimmickClock.h"
#include "DimensionalStorage/NumberStorage.h"

void ClairAction_Gimmick::Create(int GimmickNumber, int X, int Y, Vector3 Position)
{
	switch (GimmickNumber)
	{
	case GIMMICK_BOX:
		S_Gimmick.P_GimmickBox[X][Y] = NewGO<ClairAction_GimmickBox>(0, "gimmickbox");
		S_Gimmick.P_GimmickBox[X][Y]->SetPosition(Position);
		break;
	}
	S_Gimmick.P_GimmickClock = NewGO<ClairAction_GimmickClock>(0, "gimmickclock");
}