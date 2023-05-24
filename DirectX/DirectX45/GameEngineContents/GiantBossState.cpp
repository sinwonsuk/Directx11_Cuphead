#include "PrecompileHeader.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "GiantBoss.h"

void GiantBoss::ChangeState(GiantBossState _State)
{
	GiantBossState NextState = _State;
	GiantBossState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case GiantBossState::BossIntro:
		
		break;

	case GiantBossState::BossIdle:
		AnimationCheck("BossIdle");
		break;
	case GiantBossState::BossIdleHand:
		AnimationCheck("BossIdleHand");
		break;
	default:
		break;
	}


}

void GiantBoss::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case GiantBossState::BossIntro:
		BossIntroUpdate(_Time);
		break;
	case GiantBossState::BossIdle:
		BossIdleUpdate(_Time);
		break;
	case GiantBossState::BossIdleHand:
		AnimationCheck("BossIdleHand");
		break;
	default:
		break;
	}



}

void GiantBoss::BossIdleUpdate(float _Time)
{



	if (BossIntro0->IsAnimationEnd())
	{
		BossIntro0->Death();
	}
	if (BossIntroRock->IsAnimationEnd())
	{
		BossIntroRock->Death();
	}
	if (BossIntroDust->IsAnimationEnd())
	{
		BossIntroDust->Death();
	}

}

void GiantBoss::BossIntroUpdate(float _Time)
{
	if (BossIntro0->GetCurrentFrame() > 11)
	{
		BossIntroRock->On();
		BossIntroDust->On();
	}

	if (BossIntro0->IsAnimationEnd())
	{
		BossIdle->On();
		BossIdleHand->On(); 
		ChangeState(GiantBossState::BossIdle);
		return; 
	}
	
	
}


