#include "PrecompileHeader.h"
#include "Ph2_DogAirpalne.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>


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

		
		test = 1.5f;
		RotationAnimation = 3;
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

		
		test = 3.1f;
		RotationAnimation = 7;
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


		test = 4.7f;
		RotationAnimation = 11;
		Ph2_Boss->GetTransform()->SetLocalRotation({ 0,0,0 });
		ChangeState(Ph2_DogAirPlaneState::Rotation);
		return;
	}

}

void Ph2_DogAirpalne::RotationUpdate(float _Time)
{


	test1 += _Time;


	// 타원의 중심
	float x = 0.0;
	float y = 0.0;

	// 타원의 반지름
	double a = 550;
	double b = 300;

	test += 0.8f * _Time;

	//test += 1* _Time;
	Pos_x = x + a * cos(test);
	Pos_y = y + b * sin(test);

	if (Pos_x < -599.0f)
	{
		int a = 0;
	}




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
			//Ph2_Boss->ChangeAnimation("SD_Idle_3_4_back_back");
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
			//Ph2_Boss->ChangeAnimation("SD_Idle_3_4_back");
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

	

	if (dsda == false)
	{
		if (test1 > 0.2)
		{

			ph2_jetpack_smoke_a->On();
			ph2_jetpack_smoke_a->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y });
		}
		if (test1 > 0.4)
		{

			ph2_jetpack_smoke_a1->On();
			ph2_jetpack_smoke_a1->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y });
		}
		if (test1 > 0.6)
		{

			ph2_jetpack_smoke_a2->On();
			ph2_jetpack_smoke_a2->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y });
		}
		if (test1 >0.8)
		{

			ph2_jetpack_smoke_a3->On();
			ph2_jetpack_smoke_a3->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y });
		}
		if (test1 > 1.0)
		{
			ph2_jetpack_smoke_a4->On();
			dsda = true;
			ph2_jetpack_smoke_a4->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y });
		}

	}


	if (ph2_jetpack_smoke_a->IsAnimationEnd() )
	{	
		ph2_jetpack_smoke_a->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y });
	}
	if (ph2_jetpack_smoke_a1->IsAnimationEnd() )
	{
		
		ph2_jetpack_smoke_a1->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y });
	}

	if (ph2_jetpack_smoke_a2->IsAnimationEnd())
	{
	
		ph2_jetpack_smoke_a2->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y });
	}

	if (ph2_jetpack_smoke_a3->IsAnimationEnd() )
	{
		
		ph2_jetpack_smoke_a3->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y });
	}

	if (ph2_jetpack_smoke_a4->IsAnimationEnd())
	{
	
		ph2_jetpack_smoke_a4->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y });
	}
	

//	jetpack->GetTransform()->SetLocalRotation({ Ph2_Boss->GetTransform()->GetLocalRotation() });


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