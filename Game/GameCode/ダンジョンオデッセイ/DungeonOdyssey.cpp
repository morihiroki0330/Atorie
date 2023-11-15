#include "stdafx.h"
#include "Game.h"
#include "DungeonOdyssey.h"
#include "ゲームタイトル・ゲームリザルト/DungeonOdyssey_GameTitle.h"
#include "ゲームタイトル・ゲームリザルト/DungeonOdyssey_GameResult.h"
#include "キャラクター/DungeonOdyssey_Character.h"
#include "ステージ/DungeonOdyssey_Stage.h"
DungeonOdyssey::DungeonOdyssey()
{
	S_Dungeon.P_GameTitle = NewGO<DungeonOdyssey_GameTitle>(0, "gametitle");
}
DungeonOdyssey::~DungeonOdyssey()
{
	DeleteGO(S_Dungeon.P_GameTitle);
	DeleteGO(S_Dungeon.P_GameResult);
	DeleteGO(S_Dungeon.P_Stage);
	DeleteGO(S_Dungeon.P_Character);
}
void DungeonOdyssey::Create(int Number)
{
	switch (Number)
	{
	case FIRST:
		DeleteGO(S_Dungeon.P_GameTitle);
		S_Dungeon.P_Stage     = NewGO<DungeonOdyssey_Stage>(0, "stage");
		S_Dungeon.P_Character = NewGO<DungeonOdyssey_Character>(0, "character");
		break;
	case SECOND:
		DeleteGO(S_Dungeon.P_Stage);
		DeleteGO(S_Dungeon.P_Character);
		S_Dungeon.P_GameResult = NewGO<DungeonOdyssey_GameResult>(0, "gameresult");
		break;
	case THIRD:
		DeleteGO(S_Dungeon.P_GameResult);
		S_Dungeon.P_GameTitle  = NewGO<DungeonOdyssey_GameTitle>(0, "gametitle");
		break;
	}
}