#include "PrecompileHeader.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "PlayerRunEffect.h"
#include "IdleWeapon.h"
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
	case PlayerState::DuckAttack:
		AnimationCheck("DuckAttack");
		break;
	case PlayerState::DuckAttackPre:
		AnimationCheck("DuckAttackPre");
		break;
	case PlayerState::DiagonalUpAttackPre:
		AnimationCheck("DiagonalUpAttackPre");
		break;
	case PlayerState::DiagonalDownAttackPre:
		AnimationCheck("DiagonalDownAttackPre");
		break;
	case PlayerState::IdleAimAttack:
		AnimationCheck("IdleAimAttack");
		break;
	case PlayerState::IdleAimAttackPre:
		AnimationCheck("IdleAimAttackPre");
		break;
	case PlayerState::UpAimAttack:
		AnimationCheck("UpAimAttack");
		break;
	case PlayerState::UpAimAttackPre:
		AnimationCheck("UpAimAttackPre");
		break;
	case PlayerState::DownAttack:
		AnimationCheck("DownAttack");
		break;
	case PlayerState::DownAttackPre:
		AnimationCheck("DownAttackPre");
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
		DiagonalDownAttackUpdate(_Time);
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
	case PlayerState::DuckAttack:
		DuckAttackUpdate(_Time); 
		break;
	case PlayerState::DuckAttackPre:
		DuckAttackPreUpdate(_Time);
		break;
	case PlayerState::DiagonalUpAttackPre:
		DiagonalUpAttackPreUpdate(_Time);
		break;
	
	case PlayerState::DiagonalDownAttackPre:
		DiagonalDownAttackPreUpdate(_Time);
		break;
	case PlayerState::IdleAimAttack:
		IdleAimAttackUpdate(_Time);
		break;
	case PlayerState::IdleAimAttackPre:
		IdleAimAttackPreUpdate(_Time);
		break;
	case PlayerState::UpAimAttack:
		UpAimAttackUpdate(_Time);
		break;
	case PlayerState::UpAimAttackPre:
		UpAimAttackPreUpdate(_Time);
		break;
	case PlayerState::DownAttack:
		DownAttackUpdate(_Time);
		break;
	case PlayerState::DownAttackPre:
		DownAttackPreUpdate(_Time);
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

	if (true == GameEngineInput::IsPress("PlayerDash"))
	{
		ChangeState(PlayerState::Dash);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerRock"))
	{
		ChangeState(PlayerState::IdleAim);
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

	if (true == GameEngineInput::IsPress("PlayerDash") && DashCheck == true)
	{
		DashCheck = false;
		ChangeState(PlayerState::Dash);
		return;
	}

	if (true == GameEngineInput::IsDown("PlayerJump"))
	{
		ChangeState(PlayerState::Parry);
	}

	if (JumpCheck == true)
	{
		if (GetLiveTime() < 0.25)
		{
			GetTransform()->AddLocalPosition(float4::Up * 1200 * _Time);
		}
		if (GetLiveTime() > 0.25)
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
		test = false;
		DashCheck = true; 
		ChangeState(PlayerState::Idle);
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
	if (true == GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::DuckAttackPre);
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
		if (GetLiveTime() < 0.25)
		{
			GetTransform()->AddLocalPosition(float4::Up * 1200 * _Time);
		}
		if (GetLiveTime() > 0.25)
		{
			ResetLiveTime();
			JumpCheck = false;
			test = true;
		}
	}

	if (true == GameEngineInput::IsPress("PlayerDash") && DashCheck == true)
	{
		DashCheck = false;
		ChangeState(PlayerState::Dash);
		return;
	}



	if (Gravity == true && test == true)
	{
		std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(3);
		Object->SetState(EffectState::JumpEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });

		test = false;
		DashCheck = true;
		ChangeState(PlayerState::Idle);
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
	if (true == GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::UpAttackPre);
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
	if (true == GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::DownAttackPre);
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

	if (true == GameEngineInput::IsPress("PlayerAttack"))
	{
		ChangeState(PlayerState::IdleAimAttackPre);
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
		ChangeState(PlayerState::DiagonalUpAttackPre);
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
		ChangeState(PlayerState::DiagonalDownAttackPre);
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
			Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x-50,GetTransform()->GetLocalPosition().y-25  });

			Object->GetTransform()->SetLocalPositiveScaleX();
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
			Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x+50,GetTransform()->GetLocalPosition().y - 25 });

			Object->GetTransform()->SetLocalNegativeScaleX();
			DashEffectCheck = true;
		}
		GetTransform()->AddLocalPosition(float4::Left * Speed * 2 * _Time);
		
	}
	if (Render0->IsAnimationEnd() && Gravity != true)
	{
	
		DashEffectCheck = false;
		ChangeState(PlayerState::Jump);
		return;
	}

	if (Render0->IsAnimationEnd() && Gravity ==true)
	{
		DashEffectCheck = false;
		ChangeState(PlayerState::Idle);
		return;
	}
	
}

void Player::IdleAttackUpdate(float _Time)
{

	
	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.15)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x+50,GetTransform()->GetLocalPosition().y+7 });
		Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 10 });
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->SetMoveDir(float4::Right);
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->SetMoveDir(float4::Left);
		}
		BulletTime = 0;
	}

	


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

	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.15)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x+50,GetTransform()->GetLocalPosition().y+7 });
		Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y-10  });
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->SetMoveDir(float4::Right);
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->SetMoveDir(float4::Left);
		}
		BulletTime = 0;
	}



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
	if (true == GameEngineInput::IsPress("PlayerDash"))
	{
		ChangeState(PlayerState::Dash);
		return;
	}


	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		Frame = Render0->GetCurrentFrame();
		ChangeState(PlayerState::Run);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerRock"))
	{
		ChangeState(PlayerState::IdleAim);
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

	if (true == GameEngineInput::IsPress("PlayerDash"))
	{
		ChangeState(PlayerState::Dash);
		return;
	}


	if (GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(PlayerState::RunAttack);
		return;
	}
	if (GameEngineInput::IsPress("PlayerRock"))
	{
		ChangeState(PlayerState::IdleAim);
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

void Player::DuckAttackUpdate(float _Time)
{
	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::Duck);
		return;
	}
	
}

void Player::DuckAttackPreUpdate(float _Time)
{
	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::Duck);
		return;
	}
	if (Render0->IsAnimationEnd())
	{
		ChangeState(PlayerState::DuckAttack);
		return;
	}


}

void Player::DiagonalDownAttackUpdate(float _Time)
{
	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalDownAim);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DownAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DownAttack);
		return;
	}
	

}
void Player::DiagonalDownAttackPreUpdate(float _Time)
{
	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalDownAim);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DownAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DownAttack);
		return;
	}
	
	if (Render0->IsAnimationEnd())
	{
		ChangeState(PlayerState::DiagonalDownAttack);
		return;
	}

}




void Player::IdleAimAttackUpdate(float _Time)
{
	
	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::Idle);
		return;

	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DiagonalUpAttack);
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
	
	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::IdleAim);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		ChangeState(PlayerState::DownAim);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(PlayerState::UpAimAttack);
		return;
	}

	

	

}

void Player::IdleAimAttackPreUpdate(float _Time)
{
	
	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DiagonalUpAttack);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DiagonalUpAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::Idle);
		return;
	}


	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::IdleAim);
		return;
	}


	

	
	if (Render0->IsAnimationEnd())
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}

}

void Player::UpAimAttackUpdate(float _Time)
{
	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DiagonalUpAttack);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DiagonalUpAttack);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::UpAim);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	
	
}

void Player::UpAimAttackPreUpdate(float _Time)
{
	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DiagonalUpAttack);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DiagonalUpAttack);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::UpAim);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	
	if (Render0->IsAnimationEnd())
	{
		ChangeState(PlayerState::UpAimAttack);
		return;
	}

}

void Player::DownAttackUpdate(float _Time)
{
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DiagonalDownAttack);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DiagonalDownAttack);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::DuckAttackPre);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::DownAim);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(PlayerState::UpAimAttack);
		return;
	}
	
}

void Player::DownAttackPreUpdate(float _Time)
{
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::DiagonalDownAttack);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(PlayerState::DiagonalDownAttack);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::DuckAttackPre);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::DownAim);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(PlayerState::UpAimAttack);
		return;
	}
	if (Render0->IsAnimationEnd())
	{
		ChangeState(PlayerState::DownAttack);
		return;
	}
}

void Player::DiagonalUpAttackUpdate(float _Time)
{
	if (true == GameEngineInput::IsUp("PlayerRock") && true == GameEngineInput::IsPress("PlayerMoveLeft") && true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerRock") && true == GameEngineInput::IsPress("PlayerMoveRight") && true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return;
	}

	
	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalUpAim);
		return;
	}


	if (true == GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(PlayerState::UpAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::UpAimAttack);
		return;
	}
	

}

void Player::DiagonalUpAttackPreUpdate(float _Time)
{
	if (true == GameEngineInput::IsUp("PlayerRock") && true == GameEngineInput::IsPress("PlayerMoveLeft") && true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerRock") && true == GameEngineInput::IsPress("PlayerMoveRight") && true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerRock"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerAttack"))
	{
		ChangeState(PlayerState::DiagonalUpAim);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(PlayerState::IdleAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(PlayerState::UpAimAttack);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::UpAimAttack);
		return;
	}
	
	if (Render0->IsAnimationEnd())
	{
		ChangeState(PlayerState::DiagonalUpAttack);
		return;
	}
}