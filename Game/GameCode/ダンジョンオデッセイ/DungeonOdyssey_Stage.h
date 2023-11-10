#pragma once

class DungeonOdyssey_Stage : public IGameObject
{
public:
	DungeonOdyssey_Stage();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void FirstMapDataSet();
	void SecondMapDataSet();
	void ThirdMapDataSet();
	void ForthMapDataSet();

	int GetNumber(int Number);
	int GetMapData(int X, int Y, int Number);
	bool WallCheck(int X, int Y, int Direction);
	bool GroundCheck(int X, int Y, int Direction);
	Vector3 GetMapPosition(int X, int Y)
	{return M_MapPosition[X][Y];}
private:
	struct IntVector2
	{
		int x = 0;
		int y = 0;
	};

	SpriteRender M_MapTexture[16][9];

	Vector3 M_MapPosition[16][9];

	int M_MapData[16][9];
	
	Vector2 M_Width       = {0.0f,0.0f};//�}�b�v�̏c����
	Vector2 M_SquareWidth = { 0.0f,0.0f };//�}�X�̏c����

	IntVector2 M_Square          = { 0,0 };//�}�X��
	IntVector2 M_StageUpperLeft  = { 0,0 };//�}�X�̍��㒸�_
	IntVector2 M_StageLowerRight = { 0,0 };//�}�X�̉E�����_
	IntVector2 M_Start           = { 0,0 };//�X�^�[�g�n�_
	IntVector2 M_Goal            = { 0,0 };//�S�[���n�_

	int M_RandDirection = 0;
	bool M_RandCheck = false;
};

