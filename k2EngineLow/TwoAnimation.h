#pragma once
namespace nsK2EngineLow
{
	class TwoAnimation : public IGameObject
	{
	public:
		void AnimationSet(const char* Sprite,float Height,float Wide,int AnimationNumber);
		void SetPosition(Vector3 Pos);
		void Update();
		void Animation();
		void Render(RenderContext& rc);
	private:
		SpriteRender M_Animation;
		Texture M_Texture[256];
		const char* M_TextureFilePath[256];

		int AnimationFrameCount = 0;
		int AnimationFrame = 0;
		float M_AnimationSpeed = 0.0f;
		float Height = 0.0f;
		float Wide = 0.0f;
		bool M_Loop = false;
	};
}

