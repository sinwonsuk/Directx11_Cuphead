#include "PrecompileHeader.h"
#include "Boss_Finish.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
Boss_Finish::Boss_Finish()
{
}

Boss_Finish::~Boss_Finish()
{
}

void Boss_Finish::Start()
{
	Finish = CreateComponent<GameEngineSpriteRenderer>();
	Finish->CreateAnimation({ .AnimationName = "FightText_KO", .SpriteName = "FightText_KO", .FrameInter = 0.1f, .Loop = false, .ScaleToTexture = true, });
	Finish->ChangeAnimation("FightText_KO");
}

void Boss_Finish::Update(float _Delta)
{


	if (Finish->IsAnimationEnd())
	{
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 1.0f);
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 1.0f);
	}
}
