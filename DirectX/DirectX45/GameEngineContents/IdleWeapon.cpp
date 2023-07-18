#include "PrecompileHeader.h"
#include "IdleWeapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"
#include "UserInterface.h"
#include "Player.h"
#include "ph3_DogAirPlane.h"
#include "TutorialObject.h"
#include "Ph4_Bepi.h"
#include "Bepi_Duck.h"
IdleWeapon::IdleWeapon()
{
}

IdleWeapon::~IdleWeapon()
{
}

void IdleWeapon::Start()
{
	if (nullptr == GameEngineSprite::Find("IdleWeapon.png"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		
		GameEngineSprite::LoadSheet(NewDir.GetPlusFileName("Weapon\\IdleWeapon.png").GetFullPath(),5,2);
		GameEngineSprite::LoadSheet(NewDir.GetPlusFileName("Weapon\\IdleWeaponSfx.png").GetFullPath(),4, 1);
		GameEngineSprite::LoadSheet(NewDir.GetPlusFileName("Weapon\\Peashooter_Death.png").GetFullPath(), 5, 2);
	}

	Bullet = CreateComponent<GameEngineSpriteRenderer>();

	Bullet->CreateAnimation({ .AnimationName = "IdleWeapon", .SpriteName = "IdleWeapon.png", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true,.FrameIndex = {2,3,4,5,6,7} });
	Bullet->CreateAnimation({ .AnimationName = "Peashooter_Death", .SpriteName = "Peashooter_Death.png", .FrameInter = 0.05f, .Loop = false,.ScaleToTexture = true, });
	Bullet->ChangeAnimation("IdleWeapon");

	Sfx = CreateComponent<GameEngineSpriteRenderer>();
	Sfx->CreateAnimation({ .AnimationName = "IdleWeaponSfx", .SpriteName = "IdleWeaponSfx.png", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	Sfx->ChangeAnimation("IdleWeaponSfx");
	
	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision->SetOrder((int)CollisionType::Bullet);


}

void IdleWeapon::Update(float _Delta)
{


	Collision->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });

	
		if (CollisionCheck == false)
		{
			Bullet->GetTransform()->AddLocalPosition({ MoveDir * _Delta * 1500.0f });
		}
		





		
		if (Collision->Collision((int)CollisionType::BossBody) && CollisionCheck == false)
		{
			UserInterface::Cut += 0.05f;
			Bullet->ChangeAnimation("Peashooter_Death");
			CollisionCheck = true;
			//Collision->Off(); 
		}
	
		if (Collision->Collision((int)CollisionType::Duck) && CollisionCheck == false)
		{
			UserInterface::Cut += 0.05f;
			Bullet->ChangeAnimation("Peashooter_Death");
			CollisionCheck = true;
			//Collision->Off(); 
		}
		/*if (Bepi_Duck::duck != nullptr)
		{
			if (Collision->Collision((int)CollisionType::Duck) && CollisionCheck == false)
			{
				
				UserInterface::Cut += 0.05f;
				Bullet->ChangeAnimation("Peashooter_Death");
				CollisionCheck = true;
				Collision->Off();
			}
			 if ((Collision->Collision((int)CollisionType::Pink_Duck_Body) && ColorCollisionCheck2 == false))
			{
				Bepi_Duck::duck->P_DuckBody->Off();
				Bepi_Duck::duck->P_DuckHead->Off();
				Bepi_Duck::duck->Body_Pink_Collision->Off();
				Bepi_Duck::duck->PinkCollision->Off();
				Bepi_Duck::duck->DuckSpin->Off();
				Bepi_Duck::duck->P_DuckSpin->On();
				UserInterface::Cut += 0.05f;
				Bullet->ChangeAnimation("Peashooter_Death");
				ColorCollisionCheck2 = true;
				Collision->Off();
			}


		}*/

		if (TutorialObject::Object != nullptr)
		{

			if (Collision->Collision((int)CollisionType::TutorialTarget) && CollisionCheck == false)
			{
				TutorialObject::Object->Gettutorial_target()->ColorOptionValue.PlusColor = { 1.0f,1.0f,1.0f,0.0f };
				TutorialObject::Object->GetPyramid_Topper()->ColorOptionValue.PlusColor = { 1.0f,1.0f,1.0f,0.0f };
				TutorialObject::Object->Gettutorial_target()->ResetLiveTime();
				TutorialObject::Object->TargetHp -= 1;
				UserInterface::Cut += 0.1f;

				Bullet->ChangeAnimation("Peashooter_Death");
				CollisionCheck = true;
				Collision->Off();
			}

			if (CollisionCheck == true && TutorialObject::Object->Gettutorial_target()->GetLiveTime() > 0.05f)
			{
				TutorialObject::Object->Gettutorial_target()->ColorOptionValue.PlusColor = { 0.0f,0.0f,0.0f,0.0f };
				TutorialObject::Object->GetPyramid_Topper()->ColorOptionValue.PlusColor = { 0.0f,0.0f,0.0f,0.0f };
			}
		}




		if (Ph3_DogAirplane::ph3_mainBoss != nullptr)
		{
			
				if (Collision->Collision((int)CollisionType::Ph3BossBody))
				{
					Ph3_DogAirplane::Hp -= 1;

					if (CollisionCheck == false)
					{
						Ph3_DogAirplane::ph3_mainBoss->Idle_Body->ColorOptionValue.PlusColor = { 1,1,1,0 };
						Ph3_DogAirplane::ph3_mainBoss->Idle_Body->ResetLiveTime();
						UserInterface::Cut += 0.1f;
						Bullet->ChangeAnimation("Peashooter_Death");
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











	if (GetLiveTime() > 5)
	{

		this->Death();
	}


	if (Sfx->IsAnimationEnd())
	{
		Sfx->Death();
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
			Bullet->ChangeAnimation("Peashooter_Death");
			ColorCollisionCheck = true;
		}
	}

	

	



	
}
