#include "PrecompileHeader.h"
#include "ph3_DogAirPlane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "ph3_Laser.h"
#include "ph3_Dog_Npc.h"
#include "ph3_food_bowl.h"
#include "Boss_Finish.h"
#include "DogAirPlaneUnLoad_Level.h"
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
	case Ph3_DogAirPlaneState::Rotation:
	
		break;
	case Ph3_DogAirPlaneState::Rotation_Attack:
		
		break;
	case Ph3_DogAirPlaneState::Rotation_Laser_Idle:

		break;
	case Ph3_DogAirPlaneState::Rotation_Pase1_Laser_Attack:

		break;
	case Ph3_DogAirPlaneState::Rotation_Pase1_Laser_Attack_Reverse:

		break;
	case Ph3_DogAirPlaneState::Rotation_Pase2_Laser_Attack:

		break;
	case Ph3_DogAirPlaneState::Rotation_Pase2_Laser_Attack_Reverse:

		break;
	case Ph3_DogAirPlaneState::Rotation_Pase3_Laser_Attack:

		break;
	case Ph3_DogAirPlaneState::Rotation_Pase3_Laser_Attack_Reverse:

		break;
	case Ph3_DogAirPlaneState::Left_Rotation:

		break;
	case Ph3_DogAirPlaneState::Left_Rotation_Attack:

		break;
	case Ph3_DogAirPlaneState::Death:

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
	case Ph3_DogAirPlaneState::Rotation:
		Rotation_Update(_Time); 
		break;
	case Ph3_DogAirPlaneState::Rotation_Attack:
		Rotation_Attack_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Rotation_Laser_Idle:
		Rotation_Laser_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Rotation_Pase1_Laser_Attack:
		Rotation_Laser_Attack_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Rotation_Pase1_Laser_Attack_Reverse:
		Rotation_Laser_Attack_Reverse_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Rotation_Pase2_Laser_Attack:
		Rotation_Pase2_Laser_Attack_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Rotation_Pase2_Laser_Attack_Reverse:
		Rotation_Pase2_Laser_Attack_Reverse_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Rotation_Pase3_Laser_Attack:
		Rotation_Pase3_Laser_Attack_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Rotation_Pase3_Laser_Attack_Reverse:
		Rotation_Pase3_Laser_Attack_Reverse_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Left_Rotation:
		Left_Rotation_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Left_Rotation_Attack:
		Left_Rotation_Attack_Update(_Time);
		break;
	case Ph3_DogAirPlaneState::Death:
		DeathUpdate(_Time);
		break;
	default:
		break;
	}
}



void Ph3_DogAirplane::IntroUpdate(float _Time)
{
	Collision->Off();
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
	Collision->On(); 
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
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>();
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
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>();
			Object->laserDir = LaserDir::Left_Mid;
			MidLaserCheck = true;
			
			return;
		}
	}
	
}

void Ph3_DogAirplane::Pase1_Attack_Reverse_Update(float _Time)
{
	if (GetLiveTime() > 2.0)
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
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>();
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
	if (GetLiveTime() > 2.0)
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
	if (GetLiveTime() > 2.0)
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

		Idle_Arom->Off();
		Idle_Body->Off();
		Idle_Arom_Hand->Off();
		Ph3_Boss_Intro->Off();
	
		ph3_dogcopter_rotate_camera->On();
		ChangeState(Ph3_DogAirPlaneState::Rotation);
		return;
	}
	
}


void Ph3_DogAirplane::Rotation_Update(float _Time)
{
	Collision->Off(); 

	if (ph3_dogcopter_rotate_camera->GetCurrentFrame() == 10)
	{
		ph3_paw_merge->Off();
	}

	if (ph3_dogcopter_rotate_camera->GetCurrentFrame() == 12)
	{
		RotationCheck = 0; 
	}


	if (ph3_dogcopter_rotate_camera->GetCurrentFrame() == 15)
	{
		
		if (ph3_Npc_Check == false)
		{
			//++RotationCheck;
			std::shared_ptr<ph3_Dog_Npc> object = GetLevel()->CreateActor<ph3_Dog_Npc>(); 
			ph3_Npc_Check = true;
		}
	}

	if (ph3_dogcopter_rotate_camera->IsAnimationEnd())
	{

		ph3_dogcopter_rotate_camera->Off(); 
		ph3_dogcopter_rotated_idle->On(); 
		ph3_dogcopter_rotate_camera_out_blades->On(); 
		ResetLiveTime(); 
		ChangeState(Ph3_DogAirPlaneState::Rotation_Attack);
		return; 
	}
	
}

void Ph3_DogAirplane::Rotation_Attack_Update(float _Time)
{
	if (GetLiveTime() > 1.0)
	{
		
		if (BowlDirCheck == 0)
		{
			std::shared_ptr<ph3_food_bowl> Object = GetLevel()->CreateActor<ph3_food_bowl>();
			Object->GetBullet()->GetTransform()->AddLocalPosition({ -120,740 });
			Object->GetSfx()->GetTransform()->AddLocalPosition({ -160,760 });
			++BowlDirCheck;
		}
		else if (BowlDirCheck == 1)
		{
			std::shared_ptr<ph3_food_bowl> Object = GetLevel()->CreateActor<ph3_food_bowl>();
			Object->GetBullet()->GetTransform()->AddLocalPosition({ 120,740 });
			Object->GetSfx()->GetTransform()->AddLocalPosition({ 170,750 });
			BowlDirCheck = 0;
			Object->SetDirCheck(1);
		}
		++BowlCheck;
		ResetLiveTime();
	}

	if (BowlCheck == 8)
	{
		ResetLiveTime();
		ChangeState(Ph3_DogAirPlaneState::Rotation_Laser_Idle);
		return; 
	}	
}

void Ph3_DogAirplane::Rotation_Laser_Update(float _Time)
{
	if (GetLiveTime() > 3)
	{
		ph3_dogcopter_rotated_idle->Off();
		ph3_dogcopter_rotate_camera_out->On(); 
	}
	if (ph3_dogcopter_rotate_camera_out->GetCurrentFrame() == 4)
	{
		BowlCheck = 0;
		RotationCheck = 1;
	}


	if (ph3_dogcopter_rotate_camera_out->IsAnimationEnd())
	{
		ph3_dogcopter_rotate_camera_out->Off(); 
		ph3_dogcopter_rotate_camera_out_blades->Off(); 
		GetTransform()->SetLocalRotation({ 0,0,0 });
		TransformData date = GetTransform()->GetTransDataRef(); 
		Idle_Arom->On();
		Idle_Body->On();
		Idle_Arom_Hand->On();
		ph3_paw_merge->On();


		ph3_Right_paw_hole_mid->On();
		ph3_Right_paw_hole_mid_backer->On();
		
		ph3_laser_Right_mid_paw_pad_opens->ChangeAnimation("ph3_laser_mid_paw_pad_opens");
		ph3_Right_laser_mid->ChangeAnimation("ph3_laser_mid");

		ph3_laser_Right_mid_paw_pad_opens->On(); 
	
		/*dle_Arom->GetTransform()->SetLocalRotation({ 0,0,0 });
		Idle_Body->GetTransform()->SetLocalRotation({ 0,0,0 });
		Idle_Arom_Hand->GetTransform()->SetLocalRotation({ 0,0,0 });
		ph3_paw_merge->GetTransform()->SetLocalRotation({ 0,0,0 });*/

		ResetLiveTime(); 
		
		ChangeState(Ph3_DogAirPlaneState::Rotation_Pase1_Laser_Attack);
		return;
	}

	

}

void Ph3_DogAirplane::Rotation_Laser_Attack_Update(float _Time)
{
	//TransformData data 
	
Collision->On(); 
	//GetTransform()->SetLocalRotation({ 0,0,0 });

	TransformData date = GetTransform()->GetTransDataRef();

	if (GetLiveTime() > 0.5f)
	{
		if (ph3_laser_Right_mid_paw_pad_opens->IsAnimationEnd())
		{		
			ph3_Right_laser_mid->On();
		}
		
		if (ph3_Right_laser_mid->IsAnimationEnd())
		{
			if (TopLaserCheck == false)
			{
				std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(120);
				Object->laserDir = LaserDir::Left_Mid_Reverse;
				TopLaserCheck = true;


				ph3_Right_laser_mid_Reverse->ChangeAnimation("ph3_laser_mid");
				ph3_laser_Right_mid_paw_pad_opens_Reverse->ChangeAnimation("ph3_laser_mid_paw_pad_opens");

				ChangeState(Ph3_DogAirPlaneState::Rotation_Pase1_Laser_Attack_Reverse);
				ResetLiveTime();
				return;
			}
		}


		
	}
	
}void Ph3_DogAirplane::Rotation_Laser_Attack_Reverse_Update(float _Time)
{
	if (GetLiveTime() > 2.0f)
	{	
		ph3_Right_laser_mid->Off();	
		ph3_Right_laser_mid_Reverse->On(); 

	}
	TransformData date = GetTransform()->GetTransDataRef();

	if (ph3_Right_laser_mid_Reverse->IsAnimationEnd())
	{
		ph3_Right_laser_mid_Reverse->Off();
		ph3_laser_Right_mid_paw_pad_opens->Off();
		ph3_laser_Right_mid_paw_pad_opens_Reverse->On();
	}

	if (ph3_laser_Right_mid_paw_pad_opens_Reverse->IsAnimationEnd())
	{
		ph3_laser_Right_mid_paw_pad_opens_Reverse->Off();
		ph3_Right_paw_hole_mid_backer->Off();
		ph3_Right_paw_hole_mid->Off();
	

		ph3_left_paw_hole_top->On();
	    ph3_left_paw_hole_top_backer->On();
	    ph3_laser_Left_top_paw_pad_opens->On();

	    ph3_Right_paw_hole_top->On();
	    ph3_Right_paw_hole_top_backer->On();
	    ph3_laser_Right_top_paw_pad_opens->On();
		
		ph3_Left_laser_top->ChangeAnimation("ph3_laser_top");
		ph3_Right_laser_top->ChangeAnimation("ph3_laser_top");
		ph3_laser_Left_top_paw_pad_opens->ChangeAnimation("ph3_laser_top_paw_pad_opens");
		ph3_laser_Right_top_paw_pad_opens->ChangeAnimation("ph3_laser_top_paw_pad_opens");

		TopLaserCheck = false;
		MidLaserCheck = false;

		ChangeState(Ph3_DogAirPlaneState::Rotation_Pase2_Laser_Attack);
		return;
	}

}



void Ph3_DogAirplane::Rotation_Pase2_Laser_Attack_Update(float _Time)
{
	
	if (ph3_laser_Left_top_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Left_laser_top->On();

	}
	if (ph3_laser_Right_top_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Right_laser_top->On();
	}


	if (ph3_Left_laser_top->IsAnimationEnd())
	{
		if (TopLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Left_Top_Reverse;
	

			std::shared_ptr<ph3_Laser> Object1 = GetLevel()->CreateActor<ph3_Laser>(3);
			Object1->laserDir = LaserDir::Right_Top_Reverse;
			ResetLiveTime();


			TopLaserCheck = true;


			ph3_Right_laser_top_Reverse->ChangeAnimation("ph3_laser_top");
			ph3_Left_laser_top_Reverse->ChangeAnimation("ph3_laser_top");
			ph3_laser_Left_top_paw_pad_opens_Reverse->ChangeAnimation("ph3_laser_top_paw_pad_opens");
			ph3_laser_Right_top_paw_pad_opens_Reverse->ChangeAnimation("ph3_laser_top_paw_pad_opens");

		    ChangeState(Ph3_DogAirPlaneState::Rotation_Pase2_Laser_Attack_Reverse);
			
			return;
		}
	}

}


void Ph3_DogAirplane::Rotation_Pase2_Laser_Attack_Reverse_Update(float _Time)
{
	

	if (GetLiveTime() > 1.7)
	{
		ph3_Right_laser_top->Off();
		ph3_Left_laser_top->Off();

		ph3_Right_laser_top_Reverse->On();
		ph3_Left_laser_top_Reverse->On();
	}

	if (ph3_Right_laser_top_Reverse->IsAnimationEnd())
	{
		ph3_Right_laser_top_Reverse->Off();
		ph3_laser_Right_top_paw_pad_opens->Off();
		ph3_laser_Right_top_paw_pad_opens_Reverse->On();
	}

	if (ph3_Left_laser_top_Reverse->IsAnimationEnd())
	{
		ph3_Left_laser_top_Reverse->Off();
		ph3_laser_Left_top_paw_pad_opens->Off();
		ph3_laser_Left_top_paw_pad_opens_Reverse->On();
	}


	if (ph3_laser_Left_top_paw_pad_opens_Reverse->IsAnimationEnd())
	{
		ph3_Right_paw_hole_top_backer->Off();
		ph3_Right_paw_hole_top->Off();
		ph3_laser_Right_top_paw_pad_opens_Reverse->Off();

		ph3_left_paw_hole_top_backer->Off();
		ph3_left_paw_hole_top->Off();
		ph3_laser_Left_top_paw_pad_opens_Reverse->Off();


		ph3_left_paw_hole_low_backer->On();
		ph3_left_paw_hole_low->On();


		ph3_laser_Left_low_paw_pad_opens->ChangeAnimation("ph3_laser_low_paw_pad_opens");
		ph3_laser_Right_low_paw_pad_opens->ChangeAnimation("ph3_laser_low_paw_pad_opens");
		ph3_Left_laser_low->ChangeAnimation("ph3_laser_low");
		ph3_Right_laser_low->ChangeAnimation("ph3_laser_low");

		ph3_laser_Left_low_paw_pad_opens->On();
		ph3_laser_Right_low_paw_pad_opens->On();


		ph3_Right_paw_hole_low_backer->On();
		ph3_Right_paw_hole_low->On();


		

		TopLaserCheck = false;
		MidLaserCheck = false;
		LowLaserCheck = false;
		ChangeState(Ph3_DogAirPlaneState::Rotation_Pase3_Laser_Attack);
		return;
	}


}

void Ph3_DogAirplane::Rotation_Pase3_Laser_Attack_Update(float _Time)
{

	if (ph3_laser_Left_low_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Left_laser_low->On();
	}
	if (ph3_laser_Right_low_paw_pad_opens->IsAnimationEnd())
	{
		ph3_Right_laser_low->On();
	}

	if (ph3_Left_laser_low->IsAnimationEnd())
	{
		if (LowLaserCheck == false)
		{
			std::shared_ptr<ph3_Laser> Object = GetLevel()->CreateActor<ph3_Laser>(3);
			Object->laserDir = LaserDir::Low_Reverse;
			LowLaserCheck = true;
			ResetLiveTime();


			ph3_Right_laser_low_Reverse->ChangeAnimation("ph3_laser_low");
			ph3_Left_laser_low_Reverse->ChangeAnimation("ph3_laser_low");
			ph3_laser_Right_low_paw_pad_opens_Reverse->ChangeAnimation("ph3_laser_low_paw_pad_opens");
			ph3_laser_Left_low_paw_pad_opens_Reverse->ChangeAnimation("ph3_laser_low_paw_pad_opens");
			ChangeState(Ph3_DogAirPlaneState::Rotation_Pase3_Laser_Attack_Reverse);
			return;

		}
	}

}

void Ph3_DogAirplane::Rotation_Pase3_Laser_Attack_Reverse_Update(float _Time)
{
	if (GetLiveTime() > 1.7)
	{
		

		ph3_Right_laser_low->Off();
		ph3_Left_laser_low->Off();

		

		ph3_Right_laser_low_Reverse->On();
		ph3_Left_laser_low_Reverse->On();

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
		ph3_left_paw_hole_low_backer->Off();
		ph3_left_paw_hole_low->Off();
		ph3_laser_Left_low_paw_pad_opens_Reverse->Off();

		ph3_Right_paw_hole_low_backer->Off();
		ph3_Right_paw_hole_low->Off();
		ph3_laser_Right_low_paw_pad_opens_Reverse->Off();

		TopLaserCheck = false;
		MidLaserCheck = false;

		ph3_dogcopter_rotate_camera->ChangeAnimation("ph3_dogcopter_rotate_camera");
		ph3_dogcopter_rotate_camera->On();


		Idle_Arom->Off();
		Idle_Body->Off();
		Idle_Arom_Hand->Off();
		Ph3_Boss_Intro->Off();
		ph3_Npc_Check = true; 
		
		ChangeState(Ph3_DogAirPlaneState::Left_Rotation);
		return;
	}
}

void Ph3_DogAirplane::Left_Rotation_Update(float _Time)
{
	Collision->Off();

	if (ph3_dogcopter_rotate_camera->GetCurrentFrame() == 10)
	{
		ph3_paw_merge->Off();
	}

	if (ph3_dogcopter_rotate_camera->GetCurrentFrame() == 13)
	{
		RotationCheck = 2;		
	}

	if (ph3_dogcopter_rotate_camera->IsAnimationEnd())
	{
	
		ph3_dogcopter_rotate_camera->Off();
		ph3_dogcopter_rotated_idle->On();
		ph3_dogcopter_rotate_camera_out_blades->On();
		ResetLiveTime();
		ChangeState(Ph3_DogAirPlaneState::Left_Rotation_Attack);
		return;
	}
}

void Ph3_DogAirplane::Left_Rotation_Attack_Update(float _Time)
{

	if (Hp < 0)
	{
		ph3_dogcopter_rotated_idle->ChangeAnimation("ph3_dogcopter_sideways_death");
	
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 0.0f);
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 0.0f);
		Object->On();

		ResetLiveTime(); 
		ChangeState(Ph3_DogAirPlaneState::Death);
		return;
	}



	if (GetLiveTime() > 1.0)
	{

			if (BowlDirCheck == 0)
			{
				std::shared_ptr<ph3_food_bowl> Object = GetLevel()->CreateActor<ph3_food_bowl>();
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
				Object->GetBullet()->GetTransform()->AddLocalPosition({ -230,740 });
				Object->GetSfx()->GetTransform()->AddLocalPosition({ -200,750 });
				Object->SetDirCheck(2);
				++BowlDirCheck;
			}
			else if (BowlDirCheck == 1)
			{
				std::shared_ptr<ph3_food_bowl> Object = GetLevel()->CreateActor<ph3_food_bowl>();
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
				Object->GetBullet()->GetTransform()->AddLocalPosition({ 30,740 });
				Object->GetSfx()->GetTransform()->AddLocalPosition({ 100,750 });
				BowlDirCheck = 0;
				Object->SetDirCheck(3);
				++BowlCheck;
			}
			
			ResetLiveTime();
	}
	
	


}

void Ph3_DogAirplane::Right_Rotation_Attack_Update(float _Time)
{

	
}


void Ph3_DogAirplane::DeathUpdate(float _Time)
{
	GameEngineTime::GlobalTime.SetRenderOrderTimeScale(50, 1.0f);
	GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(50, 1.0f);


	if (GetLiveTime() > 2)
	{
		Exit->On(); 
		//Object->Death(); 
		//ph3_Dog_Npc::ph3_Npc = nullptr;

		//GameEngineCore::ChangeLevel("DogAirPlaneUnLoad_Level");
	}
	if (Exit->IsAnimationEnd())
	{
		Object->Death();
		GameEngineCore::ChangeLevel("DogAirPlaneUnLoad_Level");
	}

	
}
