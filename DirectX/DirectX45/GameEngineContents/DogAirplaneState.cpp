#include "PrecompileHeader.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "DogAirplane.h"
#include "BoneWeapon.h"
#include "dogfight_catshoot_yarnball.h"
#include <GameEngineCore/GameEngineCollision.h>

void DogAirplane::ChangeState(DogAirplaneState _State)
{

	DogAirplaneState NextState = _State;
	DogAirplaneState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case DogAirplaneState::Black:

		break;

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


	case DogAirplaneState::BossAttackPase2Intro:
		AnimationCheck("bulldog_Attack2_Pase1_intro");
		break;

	case DogAirplaneState::BossAttackPase2:
		AnimationCheck("bulldog_Attack2_Pase1_Attack");
		break;

	default:
		break;
	}
}


void DogAirplane::BlackUpdate(float _Time)
{
	if (Loading->IsAnimationEnd())
	{
		ChangeState(DogAirplaneState::BossIntro);
		return; 
	}
}

void DogAirplane::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case DogAirplaneState::Black:
		BlackUpdate(_Time);
		break;

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
	case DogAirplaneState::BossAttackPase2Intro:
		BossAttackPase2IntroUpdate(_Time);
		break;
	case DogAirplaneState::BossAttackPase2:
		BossAttackPase2AttackUpdate(_Time);
		break;
	case DogAirplaneState::Ph1_Finish:
		Ph1FinishUpdate(_Time);
		break;
	case DogAirplaneState::Unload:
		UnloadUpdate(_Time);
		break;
	default:
		break;
	}

}

void DogAirplane::BossIdleUpdate(float _Time)
{
	if (Hp < 0)
	{
		Airplane_Tail->Off();
		Airplane_Wing->Off();
		AirplaneFlap_A->Off();
		AirplaneFlap_B->Off();
		AirplaneFlap_C->Off();
		AirplaneFlap_D->Off();
		Ball_Monster->Off();
		Airplane_Back->Off();
		AirplaneSpin->Off();
		bulldogIdle->Off();
		Airplane_Front->Off();


		Ph1_Buldog_Death->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x, bulldogIdle->GetTransform()->GetLocalPosition().y - 90, bulldogIdle->GetTransform()->GetLocalPosition().z });
		testImage1->GetTransform()->SetLocalPosition({ AirplaneFlap_A->GetTransform()->GetLocalPosition().x,AirplaneFlap_A->GetTransform()->GetLocalPosition().y - 60,83 });
		Buldog_Death_Intro->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x,bulldogIdle->GetTransform()->GetLocalPosition().y,bulldogIdle->GetTransform()->GetLocalPosition().z });
		testImage3->GetTransform()->SetLocalPosition({ AirplaneFlap_A->GetTransform()->GetLocalPosition().x,AirplaneFlap_A->GetTransform()->GetLocalPosition().y- 80,82 });
		testImage1->On();
		Buldog_Death_Intro->On();
		testImage3->On(); 

		ChangeState(DogAirplaneState::Ph1_Finish);
		return;
	
	}
	
	if (bulldogIdle->IsAnimationEnd())
	{
		++bulldogIdleCheck;
	}

	if (bulldogIdleCheck == 2)
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


	if (AirplaneSpin->GetTransform()->GetLocalPosition().y < 180 && Intro_Jump_Check == false)
	{
		Intro_Jump_Check = true;
	}

	if (Intro_Jump_Check == true)
	{
		DownSpeed -= 30;
	}
	if (AirplaneSpin->GetTransform()->GetLocalPosition().y > 180 && Intro_Jump_Check == true)
	{
		DownSpeed = 600;
		Intro_Jump_Check = false;
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


	if (bulldogIdle->GetCurrentFrame() > 4 && JumpCheck == false)
	{
		if (Sound_Jump_Down_Check == false)
		{
			Jump_Down = GameEngineSound::Play("sfx_DLC_Dogfight_P1_Bulldog_EjectDown.wav");
			Sound_Jump_Down_Check = true;
		}

		Speed = -200;
		JumpCheck = true;
	}

	if (AirplaneSpin->GetTransform()->GetLocalPosition().y > CurPos.y && JumpCheck == true)
	{
		Speed = 0;
	}

	if (bulldogIdle->IsAnimationEnd())
	{
		JumpCheck = false;
		Speed = 75;
		bulldogIdle->GetTransform()->SetLocalPosition({ AirplaneSpin->GetTransform()->GetLocalPosition().x,AirplaneSpin->GetTransform()->GetLocalPosition().y + 50,81 });
		Sound_Jump_Down_Check = false;
		ChangeState(DogAirplaneState::bulldog_Idle);
		return;
	}

}



void DogAirplane::BossAttackPase1Update(float _Time)
{

	CollisionMove -= 350.0f * _Time;

	if (bulldogIdle->GetCurrentFrame() > 36)
	{
		if (bulldogIdle->GetCurrentFrame() < 43)
		{
			CollisionMove += 350.0f * _Time;
		}
	}

	if (bulldogIdle->GetCurrentFrame() > 47)
	{
		if (bulldogIdle->GetCurrentFrame() < 55)
		{
			CollisionMove += 350.0f * _Time;
		}
	}

	if (bulldogIdle->GetCurrentFrame() > 64)
	{
		if (bulldogIdle->GetCurrentFrame() < 82)
		{
			CollisionMove += 350.0f * _Time;
		}
	}

	if (Pase1_Attack < 0)
	{
		

		Collision->GetTransform()->SetLocalPosition({-600,CollisionMove });
	
		if (bulldogIdle->GetCurrentFrame() == 41 && BoneCheck == 0)
		{
			if (Sound_Bone_Start == false)
			{
				Bone_Sound = GameEngineSound::Play("sfx_DLC_Dogfight_P1_Bulldog_Boneshot_01.wav");
				Bone_Sound.SetVolume(0.5f);
				Sound_Bone_Start = true; 
			}
			



			++BoneCheck;
			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 0)
			{

				Object->GetBullet()->ChangeAnimation("PinkBone"); 
				Object->GetCollision()->Off();
				Object->GetPinkCollision()->On();
			}

			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x + 30,bulldogIdle->GetTransform()->GetLocalPosition().y+40 });
			Object->SetCheck(0);
		}
		if (bulldogIdle->GetCurrentFrame() == 51 && BoneCheck == 1)
		{

			/*if (Sound_Bone_Start2 == false)
			{
				Bone_Sound = GameEngineSound::Play("sfx_DLC_Dogfight_P1_Bulldog_Boneshot_01.wav");
				Bone_Sound.SetVolume(0.5f);
				Sound_Bone_Start2 = true;
			}*/

			++BoneCheck;
			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 1)
			{
				Object->GetBullet()->ChangeAnimation("PinkBone");
				Object->GetCollision()->Off();
				Object->GetPinkCollision()->On();
			}
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x + 30,bulldogIdle->GetTransform()->GetLocalPosition().y - 80 });
			Object->SetCheck(0);
		}
		if (bulldogIdle->GetCurrentFrame() == 67 && BoneCheck == 2)
		{
			/*if (Sound_Bone_Start3 == false)
			{
				Bone_Sound = GameEngineSound::Play("sfx_DLC_Dogfight_P1_Bulldog_Boneshot_01.wav");
				Bone_Sound.SetVolume(0.5f);
				Sound_Bone_Start3 = true;
			}*/
			++BoneCheck;
			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 2)
			{
				Object->GetBullet()->ChangeAnimation("PinkBone");
				Object->GetCollision()->Off();
				Object->GetPinkCollision()->On();
			}
			Object->SetTime(0.3f);
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x + 30,bulldogIdle->GetTransform()->GetLocalPosition().y - 190 });
			Object->SetCheck(0);
			BoneCheck = 0;
		}
	}

	else if (Pase1_Attack > 0)
	{
		Collision->GetTransform()->SetLocalPosition({ 600,CollisionMove });



		

		if (bulldogIdle->GetCurrentFrame() == 41 && BoneCheck == 0)
		{
			++BoneCheck;

			if (Sound_Bone_Start == false)
			{
				Bone_Sound = GameEngineSound::Play("sfx_DLC_Dogfight_P1_Bulldog_Boneshot_01.wav");
				Bone_Sound.SetVolume(0.5f);
				Sound_Bone_Start = true;
			}

			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 0)
			{
				Object->GetBullet()->ChangeAnimation("PinkBone");
				Object->GetCollision()->Off();
				Object->GetPinkCollision()->On();
			}

			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x - 30,bulldogIdle->GetTransform()->GetLocalPosition().y+40 });
			Object->SetCheck(1);
		}
		if (bulldogIdle->GetCurrentFrame() == 51 && BoneCheck == 1)
		{
			/*if (Sound_Bone_Start2 == false)
			{
				Bone_Sound = GameEngineSound::Play("sfx_DLC_Dogfight_P1_Bulldog_Boneshot_01.wav");
				Bone_Sound.SetVolume(0.5f);
				Sound_Bone_Start2 = true;
			}*/

			++BoneCheck;
			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 1)
			{
				Object->GetBullet()->ChangeAnimation("PinkBone");
				Object->GetCollision()->Off();
				Object->GetPinkCollision()->On();
			}

			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x - 30,bulldogIdle->GetTransform()->GetLocalPosition().y - 80 });
			Object->SetCheck(1);
		}
		if (bulldogIdle->GetCurrentFrame() == 68 && BoneCheck == 2)
		{
			/*if (Sound_Bone_Start3 == false)
			{
				Bone_Sound = GameEngineSound::Play("sfx_DLC_Dogfight_P1_Bulldog_Boneshot_01.wav");
				Bone_Sound.SetVolume(0.5f);
				Sound_Bone_Start3 = true;
			}*/

			++BoneCheck;
			std::shared_ptr<BoneWeapon> Object = GetLevel()->CreateActor<BoneWeapon>();
			if (PinkBone == 2)
			{
				Object->GetBullet()->ChangeAnimation("PinkBone");
				Object->GetCollision()->Off();
				Object->GetPinkCollision()->On();

			}
			Object->SetTime(0.3f);
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x - 30,bulldogIdle->GetTransform()->GetLocalPosition().y - 190 });
			Object->SetCheck(1);
			BoneCheck = 0;
		}
	}

	if (bulldogIdle->IsAnimationEnd())
	{

		bulldogIdle->GetTransform()->SetLocalPosition({ AirplaneSpin->GetTransform()->GetLocalPosition().x,AirplaneSpin->GetTransform()->GetLocalPosition().y+50,84 });
		Speed = 100;
		CollisionMove = 640;
		Sound_Bone_Start = false;
		Sound_Bone_Start2 = false;
		Sound_Bone_Start3 = false;
		ChangeState(DogAirplaneState::bulldog_Jump_Reverse);	
		return; 
	}

}

void DogAirplane::BossJumpUpdate(float _Time)
{
	if (Sound_Jump_Check == false)
	{
		Jump = GameEngineSound::Play("sfx_DLC_Dogfight_P1_Bulldog_EjectUp.wav");
		Sound_Jump_Check = true;
	}

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

	
	if (bulldogIdle->GetCurrentFrame() > 4 && JumpCheck ==false)
	{
		Speed = -200;
		JumpCheck = true;
	}
	
	if (AirplaneSpin->GetTransform()->GetLocalPosition().y > CurPos.y && JumpCheck ==true)
	{		
		Speed = 0;
	}
	if (bulldogIdle->IsAnimationEnd())
	{
		bulldogAttackPase1 = GameEngineRandom::MainRandom.RandomInt(0, 1);
		//hfghgfg
	}


	if (bulldogIdle->IsAnimationEnd() && bulldogAttackPase1 ==0 )
	{
		JumpCheck = false;
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
		bulldogIdle->GetTransform()->SetLocalPosition({ Pase1_Attack,0,-100 });

		Sound_Jump_Check = false;
		PinkBone = GameEngineRandom::MainRandom.RandomInt(0, 2);
		ChangeState(DogAirplaneState::BossAttackPase1);
		return; 
	}

	if (bulldogIdle->IsAnimationEnd() && bulldogAttackPase1 == 1)
	{
		JumpCheck = false;
		Speed = 75;
		if (Pase1_Attack < 0)
		{
			Pase1_Attack = 500;
			bulldogIdle->GetTransform()->SetLocalRotation({ 0,0,0 });
		}

		else if (Pase1_Attack > 0)
		{
			Pase1_Attack = -480;
			bulldogIdle->GetTransform()->SetLocalRotation({ 0,180,0 });
		}
		bulldogIdle->GetTransform()->SetLocalPosition({ Pase1_Attack,-100,0 });

		Sound_Jump_Check = false;
		ChangeState(DogAirplaneState::BossAttackPase2Intro);
		return;
	}
		
}
void DogAirplane::Ph1FinishUpdate(float _Time)
{
	if (Hp < 0)
	{
		if (Sound_Explodes == false)
		{
			Explodes = GameEngineSound::Play("sfx_DLC_Dogfight_P1_Bulldog_PlaneExplodes.wav");
			AirplaneLoop.Stop();

			Sound_Explodes = true;
		}


		Collision->Death(); 
	
		if (testImage1->IsAnimationEnd())
		{
			testImage1->Off();
			ChangeState(DogAirplaneState::Unload);
			return;
		}

		if (Buldog_Death_Intro->IsAnimationEnd())
		{
			Buldog_Death_Intro->Off();
			testImage3->Off();
		}
		if (testImage1->GetCurrentFrame() == 25)
		{			
			Ph1_Buldog_Death->On();
		}

		if (Ph1_Buldog_Death->IsAnimationEnd())
		{
			Ph1_Buldog_Death->Off(); 
			return; 
		}

	}
}
void DogAirplane::UnloadUpdate(float _Time)
{
	
	switch (unloadCheck)
	{
	case 0:
	{
		Finish = true;

		
		++unloadCheck;
	}
	break;

	case 1:
	{
	
		++unloadCheck;
	}
	break;

	case 2:
	{
		
		

	}
	break;

	case 3:
	{
	
	}
	break;

	case 4:
	{
	
	}
	break;

	case 5:
	{
	}
	break;

	case 6:
	{
	}
	break;

	case 7:
	{
		
		++unloadCheck;
	}
	break;
	default:
		break;
	}
}


void DogAirplane::BossAttackPase2IntroUpdate(float _Time)
{
	if (bulldogIdle->IsAnimationEnd())
	{
		ChangeState(DogAirplaneState::BossAttackPase2);
		return;
	}
}

void DogAirplane::BossAttackPase2AttackUpdate(float _Time)
{



	if (Pase1_Attack < 0)
	{
		if (YarnballCheck == 0 && bulldogIdle->GetCurrentFrame() == 16)
		{
			if (Sound_Cat_Gun == false)
			{
				Cat_Gun = GameEngineSound::Play("sfx_DLC_Dogfight_P1_CatGun_Shoot_01.wav");
				Sound_Cat_Gun = true; 
			}
			

			++YarnballCheck;
			std::shared_ptr<dogfight_catshoot_yarnball> Object = GetLevel()->CreateActor<dogfight_catshoot_yarnball>();
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x + 50,bulldogIdle->GetTransform()->GetLocalPosition().y });
			Object->SetCheck(0);
			Object->GetBullet()->ChangeAnimation("dogfight_catshoot_red_yarnball");
		}
		if ( YarnballCheck == 1 && bulldogIdle->GetCurrentFrame() == 22)
		{
			if (Sound_Cat_Gun2 == false)
			{
				Cat_Gun = GameEngineSound::Play("sfx_DLC_Dogfight_P1_CatGun_Shoot_01.wav");
				Sound_Cat_Gun2 = true;
			}
			++YarnballCheck;
			std::shared_ptr<dogfight_catshoot_yarnball> Object = GetLevel()->CreateActor<dogfight_catshoot_yarnball>();
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x + 50,bulldogIdle->GetTransform()->GetLocalPosition().y });
			Object->SetCheck(0);
			Object->GetBullet()->ChangeAnimation("dogfight_catshoot_green_yarnball");
		}
		if (YarnballCheck == 2 && bulldogIdle->GetCurrentFrame() == 28)
		{
			if (Sound_Cat_Gun3 == false)
			{
				Cat_Gun = GameEngineSound::Play("sfx_DLC_Dogfight_P1_CatGun_Shoot_01.wav");
				Sound_Cat_Gun3 = true;
			}

			++YarnballCheck;
			std::shared_ptr<dogfight_catshoot_yarnball> Object = GetLevel()->CreateActor<dogfight_catshoot_yarnball>();
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x + 50,bulldogIdle->GetTransform()->GetLocalPosition().y });
			Object->SetCheck(0);
			Object->GetBullet()->ChangeAnimation("dogfight_catshoot_yellow_yarnball");
		}
	}
	else if (Pase1_Attack > 0)
	{


		if (YarnballCheck == 0 && bulldogIdle->GetCurrentFrame() == 16)
		{
			if (Sound_Cat_Gun == false)
			{
				Cat_Gun = GameEngineSound::Play("sfx_DLC_Dogfight_P1_CatGun_Shoot_01.wav");
				Sound_Cat_Gun = true;
			}

			++YarnballCheck;
			std::shared_ptr<dogfight_catshoot_yarnball> Object = GetLevel()->CreateActor<dogfight_catshoot_yarnball>();
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x - 50,bulldogIdle->GetTransform()->GetLocalPosition().y });
			Object->SetCheck(1);
			Object->GetBullet()->ChangeAnimation("dogfight_catshoot_red_yarnball");
		}
		if (YarnballCheck == 1 && bulldogIdle->GetCurrentFrame() == 22)
		{
			if (Sound_Cat_Gun2 == false)
			{
				Cat_Gun = GameEngineSound::Play("sfx_DLC_Dogfight_P1_CatGun_Shoot_01.wav");
				Sound_Cat_Gun2 = true;
			}

			++YarnballCheck;
			std::shared_ptr<dogfight_catshoot_yarnball> Object = GetLevel()->CreateActor<dogfight_catshoot_yarnball>();
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x - 50,bulldogIdle->GetTransform()->GetLocalPosition().y });
			Object->SetCheck(1);
			Object->GetBullet()->ChangeAnimation("dogfight_catshoot_green_yarnball");
		}
		if ( YarnballCheck == 2 && bulldogIdle->GetCurrentFrame() == 28)
		{
			if (Sound_Cat_Gun3 == false)
			{
				Cat_Gun = GameEngineSound::Play("sfx_DLC_Dogfight_P1_CatGun_Shoot_01.wav");
				Sound_Cat_Gun3 = true;
			}

			++YarnballCheck;
			std::shared_ptr<dogfight_catshoot_yarnball> Object = GetLevel()->CreateActor<dogfight_catshoot_yarnball>();
			Object->GetBullet()->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition().x - 50,bulldogIdle->GetTransform()->GetLocalPosition().y });
			Object->SetCheck(1);
			Object->GetBullet()->ChangeAnimation("dogfight_catshoot_yellow_yarnball");
		}
	}

	if (bulldogIdle->IsAnimationEnd())
	{
		Sound_Cat_Gun = false;
		Sound_Cat_Gun2 = false;
		Sound_Cat_Gun3 = false;
		YarnballCheck = 0;
		bulldogIdle->GetTransform()->SetLocalPosition({ AirplaneSpin->GetTransform()->GetLocalPosition().x,AirplaneSpin->GetTransform()->GetLocalPosition().y + 50,84 });
		Speed = 100;
		ChangeState(DogAirplaneState::bulldog_Jump_Reverse);
		return;
	}
}
