#include "PrecompileHeader.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "PlayerRunEffect.h"

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
		AnimationCheck("Run",false,Frame);
		break;
	case PlayerState::Jump:
		AnimationCheck("Jump");
		break;
	case PlayerState::Duck:
		AnimationCheck("Duck");
		break;
	case PlayerState::Parry:
		AnimationCheck("Parry");
		break;
	case PlayerState::IdleAim:
		AnimationCheck("IdleAim");
		break;
	case PlayerState::UpAim:
		AnimationCheck("UpAim");
		break;
	case PlayerState::DownAim:
		AnimationCheck("DownAim");
		break;
	case PlayerState::DiagonalDownAim:
		AnimationCheck("DiagonalDownAim");
		break;
	case PlayerState::DiagonalUpAim:
		AnimationCheck("DiagonalUpAim");
		break;
	case PlayerState::Dash:
		AnimationCheck("GroundDash");
		break;
	case PlayerState::Idleattack:
		AnimationCheck("IdleAttack");
		break;
	case PlayerState::IdleAttackPre:
		AnimationCheck("IdleAttackPre");
		break;
	case PlayerState::RunAttack:
		AnimationCheck("RunAttack", false, Frame);
		break;
	case PlayerState::DiagonalUpAttack:
		AnimationCheck("DiagonalUpAttack");
		break;
	case PlayerState::DiagonalDownAttack:
		AnimationCheck("DiagonalDownAttack");
		break;
	case PlayerState::Up:
		AnimationCheck("Up");
		break;

	case PlayerState::UpAttack:
		AnimationCheck("UpAttack");
		break;
	case PlayerState::DiagonalUpRunAttack:
		AnimationCheck("DiagonalUpRunAttack");
		break;
	case PlayerState::UpAttackPre:
		AnimationCheck("UpAttackPre");
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
	case PlayerState::Parry:
		ParryUpdate(_Time);
		break;
	case PlayerState::IdleAim:
		IdleAimUpdate(_Time);
		break;
	case PlayerState::UpAim:
		UpAimUpdate(_Time);
		break;
	case PlayerState::DownAim:
		DownAimUpdate(_Time);
		break;
	case PlayerState::DiagonalDownAim:
		DiagonalDownAimUpdate(_Time);
		break;
	case PlayerState::DiagonalUpAim:
		DiagonalUpAimUpdate(_Time);
		break;
	case PlayerState::Dash:
		DashUpdate(_Time);
		break;
	case PlayerState::Idleattack:
		IdleAttackUpdate(_Time);
		break;
	case PlayerState::IdleAttackPre:
		IdleAttackPreUpdate(_Time);
		break;
	case PlayerState::RunAttack:
		RunAttackUpdate(_Time);
		break;
	case PlayerState::DiagonalUpAttack:
		DiagonalUpAttackUpdate(_Time);
		break;
	case PlayerState::DiagonalDownAttack:
		DiagonalUpAttackUpdate(_Time);
		break;
	case PlayerState::UpAttack:
		UpAttackUpdate(_Time);
		break;
	case PlayerState::Up:
		UpUpdate(_Time);
		break;
	case PlayerState::DiagonalUpRunAttack:
		DiagonalUpRunAttackUpdate(_Time); 
		break;
	case PlayerState::UpAttackPre:
		UpAttackPre(_Time);
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
		ResetLiveTime();
		return; 
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{	
		ChangeState(PlayerState::Run);
		ResetLiveTime();
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(PlayerState::Up);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		ChangeState(PlayerState::Jump);
		ResetLiveTime(); 
		JumpCheck = true;
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		ChangeState(PlayerState::Jump);
		ResetLiveTime();
		JumpCheck = true;
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		ChangeState(PlayerState::Duck);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerRock"))
	{
		ChangeState(PlayerState::IdleAim);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerDash"))
	{
		GetTransform()->AddLocalPosition({ 0,-40 });
		ChangeState(PlayerState::Dash);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::IdleAttackPre);
		return;
	}
}

void Player::RunUpdate(float _Time)
{
	

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft") && LeftMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight") && RightMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}



	if (GetLiveTime() > 0.5)
	{
		std::shared_ptr<PlayerRunEffect> Object =GetLevel()->CreateActor<PlayerRunEffect>(3);
		Object->SetState(EffectState::RunEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });
		ResetLiveTime();
		++EffectCheck;
	}
	
	if (EffectCheck == 1 && GetLiveTime() > 0.3)
	{
		std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(3);
		Object->SetState(EffectState::RunEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });
		ResetLiveTime();
		EffectCheck = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerAttack"))
	{
		Frame = Render0->GetCurrentFrame();
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return; 
	}


	if (true == GameEngineInput::IsPress("PlayerAttack"))
	{
		Frame = Render0->GetCurrentFrame();
		ChangeState(PlayerState::RunAttack);
		return; 
	}


	if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		ChangeState(PlayerState::Jump);		
		ResetLiveTime();
		JumpCheck = true;
		return;
	}


}

void Player::JumpUpdate(float _Time)
{

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft") && LeftMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight") && RightMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}


	if (true == GameEngineInput::IsDown("PlayerJump"))
	{
		ChangeState(PlayerState::Parry);
	
		
	}

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
			test = true;
		}
	}
	
	

	if (Gravity == true && test == true)
	{

		std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(3);
		Object->SetState(EffectState::JumpEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });

		ChangeState(PlayerState::Idle);
		test = false;
		return;
	}

	



}

void Player::DuckUpdate(float _Time)
{
	

	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}

}

void Player::ParryUpdate(float _Time)
{
	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft") && LeftMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight") && RightMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}


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
			test = true;
		}
	}



	if (Gravity == true && test == true)
	{
		std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(3);
		Object->SetState(EffectState::JumpEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });

		ChangeState(PlayerState::Idle);
		test = false;
		return;
	}
}

void Player::UpAimUpdate(float _Time)
{
	
	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DiagonalUpAim);
		return; 
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DiagonalUpAim);
		return;
	}
	
	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(PlayerState::IdleAim);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		ChangeState(PlayerState::DownAim);
		return;
	}


	

}

void Player::DownAimUpdate(float _Time)
{
	
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DiagonalDownAim);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DiagonalDownAim);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(PlayerState::IdleAim);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(PlayerState::UpAim);
		return;
	}
	

}

void Player::IdleAimUpdate(float _Time)
{
	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::Idle);
		return; 
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DiagonalUpAim);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DiagonalUpAim);
		return;
	}

	

	if (true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DiagonalDownAim);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DiagonalDownAim);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		ChangeState(PlayerState::DownAim);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(PlayerState::UpAim);
		return;
	}

	

}

void Player::DiagonalUpAimUpdate(float _Time)
{
	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(PlayerState::IdleAim);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(PlayerState::UpAim);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::UpAim);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalUpAttack);
		return;
	}

}

void Player::DiagonalDownAimUpdate(float _Time)
{
	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(PlayerState::IdleAim);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DownAim);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DownAim);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalDownAttack);
		return;
	}

}

void Player::DashUpdate(float _Time)
{



	if (GetTransform()->GetLocalScale().x > 0)
	{
		if (DashEffectCheck == false)
		{
			std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(3);
			Object->SetState(EffectState::DashEffect);
			Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x-100,GetTransform()->GetLocalPosition().y  });
			DashEffectCheck = true;
		}
	

		GetTransform()->AddLocalPosition(float4::Right * Speed * 2 * _Time);
	}

	if (GetTransform()->GetLocalScale().x < 0)
	{
		if (DashEffectCheck == false)
		{
			std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(3);
			Object->SetState(EffectState::DashEffect);
			Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x+100,GetTransform()->GetLocalPosition().y });
			DashEffectCheck = true;
		}
		GetTransform()->AddLocalPosition(float4::Left * Speed * 2 * _Time);
		
	}

	if (Render0->IsAnimationEnd())
	{
		DashEffectCheck = false;
		ChangeState(PlayerState::Idle);
		GetTransform()->AddLocalPosition({ 0,40 });
		return;
	}
	
}

void Player::IdleAttackUpdate(float _Time)
{

	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::RunAttack);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::RunAttack);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(PlayerState::UpAttackPre);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Run);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Run);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
}

void Player::IdleAttackPreUpdate(float _Time)
{
	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::RunAttack);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::RunAttack);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Run);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Run);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}

	if (Render0->IsAnimationEnd())
	{
		ChangeState(PlayerState::Idleattack);
		return; 
	}
}

void Player::RunAttackUpdate(float _Time)
{

	

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft") && LeftMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight") && RightMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		Frame = Render0->GetCurrentFrame();
		ChangeState(PlayerState::Run);
		return;
	}
	

	if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		ChangeState(PlayerState::Jump);
		JumpCheck = true;
		return;
	}
}

void Player::DiagonalUpAttackUpdate(float _Time)
{

}

void Player::DiagonalDownAttackUpdate(float _Time)
{
}

void Player::DiagonalUpRunAttackUpdate(float _Time)
{

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft") && LeftMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight") && RightMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}
	if (GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(PlayerState::RunAttack);
		return;
	}

	if (GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::Run);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		ChangeState(PlayerState::Jump);
		JumpCheck = true;
		return;
	}



}

void Player::UpUpdate(float _Time)
{
	
	if (GameEngineInput::IsPress("PlayerMoveRight") && GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return;
	}
	if (GameEngineInput::IsPress("PlayerMoveLeft") && GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return;
	}

	if (GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::Run);
		return;
	}
	if (GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Run);
		return;
	}




	if (GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::UpAttackPre);
		return;
	}

}



void Player::UpAttackUpdate(float _Time)
{
	if (GameEngineInput::IsPress("PlayerMoveRight") && GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return;
	}
	if (GameEngineInput::IsPress("PlayerMoveLeft") && GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return;
	}

	if (GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::Run);
		return;
	}
	if (GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Run);
		return;
	}

	if (GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}

	if (GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::Up);
		return;
	}



}

void Player::UpAttackPre(float _Time)
{
	if (Render0->IsAnimationEnd())
	{
		ChangeState(PlayerState::UpAttack);
		return; 
	}
	if (GameEngineInput::IsPress("PlayerMoveRight") && GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return;
	}
	if (GameEngineInput::IsPress("PlayerMoveLeft") && GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return;
	}

	if (GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::Run);
		return;
	}
	if (GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Run);
		return;
	}

	if (GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}

	if (GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::Up);
		return;
	}
}
