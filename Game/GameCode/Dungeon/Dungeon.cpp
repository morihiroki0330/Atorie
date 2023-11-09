#include "stdafx.h"
#include "Game.h"
#include "Dungeon.h"
#include "Dungeon_GameTitle.h"
#include "Dungeon_GameResult.h"
#include "Dungeon_Character.h"
#include "Dungeon_Stage.h"
Dungeon::Dungeon()
{
	S_Dungeon.P_GameTitle = NewGO<Dungeon_GameTitle>(0, "dungeon_gametitle");
}
Dungeon::~Dungeon()
{
	DeleteGO(S_Dungeon.P_GameTitle);
	DeleteGO(S_Dungeon.P_GameResult);
	DeleteGO(S_Dungeon.P_Stage);
	DeleteGO(S_Dungeon.P_Character);
}
void Dungeon::Create(int Number)
{
	switch (Number)
	{
	case FIRST:
		DeleteGO(S_Dungeon.P_GameTitle);
		S_Dungeon.P_Stage     = NewGO<Dungeon_Stage>(0, "dungeon_stage");
		S_Dungeon.P_Character = NewGO<Dungeon_Character>(0, "dungeon_character");
		break;
	case SECOND:
		DeleteGO(S_Dungeon.P_Stage);
		DeleteGO(S_Dungeon.P_Character);
		S_Dungeon.P_GameResult = NewGO<Dungeon_GameResult>(0, "dungeon_gameresult");
		break;
	case THIRD:
		DeleteGO(S_Dungeon.P_GameResult);
		S_Dungeon.P_GameTitle  = NewGO<Dungeon_GameTitle>(0, "dungeon_gametitle");
		break;
	}
}