#include "stdafx.h"
#include "Game.h"
#include "GameCode/クレアエクション/ClairAction.h"
#include "ClairAction_Character.h"
#include "DimensionCollision.h"
#include "Mouse・Controller/Controller.h"
#include "TwoDimensionalCamera.h"
ClairAction_Character::ClairAction_Character()
{
	M_CharacterTexture.Init("Assets/Sprite/ClairAction/Character.DDS", 100.0f, 100.0f, true);
}
bool ClairAction_Character::Start()
{
	P_Clair = FindGO<ClairAction>("clair");
	P_Collision = FindGO<DimensionCollision>("collision");
	P_Controller = FindGO<Controller>("controller");
	P_Camera = FindGO<TwoDimensionalCamera>("camera");
	return true;
}
void ClairAction_Character::Update()
{
	Move();
	M_CharacterTexture.SetPosition(M_CharacterPosition);
	M_CharacterTexture.Update();
}
void ClairAction_Character::Render(RenderContext& rc)
{
	M_CharacterTexture.Draw(rc);
}

void ClairAction_Character::Move()
{
	Fall();
	Jump();
	Walk();
	Goal();
}
void ClairAction_Character::Fall()
{
	
}
void ClairAction_Character::Jump()
{
	
}
void ClairAction_Character::Walk()
{
	
}
void ClairAction_Character::Goal()
{
	
}
