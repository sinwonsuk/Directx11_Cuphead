#include "PrecompileHeader.h"
#include "Bepi_Duck.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"
#include "IdleWeapon.h"
#include "Player.h"
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
	DuckSpin->CreateAnimation({ .AnimationName = "duck_spin", .SpriteName = "duck_spin", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	DuckSpin->ChangeAnimation("duck_spin");
	DuckSpin->Off(); 

	P_DuckHead = CreateComponent<GameEngineSpriteRenderer>();
	P_DuckHead->CreateAnimation({ .AnimationName = "p_duck_head", .SpriteName = "p_duck_head", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	P_DuckHead->ChangeAnimation("p_duck_head");
	P_DuckHead->GetTransform()->AddLocalPosition({ -55.0f,-135.0f });
	P_DuckHead->Off();


	P_DuckBody = CreateComponent<GameEngineSpriteRenderer>();
	P_DuckBody->SetScaleToTexture("p_duck_body_0002.png");
	P_DuckBody->Off();

	P_DuckSpin = CreateComponent<GameEngineSpriteRenderer>();
	P_DuckSpin->CreateAnimation({ .AnimationName = "p_duck_spin", .SpriteName = "p_duck_spin", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	P_DuckSpin->ChangeAnimation("p_duck_spin");
	P_DuckSpin->Off(); 


	GetTransform()->AddLocalPosition({ 1100.0f,300.0f });


	PinkCollision = CreateComponent<GameEngineCollision>();
	PinkCollision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	PinkCollision->GetTransform()->AddLocalPosition({ 0.0f,-170.0f });
	PinkCollision->SetOrder((int)CollisionType::PinkDuck);
	PinkCollision->SetColType(ColType::AABBBOX2D);

	Body_Pink_Collision = CreateComponent<GameEngineCollision>();
	Body_Pink_Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Body_Pink_Collision->GetTransform()->AddLocalPosition({ 0.0f,-170.0f });
	Body_Pink_Collision->SetOrder((int)CollisionType::Duck);
	Body_Pink_Collision->SetColType(ColType::AABBBOX2D);

	Body_Collision = CreateComponent<GameEngineCollision>();
	Body_Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Body_Collision->GetTransform()->AddLocalPosition({ 0.0f,-170.0f });
	Body_Collision->SetOrder((int)CollisionType::Duck);
	Body_Collision->SetColType(ColType::AABBBOX2D);



	ParryEffect = CreateComponent<GameEngineSpriteRenderer>();
	ParryEffect->CreateAnimation({ .AnimationName = "ParryEffect", .SpriteName = "ParryEffect", .FrameInter = 0.08f, .Loop = false, .ScaleToTexture = true, });
	ParryEffect->ChangeAnimation("ParryEffect");
	ParryEffect->GetTransform()->AddLocalPosition({ 0.0f,-170.0f });
	ParryEffect->Off();

}


void Bepi_Duck::Update(float _Delta)
{
	



	switch (Check)
	{
	case DuckCheck::Idle:
	{
		if (CollisonCheck == false)
		{
			Body_Pink_Collision->Off();
			PinkCollision->Off();
			CollisonCheck = true;
		}
		
		if (GetTransform()->GetLocalPosition().y > 400.0f)
		{
			MoveDir = { -1,-1, };
		}
	

		if (GetTransform()->GetLocalPosition().y < 200.0f)
		{
			MoveDir = { -1,1, };
		}
	
		GetTransform()->AddLocalPosition({ MoveDir * 200.0f * _Delta });

		std::shared_ptr<GameEngineCollision> Body_Collision1 = Body_Collision->Collision((int)CollisionType::Bullet);

		if( Body_Collision1 && CollisionCheck == false)
		{
			DuckBody->Off();
			DuckHead->Off();
			Body_Collision->Off();
			DuckSpin->On();
			P_DuckSpin->Off();
			CollisionCheck = true; 

			Body_Collision1->Death(); 
			//collision->Death();

		}



	}
	break;

	case DuckCheck::Pink:
	{
		if (CollisonCheck == false)
		{
			Body_Collision->Off();
			DuckHead->Off();
			DuckBody->Off();
			P_DuckHead->On();
			P_DuckBody->On();
			CollisonCheck = true;
		}
	

		if (GetTransform()->GetLocalPosition().y > 400.0f)
		{
			MoveDir = { -1,-1, };
		}


		if (GetTransform()->GetLocalPosition().y < 200.0f)
		{
			MoveDir = { -1,1, };
		}

		GetTransform()->AddLocalPosition({ MoveDir * 200.0f * _Delta });



		std::shared_ptr<GameEngineCollision> Body_Collision1 = Body_Pink_Collision->Collision((int)CollisionType::Bullet);

		if (Body_Collision1 && CollisionCheck == false)
		{
			P_DuckBody->Off();
			P_DuckHead->Off();
			PinkCollision->Off();
			Body_Pink_Collision->Off();
			DuckSpin->Off();
			P_DuckSpin->On();
			CollisionCheck = true;

			Body_Collision1->Death();
			//collision->Death();
		}


	}
	break;

	default:
		break;
	}
	if (Player::MainPlayer->Hp <= 0)
	{
		this->Death();
	}
	if (GetLiveTime() > 10)
	{
		this->Death(); 

	}

	if (ParryEffect->IsAnimationEnd())
	{
		ParryEffect->Off(); 
		//PinkCollision->Off(); 
	}
}

void Bepi_Duck::Render(float _Delta)
{
}
