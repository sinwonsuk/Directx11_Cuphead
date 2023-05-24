#include "PrecompileHeader.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "DogAirplane.h"
void DogAirplane::ChangeState(DogAirplaneState _State)
{
	DogAirplaneState NextState = _State;
	DogAirplaneState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case DogAirplaneState::BossIntro:
		
		break;

	case DogAirplaneState::BossIdle:
		AnimationCheck("BossIdle");
		break;
	case DogAirplaneState::BossIdleHand:
		AnimationCheck("BossIdleHand");
		break;
	default:
		break;
	}


}

void DogAirplane::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case DogAirplaneState::BossIntro:
		BossIntroUpdate(_Time);
		break;
	case DogAirplaneState::BossIdle:
		BossIdleUpdate(_Time);
		break;
	case DogAirplaneState::BossIdleHand:
		AnimationCheck("BossIdleHand");
		break;
	default:
		break;
	}



}

void DogAirplane::BossIdleUpdate(float _Time)
{
	
	
		
	AirplaneSpin->GetTransform()->AddLocalPosition({ float4::Down*DownSpeed * _Time });
	
		if (AirplaneSpin->GetTransform()->GetLocalPosition().y < 200)
		{
			AirplaneSpin->GetTransform()->AddLocalPosition({ float4::Up * DownSpeed* _Time });
		}


	
		Airplane->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	
		if (Airplane->GetTransform()->GetLocalPosition().y < 200)
		{
			Airplane->GetTransform()->AddLocalPosition({ float4::Up * DownSpeed * _Time });
		}


}

void DogAirplane::BossIntroUpdate(float _Time)
{
	if (GirlDog->IsAnimationEnd())
	{
		GirlDog->Off();
	}
	if (dogcopter->IsAnimationEnd())
	{
		dogcopter->Off();
		AirplaneSpin->On();

		Airplane->On();
		ChangeState(DogAirplaneState::BossIdle);
		return; 
	}

	if (GirlDog->GetCurrentFrame() > 5)
	{
		bulldog->On();
	}
	if (bulldog->IsAnimationEnd())
	{
		bulldog->Off();
	}

	



}

