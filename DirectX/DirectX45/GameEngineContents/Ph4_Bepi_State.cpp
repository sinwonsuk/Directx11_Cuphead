#include "PrecompileHeader.h"
#include "Ph4_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Ph3_Bepi_Weapon.h"
#include "Ph3_Bepi_Weapon_Green.h"

void Ph4_Bepi::ChangeState(Ph4_Bepi_State _State)
{
	Ph4_Bepi_State NextState = _State;
	Ph4_Bepi_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Ph4_Bepi_State::BossIntro:

		break;


	case Ph4_Bepi_State::BossIdle:

		break;
	case Ph4_Bepi_State::BossRightAttack:

		break;
	case Ph4_Bepi_State::BossLeftAttack:

		break;

	default:
		break;
	}


}


void Ph4_Bepi::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Ph4_Bepi_State::BossIntro:
		BossIntroUpdate(_Time);
		break;
	case Ph4_Bepi_State::BossIdle:
		BossIdleUpdate(_Time);
		break;
	case Ph4_Bepi_State::BossRightAttack:
	
		break;
	case Ph4_Bepi_State::BossLeftAttack:
	
		break;
	default:
		break;
	}


}
void Ph4_Bepi::BossIdleUpdate(float _Time)
{
}

void Ph4_Bepi::BossIntroUpdate(float _Time)
{
}