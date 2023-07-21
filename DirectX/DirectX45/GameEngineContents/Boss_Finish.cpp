#include "PrecompileHeader.h"
#include "Boss_Finish.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
Boss_Finish::Boss_Finish()
{
}

Boss_Finish::~Boss_Finish()
{
}

void Boss_Finish::Start()
{
	Finish = CreateComponent<GameEngineUIRenderer>();
	Finish->CreateAnimation({ .AnimationName = "FightText_KO", .SpriteName = "FightText_KO", .FrameInter = 0.07f, .Loop = false, .ScaleToTexture = true, });
	Finish->ChangeAnimation("FightText_KO");
	Finish->SetScaleRatio(2.5f);
}

void Boss_Finish::Update(float _Delta)
{
	if (Finish->GetCurrentFrame() > 4)
	{
		if (SoundCheck == false)
		{
			Sound_Finish = GameEngineSound::Play("cuphead-a-knockout.mp3");
			Sound_Finish.SetVolume(1.8f);
			SoundCheck = true;
		}
		
	}

	if (Finish->IsAnimationEnd())
	{
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 1.0f);
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 1.0f);
		Finish->Off(); 
	}

}
