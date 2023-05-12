#include "PrecompileHeader.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

void Player::ChangeState(PlayerState _State)
{
	PlayerState NextState = _State;
	PlayerState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case PlayerState::Idle:
		AnimationCheck("Idle");
		break;
	case PlayerState::Run:
		AnimationCheck("Run");
		break;
	case PlayerState::Jump:
		AnimationCheck("Jump");
		break;
	case PlayerState::Duck:
		AnimationCheck("Duck");
		break;

	default:
		break;
	}


	switch (PrevState)
	{
	case PlayerState::Idle:
	
		break;
	
	default:
		break;
	}

}

void Player::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case PlayerState::Idle:
		IdleUpdate(_Time);
		break;
	case PlayerState::Run:
		RunUpdate(_Time);
		break;
	case PlayerState::Jump:
		JumpUpdate(_Time);
		break;
	case PlayerState::Duck:
		DuckUpdate(_Time);
		break;
	default:
		break;
	}



}

void Player::IdleUpdate(float _Time)
{
	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Run);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{	
		ChangeState(PlayerState::Run);
	}
	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		ChangeState(PlayerState::Jump);
	}
	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		ChangeState(PlayerState::Jump);
		JumpCheck = true;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		ChangeState(PlayerState::Duck);
	}

	

}

void Player::RunUpdate(float _Time)
{
	
	if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Idle);
	}
	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(PlayerState::Idle);
	}
	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		ChangeState(PlayerState::Jump);		
		JumpCheck = true;
	}


}

void Player::JumpUpdate(float _Time)
{
	
	
	if (JumpCheck == true)
	{
		if (GetLiveTime() < 0.2)
		{
			GetTransform()->AddLocalPosition(float4::Up * 1200 * _Time);
		}
		if (GetLiveTime() > 0.2)
		{
			ResetLiveTime();
			JumpCheck = false;
		}
	}
		


	if (Gravity == true )
	{
		ChangeState(PlayerState::Idle);
	}

}

void Player::DuckUpdate(float _Time)
{
	/*if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		ChangeState(PlayerState::Duck);
	}*/

	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(PlayerState::Idle);
	}

}
