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
		AnimationCheck("ph2_dog_a_intro_transition");
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
	//Ph2_Boss->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);

	/*if (Ph2_Boss->GetTransform()->GetLocalPosition().x > 20)
	{
		Ph2_Boss->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}*/

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
	
	
	GetTransform()->AddLocalRotation({ 1,0,0} );
	GetTransform()->AddLocalRotation({ 0,1,0 });
	
	TransformData date = Ph2_Boss->GetTransform()->GetTransDataRef();
	Ph2_Boss->GetTransform()->SetWorldRotation({ 0,0,0 });

	TransformData date1 = Ph2_Boss->GetTransform()->GetTransDataRef();

}

void Ph2_DogAirpalne::UpIdleUpdate(float _Time)
{
}

void Ph2_DogAirpalne::RightIdleUpdate(float _Time)
{
}

void Ph2_DogAirpalne::DownIdleUpdate(float _Time)
{
}