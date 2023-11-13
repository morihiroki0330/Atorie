#include "k2EngineLowPreCompile.h"
#include "TwoDimensionalCamera.h"
namespace nsK2EngineLow 
{
	void TwoDimensionalCamera::SetObjectData(Vector3 TagPos)
	{
		S_ObjData.M_TagPos = TagPos;
	}

	void TwoDimensionalCamera::CenterObjectMove(Vector3 CenterPos)
	{
		S_ObjData.M_TagPos = CenterPos;

		S_ObjData.M_tagMoveSpeed.x = S_ObjData.M_TagPos.x - S_ObjData.M_TagPrevPos.x;
		S_ObjData.M_tagMoveSpeed.y = S_ObjData.M_TagPos.y - S_ObjData.M_TagPrevPos.y;

		S_ObjData.M_TagPrevPos.x = S_ObjData.M_TagPos.x;
		S_ObjData.M_TagPrevPos.y = S_ObjData.M_TagPos.y;
	}

	void TwoDimensionalCamera::CenterOffObjectMove(Vector3& CenterOffPos)
	{
		CenterOffPos.x -= S_ObjData.M_tagMoveSpeed.x;
		//CenterOffPos.y += S_ObjData.M_tagMoveSpeed.y;
	}
}