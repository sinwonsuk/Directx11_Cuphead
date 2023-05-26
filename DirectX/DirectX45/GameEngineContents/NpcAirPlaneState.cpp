#include "PrecompileHeader.h"
#include "NpcAirplane.h"
void NpcAirplane::ChangeState(NpcAirplaneState _State)
{
	NpcAirplaneState NextState = _State;
	NpcAirplaneState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case NpcAirplaneState::Idle:
		AnimationCheck("Idle");
		break;

	default:
		break;
	}


}

void NpcAirplane::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case NpcAirplaneState::Idle:
		NpcAirplaneState(_Time);
		break;


	default:
		break;
	}



}