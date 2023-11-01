#include "k2EngineLowPreCompile.h"
#include "DimensionCollision.h"
namespace nsK2EngineLow
{
	void DimensionCollision::DecisionDataSet(float  Wide, float Height, float PositionX, float PositionY, int ObjectName, int Tag)
	{
		for (int Count = 0; Count < 150; Count++)
		{
			if (DecisionData[Count].ObjectName == 0)
			{
				DecisionData[Count].ObjectName = ObjectName;

				DecisionData[Count].Tag = Tag;

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
	void DimensionCollision::DecisionLeg(int ObjectName1, int ObjectName2, int Tag)
	{
		for (int Count = 0; Count < 150; Count++)
		{
			if (DecisionData[Count].ObjectName == ObjectName1)
			{

				DecisionData[Count + 1].ObjectName = ObjectName2;

				DecisionData[Count + 1].Tag = Tag;

				DecisionData[Count + 1].UpperLeftVertexPositionX = DecisionData[Count].UpperLeftVertexPositionX;
				DecisionData[Count + 1].UpperLeftVertexPositionX = EvenConversion(DecisionData[Count].UpperLeftVertexPositionX);

				DecisionData[Count + 1].UpperLeftVertexPositionY = DecisionData[Count].LowerRightVertexPositionY;
				DecisionData[Count + 1].UpperLeftVertexPositionY = EvenConversion(DecisionData[Count].UpperLeftVertexPositionY);

				DecisionData[Count + 1].LowerRightVertexPositionX = DecisionData[Count].LowerRightVertexPositionX;
				DecisionData[Count + 1].LowerRightVertexPositionX = EvenConversion(DecisionData[Count].LowerRightVertexPositionX);

				DecisionData[Count + 1].LowerRightVertexPositionY = (DecisionData[Count].LowerRightVertexPositionY) + (-10);
				DecisionData[Count + 1].LowerRightVertexPositionY = EvenConversion(DecisionData[Count].LowerRightVertexPositionY);

				DecisionData[Count + 1].Wide = DecisionData[Count].Wide;
				DecisionData[Count + 1].Height = DecisionData[Count].Height;
				return;
			}
		}
	}

	void DimensionCollision::CopyDecisionData(ObjectData& Decision, int ObjectName)
	{
		for (int Count = 0; Count < 150; Count++)
		{
			if (DecisionData[Count].ObjectName == ObjectName)
			{
				Decision.ObjectName = DecisionData[Count].ObjectName;
				Decision.Tag = DecisionData[Count].Tag;
				Decision.UpperLeftVertexPositionX = DecisionData[Count].UpperLeftVertexPositionX;
				Decision.UpperLeftVertexPositionY = DecisionData[Count].UpperLeftVertexPositionY;
				Decision.LowerRightVertexPositionX = DecisionData[Count].LowerRightVertexPositionX;
				Decision.LowerRightVertexPositionY = DecisionData[Count].LowerRightVertexPositionY;
				return;
			}
		}
	}
	void DimensionCollision::CopyDecisionData(ObjectData& Decision, int Tag,int Count)
	{
		if (DecisionData[Count].Tag == Tag)
		{
			Decision.ObjectName = DecisionData[Count].ObjectName;
			Decision.Tag = DecisionData[Count].Tag;
			Decision.UpperLeftVertexPositionX = DecisionData[Count].UpperLeftVertexPositionX;
			Decision.UpperLeftVertexPositionY = DecisionData[Count].UpperLeftVertexPositionY;
			Decision.LowerRightVertexPositionX = DecisionData[Count].LowerRightVertexPositionX;
			Decision.LowerRightVertexPositionY = DecisionData[Count].LowerRightVertexPositionY;
			return;
		}
	}

	ObjectData DimensionCollision::GetDecisionData(int ObjectName)
	{
		for (int Count = 0; Count < 150; Count++)
		{
			if (DecisionData[Count].ObjectName == ObjectName)
			{
				return DecisionData[Count];
			}
		}
	}

	void DimensionCollision::DecisionSetPosition(float PositionX, float PositionY, int ObjectName)
	{
		for (int Count = 0; Count < 150; Count++)
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
	void DimensionCollision::DecisionLegSetPosition(float PositionX, float PositionY, int ObjectName1,int ObjectName2)
	{
		for (int Count = 0; Count < 150; Count++)
		{
			if (DecisionData[Count].ObjectName == ObjectName1)
			{
				for (int a = 0; a < 150; a++)
				{
					if (DecisionData[a].ObjectName == ObjectName2)
					{
						DecisionData[a].UpperLeftVertexPositionX = DecisionData[Count].UpperLeftVertexPositionX;
						DecisionData[a].UpperLeftVertexPositionX = EvenConversion(DecisionData[Count].UpperLeftVertexPositionX);

						DecisionData[a].UpperLeftVertexPositionY = DecisionData[Count].LowerRightVertexPositionY;
						DecisionData[a].UpperLeftVertexPositionY = EvenConversion(DecisionData[Count].UpperLeftVertexPositionY);

						DecisionData[a].LowerRightVertexPositionX = DecisionData[Count].LowerRightVertexPositionX;
						DecisionData[a].LowerRightVertexPositionX = EvenConversion(DecisionData[Count].LowerRightVertexPositionX);

						DecisionData[a].LowerRightVertexPositionY = (DecisionData[Count].LowerRightVertexPositionY) + (-10);
						DecisionData[a].LowerRightVertexPositionY = EvenConversion(DecisionData[Count].LowerRightVertexPositionY);
						return;
					}
				}
			}
		}
	}

	bool DimensionCollision::GroundCollision(int ObjectName1,int Tag2)
	{
		ObjectData Decision1;
		CopyDecisionData(Decision1, ObjectName1);
		ObjectData Decision2;
		
		for (int Count = 0; Count < 150; Count++)
		{
			CopyDecisionData(Decision2, Tag2,Count);
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
		}
		return false;
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