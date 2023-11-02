#include "k2EngineLowPreCompile.h"
#include "DimensionCollision.h"
namespace nsK2EngineLow
{
	//当たり判定の生成
	void DimensionCollision::DecisionDataSet(float  Wide, float Height, float PositionX, float PositionY, int ObjectName, int Tag)
	{
		for (int Count = 0; Count < 150; Count++)
		{
			if (DecisionData[Count][DIRECTION_NON].ObjectName == 0)
			{
				DecisionData[Count][DIRECTION_NON].ObjectName = ObjectName;

				DecisionData[Count][DIRECTION_NON].Tag = Tag;

				DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX = (PositionX - (Wide / 2));

				DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY = (PositionY + (Height / 2));

				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX = (PositionX + (Wide / 2));

				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY = (PositionY - (Height / 2));
				
				/*DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX = int((PositionX - (Wide / 2)));
				DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX = EvenConversion(DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX);

				DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY = int((PositionY + (Height / 2)));
				DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY = EvenConversion(DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY);

				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX = int((PositionX + (Wide / 2)));
				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX = EvenConversion(DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX);

				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY = int((PositionY - (Height / 2)));
				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY = EvenConversion(DecisionData[Count][0].LowerRightVertexPositionY);*/

				DecisionData[Count][DIRECTION_NON].Wide = (Wide);
				DecisionData[Count][DIRECTION_NON].Height = (Height);
				
				/*DecisionData[Count][DIRECTION_NON].Wide = (int)(Wide);
				DecisionData[Count][DIRECTION_NON].Height = (int)(Height);*/
				return;
			}
		}
	}

	//コピー
	void DimensionCollision::CopyDecisionData(ObjectData& Decision, int ObjectName)
	{
		for (int Count = 0; Count < 150; Count++)
		{
			if (DecisionData[Count][DIRECTION_NON].ObjectName == ObjectName)
			{
				Decision.ObjectName                = DecisionData[Count][DIRECTION_NON].ObjectName;
				Decision.Tag                       = DecisionData[Count][DIRECTION_NON].Tag;
				Decision.UpperLeftVertexPositionX  = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX;
				Decision.UpperLeftVertexPositionY  = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY;
				Decision.LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX;
				Decision.LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY;
				return;
			}
		}
	}
	void DimensionCollision::CopyDecisionsData(ObjectData& Decision, int Tag,int Count)
	{
		if (DecisionData[Count][DIRECTION_NON].Tag == Tag)
		{
			Decision.ObjectName                = DecisionData[Count][DIRECTION_NON].ObjectName;
			Decision.Tag                       = DecisionData[Count][DIRECTION_NON].Tag;
			Decision.UpperLeftVertexPositionX  = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX;
			Decision.UpperLeftVertexPositionY  = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY;
			Decision.LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX;
			Decision.LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY;
			return;
		}
	}
	void DimensionCollision::CopyEmptyData(ObjectData& Decision, int ObjectName, int Direction)
	{
		for (int Count = 0; Count < 150; Count++)
		{
			if (DecisionData[Count][DIRECTION_NON].ObjectName == ObjectName)
			{
				Decision.UpperLeftVertexPositionX  = DecisionData[Count][Direction].UpperLeftVertexPositionX;
				Decision.UpperLeftVertexPositionY  = DecisionData[Count][Direction].UpperLeftVertexPositionY;
				Decision.LowerRightVertexPositionX = DecisionData[Count][Direction].LowerRightVertexPositionX;
				Decision.LowerRightVertexPositionY = DecisionData[Count][Direction].LowerRightVertexPositionY;
				return;
			}
		}
	}

	//座標更新
	void DimensionCollision::DecisionSetPosition(float PositionX, float PositionY, int ObjectName)
	{
		for (int Count = 0; Count < 150; Count++)
		{
			if (DecisionData[Count][DIRECTION_NON].ObjectName == ObjectName)
			{
				DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX = (PositionX - (DecisionData[Count][DIRECTION_NON].Wide / 2));

				DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY = (PositionY + (DecisionData[Count][DIRECTION_NON].Height / 2));

				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX = (PositionX + (DecisionData[Count][DIRECTION_NON].Wide / 2));

				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY = (PositionY - (DecisionData[Count][DIRECTION_NON].Height / 2));

				/*DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX = int((PositionX - (DecisionData[Count][DIRECTION_NON].Wide / 2)));
				DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX = EvenConversion(DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX);

				DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY = int((PositionY + (DecisionData[Count][DIRECTION_NON].Height / 2)));
				DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY = EvenConversion(DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY);

				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX = int((PositionX + (DecisionData[Count][DIRECTION_NON].Wide / 2)));
				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX = EvenConversion(DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX);

				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY = int((PositionY - (DecisionData[Count][DIRECTION_NON].Height / 2)));
				DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY = EvenConversion(DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY);*/

				DecisionUpSetPosition(Count);
				DecisionRightSetPosition(Count);
				DecisionLeftSetPosition(Count);
				DecisionDownSetPosition(Count);
				return;
			}
		}
	}
	void DimensionCollision::DecisionUpSetPosition(int Count)
	{
		DecisionData[Count][DIRECTION_UP].UpperLeftVertexPositionX = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX;
		DecisionData[Count][DIRECTION_UP].UpperLeftVertexPositionY = (DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY) + (EmptyWidth);
		DecisionData[Count][DIRECTION_UP].LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX;
		DecisionData[Count][DIRECTION_UP].LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY;
	}
	void DimensionCollision::DecisionRightSetPosition(int Count)
	{
		DecisionData[Count][DIRECTION_RIGHT].UpperLeftVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX;
		DecisionData[Count][DIRECTION_RIGHT].UpperLeftVertexPositionY = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY;
		DecisionData[Count][DIRECTION_RIGHT].LowerRightVertexPositionX = (DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX) + (EmptyWidth);
		DecisionData[Count][DIRECTION_RIGHT].LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY;
	}
	void DimensionCollision::DecisionDownSetPosition(int Count)
	{
		DecisionData[Count][DIRECTION_DOWN].UpperLeftVertexPositionX = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX;
		DecisionData[Count][DIRECTION_DOWN].UpperLeftVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY;
		DecisionData[Count][DIRECTION_DOWN].LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX;
		DecisionData[Count][DIRECTION_DOWN].LowerRightVertexPositionY = (DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY) + (-EmptyWidth);
	}
	void DimensionCollision::DecisionLeftSetPosition(int Count)
	{
		DecisionData[Count][DIRECTION_LEFT].UpperLeftVertexPositionX = (DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX) + (-EmptyWidth);
		DecisionData[Count][DIRECTION_LEFT].UpperLeftVertexPositionY = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY;
		DecisionData[Count][DIRECTION_LEFT].LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX;
		DecisionData[Count][DIRECTION_LEFT].LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY;
	}

	//衝突判定
	bool DimensionCollision::EmptyAndEmptyCollision(int ObjectName1, int Direction1, int ObjectName2, int Direction2)
	{
		ObjectData Decision1;
		CopyEmptyData(Decision1, ObjectName1,Direction1);
		ObjectData Decision2;
		CopyEmptyData(Decision2, ObjectName2, Direction2);
		for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
		{
			for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
			{
				if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
				{
					CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
					return true;
				}
			}
		}
		return false;
	}
	bool DimensionCollision::EmptyAndDecisionCollision(int ObjectName1, int Direction1, int ObjectName2)
	{
		ObjectData Decision1;
		CopyEmptyData(Decision1, ObjectName1, Direction1);
		ObjectData Decision2;
		CopyDecisionData(Decision2, ObjectName2);
		for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
		{
			for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
			{
				if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
				{
					CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
					return true;
				}
			}
		}
		return false;
	}
	bool DimensionCollision::EmptyAndDecisionsCollision(int ObjectName1, int Direction1, int Tag2)
	{
		ObjectData Decision1;
		CopyEmptyData(Decision1, ObjectName1, Direction1);
		ObjectData Decision2;
		for (int Count = 0; Count < 150; Count++)
		{
			CopyDecisionsData(Decision2, Tag2, Count);
			for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
			{
				for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
				{
					if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
					{
						CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
						return true;
					}
				}
			}
		}
		return false;
	}
	bool DimensionCollision::DecisionAndDecisionsCollision(int ObjectName1,int Tag2)
	{
		ObjectData Decision1;
		CopyDecisionData(Decision1, ObjectName1);
		ObjectData Decision2;
		
		for (int Count = 0; Count < 150; Count++)
		{
			CopyDecisionsData(Decision2, Tag2,Count);
			for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
			{
				for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
				{
					if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
					{
						CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
						return true;
					}
				}
			}
		}
		return false;
	}
	bool DimensionCollision::DecisionAndDecisionCollision(int ObjectName1, int ObjectName2)
	{
		ObjectData Decision1;
		CopyDecisionData(Decision1, ObjectName1);
		ObjectData Decision2;
		CopyDecisionData(Decision2, ObjectName2);

		for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
		{
			for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
			{
				if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
				{
					CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
					return true;
				}
			}
		}
		return false;
	}
}