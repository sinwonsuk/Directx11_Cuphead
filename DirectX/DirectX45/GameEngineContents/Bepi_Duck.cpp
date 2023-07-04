#include "PrecompileHeader.h"
#include "Bepi_Duck.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineCollision.h>

Bepi_Duck::Bepi_Duck()
{
}

Bepi_Duck::~Bepi_Duck()
{
}

void Bepi_Duck::Start()
{
	DuckHead = CreateComponent<GameEngineSpriteRenderer>();
	DuckHead->CreateAnimation({ .AnimationName = "duck_head", .SpriteName = "duck_head", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	DuckHead->ChangeAnimation("duck_head");
	DuckHead->GetTransform()->AddLocalPosition({ -55.0f,-135.0f });

	DuckBody = CreateComponent<GameEngineSpriteRenderer>();
	DuckBody->SetScaleToTexture("duck_body_0002.png");

	DuckSpin = CreateComponent<GameEngineSpriteRenderer>();
	DuckSpin->CreateAnimation({ .AnimationName = "duck_spin", .SpriteName = "duck_spin", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	DuckSpin->ChangeAnimation("duck_spin");
	DuckSpin->Off(); 

	P_DuckHead = CreateComponent<GameEngineSpriteRenderer>();
	P_DuckHead->CreateAnimation({ .AnimationName = "p_duck_head", .SpriteName = "p_duck_head", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	P_DuckHead->ChangeAnimation("p_duck_head");
	P_DuckHead->Off();


	P_DuckBody = CreateComponent<GameEngineSpriteRenderer>();
	P_DuckBody->SetScaleToTexture("p_duck_body_0002.png");
	P_DuckBody->Off();

	P_DuckSpin = CreateComponent<GameEngineSpriteRenderer>();
	P_DuckSpin->CreateAnimation({ .AnimationName = "p_duck_spin", .SpriteName = "p_duck_spin", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	P_DuckSpin->ChangeAnimation("p_duck_spin");
	P_DuckSpin->Off(); 


	GetTransform()->AddLocalPosition({ 1100.0f,300.0f });

}

void Bepi_Duck::Update(float _Delta)
{
	
	switch (ColorCheck)
	{
	case 0:
	{
		if (GetTransform()->GetLocalPosition().y > 400.0f)
		{
			MoveDir = { -1,-1, };
		}
	

		if (GetTransform()->GetLocalPosition().y < 200.0f)
		{
			MoveDir = { -1,1, };
		}
	
		GetTransform()->AddLocalPosition({ MoveDir * 200.0f * _Delta });
	}
	break;

	case 1:
	{





	}
	break;

	default:
		break;
	}

	if (GetLiveTime() > 10)
	{
		this->Death(); 

	}

}

void Bepi_Duck::Render(float _Delta)
{
}
