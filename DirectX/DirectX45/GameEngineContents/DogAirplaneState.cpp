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
	Airplane_Back->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	Airplane_Front->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	bulldogIdle->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });



	

	if (AirplaneSpin->GetTransform()->GetLocalPosition().y < 200 && test ==false)
	{			
		test = true;
	}

	if (test == true)
	{
		DownSpeed -= 12;
	}
	if (AirplaneSpin->GetTransform()->GetLocalPosition().y > 200 && test == true )
	{
		DownSpeed = 0;
		test = false;
	}



	if (bulldogIdle->GetTransform()->GetLocalPosition().y < 200)
	{
		
		//bulldogIdle->GetTransform()->AddLocalPosition({ float4::Up * DownSpeed * _Time });
	}

	if (Airplane_Front->GetTransform()->GetLocalPosition().y < 150)
	{
	
		//Airplane_Front->GetTransform()->AddLocalPosition({ float4::Up * DownSpeed * _Time });
	}

	if (Airplane_Back->GetTransform()->GetLocalPosition().y < 150)
	{
		
		//Airplane_Back->GetTransform()->AddLocalPosition({ float4::Up * DownSpeed * _Time });
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

		Airplane_Back->On();
		ChangeState(DogAirplaneState::BossIdle);
		return;
	}

	if (GirlDog->GetCurrentFrame() > 5)
	{
		bulldogIntro->On();
	}
	if (bulldogIntro->IsAnimationEnd())
	{
		bulldogIntro->Off();
	}

	



}

