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

	case DogAirplaneState::BossIntro2:
		
		break;

	case DogAirplaneState::bulldog_Idle:
		AnimationCheck("bulldog_Idle");
		break;
	case DogAirplaneState::BossIdleHand:
		AnimationCheck("BossIdleHand");
		break;
	case DogAirplaneState::bulldog_Jump:
		AnimationCheck("bulldog_Jump");
		break;
	case DogAirplaneState::BossAttackPase1:
		AnimationCheck("bulldog_Attack_Pase1");
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
	case DogAirplaneState::BossIntro2:
		BossIntro2Update(_Time);
		break;
	case DogAirplaneState::bulldog_Idle:
		BossIdleUpdate(_Time);
		break;

	case DogAirplaneState::BossIdleHand:

	case DogAirplaneState::bulldog_Jump:
		BossJumpUpdate(_Time);
		break;
	case DogAirplaneState::BossAttackPase1:
		BossAttackPase1Update(_Time);
		break;
	default:
		break;
	}



}

void DogAirplane::BossIdleUpdate(float _Time)
{
	if (bulldogIdle->IsAnimationEnd())
	{
		++bulldogIdleCheck;
	}
	
	if (bulldogIdleCheck == 3)
	{
		bulldogIdle->GetTransform()->AddLocalPosition({ 0,0, 3 });
		CurPos = AirplaneSpin->GetTransform()->GetLocalPosition();


		ChangeState(DogAirplaneState::bulldog_Jump);
		return; 
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
		ChangeState(DogAirplaneState::BossIntro2);
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

void DogAirplane::BossIntro2Update(float _Time)
{

	AirplaneSpin->GetTransform()->AddWorldPosition({ float4::Down * DownSpeed * _Time });
	Airplane_Back->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	Airplane_Front->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	bulldogIdle->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	

	if (AirplaneSpin->GetTransform()->GetLocalPosition().y < 180 && test == false)
	{
		test = true;
	}

	if (test == true)
	{
		DownSpeed -= 30;
	}
	if (AirplaneSpin->GetTransform()->GetLocalPosition().y > 180 && test == true)
	{
		DownSpeed = 600;
		test = false;
		ChangeState(DogAirplaneState::bulldog_Idle);
		return; 
	}



}


void DogAirplane::BossAttackPase1Update(float _Time)
{
	float4 a = bulldogIdle->GetTransform()->GetLocalScale();

}

void DogAirplane::BossJumpUpdate(float _Time)
{
	
	AirplaneSpin->GetTransform()->AddWorldPosition({ float4::Down * Speed * _Time });
	Airplane_Back->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	Airplane_Front->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	bulldogIdle->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	
	if (bulldogIdle->GetCurrentFrame() > 4 && test1 ==false)
	{
		Speed = -200;
		test1 = true;
	}
	
	if (AirplaneSpin->GetTransform()->GetLocalPosition().y > CurPos.y && test1 ==true)
	{
		
		Speed = 0;
	}
	
	if (bulldogIdle->IsAnimationEnd())
	{
		bulldogIdle->On();
		bulldogIdle->GetTransform()->SetLocalPosition({ 550,0,0 });
		ChangeState(DogAirplaneState::BossAttackPase1);
		return; 
	}

		
}
