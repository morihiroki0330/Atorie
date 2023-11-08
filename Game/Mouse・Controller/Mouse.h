#pragma once
struct MouseFlag
{
	bool M_LeftButtonFlag = false;
	bool M_RightButtonFlag = false;
};
class Mouse : public IGameObject
{
public:
	void Update();
	void Render(RenderContext& rc);

	void MouseCurSorSetPosition(Vector3& Position);

	void MouseMove();
	void MouseSet();
	void MouseReset();

	void MouseCursorTextureSet(const char* Sprite, const float w, const float h, bool ColorOut = false);
	void MouseCorsorTextureSetCheck();

	void MouseButton();
	
	Vector3 GetMousePosition()
	{return M_MouseCousorPosition; }

	Vector3 GetMouseMoveSpeed()
	{return M_MouseCousorMoveSpeed;}

	bool GetLeftButton()
	{return S_Flag.M_LeftButtonFlag;}

	bool GetRightButton()
	{return S_Flag.M_RightButtonFlag;}
private:
	SpriteRender M_MouseCursorTexture;
	Vector3 M_MouseCousorPosition;
	Vector3 M_MouseCousorMoveSpeed;

	POINT M_CursorPosition = {};
	HWND M_HWnd = GetConsoleWindow();

	Vector2 M_Client = { 1535.0f,863.0f };//ウィンドウの縦横
	Vector2 M_Window = { 1920.0f,1080.0f };//正規ウィンドウの縦横
	Vector2 M_PrevMouse = { 0.0f,0.0f };
	Vector2 M_Delta = { 0.0f,0.0f };//マウスの移動量
	Vector2 M_Converted = { 0.0f,0.0f };

	MouseFlag S_Flag;
};

