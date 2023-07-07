#include "PrecompileHeader.h"
#include "Ph1_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Crown_Bepi_Level.h"
void Ph1_Bepi::ChangeState(Ph1_Beppi_State _State)
{
	Ph1_Beppi_State NextState = _State;
	Ph1_Beppi_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Ph1_Beppi_State::BossIntro:

		break;
	case Ph1_Beppi_State::BossIntro2:
		AnimationCheck("Beppi_Intro");
		break;
	case Ph1_Beppi_State::BossIntro3:
		AnimationCheck("Beppi_Intro3");
		break;
	case Ph1_Beppi_State::BossIdle:
		AnimationCheck("Beppi_Idle");
		break;
	case Ph1_Beppi_State::BossLeftStartAttack:
		AnimationCheck("Beppi_Rush_Attack_Start");
		break;
	case Ph1_Beppi_State::BossLeftRunAttack:
		AnimationCheck("Beppi_Rush_Attack_Run");
		break;
	case Ph1_Beppi_State::BossLeftFinishAttack:
		AnimationCheck("Beppi_Rush_Attack_Finish");
		break;
	case Ph1_Beppi_State::BossRightIdle:
		AnimationCheck("Beppi_Idle");
		break;
	case Ph1_Beppi_State::BossRightStartAttack:
		AnimationCheck("Beppi_Rush_Attack_Start");
		break;
	case Ph1_Beppi_State::BossRightRunAttack:
		AnimationCheck("Beppi_Rush_Attack_Run");
		break;
	case Ph1_Beppi_State::BossRightFinishAttack:
		AnimationCheck("Beppi_Rush_Attack_Finish");
		break;
	case Ph1_Beppi_State::BossLeftIdle:
		AnimationCheck("Beppi_Idle");
		break;
	case Ph1_Beppi_State::BossFinish:
		AnimationCheck("Ph1_Beppi_End");
		break;
	default:
		break;
	}


}






void Ph1_Bepi::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Ph1_Beppi_State::BossIntro:
		BossIntroUpdate(_Time); 
		break;
	case Ph1_Beppi_State::BossIntro2:
		BossIntro2Update(_Time);
		break;
	case Ph1_Beppi_State::BossIntro3:
		BossIntro3Update(_Time);
		break;

	case Ph1_Beppi_State::BossIdle:
		BossIdleUpdate(_Time);
		break;
	case Ph1_Beppi_State::BossLeftStartAttack:
		LeftStartAttackUpdate(_Time);
		break;
	case Ph1_Beppi_State::BossLeftRunAttack:
		LeftRunAttackUpdate(_Time);
		break;
	case Ph1_Beppi_State::BossLeftFinishAttack:
		LeftFinishAttackUpdate(_Time);
		break;
	case Ph1_Beppi_State::BossRightIdle:
		RightIdleUpdate(_Time);
		break;

	case Ph1_Beppi_State::BossRightStartAttack:
		RightStartAttackUpdate(_Time);
		break;
	case Ph1_Beppi_State::BossRightRunAttack:
		RightRunAttackUpdate(_Time);
		break;
	case Ph1_Beppi_State::BossRightFinishAttack:
		RightFinishAttackUpdate(_Time);
		break;
	case Ph1_Beppi_State::BossLeftIdle:
		LeftIdleUpdate(_Time);
		break;
	case Ph1_Beppi_State::BossFinish:
		BossFinsihUpdate(_Time);
		break;

	default:
		break;
	}



}

void Ph1_Bepi::BossIntroUpdate(float _Time)
{
	if (Beppi_Intro->IsAnimationEnd())
	{
		Beppi_Intro->Off(); 
		Beppi_Intro2->On();
		ChangeState(Ph1_Beppi_State::BossIntro2);
		return; 
	}
}

void Ph1_Bepi::BossIntro2Update(float _Time)
{
	if (Beppi_Intro2->IsAnimationEnd())
	{

		
		ChangeState(Ph1_Beppi_State::BossIntro3);
		return; 
	}
}

void Ph1_Bepi::BossIntro3Update(float _Time)
{
	if (introFinish == 2)
	{
		GetTransform()->AddLocalPosition({ -200.0f,-90.0f });
		ChangeState(Ph1_Beppi_State::BossIdle);
	}

	if (Beppi_Intro2->IsAnimationEnd())
	{
		++introFinish;
	}

	

}

void Ph1_Bepi::BossIdleUpdate(float _Time)
{
	DuckStart = true;
	switch (IdleCheck)
	{
	case 0:
	{
		if (Beppi_Intro2->GetCurrentFrame() < 5)
		{
			GetTransform()->AddLocalPosition({float4::Right * Speed * _Time});
		}

		if (Beppi_Intro2->GetCurrentFrame() > 13 )
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 19)
		{
			GetTransform()->AddLocalPosition({ float4::Left * Speed * _Time });
		}

		if (Beppi_Intro2->IsAnimationEnd())
		{
			IdleCheck = 1;
		}



	}
	break;
	case 1:
	{
		if (Beppi_Intro2->GetCurrentFrame() < 5 )
		{
			GetTransform()->AddLocalPosition({ float4::Left * Speed * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 13 )
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 19 )
		{
			GetTransform()->AddLocalPosition({ float4::Left * Speed * _Time });
		}
		if (Beppi_Intro2->IsAnimationEnd())
		{
			IdleCheck = 2;
		}
	}
	break;
	case 2:
	{
		if (Beppi_Intro2->GetCurrentFrame() < 5 )
		{
			GetTransform()->AddLocalPosition({ float4::Left * LastSpeed * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 5 )
		{
			IdleCheck = 3;
			GetTransform()->AddLocalPosition({ 0.0f,50.0f });
			ResetLiveTime(); 

			ChangeState(Ph1_Beppi_State::BossLeftStartAttack);
			return;
		}
		if (Beppi_Intro2->IsAnimationEnd())
		{
			IdleCheck = 3;
		}
	}
	break;
	default:
		break;
	}
}

void Ph1_Bepi::LeftStartAttackUpdate(float _Time)
{
	if (GetLiveTime() > 0.7f)
	{
		ChangeState(Ph1_Beppi_State::BossLeftRunAttack);
		return;
	}
}

void Ph1_Bepi::LeftRunAttackUpdate(float _Time)
{
	GetTransform()->AddLocalPosition({ float4::Left * RunSpeed * _Time });

	if (GetTransform()->GetLocalPosition().x < -500.0f && FinishCheck == 0)
	{
		FinishCheck = 1;
		ChangeState(Ph1_Beppi_State::BossLeftFinishAttack);
		return;
	}

	if (GetTransform()->GetLocalPosition().x < -500.0f && FinishCheck ==1)
	{

		ChangeState(Ph1_Beppi_State::BossFinish);
		return;
	}


}

void Ph1_Bepi::LeftFinishAttackUpdate(float _Time)
{


	if (Beppi_Intro2->GetCurrentFrame() > 20)
	{
		if (Beppi_Intro2->GetCurrentFrame() < 25)
		{
			GetTransform()->AddLocalPosition({ float4::Right * 1000.0f * _Time });
		}
	}

	if (Beppi_Intro2->IsAnimationEnd())
	{
		GetTransform()->AddLocalRotation({ 0.0f,180.0f,0.0f });
		GetTransform()->AddLocalPosition({ 0.0f,-40.0f });
		IdleCheck = 0;
		ChangeState(Ph1_Beppi_State::BossRightIdle);
		return; 
	}

}

void Ph1_Bepi::RightIdleUpdate(float _Time)
{
	switch (IdleCheck)
	{
	case 0:
	{
		if (Beppi_Intro2->GetCurrentFrame() < 5)
		{
			//GetTransform()->AddLocalPosition({ float4::Right * Speed * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 13)
		{
			GetTransform()->AddLocalPosition({ float4::Left * Speed * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 19)
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed * _Time });
		}

		if (Beppi_Intro2->IsAnimationEnd())
		{
			IdleCheck = 1;
		}



	}
	break;
	case 1:
	{
		if (Beppi_Intro2->GetCurrentFrame() < 5)
		{
			//GetTransform()->AddLocalPosition({ float4::Left * Speed * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 13)
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 19)
		{
			GetTransform()->AddLocalPosition({ float4::Left * Speed * _Time });
		}
		if (Beppi_Intro2->IsAnimationEnd())
		{
			IdleCheck = 2;
		}
	}
	break;
	case 2:
	{
		if (Beppi_Intro2->GetCurrentFrame() < 5)
		{
			GetTransform()->AddLocalPosition({ float4::Left * Speed * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 5)
		{
			IdleCheck = 3;
			GetTransform()->AddLocalPosition({ 0.0f,30.0f });
			ResetLiveTime();
			ChangeState(Ph1_Beppi_State::BossRightStartAttack);
			return;
		}
		
	}
	break;
	default:
		break;
	}
}

void Ph1_Bepi::RightStartAttackUpdate(float _Time)
{
	if (GetLiveTime() > 0.7f)
	{
		ChangeState(Ph1_Beppi_State::BossRightRunAttack);
		return;
	}
}

void Ph1_Bepi::RightRunAttackUpdate(float _Time)
{
	GetTransform()->AddLocalPosition({ float4::Right * RunSpeed * _Time });

	if (GetTransform()->GetLocalPosition().x > 500.0f)
	{
		ChangeState(Ph1_Beppi_State::BossRightFinishAttack);
		return;
	}
}

void Ph1_Bepi::RightFinishAttackUpdate(float _Time)
{

	if (Beppi_Intro2->GetCurrentFrame() > 20)
	{
		if (Beppi_Intro2->GetCurrentFrame() < 25)
		{
			GetTransform()->AddLocalPosition({ float4::Left * 1000.0f * _Time });
		}
	}

	if (Beppi_Intro2->IsAnimationEnd())
	{
		GetTransform()->AddLocalRotation({ 0.0f,180.0f,0.0f });
		GetTransform()->AddLocalPosition({ 0.0f,-40.0f });
		IdleCheck = 0;
		ChangeState(Ph1_Beppi_State::BossLeftIdle);
		return;
	}
}

void Ph1_Bepi::LeftIdleUpdate(float _Time)
{
	switch (IdleCheck)
	{
	case 0:
	{
		if (Beppi_Intro2->GetCurrentFrame() < 5)
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 13)
		{
			GetTransform()->AddLocalPosition({ float4::Left * Speed1 * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 19)
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed1 * _Time });
		}

		if (Beppi_Intro2->IsAnimationEnd())
		{
			IdleCheck = 1;
		}



	}
	break;
	case 1:
	{
		if (Beppi_Intro2->GetCurrentFrame() < 5)
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed * 0.5f * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 13)
		{
			GetTransform()->AddLocalPosition({ float4::Left * Speed1 * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 19)
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed1 * _Time });
		}
		if (Beppi_Intro2->IsAnimationEnd())
		{
			IdleCheck = 2;
		}
	}
	break;
	case 2:
	{
		if (Beppi_Intro2->GetCurrentFrame() < 5)
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed * _Time });
		}

		if (Beppi_Intro2->GetCurrentFrame() > 5)
		{
			IdleCheck = 3;
			GetTransform()->AddLocalPosition({ 0.0f,50.0f });
			ResetLiveTime();

			ChangeState(Ph1_Beppi_State::BossLeftStartAttack);
			return;
		}
		if (Beppi_Intro2->IsAnimationEnd())
		{
			IdleCheck = 3;
		}
	}
	break;
	default:
		break;
	}
}

void Ph1_Bepi::BossFinsihUpdate(float _Time)
{
	if (Beppi_Intro2->GetCurrentFrame() == 4 && FinishDown ==false)
	{
		GetTransform()->AddLocalPosition({ 0.0f,0.0f,75.0f });
		ResetLiveTime(); 
		FinishDown = true;
		
	}


	if (Beppi_Intro2->GetCurrentFrame() > 3)
	{
		GetTransform()->AddLocalPosition({ float4::Right * 400.0f * _Time });
		GetTransform()->AddLocalPosition({ float4::Down * 700.0f * _Time});
	}
	if (GetLiveTime() > 3)
	{
		Crown_Bepi_Level* Level = (Crown_Bepi_Level*)GetLevel();
		Level->PaseCheck = Pase::Pase2;
		this->Death(); 
		return;
	}
	
}

void Ph1_Bepi::UnloadUpdate(float _Time)
{
}
