#include "stdafx.h"
#include "ClairAction_Gimmick.h"

#include "GameCode/クレアエクション/ClairAction.h"
#include "ギミック/ClairAction_GimmickBox.h"

void ClairAction_Gimmick::Create(int GimmickNumber, int X, int Y, Vector3 Position)
{
	switch (GimmickNumber)
	{
	case CA_GIMMICK_BOX:
		S_Gimmick.P_GimmickBox[X][Y] = NewGO<ClairAction_GimmickBox>(0, "gimmickbox");
		S_Gimmick.P_GimmickBox[X][Y]->SetPosition(Position);
		break;
	}
}