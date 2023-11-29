#pragma once
class ClairAction_GimmickBox;
class ClairAction_GimmickClock;
struct ClairActionGimmick
{
	ClairAction_GimmickBox* P_GimmickBox[16][9];
	ClairAction_GimmickClock* P_GimmickClock;
};
class ClairAction_Gimmick : public IGameObject
{
public:
	void Create(int GimmickNumber,int X,int Y,Vector3 Position);
private:
	ClairActionGimmick S_Gimmick;
};

