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
	case Ph2_DogAirPlaneState::LeftIdle:
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
	case Ph2_DogAirPlaneState::LeftIdle:
		LeftIdleUpdate(_Time);
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
	

	if (Ph2_Boss->IsAnimationEnd())
	{
		++IntroCheck;

	}

	if (IntroCheck == 2)
	{
		//Ph2_Boss->GetTransform()->SetParent(GetTransform());
		ChangeState(Ph2_DogAirPlaneState::LeftIdle);
		return; 
	}

}

void Ph2_DogAirpalne::UpIntroUpdate(float _Time)
{

}

void Ph2_DogAirpalne::RightIntroUpdate(float _Time)
{
}

void Ph2_DogAirpalne::DownIntroUpdate(float _Time)
{
}

void Ph2_DogAirpalne::LeftIdleUpdate(float _Time)
{
		
	switch (RotationAnimation)
	{
	case 0:
	{
		if (Left_Pos_x > -525)
		{

			Ph2_Boss->ChangeAnimation("SD_Idle_front_side");

			++RotationAnimation;

		}
		
	}
	break;
	case 1:
	{
		if (Left_Pos_x > -375)
		{

			Ph2_Boss->ChangeAnimation("SD_Idle_3_4_front");

			++RotationAnimation;

		}
	}
	break;
case 2:
	{
	if (Left_Pos_x > -225)
	{
		Ph2_Boss->ChangeAnimation("SD_Idle_front_front");
		++RotationAnimation;
	}
	}
	break;
case 3:
	{
	if (Left_Pos_x > -75)
	{
		Ph2_Boss->ChangeAnimation("SD_Idle_front_Up");
		++RotationAnimation;
	}
		
		
	}
	break;

	default:
		break;
	}
	
	float RadiousX = 600;
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
		Left_Pos_x += 1;

		float y1 = (RadiousY * RadiousY) - ((RadiousY * RadiousY) * (Left_Pos_x * Left_Pos_x)) / (RadiousX * RadiousX);
		float y = sqrt(y1);

		Ph2_Boss->GetTransform()->SetLocalPosition({ Left_Pos_x ,y,0 });
	}

	if (RotationCheck == true)
	{
		Left_Pos_x -= 1;

		float y1 = (RadiousY * RadiousY) - ((RadiousY * RadiousY) * (Left_Pos_x * Left_Pos_x)) / (RadiousX * RadiousX);
		float y = sqrt(y1);

		Ph2_Boss->GetTransform()->SetLocalPosition({ Left_Pos_x ,-y,0 });
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