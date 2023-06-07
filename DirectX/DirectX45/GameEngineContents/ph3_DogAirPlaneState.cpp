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
		//AnimationCheck("ph2_dog_a_intro");
		break;

	case Ph3_DogAirPlaneState::Idle:
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

	
}
