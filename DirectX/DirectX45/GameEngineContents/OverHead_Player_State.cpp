#include "PrecompileHeader.h"
#include "OverHead_Player.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
void OverHead_Player::ChangeState(OverHead_PlayerState _State)
{
	OverHead_PlayerState NextState = _State;
	OverHead_PlayerState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case OverHead_PlayerState::DownIdle:
		AnimationCheck("Down_Idle");
		break;
	case OverHead_PlayerState::UpIlde:
		AnimationCheck("Up_Idle");
		break;

	case OverHead_PlayerState::RightIdle:
		AnimationCheck("Side_Idle");
		break;

	case OverHead_PlayerState::LeftIdle:
		AnimationCheck("Side_Idle");
		break;

	case OverHead_PlayerState::LeftMove:
		AnimationCheck("Side_Move");
		break;

	case OverHead_PlayerState::DownMove:
		AnimationCheck("Down_Move");
		break;

	case OverHead_PlayerState::RightMove:
		AnimationCheck("Side_Move");
		break;
	case OverHead_PlayerState::UpMove:
		AnimationCheck("Up_Move");
		break;
	case OverHead_PlayerState::Right_diagonal_Up:
		AnimationCheck("DU_Idle");
		break;
	case OverHead_PlayerState::Right_diagonal_Up_Move:
		AnimationCheck("DU_Move");
		break;
	case OverHead_PlayerState::Right_diagonal_Down:
		AnimationCheck("DD_Idle");
		break;
	case OverHead_PlayerState::Right_diagonal_Down_Move:
		AnimationCheck("DD_Move");
		break;
	case OverHead_PlayerState::Left_diagonal_Up:
		AnimationCheck("DU_Idle");
		break;
	case OverHead_PlayerState::Left_diagonal_Up_Move:
		AnimationCheck("DU_Move");
		break;
	case OverHead_PlayerState::Left_diagonal_Down:
		AnimationCheck("DD_Idle");
		break;
	case OverHead_PlayerState::Left_diagonal_Down_Move:
		AnimationCheck("DD_Move");
		break;

	
	default:
		break;
	}

}



void OverHead_Player::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case OverHead_PlayerState::DownIdle:
		DownIldeUpdate(_Time);
		break;
	case OverHead_PlayerState::UpIlde:
		UpIldeUpdate(_Time);
		break;

	case OverHead_PlayerState::RightIdle:
		RightIdleUpdate(_Time);
		break;

	case OverHead_PlayerState::LeftIdle:
		LeftIdleUpdate(_Time);
		break;

	case OverHead_PlayerState::LeftMove:
		LeftMoveUpdate(_Time);
		break;

	case OverHead_PlayerState::DownMove:
		DownMoveUpdate(_Time);
		break;

	case OverHead_PlayerState::RightMove:
		RightMoveUpdate(_Time);
		break;
	case OverHead_PlayerState::UpMove:
		UpMoveUpdate(_Time);
		break;
	case OverHead_PlayerState::Right_diagonal_Up:
		Right_diagonal_Up_Update(_Time);
		break;
	case OverHead_PlayerState::Right_diagonal_Up_Move:
		Right_diagonal_Up_Move_Update(_Time);
		break;
	case OverHead_PlayerState::Right_diagonal_Down:
		Right_diagonal_Down_Update(_Time);
		break;
	case OverHead_PlayerState::Right_diagonal_Down_Move:
		Right_diagonal_Down_Move_Update(_Time);
		break;
	case OverHead_PlayerState::Left_diagonal_Up:
		Left_diagonal_Up_Update(_Time);
		break;
	case OverHead_PlayerState::Left_diagonal_Up_Move:
		Left_diagonal_Up_Move_Update(_Time);
		break;
	case OverHead_PlayerState::Left_diagonal_Down:
		Left_diagonal_Down_Update(_Time);
		break;
	case OverHead_PlayerState::Left_diagonal_Down_Move:
		Left_diagonal_Down_Move_Update(_Time);
		break;

	default:
		break;
	}


}

void OverHead_Player::DownIldeUpdate(float _Time)
{
	GetTransform()->SetLocalRotation({ 0,0,0 });

	

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}


	if (true==GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(OverHead_PlayerState::UpMove);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		ChangeState(OverHead_PlayerState::DownMove);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(OverHead_PlayerState::DownIdle);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightMove);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftMove);
		return;
	}



}

void OverHead_Player::UpIldeUpdate(float _Time)
{
	GetTransform()->SetLocalRotation({ 0,0,0 });

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}


	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(OverHead_PlayerState::UpMove);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(OverHead_PlayerState::UpIlde);
		return;

	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		ChangeState(OverHead_PlayerState::DownMove);
		return;
	}
	
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightMove);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftMove);
		return;
	}

}

void OverHead_Player::RightIdleUpdate(float _Time)
{

	GetTransform()->SetLocalRotation({ 0,0,0 });

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}


	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(OverHead_PlayerState::UpMove);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		ChangeState(OverHead_PlayerState::DownMove);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightMove);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightIdle);
		return;

	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftMove);
		return;
	}

}

void OverHead_Player::LeftIdleUpdate(float _Time)
{
	GetTransform()->SetLocalRotation({ 0,180,0 });

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}


	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(OverHead_PlayerState::UpMove);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		ChangeState(OverHead_PlayerState::DownMove);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightMove);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightIdle);
		return;

	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftMove);
		return;
	}

}

void OverHead_Player::LeftMoveUpdate(float _Time)
{
	if (LeftMove == true)
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ float4::Left * 300 * _Time });
		GetTransform()->AddLocalPosition({ float4::Left * 300 * _Time });
	}



	GetTransform()->SetLocalRotation({ 0,180,0 });

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}


	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(OverHead_PlayerState::UpMove);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightMove);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftIdle);
		return;
	}

	
}

void OverHead_Player::DownMoveUpdate(float _Time)
{
	if (Gravity == true)
	{
		GetTransform()->AddLocalPosition({ float4::Down * 300 * _Time });
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ float4::Down * 300 * _Time });
	}
	

	GetTransform()->SetLocalRotation({ 0,0,0 });

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}


	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(OverHead_PlayerState::UpMove);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightMove);
		return;
	}
	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(OverHead_PlayerState::DownIdle);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftMove);
		return;
	}

}

void OverHead_Player::RightMoveUpdate(float _Time)
{
	if (RightMove == true)
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ float4::Right * 300 * _Time });
		GetTransform()->AddLocalPosition({ float4::Right * 300 * _Time });
	}
	GetTransform()->SetLocalRotation({ 0,0,0 });

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}


	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		ChangeState(OverHead_PlayerState::UpMove);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightIdle);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftMove);
		return;
	}
}

void OverHead_Player::UpMoveUpdate(float _Time)
{
	if (UpMove == true)
	{
		GetTransform()->AddLocalPosition({ float4::Up * 300 * _Time });
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ float4::Up * 300 * _Time });
	}
	GetTransform()->SetLocalRotation({ 0,0,0 });

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(OverHead_PlayerState::UpIlde);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftMove);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightMove);
		return;
	}



}

void OverHead_Player::Right_diagonal_Up_Update(float _Time)
{
	//GetTransform()->SetLocalRotation({ 0,0,0 });

	//if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	//{
	//	ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
	//	return;
	//}
	//if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	//{
	//	ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
	//	return;
	//}

	///*if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	//{
	//	ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
	//	return;
	//}*/
	//if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	//{
	//	ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
	//	return;
	//}

	//if (true == GameEngineInput::IsUp("PlayerMoveUp"))
	//{
	//	ChangeState(OverHead_PlayerState::UpIlde);
	//	return;
	//}
	//else if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	//{
	//	ChangeState(OverHead_PlayerState::RightIdle);
	//	return;
	//}

	//if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	//{
	//	ChangeState(OverHead_PlayerState::LeftMove);
	//	return;
	//}

}

void OverHead_Player::Right_diagonal_Up_Move_Update(float _Time)
{
	float4 MoveDir = { 1,1 };

	if (Right_diagonal_Move == true)
	{
		GetTransform()->AddLocalPosition({ MoveDir * 300 * _Time });
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ MoveDir * 300 * _Time });
	}
	GetTransform()->SetLocalRotation({ 0,0,0 });

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}

	/*if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}*/

	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(OverHead_PlayerState::UpIlde);
		return;
	}
	else if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightIdle);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftMove);
		return;
	}

}

void OverHead_Player::Right_diagonal_Down_Update(float _Time)
{
	
}

void OverHead_Player::Right_diagonal_Down_Move_Update(float _Time)
{
	float4 MoveDir = { 1,-1 };
	if (Right_diagonal_Down_Move == true)
	{
		GetTransform()->AddLocalPosition({ MoveDir * 300 * _Time });
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ MoveDir * 300 * _Time });
	}
	GetTransform()->SetLocalRotation({ 0,0,0 });

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}
	/*if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}*/

	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(OverHead_PlayerState::DownIdle);
		return;
	}
	else if (true == GameEngineInput::IsUp("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightIdle);
		return;
	}



	/*if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftMove);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		ChangeState(OverHead_PlayerState::RightMove);
		return;
	}*/

}

void OverHead_Player::Left_diagonal_Up_Update(float _Time)
{
	

}

void OverHead_Player::Left_diagonal_Up_Move_Update(float _Time)
{

	float4 MoveDir = { -1,1 };
	if (Left_diagonal_Move == true)
	{
		GetTransform()->AddLocalPosition({ MoveDir * 300 * _Time });
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ MoveDir * 300 * _Time });
	}
	GetTransform()->SetLocalRotation({ 0,180,0 });

	/*if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}*/
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerMoveUp"))
	{
		ChangeState(OverHead_PlayerState::UpIlde);
		return;
	}
	else if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftIdle);
		return;
	}

}

void OverHead_Player::Left_diagonal_Down_Update(float _Time)
{


}

void OverHead_Player::Left_diagonal_Down_Move_Update(float _Time)
{

	float4 MoveDir = { -1,-1 };
	if (Left_diagonal_Down_Move == true)
	{
		GetTransform()->AddLocalPosition({ MoveDir * 300 * _Time });
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ MoveDir * 300 * _Time });
	}

	GetTransform()->SetLocalRotation({ 0,180,0 });

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Up_Move);
		return;
	}
	/*if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveLeft")))
	{
		ChangeState(OverHead_PlayerState::Left_diagonal_Down_Move);
		return;
	}*/

	if (true == GameEngineInput::IsPress("PlayerMoveUp") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Up_Move);
		return;
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown") && (true == GameEngineInput::IsPress("PlayerMoveRight")))
	{
		ChangeState(OverHead_PlayerState::Right_diagonal_Down_Move);
		return;
	}

	if (true == GameEngineInput::IsUp("PlayerMoveDown"))
	{
		ChangeState(OverHead_PlayerState::DownIdle);
		return;
	}
	else if (true == GameEngineInput::IsUp("PlayerMoveLeft"))
	{
		ChangeState(OverHead_PlayerState::LeftIdle);
		return;
	}

}