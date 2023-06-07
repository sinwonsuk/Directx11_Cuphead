#include "PrecompileHeader.h"
#include "ph3_DogAirPlane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ph3_Laser.h"
void Ph3_DogAirplane::ChangeState(Ph3_DogAirPlaneState _State)
{
	Ph3_DogAirPlaneState NextState = _State;
	Ph3_DogAirPlaneState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Ph3_DogAirPlaneState::Intro:
		//AnimationCheck("ph2_dog_a_intro");
		break;

	case Ph3_DogAirPlaneState::Idle:
	//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase1_Attack:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase1_Attack_Reverse:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase2_Attack:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase2_Attack_Reverse:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase3_Attack:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph3_DogAirPlaneState::Pase3_Attack_Reverse:
		//	AnimationCheck("ph2_dog_b_intro");
		break;
	default:
		break;
	}


}


void Ph3_DogAirplane::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Ph3_DogAirPlaneState::Intro:
		IntroUpdate(_Time);
		break;

	case Ph3_DogAirPlaneState::Idle:
		IdleUpdate(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase1_Attack:
		Pase1_AttackUpdate(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase1_Attack_Reverse:
		Pase1_Attack_Reverse_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase2_Attack:
		Pase2_AttackUpdate(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase2_Attack_Reverse:
		Pase2_Attack_Reverse_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase3_Attack:
		Pase3_AttackUpdate(_Time);
		break;
	case Ph3_DogAirPlaneState::Pase3_Attack_Reverse:
		Pase3_Attack_Reverse_Update(_Time);
		break;

	default:
		break;
	}
}



void Ph3_DogAirplane::IntroUpdate(float _Time)
{
	if (Ph3_Boss_Intro->IsAnimationEnd())
	{
		Ph3_Boss_Intro->Off(); 

		Idle_Arom->On();
		Idle_Body->On();
		Idle_Arom_Hand->On();
		ph3_paw_merge->On();

		ChangeState(Ph3_DogAirPlaneState::Idle);
		return;
	}
}

void Ph3_DogAirplane::IdleUpdate(float _Time)
{
	if (GetLiveTime() > 1)
	{
		ph3_left_paw_hole_top->On(); 
		ph3_left_paw_hole_top_backer->On(); 
		ph3_laser_Left_top_paw_pad_opens->On(); 

		ph3_left_paw_hole_mid->On();
		ph3_left_paw_hole_mid_backer->On(); 
		ph3_laser_Left_mid_paw_pad_opens->On(); 

		ChangeState(Ph3_DogAirPlaneState::Pase1_Attack);
		return; 
	}
	
}

void Ph3_DogAirplane::Pase1_AttackUpdate(float _Time)
{
	if (ph3_laser_Left_top_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Left_laser_top->On(); 
		
	}
	if (ph3_laser_Left_mid_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Left_laser_mid->On();		
	}

	if (ph3_Left_laser_top->IsAnimationEnd())
	{
		if (TopLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Left_Top;
			TopLaserCheck = true;

			ChangeState(Ph3_DogAirPlaneState::Pase1_Attack_Reverse);
			ResetLiveTime();
		}		
	}



	if (ph3_Left_laser_mid->IsAnimationEnd())
	{
		if (MidLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Left_Mid;
			MidLaserCheck = true;
			
			return;
		}
	}
	
}

void Ph3_DogAirplane::Pase1_Attack_Reverse_Update(float _Time)
{
	if (GetLiveTime() > 1.7)
	{
		ph3_Left_laser_top->Off();
		ph3_Left_laser_mid->Off(); 
		ph3_Left_laser_top_Reverse->On();
		ph3_Left_laser_mid_Reverse->On();
	}

	if (ph3_Left_laser_top_Reverse->IsAnimationEnd())
	{
		ph3_Left_laser_top_Reverse->Off(); 
		ph3_laser_Left_top_paw_pad_opens->Off(); 
		ph3_laser_Left_top_paw_pad_opens_Reverse->On();
	}

	if (ph3_Left_laser_mid_Reverse->IsAnimationEnd())
	{
		ph3_Left_laser_mid_Reverse->Off();
		ph3_laser_Left_mid_paw_pad_opens->Off(); 
		ph3_laser_Left_mid_paw_pad_opens_Reverse->On();
	}

	if (ph3_laser_Left_mid_paw_pad_opens_Reverse->IsAnimationEnd())
	{
		ph3_left_paw_hole_mid_backer->Off();
		ph3_left_paw_hole_mid->Off(); 
		ph3_laser_Left_mid_paw_pad_opens_Reverse->Off();
	}

	if (ph3_laser_Left_top_paw_pad_opens_Reverse->IsAnimationEnd())
	{
		ph3_left_paw_hole_top_backer->Off(); 
		ph3_left_paw_hole_top->Off(); 
		ph3_laser_Left_top_paw_pad_opens_Reverse->Off(); 


		ph3_Right_paw_hole_mid->On();
		ph3_Right_paw_hole_mid_backer->On();
		ph3_laser_Right_mid_paw_pad_opens->On();

		TopLaserCheck = false;
		MidLaserCheck = false;

		ChangeState(Ph3_DogAirPlaneState::Pase2_Attack);
		return; 
	}


}

void Ph3_DogAirplane::Pase2_AttackUpdate(float _Time)
{
	if (ph3_laser_Right_mid_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Right_laser_mid->On();

	}
	
	if (ph3_Right_laser_mid->IsAnimationEnd())
	{
		int a = 0;
		if (MidLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Right_Mid;
			MidLaserCheck = true;

			ChangeState(Ph3_DogAirPlaneState::Pase2_Attack_Reverse);
			ResetLiveTime();
			return; 
		}
	}

}

void Ph3_DogAirplane::Pase2_Attack_Reverse_Update(float _Time)
{
	if (GetLiveTime() > 1.7)
	{
		ph3_Right_laser_mid->Off();
		ph3_Right_laser_mid_Reverse->On();
	}
	if (ph3_Right_laser_mid_Reverse->IsAnimationEnd())
	{
		ph3_Right_laser_mid_Reverse->Off();
		ph3_laser_Right_mid_paw_pad_opens->Off();
		ph3_laser_Right_mid_paw_pad_opens_Reverse->On();
	}

	if (ph3_laser_Right_mid_paw_pad_opens_Reverse->IsAnimationEnd())
	{
		ph3_Right_paw_hole_mid_backer->Off();
		ph3_Right_paw_hole_mid->Off();
		ph3_laser_Right_mid_paw_pad_opens_Reverse->Off();

		MidLaserCheck = false;



		ph3_Right_paw_hole_top->On();
		ph3_Right_paw_hole_top_backer->On();
		ph3_laser_Right_top_paw_pad_opens->On();

		ph3_left_paw_hole_low_backer->On();
		ph3_left_paw_hole_low->On();
		ph3_laser_Left_low_paw_pad_opens->On();

		ph3_Right_paw_hole_low_backer->On();
		ph3_Right_paw_hole_low->On();
		ph3_laser_Right_low_paw_pad_opens->On();

		ChangeState(Ph3_DogAirPlaneState::Pase3_Attack);
		return; 
	}

	
}

void Ph3_DogAirplane::Pase3_AttackUpdate(float _Time)
{
	if (ph3_laser_Left_top_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Right_laser_top->On();

	}
	if (ph3_laser_Left_low_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Left_laser_low->On();
	}
	if (ph3_laser_Right_low_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Right_laser_low->On();
	}

	if (ph3_Right_laser_top->IsAnimationEnd())
	{
		if (TopLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Right_Top;
			TopLaserCheck = true;
			

		}
	}

	if (ph3_Left_laser_low->IsAnimationEnd())
	{
		if (LowLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Left_Low;
			LowLaserCheck = true;

			ResetLiveTime();
			ChangeState(Ph3_DogAirPlaneState::Pase3_Attack_Reverse);
			return;
			
		}
	}

	
}

void Ph3_DogAirplane::Pase3_Attack_Reverse_Update(float _Time)
{
	if (GetLiveTime() > 1.7)
	{
		ph3_Right_laser_top->Off();

		ph3_Right_laser_low->Off();
		ph3_Left_laser_low->Off();

		ph3_Right_laser_top_Reverse->On();

		ph3_Right_laser_low_Reverse->On();
		ph3_Left_laser_low_Reverse->On();

	}

	if (ph3_Right_laser_top_Reverse->IsAnimationEnd())
	{
		ph3_Right_laser_top_Reverse->Off();
		ph3_laser_Right_top_paw_pad_opens->Off();
		ph3_laser_Right_top_paw_pad_opens_Reverse->On();
	}

	if (ph3_Right_laser_low_Reverse->IsAnimationEnd())
	{
		ph3_Right_laser_low_Reverse->Off();
		ph3_laser_Right_low_paw_pad_opens->Off();
		ph3_laser_Right_low_paw_pad_opens_Reverse->On();
	}
	if (ph3_Left_laser_low_Reverse->IsAnimationEnd())
	{
		ph3_Left_laser_low_Reverse->Off();
		ph3_laser_Left_low_paw_pad_opens->Off();
		ph3_laser_Left_low_paw_pad_opens_Reverse->On();
	}

	if (ph3_laser_Left_low_paw_pad_opens_Reverse->IsAnimationEnd())
	{
		ph3_Right_paw_hole_top_backer->Off();
		ph3_Right_paw_hole_top->Off();
		ph3_laser_Right_top_paw_pad_opens_Reverse->Off();

		ph3_left_paw_hole_low_backer->Off();
		ph3_left_paw_hole_low->Off();
		ph3_laser_Left_low_paw_pad_opens_Reverse->Off();

		ph3_Right_paw_hole_low_backer->Off();
		ph3_Right_paw_hole_low->Off();
		ph3_laser_Right_low_paw_pad_opens_Reverse->Off();

		TopLaserCheck = false;
		MidLaserCheck = false;

		
		return;
	}
}
