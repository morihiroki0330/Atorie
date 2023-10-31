#pragma once
class Action_GameTitle;
class Action_GameResult;
class Action_Character;
class Action_Stage;
class Action_WindowFrame;
struct ActionClass
{
	Action_GameTitle* P_GameTitle;
	Action_GameResult* P_GameResult;
	Action_Character* P_Character;
	Action_Stage* P_Stage;
	Action_WindowFrame* P_WindowFrame;
};
class Action : public IGameObject
{
public:
	Action();
	~Action();
	void Create(int Number);
private:
	ActionClass S_Action;
	SpriteRender M_BackTexture;
	int M_Number = FIRST;
};

