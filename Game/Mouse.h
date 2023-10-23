#pragma once
class Mouse : public IGameObject
{
public:
	Mouse();
	void Update();
	void MouseCurSorSetPosition(Vector3 &Position);
	void MouseMove();
	Vector3 GetMousePosition() { return M_MouseCousorPosition; }
	Vector2 GetMouseDelta() { return M_DeltaPosition; }

	void MouseCursorTextureSet(const char* Sprite,const float w, const float h,bool ColorOut = false);
	void MouseCorsorTextureSetCheck();
	void Render(RenderContext& rc);
	DimensionCollision M_MouseCollision;
private:
	SpriteRender M_MouseCursorTexture;
	Vector3 M_MouseCousorPosition;
	bool M_MouseCursorTextureFlag= false;
	POINT CursorPos;
	HWND HWnd;

	Vector2 M_PrevMousePosition;
	Vector2 M_DeltaPosition;
	Vector2 M_MousePosition;
	Vector2 M_Window;
	Vector2 M_Converted;

};

