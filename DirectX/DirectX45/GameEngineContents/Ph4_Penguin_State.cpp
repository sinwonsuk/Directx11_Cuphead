#include "PrecompileHeader.h"
#include "Ph4_Penguin.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"

void Ph4_Penguin::ChangeState(Ph4_Penguin_State _State)
{
	Ph4_Penguin_State NextState = _State;
	Ph4_Penguin_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Ph4_Penguin_State::Intro:

		break;

	case Ph4_Penguin_State::Ground:

		break;

	case Ph4_Penguin_State::Jump:

		break;
	case Ph4_Penguin_State::Idle:

		break;
	
	case Ph4_Penguin_State::Attack:

		break;
	

	default:
		break;
	}


}






void Ph4_Penguin::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Ph4_Penguin_State::Intro:
		IntroUpdate(_Time); 
		break;

	case Ph4_Penguin_State::Ground:
		GroundUpdate(_Time);
		break;

	case Ph4_Penguin_State::Jump:
		JumpUpdate(_Time);
		break;
	case Ph4_Penguin_State::Idle:
		IdleUpdate(_Time);
		break;

	case Ph4_Penguin_State::Attack:
		AttackUpdate(_Time);
		break;
	default:
		break;
	}


}

void Ph4_Penguin::IntroUpdate(float _Time)
{
	if (clown_ph3_penguin_roll->GetCurrentFrame() > 10 )
	{
		GetTransform()->AddLocalPosition({ float4::Down * _Time * Speed });
	}

	if (Collision->Collision((int)CollisionType::BepiMap) )
	{
	
		clown_ph3_penguin_roll->Off();
		clown_ph3_penguin_roll_ground->On();

		ChangeState(Ph4_Penguin_State::Ground);
		return; 
	}
}

void Ph4_Penguin::GroundUpdate(float _Time)
{
	
		switch (dir)
		{
		case Ph4_Penguin_Dir::Left:
		{


			if (MoveCheck == false)
			{
				GetTransform()->AddLocalPosition({ float4::Left * _Time * Speed });
			}
			if (GetTransform()->GetLocalPosition().x < StopPos)
			{
				CurPos = GetTransform()->GetLocalPosition();
				clown_ph3_penguin_roll_ground->Off();
				clown_ph3_penguin_roll_Jump->On();
				ChangeState(Ph4_Penguin_State::Jump);
				return; 

			}

			


		}
		break;
		case Ph4_Penguin_Dir::Right:
		{
			if (MoveCheck == false)
			{
				GetTransform()->AddLocalPosition({ float4::Right * _Time * Speed });
			}

			if (GetTransform()->GetLocalPosition().x > StopPos )
			{
				clown_ph3_penguin_roll_ground->Off();
				clown_ph3_penguin_roll_Jump->On();

				CurPos = GetTransform()->GetLocalPosition();

				ChangeState(Ph4_Penguin_State::Jump);
				MoveCheck = true;
			}

		}
		break;
		default:
			break;
		}
	
}



void Ph4_Penguin::JumpUpdate(float _Time)
{
	GetTransform()->AddLocalPosition({ float4::Up * _Time * (Speed-400.0f) });

	if (clown_ph3_penguin_roll_Jump->IsAnimationEnd())
	{
		GetTransform()->SetLocalPosition(CurPos);
		clown_ph3_penguin_roll_Jump->Off();
		clown_ph3_penguin_idle->On();
		ChangeState(Ph4_Penguin_State::Idle);
		return; 
	}
}
void Ph4_Penguin::IdleUpdate(float _Time)
{
	if (clown_ph3_penguin_idle->IsAnimationEnd())
	{
		++IdleNumber;
	}

	if (IdleNumber == 2)
	{
		clown_ph3_penguin_idle->Off();
		clown_ph3_penguin_clap->On(); 
		ChangeState(Ph4_Penguin_State::Attack);
		return;
	}

}
void Ph4_Penguin::AttackUpdate(float _Time)
{
	GetTransform()->AddLocalPosition({ float4::Up * _Time * (Speed - 400.0f) });

	if (clown_ph3_penguin_clap->GetCurrentFrame() > 9)
	{
		GetTransform()->AddLocalPosition({ float4::Down * _Time * (Speed - 400.0f) });
	}

	if (clown_ph3_penguin_clap->IsAnimationEnd())
	{
		GetTransform()->SetLocalPosition(CurPos);
		clown_ph3_penguin_idle->On();
		clown_ph3_penguin_clap->Off();

		IdleNumber = 0;
		clown_ph3_penguin_clap->ChangeAnimation("clown_ph3_penguin_clap");
		ChangeState(Ph4_Penguin_State::Idle);
		return; 
	}





}