#include "PrecompileHeader.h"
#include "Ph3_Bepi_Weapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "EnumClass.h"
#include "Player.h"
Ph3_Bepi_Weapon::Ph3_Bepi_Weapon()
{
}

Ph3_Bepi_Weapon::~Ph3_Bepi_Weapon()
{
}

void Ph3_Bepi_Weapon::Start()
{
	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "HorseShoe_Gold", .SpriteName = "HorseShoe_Gold", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Bullet->ChangeAnimation("HorseShoe_Gold");

	Bullet_Sfx = CreateComponent<GameEngineSpriteRenderer>();
	Bullet_Sfx->CreateAnimation({ .AnimationName = "clown_ph3_horse_horseshoe_puff", .SpriteName = "clown_ph3_horse_horseshoe_puff", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	Bullet_Sfx->ChangeAnimation("clown_ph3_horse_horseshoe_puff");	
	Bullet_Sfx->Off(); 

	Bullet_Destory = CreateComponent<GameEngineSpriteRenderer>();
	Bullet_Destory->CreateAnimation({ .AnimationName = "clown_ph3_horse_horseshoe_explode_yellow", .SpriteName = "clown_ph3_horse_horseshoe_explode_yellow", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	Bullet_Destory->ChangeAnimation("clown_ph3_horse_horseshoe_explode_yellow");
	Bullet_Destory->Off();



	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision->GetTransform()->AddLocalPosition({ 0.0f,0.0f });

	Collision->SetOrder((int)CollisionType::BossAttack);
	Collision->SetColType(ColType::AABBBOX2D);


}


void Ph3_Bepi_Weapon::Update(float _Delta)
{
	if (Player::MainPlayer->Hp <= 0)
	{
		this->Death(); 
	}

	if (Collision->Collision((int)CollisionType::RollerCoaster) && CoiisionCheck == false)
	{
		if (Sound_destory_Check == false)
		{
			destory = GameEngineSound::Play("clown_horseshoe_land_01.wav");
			Sound_destory_Check = true;
		}

		Bullet->Off(); 
		Bullet_Destory->On(); 
		Bullet_Sfx->On(); 
		Collision->Off(); 
		CoiisionCheck = true;
	}

	if (Collision->Collision((int)CollisionType::BepiMap) && CoiisionCheck == false)
	{
		if (Sound_destory_Check == false)
		{
			destory = GameEngineSound::Play("clown_horseshoe_land_01.wav"); 
			Sound_destory_Check = true;
		}

		Bullet->Off();
		Bullet_Destory->On();
		Bullet_Sfx->On();
		Collision->Off();

		CoiisionCheck = true;
	}

	if (Bullet_Destory->IsAnimationEnd())
	{
		Bullet_Destory->Off(); 
	}

	if (Bullet_Sfx->IsAnimationEnd())
	{
		Bullet_Sfx->Off();
	}


	if (CoiisionCheck == false)
	{

		switch (YellowPattern)
		{
		case 1:
		{

			if (GetLiveTime() < 1.0)
			{
				GetTransform()->AddLocalPosition({ float4::Right * Speed * _Delta });
				//Bullet_Sfx->GetTransform()->AddLocalPosition({ float4::Left * Speed * _Delta });
			}

			if (GetLiveTime() > 1.0 && Stop == false)
			{
				GetTransform()->AddLocalPosition({ 0.0f,200.0f });
				Stop = true;
			}

			if (GetLiveTime() > 1.0)
			{
				GetTransform()->AddLocalPosition({ float4::Left * Speed * _Delta });
			}

			if (StopPos > GetTransform()->GetLocalPosition().x && Stop == true)
			{
				GetTransform()->AddLocalPosition({ float4::Right * Speed * _Delta });

			}
			if (DownCheck == true)
			{
				if (Sound_Fail_Check == false)
				{
					Fail = GameEngineSound::Play("clown_horseshoe_drop_01.wav");
					Sound_Fail_Check = true;
				}
				GetTransform()->AddLocalPosition({ float4::Down * Speed * _Delta });
			}
		}
		break;
		case 0:
		{
			if (GetLiveTime() < 1.0)
			{
				GetTransform()->AddLocalPosition({ float4::Left * Speed * _Delta });
				//Bullet_Sfx->GetTransform()->AddLocalPosition({ float4::Right * Speed * _Delta });
			}

			if (GetLiveTime() > 1.0 && Stop == false)
			{
				GetTransform()->AddLocalPosition({ 0.0f,200.0f });
				Stop = true;
			}

			if (GetLiveTime() > 1.0)
			{
				GetTransform()->AddLocalPosition({ float4::Right * Speed * _Delta });
			}

			if (StopPos < GetTransform()->GetLocalPosition().x && Stop == true)
			{
				GetTransform()->AddLocalPosition({ float4::Left * Speed * _Delta });
			}
			if (DownCheck == true)
			{
				GetTransform()->AddLocalPosition({ float4::Down * Speed * _Delta });
			}
		}
		break;

		case 2:
		{

		}
		break;



		default:
			break;
		}

	}

}
