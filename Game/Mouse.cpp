#include "stdafx.h"
#include "Mouse.h"
Mouse::Mouse()
{
    M_Window.x = 1920.0f;
    M_Window.y = 1080.0f;
    M_MouseCollision.DecisionDataSet(15.0f, 15.0f, M_MousePosition.x, M_MouseCousorPosition.y, 1);
    MouseCursorTextureSet("Assets/Sprite/Flick/Cursor.DDS","Assets/Sprite/Flick/CursorColor.DDS","Assets/Sprite/Flick/CursorGreenBack.DDS",90.0f,90.0f);
}
void Mouse::Update()
{
    HWnd = GetConsoleWindow();
    GetCursorPos(&CursorPos);
    ScreenToClient(HWnd, &CursorPos);

    M_Converted.x = (CursorPos.x * M_Window.x) / 1535;
    M_Converted.y = (CursorPos.y * M_Window.y) / 863;
    
    M_MousePosition.x = M_Converted.x;
    M_MousePosition.y = M_Converted.y;

    MouseCorsorTextureSetCheck();
    MouseCurSorSetPosition(M_MouseCousorPosition);
    M_MouseCursorTexture.SetPosition(M_MouseCousorPosition);
    M_MouseCursorTexture.Update();
}
void Mouse::MouseMove()
{
    M_DeltaPosition.x = M_MousePosition.x - M_PrevMousePosition.x;
    M_DeltaPosition.y = M_MousePosition.y - M_PrevMousePosition.y;

    M_PrevMousePosition.x = M_MousePosition.x;
    M_PrevMousePosition.y = M_MousePosition.y;
}
void Mouse::MouseCurSorSetPosition(Vector3 &Position)
{
    Position.x = (M_MousePosition.x - (M_Window.x / 2));
    Position.y = (M_MousePosition.y - (M_Window.y / 2)) * -1;
}

void Mouse::MouseCursorTextureSet(const char* Sprite,const char* Color,const char* GreenBack, const float w, const float h)
{
    M_MouseCursorTexture.ColorOutInit(Sprite,Color,GreenBack,w, h);
    M_MouseCursorTextureFlag = true;
}
void Mouse::MouseCursorTextureSet(const char* Sprite,const float w, const float h)
{
    M_MouseCursorTexture.Init(Sprite,w, h);
    M_MouseCursorTextureFlag = true;
}
void Mouse::MouseCorsorTextureSetCheck()
{
    if (M_MouseCursorTextureFlag)
    {
        ShowCursor(false);
    }else {
        ShowCursor(true);
    }
}
void Mouse::Render(RenderContext& rc)
{
    if (M_MouseCursorTextureFlag)
    {
        M_MouseCursorTexture.Draw(rc);
    }
}