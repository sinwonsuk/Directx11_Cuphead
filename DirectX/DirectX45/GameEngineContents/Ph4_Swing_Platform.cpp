#include "PrecompileHeader.h"
#include "Ph4_Swing_Platform.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"
#include "Player.h"
bool Ph4_Swing_Platform::Ph4_Platform_Check = false;
Ph4_Swing_Platform::Ph4_Swing_Platform()
{
}

Ph4_Swing_Platform::~Ph4_Swing_Platform()
{
}

void Ph4_Swing_Platform::Start()
{

	Swing_Rope = CreateComponent<GameEngineSpriteRenderer>();
	Swing_Rope->CreateAnimation({ .AnimationName = "Swing_Rope", .SpriteName = "Swing_Rope", .FrameInter = 0.2f,.Loop = true, .ScaleToTexture = true, });
	Swing_Rope->ChangeAnimation("Swing_Rope");
	Swing_Rope->GetTransform()->AddLocalPosition({ 140.0f,250.0f,56.0f });
	Swing_Rope->GetTransform()->AddLocalRotation({ 0.0f,0.0f,-30.0f });
	Swing_Rope->On();

	Swing_Platform = CreateComponent<GameEngineSpriteRenderer>();
	Swing_Platform->CreateAnimation({ .AnimationName = "Swing_Platform", .SpriteName = "Swing_Platform", .FrameInter = 0.2f,.Loop = true, .ScaleToTexture = true, });
	Swing_Platform->ChangeAnimation("Swing_Platform");
	Swing_Platform->GetTransform()->AddLocalPosition({ 0.0f,0.0f,56.0f });
	Swing_Platform->On();

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 200.0f, 50.0f, 300.0f });
	Collision->SetOrder((int)CollisionType::Ph4_swing_Platform);
	Collision->SetColType(ColType::AABBBOX2D);

	GetTransform()->AddLocalPosition({ 0.0f,-120.0f });
}

void Ph4_Swing_Platform::Update(float _Delta)
{
	if (CollisionCheck == true)
	{
		Time += _Delta; 
	}


	




	

	/*if (Collision->Collision((int)CollisionType::Player) == nullptr && CollisionCheck == true && CurPos.y > Player::MainPlayer->GetTransform()->GetLocalPosition().y )
	{
		Player::MainPlayer->SetGravity(true);
	}

	if (Time > 0.3)
	{
		CollisionCheck = false;
	}
*/



	/*if (Collision->Collision((int)CollisionType::Player) == nullptr && Ph4_Platform_Check == true)
	{
		Player::MainPlayer->SetGravity(false);
		Ph4_Platform_Check = false;
	}*/





	


	//else if (0.5 > GetLiveTime() && Ph4_Platform_Check == true)
	//{
	//	Player::MainPlayer->SetGravity(true);
	//}

	




	switch (choic)
	{
	case Choice::Intro :
	{
		if (Collision->Collision((int)CollisionType::PlayerDown) && Player::MainPlayer->GetJumpCheck() == false)
		{
			Player::MainPlayer->GetTransform()->AddLocalPosition({ float4::Right * (Speed)*_Delta });
		}
		GetTransform()->AddLocalPosition({ float4::Right * (Speed)*_Delta });

		if (GetTransform()->GetLocalPosition().y > 0)
		{

			if (Collision->Collision((int)CollisionType::PlayerDown) && Player::MainPlayer->GetJumpCheck() == false)
			{
				Player::MainPlayer->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Delta });
			}
			GetTransform()->AddLocalPosition({ float4::Down * Speed * _Delta });
		}

		if (GetTransform()->GetLocalPosition().x > 400)
		{
			if (Collision->Collision((int)CollisionType::PlayerDown) && Player::MainPlayer->GetJumpCheck() == false)
			{
				Player::MainPlayer->GetTransform()->AddLocalPosition({ float4::Up * (Speed + 40.0f) * _Delta });
			}
			GetTransform()->AddLocalPosition({ float4::Up * (Speed + 40.0f) * _Delta });
		}

	}
	break;
	case Choice::Idle:
	{

		if (Collision->Collision((int)CollisionType::PlayerDown) && Player::MainPlayer->GetJumpCheck() == false)
		{
			Player::MainPlayer->GetTransform()->AddLocalPosition({ float4::Right * (Speed)*_Delta });
		}
		GetTransform()->AddLocalPosition({ float4::Right * (Speed)*_Delta });

		if (GetTransform()->GetLocalPosition().x < -500.0f)
		{
			if (Collision->Collision((int)CollisionType::PlayerDown) && Player::MainPlayer->GetJumpCheck() == false)
			{
				Player::MainPlayer->GetTransform()->AddLocalPosition({ float4::Up * Speed * _Delta });
			}
			GetTransform()->AddLocalPosition({ float4::Up * Speed * _Delta });
		}

		if (GetTransform()->GetLocalPosition().y > 0)
		{
			if (Collision->Collision((int)CollisionType::PlayerDown) && Player::MainPlayer->GetJumpCheck() == false)
			{
				Player::MainPlayer->GetTransform()->AddLocalPosition({ float4::Down * Speed * _Delta });
			}
			GetTransform()->AddLocalPosition({ float4::Down * Speed * _Delta });
		}

		if (GetTransform()->GetLocalPosition().x > 400)
		{
			if (Collision->Collision((int)CollisionType::PlayerDown) && Player::MainPlayer->GetJumpCheck() == false)
			{
				Player::MainPlayer->GetTransform()->AddLocalPosition({ float4::Up * (Speed + 45.0f) * _Delta });
			}
			GetTransform()->AddLocalPosition({ float4::Up * (Speed + 45.0f) * _Delta });
		}

		else if (GetTransform()->GetLocalPosition().x > -500.0f)
		{
			if (Collision->Collision((int)CollisionType::PlayerDown) && Player::MainPlayer->GetJumpCheck() == false)
			{
				Player::MainPlayer->GetTransform()->AddLocalPosition({ float4::Up * (Speed - 45.0f) * _Delta });
			}
			GetTransform()->AddLocalPosition({ float4::Up * (Speed - 45.0f) * _Delta });
		}




	}
	break;
	default:
		break;
	}


	if (Collision->Collision((int)CollisionType::PlayerDown) && Player::MainPlayer->GetJumpCheck() == false)
	{
		Player::MainPlayer->SetGravity(false);
		CurPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
		Time = 0;
		CollisionCheck = true;
	}

	if (CollisionCheck == true && CurPos.y > Player::MainPlayer->GetTransform()->GetLocalPosition().y)
	{
		TransformData date = Player::MainPlayer->GetTransform()->GetTransDataRef();
		Collision->Off();

	}

	if (Time > 0.5)
	{
		Collision->On();
	}




	
	
	
}

void Ph4_Swing_Platform::Render(float _Delta)
{
}
