#include "k2EngineLowPreCompile.h"
#include "DimensionCollision.h"
namespace nsK2EngineLow
{
	void DimensionCollision::DecisionDataSet(float  Wide, float Height, float PositionX, float PositionY, int ObjectName)
	{
		for (int Count = 0; Count < 20; Count++)
		{
			if (DecisionData[Count].ObjectName == 0)
			{
				DecisionData[Count].ObjectName = ObjectName;

				DecisionData[Count].UpperLeftVertexPositionX = int((PositionX - (Wide / 2)));
				DecisionData[Count].UpperLeftVertexPositionX = EvenConversion(DecisionData[Count].UpperLeftVertexPositionX);

				DecisionData[Count].UpperLeftVertexPositionY = int((PositionY + (Height / 2)));
				DecisionData[Count].UpperLeftVertexPositionY = EvenConversion(DecisionData[Count].UpperLeftVertexPositionY);

				DecisionData[Count].LowerRightVertexPositionX = int((PositionX + (Wide / 2)));
				DecisionData[Count].LowerRightVertexPositionX = EvenConversion(DecisionData[Count].LowerRightVertexPositionX);

				DecisionData[Count].LowerRightVertexPositionY = int((PositionY - (Height / 2)));
				DecisionData[Count].LowerRightVertexPositionY = EvenConversion(DecisionData[Count].LowerRightVertexPositionY);

				DecisionData[Count].Wide = (int)(Wide);
				DecisionData[Count].Height = (int)(Height);
				return;
			}
		}
	}

	void DimensionCollision::DecisionDataSet(ObjectData Decision,int ObjectName)
	{
		for (int Count = 0; Count < 20; Count++)
		{
			if (DecisionData[Count].ObjectName == 0)
			{
				DecisionData[Count].ObjectName = ObjectName;

				DecisionData[Count].UpperLeftVertexPositionX = Decision.UpperLeftVertexPositionX;
				DecisionData[Count].UpperLeftVertexPositionX = EvenConversion(DecisionData[Count].UpperLeftVertexPositionX);

				DecisionData[Count].UpperLeftVertexPositionY = Decision.UpperLeftVertexPositionY;
				DecisionData[Count].UpperLeftVertexPositionY = EvenConversion(DecisionData[Count].UpperLeftVertexPositionY);

				DecisionData[Count].LowerRightVertexPositionX = Decision.LowerRightVertexPositionX;
				DecisionData[Count].LowerRightVertexPositionX = EvenConversion(DecisionData[Count].LowerRightVertexPositionX);

				DecisionData[Count].LowerRightVertexPositionY = Decision.LowerRightVertexPositionY;
				DecisionData[Count].LowerRightVertexPositionY = EvenConversion(DecisionData[Count].LowerRightVertexPositionY);

				DecisionData[Count].Wide = (int)(Decision.Wide);
				DecisionData[Count].Height = (int)(Decision.Height);
				return;
			}
		}
	}

	void DimensionCollision::DecisionDataUpdate(ObjectData Decision, int ObjectName)
	{
		for (int Count = 0; Count < 20; Count++)
		{
			if (DecisionData[Count].ObjectName == ObjectName)
			{
				DecisionData[Count].UpperLeftVertexPositionX = Decision.UpperLeftVertexPositionX;
				DecisionData[Count].UpperLeftVertexPositionX = EvenConversion(DecisionData[Count].UpperLeftVertexPositionX);

				DecisionData[Count].UpperLeftVertexPositionY = Decision.UpperLeftVertexPositionY;
				DecisionData[Count].UpperLeftVertexPositionY = EvenConversion(DecisionData[Count].UpperLeftVertexPositionY);

				DecisionData[Count].LowerRightVertexPositionX = Decision.LowerRightVertexPositionX;
				DecisionData[Count].LowerRightVertexPositionX = EvenConversion(DecisionData[Count].LowerRightVertexPositionX);

				DecisionData[Count].LowerRightVertexPositionY = Decision.LowerRightVertexPositionY;
				DecisionData[Count].LowerRightVertexPositionY = EvenConversion(DecisionData[Count].LowerRightVertexPositionY);
				return;
			}
		}
	}

	void DimensionCollision::CopyDecisionData(ObjectData& Decision, int ObjectName)
	{
		for (int Count = 0; Count < 20; Count++)
		{
			if (DecisionData[Count].ObjectName == ObjectName)
			{
				Decision.ObjectName = DecisionData[Count].ObjectName;
				Decision.UpperLeftVertexPositionX = DecisionData[Count].UpperLeftVertexPositionX;
				Decision.UpperLeftVertexPositionY = DecisionData[Count].UpperLeftVertexPositionY;
				Decision.LowerRightVertexPositionX = DecisionData[Count].LowerRightVertexPositionX;
				Decision.LowerRightVertexPositionY = DecisionData[Count].LowerRightVertexPositionY;
				return;
			}
		}
	}

	ObjectData DimensionCollision::GetDecisionData(int ObjectName)
	{
		for (int Count = 0; Count < 20; Count++)
		{
			if (DecisionData[Count].ObjectName == ObjectName)
			{
				return DecisionData[Count];
			}
		}
	}

	void DimensionCollision::DecisionSetPosition(float PositionX, float PositionY, int ObjectName)
	{
		for (int Count = 0; Count < 20; Count++)
		{
			if (DecisionData[Count].ObjectName == ObjectName)
			{
				DecisionData[Count].UpperLeftVertexPositionX = int((PositionX - (DecisionData[Count].Wide / 2)));
				DecisionData[Count].UpperLeftVertexPositionX = EvenConversion(DecisionData[Count].UpperLeftVertexPositionX);

				DecisionData[Count].UpperLeftVertexPositionY = int((PositionY + (DecisionData[Count].Height / 2)));
				DecisionData[Count].UpperLeftVertexPositionY = EvenConversion(DecisionData[Count].UpperLeftVertexPositionY);

				DecisionData[Count].LowerRightVertexPositionX = int((PositionX + (DecisionData[Count].Wide / 2)));
				DecisionData[Count].LowerRightVertexPositionX = EvenConversion(DecisionData[Count].LowerRightVertexPositionX);

				DecisionData[Count].LowerRightVertexPositionY = int((PositionY - (DecisionData[Count].Height / 2)));
				DecisionData[Count].LowerRightVertexPositionY = EvenConversion(DecisionData[Count].LowerRightVertexPositionY);
				return;
			}
		}
	}
	bool DimensionCollision::DecisionCollision(int ObjectName1, int ObjectName2)
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
					return true;
				}
			}
		}
		return false;
	}
}