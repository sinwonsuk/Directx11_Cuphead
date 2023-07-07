#include "PrecompileHeader.h"
#include "Ph4_Swing_Platform.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineCollision.h>


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

	

	GetTransform()->AddLocalPosition({ 0.0f,0.0f });
}

void Ph4_Swing_Platform::Update(float _Delta)
{
	
	switch (choic)
	{
	case Choice::Intro :
	{

		GetTransform()->AddLocalPosition({ float4::Right * (Speed)*_Delta });

		if (GetTransform()->GetLocalPosition().y > 0)
		{
			GetTransform()->AddLocalPosition({ float4::Down * Speed * _Delta });
		}

		if (GetTransform()->GetLocalPosition().x > 400)
		{
			GetTransform()->AddLocalPosition({ float4::Up * (Speed + 40.0f) * _Delta });
		}

	}
	break;
	case Choice::Idle:
	{
		GetTransform()->AddLocalPosition({ float4::Right * (Speed)*_Delta });

		if (GetTransform()->GetLocalPosition().x < -500.0f)
		{
			GetTransform()->AddLocalPosition({ float4::Up * Speed * _Delta });
		}

		if (GetTransform()->GetLocalPosition().y > 0)
		{
			GetTransform()->AddLocalPosition({ float4::Down * Speed * _Delta });
		}

		if (GetTransform()->GetLocalPosition().x > 400)
		{
			GetTransform()->AddLocalPosition({ float4::Up * (Speed + 45.0f) * _Delta });
		}

		else if (GetTransform()->GetLocalPosition().x > -500.0f)
		{
			GetTransform()->AddLocalPosition({ float4::Up * (Speed - 45.0f) * _Delta });
		}




	}
	break;
	default:
		break;
	}







	
	
	
}

void Ph4_Swing_Platform::Render(float _Delta)
{
}
