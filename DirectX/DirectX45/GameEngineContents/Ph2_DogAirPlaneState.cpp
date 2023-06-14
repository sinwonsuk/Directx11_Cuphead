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
	case Ph2_DogAirPlaneState::UpIdle:
		AnimationCheck("ph2_dog_b_intro_transition");
		break;
	case Ph2_DogAirPlaneState::RightIdle:
		AnimationCheck("ph2_dog_c_intro_transition");
		break;
	case Ph2_DogAirPlaneState::DownIdle:
		AnimationCheck("ph2_dog_d_intro_transition");
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
	case Ph2_DogAirPlaneState::UpIdle:
		UpIdleUpdate(_Time);
		break;
	case Ph2_DogAirPlaneState::RightIdle:
		RightIdleUpdate(_Time);
		break;
	case Ph2_DogAirPlaneState::DownIdle:
		DownIdleUpdate(_Time);
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
	}

	Ph2_Boss->GetTransform()->AddLocalPosition({ 300.0f* _Time,0 });

	
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
	}

	Ph2_Boss->GetTransform()->AddLocalPosition({ 0.0f , -300.0f * _Time, 0.0f });

	

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
	}


	Ph2_Boss->GetTransform()->AddLocalPosition({ -300.0f * _Time,  0.0f, 0.0f });

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
	}

	Ph2_Boss->GetTransform()->AddLocalPosition({ 0.0f , 300.0f * _Time, 0.0f });



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
		
	// 타원의 중심
	float x = 0.0;
	float y = 0.0;

	// 타원의 반지름
	double a = 550;
	double b = 300;

	test += 1.2f * _Time;

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
		if (Pos_x < 525.0f)
		{

			Ph2_Boss->ChangeAnimation("SD_Idle_front_side");

			++RotationAnimation;

		}
		
	}
	break;
	case 1:
	{
		if (Pos_x < 375.0f)
		{

			Ph2_Boss->ChangeAnimation("SD_Idle_3_4_front");

			++RotationAnimation;

		}
	}
	break;
case 2:
	{
	if (Pos_x < 225.0f)
	{
		Ph2_Boss->ChangeAnimation("SD_Idle_front_front");
		++RotationAnimation;
	}
	}
	break;
case 3:
	{
	if (Pos_x < 75.0f)
	{
		Ph2_Boss->ChangeAnimation("SD_Idle_front_Up");
		++RotationAnimation;
	}
		
	}
	break;
case 4:
{
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
	if (Pos_x > -75.0f)
	{
		Ph2_Boss->GetTransform()->SetLocalRotation({ 0,0,0 });
		Ph2_Boss->ChangeAnimation("SD_Idle_back");
		++RotationAnimation;
	}

}
case 12:
{
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
	if (Pos_x > 225.0f)
	{

		Ph2_Boss->ChangeAnimation("SD_Idle_3_4_back");
		++RotationAnimation;
	}

}
break;

case 14:
{
	if (Pos_x > 375)
	{

		Ph2_Boss->ChangeAnimation("SD_Idle_side_back");
		++RotationAnimation;
	}

}
break;

case 15:
{
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



	

	
	// 회전 각도
	//test += 1* _Time*2;

	// 타원을 출력합니다.
	
		// x, y 좌표를 계산합니다.
//	float x_1 = x + a * cos(90);
//	float ds = cos(90);
		

	
		Ph2_Boss->GetTransform()->SetLocalPosition({ -Pos_x, Pos_y,0 });

	


		// 회전 각도를 증가시킵니다.
		
	
		if (test > 90)
		{
			int a = 0;
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