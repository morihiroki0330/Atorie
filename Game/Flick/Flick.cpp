#include "stdafx.h"
#include "Game.h"
#include "Flick.h"
#include "Flick_GameTitle.h"
#include "Flick_GameResult.h"
#include "Flick_Stage.h"
#include "Flick_Box.h"
#include "DimensionCollision.h"
#include "MouseÅEController/Mouse.h"
Flick::Flick()
{
	S_Flick.P_Collision = NewGO<DimensionCollision>(0, "collision");
	S_Flick.P_GameTitle = NewGO<Flick_GameTitle>(0, "flick_gametitle");
}
Flick::~Flick()
{
	DeleteGO(S_Flick.P_GameTitle);
	DeleteGO(S_Flick.P_GameResult);
	DeleteGO(S_Flick.P_Collision);
}
bool Flick::Start()
{
	S_Flick.P_Mouse = FindGO<Mouse>("mouse");
	S_Flick.P_Mouse->MouseCursorTextureSet("Assets/Sprite/Flick/MouseCursor.DDS", 90.0f, 90.0f, true);
	S_Flick.P_Collision->DecisionDataSet(150.0f, 150.0f, S_Flick.P_Mouse->GetMousePosition().x, S_Flick.P_Mouse->GetMousePosition().y, FLICK_COLLISION_CURSOR, FLICK_TAG_NON);
	return true;
}
void Flick::Update()
{
	S_Flick.P_Collision->DecisionSetPosition(S_Flick.P_Mouse->GetMousePosition().x, S_Flick.P_Mouse->GetMousePosition().y, FLICK_COLLISION_CURSOR);
}
void Flick::Create(int Number)
{
	switch (Number)
	{
	case FIRST:
		DeleteGO(S_Flick.P_GameTitle);
		S_Flick.P_Stage = NewGO<Flick_Stage>(0, "flick_stage");
		S_Flick.P_Box = NewGO<Flick_Box>(0, "flick_box");
		break;
	case SECOND:
		DeleteGO(S_Flick.P_Stage);
		DeleteGO(S_Flick.P_Box);
		break;
	case THIRD:
		
		break;
	}
}