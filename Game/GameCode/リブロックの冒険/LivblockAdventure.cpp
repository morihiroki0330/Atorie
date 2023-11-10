#include "stdafx.h"
#include "Game.h"
#include "LivblockAdventure.h"
#include "LivblockAdventure_GameTitle.h"
#include "LivblockAdventure_GameResult.h"
#include "LivblockAdventure_Character.h"
#include "LivblockAdventure_Stage.h"
#include "LivblockAdventure_WindowFrame.h"
#include "DimensionCollision.h"
LivblockAdventure::LivblockAdventure()
{
	S_Livblock.P_Collision   = NewGO<DimensionCollision>(0, "collision");
	S_Livblock.P_WindowFrame = NewGO<LivblockAdventure_WindowFrame>(0, "windowframe");
	S_Livblock.P_GameTitle   = NewGO<LivblockAdventure_GameTitle>(0, "gametitle");
}
LivblockAdventure::~LivblockAdventure()
{
	DeleteGO(S_Livblock.P_GameTitle);
	DeleteGO(S_Livblock.P_GameResult);
	DeleteGO(S_Livblock.P_Stage);
	DeleteGO(S_Livblock.P_Character);
	DeleteGO(S_Livblock.P_WindowFrame);
	DeleteGO(S_Livblock.P_Collision);
}
void LivblockAdventure::Create(int Number)
{
	switch (Number)
	{
	case FIRST:
		DeleteGO(S_Livblock.P_GameTitle);
		S_Livblock.P_Stage     = NewGO<LivblockAdventure_Stage>(0, "stage");
		S_Livblock.P_Character = NewGO<LivblockAdventure_Character>(0, "character");
		break;
	case SECOND:
		DeleteGO(S_Livblock.P_Stage);
		DeleteGO(S_Livblock.P_Character);
		S_Livblock.P_Collision->Reset();
		S_Livblock.P_GameResult = NewGO<LivblockAdventure_GameResult>(0, "gameresult");
		break;
	case THIRD:
		DeleteGO(S_Livblock.P_GameResult);
		S_Livblock.P_GameTitle = NewGO<LivblockAdventure_GameTitle>(0, "gametitle");
		break;
	}
}