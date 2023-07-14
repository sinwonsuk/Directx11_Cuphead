#include "PrecompileHeader.h"
#include "ExWeapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "EnumClass.h"
#include "UserInterface.h"
#include "Player.h"
#include "ph3_DogAirPlane.h"
#include "Ph4_Bepi.h"
ExWeapon::ExWeapon()
{
}

ExWeapon::~ExWeapon()
{
}

void ExWeapon::Start()
{
	


	Bullet = CreateComponent<GameEngineSpriteRenderer>();

	Bullet->CreateAnimation({ .AnimationName = "Peashooter_EX_Loop", .SpriteName = "Peashooter_EX_Loop.png", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true,.FrameIndex = {2,3,4,5,6,7} });
	Bullet->CreateAnimation({ .AnimationName = "Peashooter_EX_Death", .SpriteName = "Peashooter_EX_Death.png", .FrameInter = 0.05f, .Loop = false,.ScaleToTexture = true, });
	Bullet->ChangeAnimation("Peashooter_EX_Loop");
	Bullet->SetScaleRatio(0.8f);

	Sfx = CreateComponent<GameEngineSpriteRenderer>();
	Sfx->CreateAnimation({ .AnimationName = "EX_ChargeUp", .SpriteName = "EX_ChargeUp", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	Sfx->ChangeAnimation("EX_ChargeUp");
	Sfx->SetScaleRatio(0.8f);
	Sfx_Dust = CreateComponent<GameEngineSpriteRenderer>();
	Sfx_Dust->CreateAnimation({ .AnimationName = "EX_Dust", .SpriteName = "EX_Dust", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	Sfx_Dust->ChangeAnimation("EX_Dust");
	
	Sfx_Dust->SetScaleRatio(0.8f);

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision->SetOrder((int)CollisionType::Bullet);

}

void ExWeapon::Update(float _Delta)
{
	Collision->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });


	if (CollisionCheck == false)
	{
		Bullet->GetTransform()->AddLocalPosition({ MoveDir * _Delta * 1500.0f });
	}



	if (Collision->Collision((int)CollisionType::BossBody) && CollisionCheck == false)
	{
		Bullet->ChangeAnimation("Peashooter_EX_Death");
		CollisionCheck = true;
	}



	if (Player::MainPlayer->GetTutorialCheck() == true)
	{


		std::shared_ptr<GameEngineTexture> testMap = GameEngineTexture::Find("Tutorial_ColMap.png");

		GameEnginePixelColor Pixel = testMap->GetPixel(Bullet->GetTransform()->GetLocalPosition().x + 640.0f, -Bullet->GetTransform()->GetLocalPosition().y + 360.0f);


		TransformData Data = Bullet->GetTransform()->GetTransDataRef();


		unsigned char ColorChar[4] = { 0,0,0,255 };

		for (size_t i = 0; i < 4; i++)
		{
			if (ColorChar[i] == Pixel.ColorChar[i])
			{
				++ColorCheck;
			}

			if (ColorCheck == 4)
			{
				CollisionColor = true;
			}
			if (ColorCheck != 4)
			{
				CollisionColor = false;
			}


		}
		ColorCheck = 0;

		if (CollisionColor == true)
		{
			Bullet->GetTransform()->AddLocalPosition({ MoveDir * _Delta * -1500.0f });
		}

		if (CollisionColor == true && ColorCollisionCheck == false)
		{
			Bullet->ChangeAnimation("Peashooter_EX_Death");
			ColorCollisionCheck = true;
		}
	}


	if (Ph3_DogAirplane::ph3_mainBoss != nullptr)
	{

		if (Collision->Collision((int)CollisionType::Ph3BossBody))
		{
			Ph3_DogAirplane::Hp -= 3;

			if (CollisionCheck == false)
			{
				Ph3_DogAirplane::ph3_mainBoss->Idle_Body->ColorOptionValue.PlusColor = { 1,1,1,0 };
				Ph3_DogAirplane::ph3_mainBoss->Idle_Body->ResetLiveTime();
				Bullet->ChangeAnimation("Peashooter_EX_Death");
				CollisionCheck = true;
			}
			std::shared_ptr<GameEngineCollision> collision = Collision->Collision((int)CollisionType::Bullet);
			collision->Death();
		}

		if (CollisionCheck == true && Ph3_DogAirplane::ph3_mainBoss->Idle_Body->GetLiveTime() > 0.05f)
		{
			Ph3_DogAirplane::ph3_mainBoss->Idle_Body->ColorOptionValue.PlusColor = { 0,0,0,0 };
		}
	}

	if (Ph4_Bepi::ph4_Bepi != nullptr)
	{

		if (Collision->Collision((int)CollisionType::Ph4_Beppi_Body))
		{
			Ph4_Bepi::ph4_Bepi->Hp -= 1;

			if (CollisionCheck == false)
			{
				Ph4_Bepi::ph4_Bepi->Phase4_Idle->ColorOptionValue.PlusColor = { 1,1,1,0 };
				Ph4_Bepi::ph4_Bepi->Phase4_Idle->ResetLiveTime();
				UserInterface::Cut += 0.1f;
				Bullet->ChangeAnimation("Peashooter_Death");
				CollisionCheck = true;
			}
			std::shared_ptr<GameEngineCollision> collision = Collision->Collision((int)CollisionType::Bullet);
			collision->Death();
		}



		if (CollisionCheck == true && Ph4_Bepi::ph4_Bepi->Phase4_Idle->GetLiveTime() > 0.05f)
		{
			Ph4_Bepi::ph4_Bepi->Phase4_Idle->ColorOptionValue.PlusColor = { 0,0,0,0 };

		}

	}
	if (Sfx_Dust->IsAnimationEnd())
	{
		Sfx_Dust->Death();
	}

	if (Sfx->IsAnimationEnd())
	{
		Sfx->Death();
	}

	if (GetLiveTime() > 5)
	{
		this->Death();
	}

	


}