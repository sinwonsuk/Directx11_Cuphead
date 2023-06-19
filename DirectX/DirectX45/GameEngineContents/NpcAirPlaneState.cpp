#include "PrecompileHeader.h"
#include "NpcAirplane.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
void NpcAirplane::ChangeState(NpcAirplaneState _State)
{
	NpcAirplaneState NextState = _State;
	NpcAirplaneState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case NpcAirplaneState::Intro:
		break;
	case NpcAirplaneState::Intro2:
		AnimationCheck("Npc_Intro2");
		break;
	case NpcAirplaneState::Idle:
		AnimationCheck("Npc_Idle");
		break;
	default:
		break;
	}


}

void NpcAirplane::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case NpcAirplaneState::Intro:
		IntroUpdate(_Time);
		break;
	case NpcAirplaneState::Intro2:
		Intro2Update(_Time);
		break;
	case NpcAirplaneState::Idle:
		IdleUpdate(_Time);
		break;

	default:
		break;
	}



}

void NpcAirplane::Intro2Update(float _Time)
{
	if (Npc->IsAnimationEnd())
	{
		ChangeState(NpcAirplaneState::Idle);
		return;
	}
}

void NpcAirplane::IntroUpdate(float _Time)
{
	if (Npc->IsAnimationEnd())
	{
		++IntroCheck;
	}

	if (IntroCheck == 4)
	{
		ChangeState(NpcAirplaneState::Intro2);
		return; 
	}
}

void NpcAirplane::IdleUpdate(float _Time)
{

}
