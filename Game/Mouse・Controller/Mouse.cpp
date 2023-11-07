#include "stdafx.h"
#include "Mouse.h"
void Mouse::Update()
{
	M_HWnd = GetConsoleWindow();
    GetCursorPos(&M_CursorPosition);
    ScreenToClient(M_HWnd, &M_CursorPosition);
    MouseSet();
    MouseCorsorTextureSetCheck();
	MouseButton();
    MouseCurSorSetPosition(M_MouseCousorPosition);
    M_MouseCursorTexture.SetPosition(M_MouseCousorPosition);
    M_MouseCursorTexture.Update();
}
void Mouse::Render(RenderContext& rc)
{
    M_MouseCursorTexture.Draw(rc);
}

void Mouse::MouseCurSorSetPosition(Vector3& Position)
{
	Position.x = (M_Mouse.x - (M_Window.x / 2));
	Position.y = (M_Mouse.y - (M_Window.y / 2)) * -1;
}

void Mouse::MouseMove()
{
	M_Delta.x = M_Mouse.x - M_PrevMouse.x;
	M_Delta.y = M_Mouse.y - M_PrevMouse.y;

	M_PrevMouse.x = M_Mouse.x;
	M_PrevMouse.y = M_Mouse.y;
}
void Mouse::MouseSet()
{
	M_Converted.x = (M_CursorPosition.x * M_Window.x) / M_Client.x;
	M_Converted.y = (M_CursorPosition.y * M_Window.y) / M_Client.y;

	M_Mouse.x = M_Converted.x;
	M_Mouse.y = M_Converted.y;
}
void Mouse::MouseReset()
{
	SetCursorPos(M_Client.x / 2, M_Client.y / 2);
}

void Mouse::MouseCursorTextureSet(const char* Sprite, const float w, const float h, bool ColorOut)
{
    M_MouseCursorTexture.Init(Sprite, w, h, ColorOut);
}
void Mouse::MouseCorsorTextureSetCheck()
{
	if (M_MouseCursorTexture.GetInitFlag())
	{
		ShowCursor(false);
	}else {
		if (!M_MouseCursorTexture.GetInitFlag())
		{
			ShowCursor(true);
		}
	}
}

void Mouse::MouseButton()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{S_Flag.M_LeftButtonFlag = true;}
	else
	{S_Flag.M_LeftButtonFlag = false;}

	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{S_Flag.M_RightButtonFlag = true;}
	else
	{S_Flag.M_RightButtonFlag = false;}
}