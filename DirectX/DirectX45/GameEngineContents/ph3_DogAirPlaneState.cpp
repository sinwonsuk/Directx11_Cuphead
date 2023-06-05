#include "PrecompileHeader.h"
#include "ph3_DogAirPlane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>

void Ph3_DogAirplane::ChangeState(Ph3_DogAirPlaneState _State)
{
	Ph3_DogAirPlaneState NextState = _State;
	Ph3_DogAirPlaneState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Ph3_DogAirPlaneState::Intro:
		AnimationCheck("ph2_dog_a_intro");
		break;

	case Ph3_DogAirPlaneState::Idle:
		AnimationCheck("ph2_dog_b_intro");
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
		LeftIntroUpdate(_Time);
		break;

	case Ph3_DogAirPlaneState::Idle:
		UpIntroUpdate(_Time);
		break;
	

	default:
		break;
	}



}