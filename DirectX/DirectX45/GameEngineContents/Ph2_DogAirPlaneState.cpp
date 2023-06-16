#include "PrecompileHeader.h"
#include "Ph2_DogAirpalne.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "ph2_Boss_Weapon.h"
#include <GameEngineCore/GameEngineLevel.h>

void Ph2_DogAirpalne::ChangeState(Ph2_DogAirPlaneState _State)
{
	Ph2_DogAirPlaneState NextState = _State;
	Ph2_DogAirPlaneState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Ph2_DogAirPlaneState::LeftIntro:
		AnimationCheck("ph2_dog_a_intro");
		break;

	case Ph2_DogAirPlaneState::UpIntro:
		AnimationCheck("ph2_dog_b_intro");
		break;
	case Ph2_DogAirPlaneState::RightIntro:
		AnimationCheck("ph2_dog_c_intro");
		break;
	case Ph2_DogAirPlaneState::DownIntro:
		AnimationCheck("ph2_dog_d_intro");
		break;
	case Ph2_DogAirPlaneState::Rotation:
		AnimationCheck("SD_Idle_side");
		break;
	case Ph2_DogAirPlaneState::Attack:
		//AnimationCheck("SD_Idle_side");
		break;

	
	default:
		break;
	}


}


void Ph2_DogAirpalne::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Ph2_DogAirPlaneState::LeftIntro:
		LeftIntroUpdate(_Time); 
		break;

	case Ph2_DogAirPlaneState::UpIntro:
		UpIntroUpdate(_Time);
		break;
	case Ph2_DogAirPlaneState::RightIntro:
		RightIntroUpdate(_Time);
		break;
	case Ph2_DogAirPlaneState::DownIntro:
		DownIntroUpdate(_Time);
		break;
	case Ph2_DogAirPlaneState::Rotation:
		RotationUpdate(_Time);
		break;
	case Ph2_DogAirPlaneState::Attack:
		AttackUpdate(_Time); 
		break;
	
	default:
		break;
	}



}

void Ph2_DogAirpalne::LeftIntroUpdate(float _Time)
{




	if (Ph2_Boss->GetTransform()->GetLocalPosition().x > -550.0f)
	{
		Ph2_Boss->GetTransform()->AddLocalPosition({ -300.0f* _Time,0 });
		jetpack->GetTransform()->AddLocalPosition({ -300.0f * _Time,0 });
	}

	Ph2_Boss->GetTransform()->AddLocalPosition({ 300.0f* _Time,0 });

	jetpack->GetTransform()->AddLocalPosition({ 300.0f * _Time,0 });

	if (GetLiveTime() > 2)
	{
		ResetLiveTime();
		RandomAttack = GameEngineRandom().MainRandom.RandomFloat(0.5f, 6.0f);
		ChangeState(Ph2_DogAirPlaneState::Rotation);
		return;
	}
	


}

void Ph2_DogAirpalne::UpIntroUpdate(float _Time)
{

	if (Ph2_Boss->GetTransform()->GetLocalPosition().y < 300.0f)
	{
		Ph2_Boss->GetTransform()->AddLocalPosition({ 0.0f , 300.0f * _Time,0.0f });
		jetpack->GetTransform()->AddLocalPosition({ 0.0f , 300.0f * _Time, 0.0f });
	}

	Ph2_Boss->GetTransform()->AddLocalPosition({ 0.0f , -300.0f * _Time, 0.0f });
	jetpack->GetTransform()->AddLocalPosition({ 0.0f , -300.0f * _Time, 0.0f });
	

	if (GetLiveTime() > 2)
	{

		ResetLiveTime();
		test = 1.5f;
		RotationAnimation = 3;
		RandomAttack = GameEngineRandom().MainRandom.RandomFloat(0.5f, 6.0f);
		ChangeState(Ph2_DogAirPlaneState::Rotation);
		return;
	}
}

void Ph2_DogAirpalne::RightIntroUpdate(float _Time)
{
	if (Ph2_Boss->GetTransform()->GetLocalPosition().x < 550.0f)
	{
		Ph2_Boss->GetTransform()->AddLocalPosition({ 300.0f * _Time , 0.0f ,0.0f });
		jetpack->GetTransform()->AddLocalPosition({ 300.0f * _Time , 0, 0.0f });
	}

	jetpack->GetTransform()->AddLocalPosition({ -300.0f * _Time , 0.0f, 0.0f });
	Ph2_Boss->GetTransform()->AddLocalPosition({- 300.0f * _Time,  0.0f, 0.0f });

	if (GetLiveTime() > 2)
	{

		ResetLiveTime();
		test = 3.1f;
		RotationAnimation = 7;
		RandomAttack = GameEngineRandom().MainRandom.RandomFloat(0.5f, 6.0f);
		ChangeState(Ph2_DogAirPlaneState::Rotation);
		return;
	}

}

void Ph2_DogAirpalne::DownIntroUpdate(float _Time)
{
	if (Ph2_Boss->GetTransform()->GetLocalPosition().y > -300.0f)
	{
		Ph2_Boss->GetTransform()->AddLocalPosition({ 0.0f , -300.0f * _Time,0.0f });
		jetpack->GetTransform()->AddLocalPosition({ 0.0f , -300.0f * _Time, 0.0f });
	}

	Ph2_Boss->GetTransform()->AddLocalPosition({ 0.0f , 300.0f * _Time, 0.0f });
	jetpack->GetTransform()->AddLocalPosition({ 0.0f , 300.0f * _Time, 0.0f });


	if (GetLiveTime() > 2)
	{

		ResetLiveTime();
		test = 4.7f;
		RotationAnimation = 11;
		Ph2_Boss->GetTransform()->SetLocalRotation({ 0,0,0 });
		RandomAttack = GameEngineRandom().MainRandom.RandomFloat(0.5f, 7.0f);
		ChangeState(Ph2_DogAirPlaneState::Rotation);
		return;
	}
	

}

void Ph2_DogAirpalne::AttackUpdate(float _Time)
{


	


	// 타원의 중심
	float x = 0.0;
	float y = 0.0;

	// 타원의 반지름
	double a = 550;
	double b = 300;

	test += 1.0f * _Time;

	//test += 1* _Time;
	Pos_x = x + a * cos(test);
	Pos_y = y + b * sin(test);

		switch (RotationAnimation)
		{
		case 0:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 40, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < 525.0f && AttackCheck == true)
			{
				Ph2_Boss->ChangeAnimation("SD_Attack_front_side");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;
		case 1:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 30, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < 375.0f && AttackCheck == true)
			{

				Ph2_Boss->ChangeAnimation("SD_Attack_3_4_front");
				++RotationAnimation;
				AttackCheck = false;
			}
		}
		break;
		case 2:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 20, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < 225.0f && AttackCheck == true)
			{
				Ph2_Boss->ChangeAnimation("SD_Attack_front_front");
				++RotationAnimation;
				AttackCheck = false;
			}
		}
		break;
		case 3:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 10, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < 75.0f && AttackCheck == true)
			{
				Ph2_Boss->ChangeAnimation("SD_Attack_front");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;
		case 4:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < -75.0f && AttackCheck == true)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Attack_front_front");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;
		case 5:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 10, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < -225.0f && AttackCheck == true)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Attack_3_4_front");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;
		case 6:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 20, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < -375.0f && AttackCheck == true)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Attack_front_side");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;
		case 7:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 30, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < -525.0f && AttackCheck == true)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Attack_side");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;
		case 8:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 40, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > -525.0f && AttackCheck == true)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Attack_side_back");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;
		case 9:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 40, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > -375.0f && AttackCheck == true)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				//Ph2_Boss->ChangeAnimation("SD_Idle_3_4_back");
				Ph2_Boss->ChangeAnimation("SD_Attack_3_4_back");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;
		case 10:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 30, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > -225.0f && AttackCheck == true)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Attack_3_4_back_back");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;
		case 11:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 37, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > -75.0f && AttackCheck == true)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,0,0 });
				Ph2_Boss->ChangeAnimation("SD_Attack_back");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		case 12:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 15, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > 75.0f  && AttackCheck == true)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,0,0 });
				Ph2_Boss->ChangeAnimation("SD_Attack_3_4_back_back");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;

		case 13:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 20, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > 225.0f && AttackCheck == true)
			{

				Ph2_Boss->ChangeAnimation("SD_Attack_3_4_back");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;

		case 14:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 35, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > 375 && AttackCheck == true)
			{

				Ph2_Boss->ChangeAnimation("SD_Attack_side_back");
				++RotationAnimation;
				AttackCheck = false;
			}

		}
		break;

		case 15:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 40, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > 525 && AttackCheck == true)
			{

				Ph2_Boss->ChangeAnimation("SD_Attack_side");
				RotationAnimation = 0;
				AttackCheck = false;
			}

		}
		break;

		default:
			break;
		}
	

	



	Ph2_Boss->GetTransform()->SetLocalPosition({ -Pos_x, Pos_y,0 });

	test1 += _Time;


	
	if (test1 > 0.1 && f==0)
	{
		
		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x ,jetpack->GetTransform()->GetLocalPosition().y,83.0f});	
		f++;
	}
	if (test1 > 0.2 && f == 1)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x ,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 0.3 && f == 2)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 0.4 && f == 3)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 0.5 && f == 4)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 0.6 && f == 5)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 0.7 && f == 6)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 0.8 && f == 7)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 0.9 && f == 8)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.0 && f == 9)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 1.1 && f == 10)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.2 && f == 11)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.3 && f == 12)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.4 && f == 13)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 1.5 && f == 14)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.6 && f == 15)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.7 && f == 16)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 1.8 && f == 17)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 1.9 && f == 18)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 2.0 && f == 19)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	
	for (size_t i = 0; i < ph2_jetpack_smoke_a.size(); i++)
	{
		if (ph2_jetpack_smoke_a[i]->IsAnimationEnd())
		{
			ph2_jetpack_smoke_a[i]->Off();
			ph2_jetpack_smoke_a[i]->ChangeAnimation("ph2_jetpack_smoke_a");
			ph2_jetpack_smoke_a[i]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x+10,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
			ph2_jetpack_smoke_a[i]->On();

		}
	}
	if (AttackCheck == false && Ph2_Boss->GetCurrentFrame() == 2)
	{
		
		if (WeaponCheck == false)
		{
			std::shared_ptr<ph2_Boss_Weapon> Object = GetLevel()->CreateActor<ph2_Boss_Weapon>();
			Object->GetBullet()->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x,Ph2_Boss->GetTransform()->GetLocalPosition().y,-1.0f });
			WeaponCheck = true;
		}

		Attack_Effect->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x,Ph2_Boss->GetTransform()->GetLocalPosition().y,-1.0f });
		Attack_Effect->On();
	}
	
	
	




	if (Attack_Effect->IsAnimationEnd())
	{
		Attack_Effect->Off();
	}



	if (AttackCheck == false)
	{
		if (Ph2_Boss->IsAnimationEnd())
		{
			
			ResetLiveTime();
			WeaponCheck = false;
			AttackCheck = true;
			RandomAttack = GameEngineRandom().MainRandom.RandomFloat(0.5f, 6.0f);
			ChangeState(Ph2_DogAirPlaneState::Rotation);
			return;
		}
	}


}

void Ph2_DogAirpalne::UpIdleUpdate(float _Time)
{
	float RadiousX = 620;
	float RadiousY = 300;


	if (Ph2_Boss->GetTransform()->GetLocalPosition().x <= -620)
	{
		RotationCheck = false;
	}

	if (Ph2_Boss->GetTransform()->GetLocalPosition().x >= 620)
	{
		RotationCheck = true;
	}

	if (RotationCheck == false)
	{
		Up_Pos_x += 1;

		float y1 = (RadiousY * RadiousY) - ((RadiousY * RadiousY) * (Up_Pos_x * Up_Pos_x)) / (RadiousX * RadiousX);
		float y = sqrt(y1);

		Ph2_Boss->GetTransform()->SetLocalPosition({ Up_Pos_x ,y,0 });
	}

	if (RotationCheck == true)
	{
		Right_Pos_x -= 1;

		float y1 = (RadiousY * RadiousY) - ((RadiousY * RadiousY) * (Up_Pos_x * Up_Pos_x)) / (RadiousX * RadiousX);
		float y = sqrt(y1);

		Ph2_Boss->GetTransform()->SetLocalPosition({ Up_Pos_x ,-y,0 });
	}

}

void Ph2_DogAirpalne::RightIdleUpdate(float _Time)
{
	float RadiousX = 620;
	float RadiousY = 300;

	if (Ph2_Boss->GetTransform()->GetLocalPosition().x <= -620)
	{
		RotationCheck = false;
	}

	if (Ph2_Boss->GetTransform()->GetLocalPosition().x >= 620)
	{
		RotationCheck = true;
	}

	if (RotationCheck == false)
	{
		Right_Pos_x += 1;

		float y1 = (RadiousY * RadiousY) - ((RadiousY * RadiousY) * (Right_Pos_x * Right_Pos_x)) / (RadiousX * RadiousX);
		float y = sqrt(y1);

		Ph2_Boss->GetTransform()->SetLocalPosition({ Right_Pos_x ,y,0 });
	}

	if (RotationCheck == true)
	{
		Right_Pos_x -= 1;

		float y1 = (RadiousY * RadiousY) - ((RadiousY * RadiousY) * (Right_Pos_x * Right_Pos_x)) / (RadiousX * RadiousX);
		float y = sqrt(y1);

		Ph2_Boss->GetTransform()->SetLocalPosition({ Right_Pos_x ,-y,0 });
	}


}

void Ph2_DogAirpalne::DownIdleUpdate(float _Time)
{

	float RadiousX = 620;
	float RadiousY = 300;

	if (Ph2_Boss->GetTransform()->GetLocalPosition().x <= -620)
	{
		RotationCheck = false;
	}

	if (Ph2_Boss->GetTransform()->GetLocalPosition().x >= 620)
	{
		RotationCheck = true;
	}

	if (RotationCheck == false)
	{
		Down_Pos_x += 1;

		float y1 = (RadiousY * RadiousY) - ((RadiousY * RadiousY) * (Down_Pos_x * Down_Pos_x)) / (RadiousX * RadiousX);
		float y = sqrt(y1);

		Ph2_Boss->GetTransform()->SetLocalPosition({ Down_Pos_x ,y,0 });
	}

	if (RotationCheck == true)
	{
		Down_Pos_x -= 1;

		float y1 = (RadiousY * RadiousY) - ((RadiousY * RadiousY) * (Down_Pos_x * Down_Pos_x)) / (RadiousX * RadiousX);
		float y = sqrt(y1);

		Ph2_Boss->GetTransform()->SetLocalPosition({ Down_Pos_x ,-y,0 });
	}

}

void Ph2_DogAirpalne::RotationUpdate(float _Time)
{



	// 타원의 중심
	float x = 0.0;
	float y = 0.0;

	// 타원의 반지름
	double a = 550;
	double b = 300;

	test += 1.0f * _Time;

	//test += 1* _Time;
	Pos_x = x + a * cos(test);
	Pos_y = y + b * sin(test);




		switch (RotationAnimation)
		{
		case 0:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 40, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < 525.0f)
			{
				
				Ph2_Boss->ChangeAnimation("SD_Idle_front_side");			
				++RotationAnimation;

			}

		}
		break;
		case 1:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 30, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < 375.0f)
			{
				Ph2_Boss->ChangeAnimation("SD_Idle_3_4_front");
				++RotationAnimation;
			}
		}
		break;
		case 2:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 20, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < 225.0f)
			{
				Ph2_Boss->ChangeAnimation("SD_Idle_front_front");
				++RotationAnimation;
			}
		}
		break;
		case 3:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 10, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < 75.0f)
			{
				Ph2_Boss->ChangeAnimation("SD_Idle_front_Up");
				++RotationAnimation;
			}

		}
		break;
		case 4:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < -75.0f)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Idle_front_front");
				++RotationAnimation;
			}

		}
		break;
		case 5:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 10, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < -225.0f)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Idle_3_4_front");
				++RotationAnimation;
			}

		}
		break;
		case 6:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 20, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < -375.0f)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Idle_front_side");
				++RotationAnimation;
			}

		}
		break;
		case 7:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 30, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x < -525.0f)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Idle_side");
				++RotationAnimation;
			}

		}
		break;
		case 8:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 40, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > -525.0f)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Idle_side_back");
				++RotationAnimation;
			}

		}
		break;
		case 9:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 40, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > -375.0f)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Idle_3_4_back");
				++RotationAnimation;
			}

		}
		break;
		case 10:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 30, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > -225.0f)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,180.0f,0 });
				Ph2_Boss->ChangeAnimation("SD_Idle_3_4_back_back");
				++RotationAnimation;
			}

		}
		break;
		case 11:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 37, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > -75.0f)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,0,0 });
				Ph2_Boss->ChangeAnimation("SD_Idle_back");
				++RotationAnimation;
			}

		}
		case 12:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x + 15, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > 75.0f)
			{
				Ph2_Boss->GetTransform()->SetLocalRotation({ 0,0,0 });
				Ph2_Boss->ChangeAnimation("SD_Idle_3_4_back_back");
				++RotationAnimation;
			}

		}
		break;

		case 13:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 20, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > 225.0f)
			{

				Ph2_Boss->ChangeAnimation("SD_Idle_3_4_back");
				++RotationAnimation;
			}

		}
		break;

		case 14:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 35, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > 375)
			{

				Ph2_Boss->ChangeAnimation("SD_Idle_side_back");
				++RotationAnimation;
			}

		}
		break;

		case 15:
		{
			jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x - 40, Ph2_Boss->GetTransform()->GetLocalPosition().y - 60,0 });
			if (Pos_x > 525)
			{

				Ph2_Boss->ChangeAnimation("SD_Idle_side");
				RotationAnimation = 0;
			}

		}
		break;
		default:
			break;
		}
	


	Ph2_Boss->GetTransform()->SetLocalPosition({ -Pos_x, Pos_y,0 });

	test1 += _Time;



	if (test1 > 0.1 && f == 0)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x ,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 0.2 && f == 1)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x ,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 0.3 && f == 2)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 0.4 && f == 3)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 0.5 && f == 4)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 0.6 && f == 5)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 0.7 && f == 6)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 0.8 && f == 7)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 0.9 && f == 8)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.0 && f == 9)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 1.1 && f == 10)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.2 && f == 11)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.3 && f == 12)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.4 && f == 13)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 1.5 && f == 14)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.6 && f == 15)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 1.7 && f == 16)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 1.8 && f == 17)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y ,83.0f });
		f++;
	}
	if (test1 > 1.9 && f == 18)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}
	if (test1 > 2.0 && f == 19)
	{

		ph2_jetpack_smoke_a[f]->On();
		ph2_jetpack_smoke_a[f]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
		f++;
	}

	for (size_t i = 0; i < ph2_jetpack_smoke_a.size(); i++)
	{
		if (ph2_jetpack_smoke_a[i]->IsAnimationEnd())
		{
			ph2_jetpack_smoke_a[i]->Off();
			ph2_jetpack_smoke_a[i]->ChangeAnimation("ph2_jetpack_smoke_a");
			ph2_jetpack_smoke_a[i]->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x + 10,jetpack->GetTransform()->GetLocalPosition().y,83.0f });
			ph2_jetpack_smoke_a[i]->On();

		}
	}

	

	if (Attack_Effect->IsAnimationEnd())
	{
		Attack_Effect->Off();
	}
	

	if (GetLiveTime() > RandomAttack)
	{
		if (Ph2_Boss->IsAnimationEnd())
		{
			ResetLiveTime();
		
			Attack_Effect->ChangeAnimation("SD_bow_big_spark");

			ChangeState(Ph2_DogAirPlaneState::Attack);
			return;
		}
	}


}
