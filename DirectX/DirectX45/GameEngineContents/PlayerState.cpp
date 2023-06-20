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
	case PlayerState::MapOut:
		AnimationCheck("Hit_Ground");
		break;
	case PlayerState::Fail:
		AnimationCheck("Jump");
		break;
	case PlayerState::Hit:
		AnimationCheck("Hit_Ground");
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
	case PlayerState::MapOut:
		MapOutUpdate(_Time);
		break;
	case PlayerState::Fail:
		FailUpdate(_Time);
		break;
	case PlayerState::Hit:
		HitUpdate(_Time); 
		break;
	default:
		break;
	}



}

void Player::IdleUpdate(float _Time)
{
	if (DownCheck == false)
	{
		CurPos_y = GetTransform()->GetLocalPosition().y;
		DownCheck = true;
	}
	

	if (CurPos_y-25.0f > GetTransform()->GetLocalPosition().y)
	{
		DownCheck = false;
		ChangeState(PlayerState::Fail);	
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(PlayerState::Run);
		DownCheck = false;
		ResetLiveTime();
		return; 
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{	
		DownCheck = false;
		ResetLiveTime();
		ChangeState(PlayerState::Run);
	
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		DownCheck = false;
		ChangeState(PlayerState::Up);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		DownCheck = false;
		ResetLiveTime(); 
		JumpCheck = true;
		ChangeState(PlayerState::Jump);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		DownCheck = false;
		ResetLiveTime();
		JumpCheck = true;
		ChangeState(PlayerState::Jump);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		DownCheck = false;
		ChangeState(PlayerState::Duck);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerRock"))
	{
		DownCheck = false;
		ChangeState(PlayerState::IdleAim);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerDash"))
	{
		DownCheck = false;
		ChangeState(PlayerState::Dash);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerAttack"))
	{
		DownCheck = false;
		ChangeState(PlayerState::IdleAttackPre);
		return;
	}
}

void Player::RunUpdate(float _Time)
{

	if (DownCheck == false)
	{
		CurPos_y = GetTransform()->GetLocalPosition().y;
		DownCheck = true;
	}
	

	if (CheckCamera == true)
	{
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
		}
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
		}

	}


	if (true == GameEngineInput::IsPress("PlayerMoveLeft") && LeftMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight") && RightMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}



	if (RunTime > 0.5)
	{
		std::shared_ptr<PlayerRunEffect> Object =GetLevel()->CreateActor<PlayerRunEffect>(101);
		Object->SetState(EffectState::RunEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });
		RunTime = 0;
		++EffectCheck;
	}
	
	if (EffectCheck == 1 && RunTime > 0.3)
	{
		std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(101);
		Object->SetState(EffectState::RunEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });
		RunTime = 0;
		EffectCheck = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerAttack"))
	{
		Frame = Render0->GetCurrentFrame();
		ChangeState(PlayerState::DiagonalUpRunAttack);
		return; 
	}


	if (CurPos_y - 25.0f > GetTransform()->GetLocalPosition().y)
	{
		DownCheck = false;
		ChangeState(PlayerState::Fail);
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
		ResetLiveTime();
		JumpCheck = true;
		ChangeState(PlayerState::Jump);		
		return;
	}
	

}

void Player::JumpUpdate(float _Time)
{
	

	if (CheckCamera == true)
	{
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
		}
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
		}

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
			JumpCheck = false;
			//test = true;
			ResetLiveTime();

		}
	}
	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveRight") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y + 25 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y + 0 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,45 });
			Object->SetMoveDir({ 1,1 });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y + 25 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y + 0 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,135 });
			Object->SetMoveDir({ -1,1 });
		}
		BulletTime = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveLeft") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y + 25 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y + 0 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,45 });
			Object->SetMoveDir({ 1,1 });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y + 25 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y + 0 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,135 });
			Object->SetMoveDir({ -1,1 });
		}
		BulletTime = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerAttack")&& true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveRight") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,315 });
			Object->SetMoveDir({ 1,-1 });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,225 });
			Object->SetMoveDir({ -1,-1 });
		}
		BulletTime = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveLeft") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,315 });
			Object->SetMoveDir({ 1,-1 });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,225 });
			Object->SetMoveDir({ -1,-1 });
		}
		BulletTime = 0;
	}



	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.15)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y + 2 });

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->SetMoveDir(float4::Right);
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
			Object->SetMoveDir(float4::Left);
		}
		BulletTime = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveDown") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 25 ,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 25,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,270 });
			Object->SetMoveDir({ float4::Down });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 25 ,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 25,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,270 });
			Object->SetMoveDir({ float4::Down });
		}
		BulletTime = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveUp") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 20 ,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 20,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 20 ,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 20,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		BulletTime = 0;
	}

	
		

	
	
	if (Gravity == false /*&& test == true*/)
	{

		std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(101);
		Object->SetState(EffectState::JumpEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });
		test = false;
		DashCheck = true;
		RunTime = 0;
		GravitySpeed = 450;
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

	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.15)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y + 2 });

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->SetMoveDir(float4::Right);
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
			Object->SetMoveDir(float4::Left);
		}
		BulletTime = 0;
		BulletTime = 0;
	}


	if (CheckCamera == true)
	{
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
		}
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
		}

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
			//test = true;
		}
	}


	if (true == GameEngineInput::IsPress("PlayerDash") && DashCheck == true)
	{
		DashCheck = false;
		ChangeState(PlayerState::Dash);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveRight") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y + 25 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y + 0 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,45 });
			Object->SetMoveDir({ 1,1 });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y + 25 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y + 0 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,135 });
			Object->SetMoveDir({ -1,1 });
		}
		BulletTime = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveUp") && true == GameEngineInput::IsPress("PlayerMoveLeft") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y + 25 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y + 0 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,45 });
			Object->SetMoveDir({ 1,1 });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y + 25 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y + 0 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,135 });
			Object->SetMoveDir({ -1,1 });
		}
		BulletTime = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveRight") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,315 });
			Object->SetMoveDir({ 1,-1 });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,225 });
			Object->SetMoveDir({ -1,-1 });
		}
		BulletTime = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveDown") && true == GameEngineInput::IsPress("PlayerMoveLeft") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,315 });
			Object->SetMoveDir({ 1,-1 });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y - 45 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,225 });
			Object->SetMoveDir({ -1,-1 });
		}
		BulletTime = 0;
	}



	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.15)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y + 2 });

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->SetMoveDir(float4::Right);
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
			Object->SetMoveDir(float4::Left);
		}
		BulletTime = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveDown") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 25 ,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 25,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,270 });
			Object->SetMoveDir({ float4::Down });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 25 ,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 25,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,270 });
			Object->SetMoveDir({ float4::Down });
		}
		BulletTime = 0;
	}

	if (true == GameEngineInput::IsPress("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveUp") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 20 ,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 20,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 20 ,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 20,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		BulletTime = 0;
	}



	if (Gravity == false /*&& test == true*/)
	{
		std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(101);
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
		ChangeState(PlayerState::UpAimAttackPre);
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
			std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(101);
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
			std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(101);
			Object->SetState(EffectState::DashEffect);
			Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x+50,GetTransform()->GetLocalPosition().y - 25 });

			Object->GetTransform()->SetLocalNegativeScaleX();
			DashEffectCheck = true;
		}
		GetTransform()->AddLocalPosition(float4::Left * Speed * 2 * _Time);
		
	}
	if (Render0->IsAnimationEnd() && Gravity != false)
	{
	
		JumpCheck = false;
		DashEffectCheck = false;
		ResetLiveTime();
		ChangeState(PlayerState::Jump);
		return;
	}

	if (Render0->IsAnimationEnd() && Gravity ==false)
	{
		DashEffectCheck = false;

		ChangeState(PlayerState::Idle);
		return;
	}
	
}

void Player::IdleAttackUpdate(float _Time)
{

	switch (Bulletlocation)
	{
	case 0:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y + 20 });
			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 10 });
				Object->SetMoveDir(float4::Right);
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 10 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });

				Object->SetMoveDir(float4::Left);
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 1:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y  });
			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 10 });
				Object->SetMoveDir(float4::Right);
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 10 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
				Object->SetMoveDir(float4::Left);
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 2:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y -20 });
			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 10 });
				Object->SetMoveDir(float4::Right);
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 10 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
				Object->SetMoveDir(float4::Left);
			}
			BulletTime = 0;
		}
		Bulletlocation = 0;
	}
	break;
	default:
		break;
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

	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		
		ResetLiveTime();
		JumpCheck = true;
		ChangeState(PlayerState::Jump);
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

	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y + 0 });

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->SetMoveDir(float4::Right);
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
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
	if (true == GameEngineInput::IsPress("PlayerJump"))
	{
		
		ResetLiveTime();
		JumpCheck = true;
		ChangeState(PlayerState::Jump);
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

	if (DownCheck == false)
	{
		CurPos_y = GetTransform()->GetLocalPosition().y;
		DownCheck = true;
	}
	

	switch (Bulletlocation)
	{
	case 0:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
			

			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y + 20 });
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 100,GetTransform()->GetLocalPosition().y - 20 });
				Object->SetMoveDir(float4::Right);
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 50,GetTransform()->GetLocalPosition().y + 20 });
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 100,GetTransform()->GetLocalPosition().y - 20 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
				Object->SetMoveDir(float4::Left);
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 1:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y });
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 100,GetTransform()->GetLocalPosition().y - 20 });
				Object->SetMoveDir(float4::Right);
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 50,GetTransform()->GetLocalPosition().y });
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 100,GetTransform()->GetLocalPosition().y - 20 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
				Object->SetMoveDir(float4::Left);
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 2:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y - 20 });
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 100,GetTransform()->GetLocalPosition().y - 20 });
				Object->SetMoveDir(float4::Right);
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 50,GetTransform()->GetLocalPosition().y - 20 });
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 100,GetTransform()->GetLocalPosition().y - 20 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
				Object->SetMoveDir(float4::Left);
			}
			BulletTime = 0;
		}
		Bulletlocation = 0;
	}
	break;
	default:
		break;
	}

	if (RunTime > 0.5)
	{
		std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(101);
		Object->SetState(EffectState::RunEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });
		RunTime = 0;
		++EffectCheck;
	}

	if (EffectCheck == 1 && RunTime > 0.3)
	{
		std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(101);
		Object->SetState(EffectState::RunEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });
		RunTime = 0;
		EffectCheck = 0;
	}

	if (CheckCamera == true)
	{
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
		}
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
		}

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


	if (true == GameEngineInput::IsUp("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		Frame = Render0->GetCurrentFrame();
		ChangeState(PlayerState::Run);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerAttack") && true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		Frame = Render0->GetCurrentFrame();
		ChangeState(PlayerState::Run);
		return;
	}

	if (CurPos_y - 25.0f > GetTransform()->GetLocalPosition().y)
	{
		DownCheck = false;
		ChangeState(PlayerState::Fail);
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
		ResetLiveTime();
		JumpCheck = true;
		ChangeState(PlayerState::Jump);
		
		return;
	}
}




void Player::DiagonalUpRunAttackUpdate(float _Time)
{
	switch (Bulletlocation)
	{
	case 0:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 100,GetTransform()->GetLocalPosition().y + 25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,45 });
				Object->SetMoveDir({ 1,1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 100,GetTransform()->GetLocalPosition().y + 25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,135 });
				Object->SetMoveDir({ -1,1 });
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 1:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);


			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 100,GetTransform()->GetLocalPosition().y + 25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,45 });
				Object->SetMoveDir({ 1,1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 100,GetTransform()->GetLocalPosition().y + 25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,135 });
				Object->SetMoveDir({ -1,1 });
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 2:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 100,GetTransform()->GetLocalPosition().y + 25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,45 });
				Object->SetMoveDir({ 1,1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 100,GetTransform()->GetLocalPosition().y + 25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,135 });
				Object->SetMoveDir({ -1,1 });
			}
			BulletTime = 0;
		}
		Bulletlocation = 0;
	}
	break;
	default:
		break;
	}

	if (CheckCamera == true)
	{
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
		}
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
		}

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
		ResetLiveTime();
		JumpCheck = true;
		ChangeState(PlayerState::Jump);

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

	if (GameEngineInput::IsPress("PlayerRock"))
	{
		ChangeState(PlayerState::UpAim);
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
	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x+20 ,GetTransform()->GetLocalPosition().y+80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 20,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x-20 ,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 20,GetTransform()->GetLocalPosition().y +80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		BulletTime = 0;
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

	if (GameEngineInput::IsPress("PlayerJump"))
	{
		
		ResetLiveTime();
		JumpCheck = true;
		ChangeState(PlayerState::Jump);
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

	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 20 ,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 20,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 20 ,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 20,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		BulletTime = 0;
	}

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
	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 80 ,GetTransform()->GetLocalPosition().y -40 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 80 ,GetTransform()->GetLocalPosition().y - 40 });
			
			Object->SetMoveDir({ float4::Right });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 80 ,GetTransform()->GetLocalPosition().y -40 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 80 ,GetTransform()->GetLocalPosition().y -40 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
			Object->SetMoveDir({ float4::Left });
		}
		BulletTime = 0;
	}

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
	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 80 ,GetTransform()->GetLocalPosition().y - 40 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 80 ,GetTransform()->GetLocalPosition().y - 40 });

			Object->SetMoveDir({ float4::Right });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 80 ,GetTransform()->GetLocalPosition().y - 40 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 80 ,GetTransform()->GetLocalPosition().y - 40 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
			Object->SetMoveDir({ float4::Left });
		}
		BulletTime = 0;
	}

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

	switch (Bulletlocation)
	{
	case 0:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,315 });
				Object->SetMoveDir({ 1,-1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,225 });
				Object->SetMoveDir({ -1,-1 });
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 1:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,315 });
				Object->SetMoveDir({ 1,-1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y -45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,225 });
				Object->SetMoveDir({ -1,-1 });
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 2:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,315 });
				Object->SetMoveDir({ 1,-1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,225 });
				Object->SetMoveDir({ -1,-1 });
			}
			BulletTime = 0;
		}
		Bulletlocation = 0;
	}
	break;
	default:
		break;
	}

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


	switch (Bulletlocation)
	{
	case 0:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,315 });
				Object->SetMoveDir({ 1,-1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,225 });
				Object->SetMoveDir({ -1,-1 });
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 1:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,315 });
				Object->SetMoveDir({ 1,-1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,225 });
				Object->SetMoveDir({ -1,-1 });
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 2:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,315 });
				Object->SetMoveDir({ 1,-1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y - 45 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,225 });
				Object->SetMoveDir({ -1,-1 });
			}
			BulletTime = 0;
		}
		Bulletlocation = 0;
	}
	break;
	default:
		break;
	}


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
	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y + 0 });

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->SetMoveDir(float4::Right);
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
			Object->SetMoveDir(float4::Left);
		}
		BulletTime = 0;
	}

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
	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 50,GetTransform()->GetLocalPosition().y + 0 });

		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->SetMoveDir(float4::Right);
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y - 10 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,180 });
			Object->SetMoveDir(float4::Left);
		}
		BulletTime = 0;
	}

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
	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 20 ,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 20,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 20 ,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 20,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		BulletTime = 0;
	}

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
	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 20 ,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 20,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 20 ,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 20,GetTransform()->GetLocalPosition().y + 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,90 });
			Object->SetMoveDir({ float4::Up });
		}
		BulletTime = 0;
	}

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
	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 25 ,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 25,GetTransform()->GetLocalPosition().y -80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,270 });
			Object->SetMoveDir({ float4::Down });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 25 ,GetTransform()->GetLocalPosition().y -80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 25,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,270 });
			Object->SetMoveDir({ float4::Down });
		}
		BulletTime = 0;
	}

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

	if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
	{
		std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
		if (GetTransform()->GetLocalScale().x > 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 25 ,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 25,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,270 });
			Object->SetMoveDir({ float4::Down });
		}
		if (GetTransform()->GetLocalScale().x < 0)
		{
			Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 25 ,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 25,GetTransform()->GetLocalPosition().y - 80 });
			Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,270 });
			Object->SetMoveDir({ float4::Down });
		}
		BulletTime = 0;
	}

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

void Player::MapOutUpdate(float _Time)
{
	if (CheckCamera == true)
	{
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
		}
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
		}

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
		if (GetLiveTime() < 0.5)
		{
			GetTransform()->AddLocalPosition(float4::Up * 1200 * _Time);
		}
		if (GetLiveTime() > 0.5)
		{

			GravitySpeed = 800;
			//GetTransform()->AddLocalPosition(float4::Down * 400 * _Time);
			ChangeState(PlayerState::Jump);
			return;
		

		}
	}
	

	if (Gravity == false && test == true)
	{

		std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(101);
		Object->SetState(EffectState::JumpEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });
		test = false;
		DashCheck = true;
		RunTime = 0;
		ChangeState(PlayerState::Idle);
		return;
	}





}

void Player::FailUpdate(float _Time)
{
	if (CheckCamera == true)
	{
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
		}
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
		}

	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft") && LeftMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight") && RightMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
	}

	
	if (Gravity == false /*&& test == true*/)
	{

		std::shared_ptr<PlayerRunEffect> Object = GetLevel()->CreateActor<PlayerRunEffect>(3);
		Object->SetState(EffectState::JumpEffect);
		Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x,GetTransform()->GetLocalPosition().y - 100 });
		test = false;
		DashCheck = true;
		RunTime = 0;
		GravitySpeed = 450;
		ChangeState(PlayerState::Idle);
		return;
	}

}

void Player::HitUpdate(float _Time)
{
	

	if (CheckCamera == true)
	{
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left * Speed * _Time);
		}
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right * Speed * _Time);
		}

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
			GetTransform()->AddLocalPosition(float4::Up * 800 * _Time);
		}
		if (GetLiveTime() > 0.2)
		{
			JumpCheck = false;
			return;
		}
	}


	if (Render0->IsAnimationEnd())
	{
		//Render0->ColorOptionValue.MulColor = { 1.0f,1.0f,1.0f,1.0f };
		ChangeState(PlayerState::Idle);
		return;
	}


	
	
	/*if (GetLiveTime() > 0.1)
	{
		Render0->ColorOptionValue.MulColor *= 1.0f;
		ResetLiveTime();
	}*/

	/*if (HitNumber == 7)
	{
		HitCheck = true;
		ChangeState(PlayerState::Idle);
		return;
	}*/



}

void Player::DiagonalUpAttackUpdate(float _Time)
{

	switch (Bulletlocation)
	{
	case 0:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);

			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y + 25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,45 });
				Object->SetMoveDir({ 1,1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y + 25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,135 });
				Object->SetMoveDir({ -1,1 });
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 1:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
			
			
			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y + 25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,45 });
				Object->SetMoveDir({ 1,1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x -60,GetTransform()->GetLocalPosition().y +25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,135 });
				Object->SetMoveDir({ -1,1 });
			}
			BulletTime = 0;
		}
		++Bulletlocation;
	}
	break;
	case 2:
	{
		if (true == GameEngineInput::IsPress("PlayerAttack") && BulletTime > 0.13)
		{
			std::shared_ptr<IdleWeapon> Object = GetLevel()->CreateActor<IdleWeapon>(3);
			if (GetTransform()->GetLocalScale().x > 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 60,GetTransform()->GetLocalPosition().y + 25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,45 });
				Object->SetMoveDir({ 1,1 });
			}
			if (GetTransform()->GetLocalScale().x < 0)
			{
				Object->GetSfx()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 60,GetTransform()->GetLocalPosition().y + 25 });
				Object->GetBullet()->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 40,GetTransform()->GetLocalPosition().y + 0 });
				Object->GetBullet()->GetTransform()->SetLocalRotation({ 0,0,135 });
				Object->SetMoveDir({ -1,1 });
			}
			BulletTime = 0;
		}
		Bulletlocation = 0;
	}
	break;
	default:
		break;
	}




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