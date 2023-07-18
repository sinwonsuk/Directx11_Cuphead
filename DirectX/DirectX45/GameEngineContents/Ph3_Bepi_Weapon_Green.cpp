#include "PrecompileHeader.h"
#include "Ph3_Bepi_Weapon_Green.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "EnumClass.h"
#include "Player.h"
Ph3_Bepi_Weapon_Green::Ph3_Bepi_Weapon_Green()
{
}

Ph3_Bepi_Weapon_Green::~Ph3_Bepi_Weapon_Green()
{
}

void Ph3_Bepi_Weapon_Green::Start()
{
	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "Horseshoe_Green", .SpriteName = "Horseshoe_Green", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Bullet->ChangeAnimation("Horseshoe_Green");



	Pink_Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Pink_Bullet->CreateAnimation({ .AnimationName = "clown_ph3_horse_horseshoe_pink", .SpriteName = "clown_ph3_horse_horseshoe_pink", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Pink_Bullet->ChangeAnimation("clown_ph3_horse_horseshoe_pink");
	Pink_Bullet->Off(); 

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision->SetOrder((int)CollisionType::BossAttack);
	Collision->SetColType(ColType::AABBBOX2D);


	Pink_Collision = CreateComponent<GameEngineCollision>();
	Pink_Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Pink_Collision->SetOrder((int)CollisionType::BossAttack);
	Pink_Collision->SetColType(ColType::AABBBOX2D);
	Pink_Collision->Off();

	Pink_Collision2 = CreateComponent<GameEngineCollision>();
	Pink_Collision2->GetTransform()->SetLocalScale({ 100.0f, 100.0f, 50.0f });
	Pink_Collision2->SetOrder((int)CollisionType::ph3_Bepi_Attack_Pink);
	Pink_Collision2->SetColType(ColType::AABBBOX2D);
	Pink_Collision2->Off();

	ParryEffect = CreateComponent<GameEngineSpriteRenderer>();
	ParryEffect->CreateAnimation({ .AnimationName = "ParryEffect", .SpriteName = "ParryEffect", .FrameInter = 0.08f, .Loop = false, .ScaleToTexture = true, });
	ParryEffect->ChangeAnimation("ParryEffect");
	ParryEffect->GetTransform()->AddLocalPosition({ 0.0f,0.0f });
	ParryEffect->Off();
}

void Ph3_Bepi_Weapon_Green::Update(float _Delta)
{
	if (Player::MainPlayer->Hp <= 0)
	{
		this->Death();
	}

	switch (color)
	{
	case Ph3_Bepi_Weapon_Color::Green:
	{

		switch (MoveDir)
		{
		case 0:
		{
			AccTime += _Delta * 3;
			Pos_y = sin(AccTime) * 250;
			GetTransform()->SetLocalPosition({ (-AccTime * 100) + 270.0f, Pos_y + 100.0f });

		}
		break;

		case 1:
		{
			AccTime += _Delta * 3;
			Pos_y = sin(AccTime) * 250;
			GetTransform()->SetLocalPosition({ (AccTime * 100) - 270.0f, Pos_y + 100.0f });
		}
		break;


		default:
			break;
		}
	}
		break;
	case Ph3_Bepi_Weapon_Color::Red:
	{
		if (ColorCheck == false)
		{
			Bullet->Off();
			Collision->Off(); 

			Pink_Bullet->On(); 
			Pink_Collision->On(); 
			Pink_Collision2->On();
			ColorCheck = true;
		}
		switch (MoveDir)
		{


		case 0:
		{
			AccTime += _Delta * 3;
			Pos_y = sin(AccTime) * 250;
			if (ParryEffect->GetCurrentFrame() <= 0)
			{
				GetTransform()->SetLocalPosition({ (-AccTime * 100) + 270.0f, Pos_y + 100.0f });
			}
			

		}
		break;

		case 1:
		{
			AccTime += _Delta * 3;
			Pos_y = sin(AccTime) * 250;
			if (ParryEffect->GetCurrentFrame() <= 0)
			{
				GetTransform()->SetLocalPosition({ (AccTime * 100) - 270.0f, Pos_y + 100.0f });
			}
		}
		break;


		default:
			break;
		}
	}
		break;
	default:
		break;
	}
	


	if (ParryEffect->IsAnimationEnd())
	{
		ParryEffect->Off();
	}

	 
}
