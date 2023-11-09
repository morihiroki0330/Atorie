#pragma once
namespace nsK2EngineLow
{
	struct ObjData
	{
		Vector2 M_TagPos       = { 0.0f,0.0f };
		Vector2 M_TagPrevPos   = { 0.0f,0.0f };
		Vector2 M_tagMoveSpeed = { 0.0f,0.0f };
	};
	class TwoDimensionalCamera : public IGameObject
	{
	public:
		void SetObjectData(Vector2 TagPos);
		void CenterObjectMove(Vector2 CenterPos);
		void CenterOffObjectMove(Vector2& CenterOffPos);
	private:
		ObjData S_ObjData;
	};
}

