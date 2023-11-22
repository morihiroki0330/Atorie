#pragma once
//‚â‚è’¼‚µ
class DimensionalCollision;
class Mouse;
struct ClairActionClock
{
	SpriteRender M_DialTexture;
	SpriteRender M_MinuteHandTexture;
	SpriteRender M_HourHandTexture;

	Vector3 M_DialPosition;
	Vector3 M_MinuteHandPosition;
	Vector3 M_HourHandPosition;
	void ClockUpdate()
	{
		M_DialTexture.Update();
		M_MinuteHandTexture.Update();
		M_HourHandTexture.Update();
	}
	void ClockRender(RenderContext& rc)
	{

	}
};
enum
{
	MinuteHand,
	HourHand
};
class ClairAction_GimmickClock : public IGameObject
{
public:
	ClairAction_GimmickClock();
	void Upadte();
	void Render(RenderContext& rc);
private:

	ClairActionClock S_Clock;

	DimensionalCollision* P_Collision = nullptr;
	Mouse* P_Mouse = nullptr;
};

