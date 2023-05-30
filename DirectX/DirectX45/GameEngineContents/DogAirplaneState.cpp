#include "PrecompileHeader.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "DogAirplane.h"
#include "BoneWeapon.h"
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
	case DogAirplaneState::bulldog_Jump_Reverse:
		AnimationCheck("bulldog_Jump_Reverse");
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
	case DogAirplaneState::bulldog_Jump_Reverse:
		BossJumpReverseUpdate(_Time);
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
		
		CurPos = AirplaneSpin->GetTransform()->GetLocalPosition();

		bulldogIdle->GetTransform()->AddLocalPosition({ 0,0, 3 });
		bulldogIdleCheck = 0;
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

	AirplaneSpin->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	Airplane_Back->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	Airplane_Front->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	AirplaneFlap_A->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	AirplaneFlap_B->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	AirplaneFlap_C->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	AirplaneFlap_D->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	Airplane_Tail->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	bulldogIdle->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	Ball_Monster->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });
	Airplane_Wing->GetTransform()->AddLocalPosition({ float4::Down * DownSpeed * _Time });


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

void DogAirplane::BossJumpReverseUpdate(float _Time)
{
	AirplaneSpin->GetTransform()->AddWorldPosition({ float4::Down * Speed * _Time });
	Airplane_Back->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	Airplane_Front->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	bulldogIdle->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	AirplaneFlap_A->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	AirplaneFlap_B->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	AirplaneFlap_C->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	AirplaneFlap_D->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	Airplane_Tail->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });

	Ball_Monster->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	Airplane_Wing->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });


	if (bulldogIdle->GetCurrentFrame() > 4 && test1 == false)
	{
		Speed = -200;
		test1 = true;
	}

	if (AirplaneSpin->GetTransform()->GetLocalPosition().y > CurPos.y && test1 == true)
	{
		Speed = 0;
	}

	if (bulldogIdle->IsAnimationEnd())
	{
		test1 = false;
		Speed = 75;
		bulldogIdle->GetTransform()->SetLocalPosition({ AirplaneSpin->GetTransform()->GetLocalPosition().x,AirplaneSpin->GetTransform()->GetLocalPosition().y + 50,81 });
		ChangeState(DogAirplaneState::bulldog_Idle);
		return;
	}

}



void DogAirplane::BossAttackPase1Update(float _Time)
{
	if (Pase1_Attack < 0)
	{
		
		int PinkBone = GameEngineRandom::MainRandom.RandomInt(0, 2);

		if (bulldogIdle->GetCurrentFrame() == 41 && BoneCheck == 0)
		{
			
			++BoneCheck;
			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 0)
			{
				Object->GetBullet()->ChangeAnimation("PinkBone"); 
			}
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x + 30,bulldogIdle->GetTransform()->GetLocalPosition().y+40 });
			Object->SetCheck(0);
		}
		if (bulldogIdle->GetCurrentFrame() == 51 && BoneCheck == 1)
		{
			++BoneCheck;
			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 1)
			{
				Object->GetBullet()->ChangeAnimation("PinkBone");
			}
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x + 30,bulldogIdle->GetTransform()->GetLocalPosition().y - 80 });
			Object->SetCheck(0);
		}
		if (bulldogIdle->GetCurrentFrame() == 67 && BoneCheck == 2)
		{
			++BoneCheck;
			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 2)
			{
				Object->GetBullet()->ChangeAnimation("PinkBone");
			}
			Object->SetTime(0.3);
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x + 30,bulldogIdle->GetTransform()->GetLocalPosition().y - 190 });
			Object->SetCheck(0);
			BoneCheck = 0;
		}
	}
	else if (Pase1_Attack > 0)
	{
		int PinkBone = GameEngineRandom::MainRandom.RandomInt(0, 3);

		if (bulldogIdle->GetCurrentFrame() == 41 && BoneCheck == 0)
		{
			++BoneCheck;
			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 0)
			{
				Object->GetBullet()->ChangeAnimation("PinkBone");
			}

			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x - 30,bulldogIdle->GetTransform()->GetLocalPosition().y+40 });
			Object->SetCheck(1);
		}
		if (bulldogIdle->GetCurrentFrame() == 51 && BoneCheck == 1)
		{
			++BoneCheck;
			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 1)
			{
				Object->GetBullet()->ChangeAnimation("PinkBone");
			}

			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x - 30,bulldogIdle->GetTransform()->GetLocalPosition().y - 80 });
			Object->SetCheck(1);
		}
		if (bulldogIdle->GetCurrentFrame() == 68 && BoneCheck == 2)
		{
			

			++BoneCheck;
			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 2)
			{
				Object->GetBullet()->ChangeAnimation("PinkBone");

			}
			Object->SetTime(0.3);
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x - 30,bulldogIdle->GetTransform()->GetLocalPosition().y - 190 });
			Object->SetCheck(1);
			BoneCheck = 0;
		}
	}

	

	

	if (bulldogIdle->IsAnimationEnd())
	{

		bulldogIdle->GetTransform()->SetLocalPosition({ AirplaneSpin->GetTransform()->GetLocalPosition().x,AirplaneSpin->GetTransform()->GetLocalPosition().y+50,84 });
		Speed = 100;
		ChangeState(DogAirplaneState::bulldog_Jump_Reverse);	
		return; 
	}

}

void DogAirplane::BossJumpUpdate(float _Time)
{
	
	AirplaneSpin->GetTransform()->AddWorldPosition({ float4::Down * Speed * _Time });
	Airplane_Back->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	Airplane_Front->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	bulldogIdle->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	AirplaneFlap_A->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	AirplaneFlap_B->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	AirplaneFlap_C->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	AirplaneFlap_D->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	Airplane_Tail->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });

	Ball_Monster->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });
	Airplane_Wing->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Time });

	
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
		test1 = false;
		Speed = 75;
		if (Pase1_Attack > 0)
		{
			Pase1_Attack = -500;
			bulldogIdle->GetTransform()->SetLocalRotation({ 0,0,0 });
		}

		else if (Pase1_Attack < 0)
		{
			Pase1_Attack = 500;
			bulldogIdle->GetTransform()->SetLocalRotation({ 0,180,0 });
		}


		bulldogIdle->GetTransform()->SetLocalPosition({ Pase1_Attack,0,0 });
		
		ChangeState(DogAirplaneState::BossAttackPase1);
		return; 
	}

		
}
