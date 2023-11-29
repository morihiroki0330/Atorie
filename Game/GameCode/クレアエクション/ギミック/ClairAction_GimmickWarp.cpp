#include "stdafx.h"
#include "ClairAction_GimmickWarp.h"
#include "GameCode/クレアエクション/ClairAction.h"
#include "DimensionalElement/DimensionalCollision.h"
#include "DimensionalStorage/NumberStorage.h"
ClairAction_GimmickWarp::ClairAction_GimmickWarp()
{
	M_WarpTexture[BLACKHOLE].Init("Assets/Sprite/ClairAction/GimmickBox.DDS", 120.0f, 120.0f, true);
	M_WarpTexture[WHITEHOLE].Init("Assets/Sprite/ClairAction/GimmickBox.DDS", 120.0f, 120.0f, true);
}
bool ClairAction_GimmickWarp::Start()
{
	P_Collision = FindGO<DimensionalCollision>("collision");
	P_Clair = FindGO<ClairAction>("clair");
	P_Collision->DecisionDataSet(M_WarpTexture[BLACKHOLE].GetWideAndHeight().x, M_WarpTexture[BLACKHOLE].GetWideAndHeight().y, M_WarpPosition[BLACKHOLE].x, M_WarpPosition[BLACKHOLE].y, COLLISION_BOX, TAG_NON, M_CollisionNumner[BLACKHOLE]);
	P_Collision->DecisionDataSet(M_WarpTexture[BLACKHOLE].GetWideAndHeight().x, M_WarpTexture[BLACKHOLE].GetWideAndHeight().y, M_WarpPosition[BLACKHOLE].x, M_WarpPosition[BLACKHOLE].y, COLLISION_BOX, TAG_NON, M_CollisionNumner[BLACKHOLE]);
}
void ClairAction_GimmickWarp::Update()
{
	M_WarpTexture[BLACKHOLE].Update();
	M_WarpTexture[WHITEHOLE].Update();
}
void ClairAction_GimmickWarp::Render(RenderContext& rc)
{
	M_WarpTexture[BLACKHOLE].Draw(rc);
	M_WarpTexture[WHITEHOLE].Draw(rc);
}