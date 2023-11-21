#pragma once
class ClairAction_GimmickBox;
struct ClairActionGimmick
{
	ClairAction_GimmickBox* P_GimmickBox[16][9];
};
class ClairAction_Gimmick : public IGameObject
{
public:
	void Create(int GimmickNumber,int X,int Y,Vector3 Position);
private:
	ClairActionGimmick S_Gimmick;
};

