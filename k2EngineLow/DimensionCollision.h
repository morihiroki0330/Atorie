#pragma once
namespace nsK2EngineLow
{
	struct ObjectData
	{
		int ObjectName;
		int Tag;
		int UpperLeftVertexPositionX;
		int UpperLeftVertexPositionY;
		int LowerRightVertexPositionX;
		int LowerRightVertexPositionY;
		int Wide;
		int Height;
		
	};
	class DimensionCollision : public Noncopyable
	{
	public:
		void DecisionDataSet(float  Wide, float Height, float PositionX, float PositionY, int ObjectName, int Tag);
		void DecisionDataSet(ObjectData DecisionData, int ObjectName,int Tag);
		void DecisionDataUpdate(ObjectData DecisionData, int ObjectName);
		void CopyDecisionData(ObjectData& DecisionData, int ObjectName);
		ObjectData GetDecisionData(int ObjectName);
		void DecisionSetPosition(float PositionX, float PositionY, int ObjectName);
		bool DecisionCollision(int ObjectName1, int ObjectName2);
		int OddConversion(int Number)
		{
			if (Number % 2 == 0)
			{
				return Number += 1;
			}else {
				return Number;
			}
		}
		int EvenConversion(int Number)
		{
			if (Number % 2 == 1)
			{
				return Number += 1;
			}else {
				return Number;
			}
		}
		ObjectData DecisionData[150];
	private:
		
	};
}

