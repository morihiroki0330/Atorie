#pragma once
namespace nsK2EngineLow
{
	struct ObjectData
	{
		int ObjectName = 0;
		int Tag = 0;
		int UpperLeftVertexPositionX = 0;//��`�̍���X
		int UpperLeftVertexPositionY = 0;//��`�̍���Y
		int LowerRightVertexPositionX = 0;//��`�̉E��X
		int LowerRightVertexPositionY = 0;//��`�̉E��Y
		int Wide = 0;
		int Height = 0;
		
	};
	class DimensionCollision : public IGameObject
	{
	public:
		void DecisionDataSet(float  Wide, float Height, float PositionX, float PositionY, int ObjectName, int Tag);
		
		void DecisionLeg(int ObjectName1, int ObjectName2, int Tag);

		void CopyDecisionData(ObjectData& DecisionData, int ObjectName);
		void CopyDecisionData(ObjectData& DecisionData, int Tag,int Count);

		ObjectData GetDecisionData(int ObjectName);

		void DecisionSetPosition(float PositionX, float PositionY, int ObjectName);
		void DecisionLegSetPosition(float PositionX, float PositionY, int ObjectName1, int ObjectName2);

		bool GroundCollision(int ObjectName1,int Tag2);
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

