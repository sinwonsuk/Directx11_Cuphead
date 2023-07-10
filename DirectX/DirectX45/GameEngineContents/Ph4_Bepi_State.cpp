#include "PrecompileHeader.h"
#include "Ph4_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Ph4_Swing_Platform.h"
#include "Ph4_Penguin.h"
#include "Crown_Bepi_Map.h"
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
		AnimationCheck("Phase4_Idle");
		break;
	case Ph4_Bepi_State::BossAttackStart:
		AnimationCheck("Phase4_Attack_Start");
		break;
	case Ph4_Bepi_State::BossAttackMiddle:
		AnimationCheck("Phase4_Attack_Middle");
		break;
	case Ph4_Bepi_State::BossAttackEnd:
		AnimationCheck("Phase4_Attack_End");
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
	case Ph4_Bepi_State::BossAttackStart:
		BossAttackStartUpdate(_Time);
		break;
	case Ph4_Bepi_State::BossAttackMiddle:
		BossAttackMiddleUpdate(_Time);
		break;
	case Ph4_Bepi_State::BossAttackEnd:
		BossAttackEndUpdate(_Time);
		break;



	default:
		break;
	}


}
void Ph4_Bepi::BossIdleUpdate(float _Time)
{
	if (GetLiveTime() > 10 && Crown_Bepi_Map::Ph4_Check == true)
	{
		Crown_Bepi_Map::Ph4_Check = false;

		ChangeState(Ph4_Bepi_State::BossAttackStart);
		return; 
	}

}

void Ph4_Bepi::BossIntroUpdate(float _Time)
{
	if (Phase4_Intro->IsAnimationEnd() && Swing_Platform_Intro == false)
	{
		Phase4_Intro->Off();
		Phase4_Intro_Spin->On();
		umbrella_bk->On();

		std::shared_ptr<Ph4_Swing_Platform> Object = GetLevel()->CreateActor<Ph4_Swing_Platform>();
		Object->GetTransform()->AddLocalPosition({ -800.0f,200.0f });

		std::shared_ptr<Ph4_Swing_Platform> Object2 = GetLevel()->CreateActor<Ph4_Swing_Platform>();
		Object2->GetTransform()->AddLocalPosition({ -500.0f,200.0f });

		std::shared_ptr<Ph4_Swing_Platform> Object3 = GetLevel()->CreateActor<Ph4_Swing_Platform>();
		Object3->GetTransform()->AddLocalPosition({ -200.0f,200.0f });

		std::shared_ptr<Ph4_Swing_Platform> Object4 = GetLevel()->CreateActor<Ph4_Swing_Platform>();
		Object4->GetTransform()->AddLocalPosition({ 100.0f,200.0f });

		Swing_Platform_Intro = true;
		ResetLiveTime(); 
		ChangeState(Ph4_Bepi_State::BossIdle);
		return; 
	}

	
}

void Ph4_Bepi::BossAttackStartUpdate(float _Time)
{
	if (Phase4_Idle->IsAnimationEnd() )
	{
		ChangeState(Ph4_Bepi_State::BossAttackMiddle);
		return; 
	}
}

void Ph4_Bepi::BossAttackMiddleUpdate(float _Time)
{
	
	switch (AttackNumber)
	{
	case 0:
	{
		if (GetLiveTime() > 1)
		{
			std::shared_ptr<Ph4_Penguin> object = GetLevel()->CreateActor<Ph4_Penguin>();
			object->dir = Ph4_Penguin_Dir::Left;
			object->SetStopPos(-500.0f);
			++AttackNumber;
			ResetLiveTime(); 
		}
	}
	break; 
	case 1:
	{
		if (GetLiveTime() > 1)
		{
			std::shared_ptr<Ph4_Penguin> object = GetLevel()->CreateActor<Ph4_Penguin>();
			object->dir = Ph4_Penguin_Dir::Left;
			object->SetStopPos(-200.0f);
			++AttackNumber;
			ResetLiveTime();
		}
	}
	break;
	case 2:
	{
		if (GetLiveTime() > 1)
		{
			std::shared_ptr<Ph4_Penguin> object = GetLevel()->CreateActor<Ph4_Penguin>();
			object->dir = Ph4_Penguin_Dir::Right;
			object->SetStopPos(500.0f);
			++AttackNumber;
			ResetLiveTime();
		}
	}
	break;
	case 3:
	{
		if (GetLiveTime() > 1)
		{
			std::shared_ptr<Ph4_Penguin> object = GetLevel()->CreateActor<Ph4_Penguin>();
			object->dir = Ph4_Penguin_Dir::Right;
			object->SetStopPos(200.0f);
			++AttackNumber;
			ResetLiveTime();
		}
	}
	break;



	default:
		break;
	}

	if (GetLiveTime() > 1 && AttackNumber==4)
	{
		AttackNumber = 0;
		ChangeState(Ph4_Bepi_State::BossAttackEnd);
		return; 
	}



}

void Ph4_Bepi::BossAttackEndUpdate(float _Time)
{
	if (Phase4_Idle->IsAnimationEnd())
	{
		/*Crown_Bepi_Map::Ph4_Check = false;*/
		ChangeState(Ph4_Bepi_State::BossIdle);
		return;
	}

}

