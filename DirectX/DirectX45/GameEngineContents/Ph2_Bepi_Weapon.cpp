#include "PrecompileHeader.h"
#include "Ph2_Bepi_Weapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "Player.h"
#include "EnumClass.h"
#include <math.h>
#include "IdleWeapon.h"
Ph2_Bepi_Weapon::Ph2_Bepi_Weapon()
{
}

Ph2_Bepi_Weapon::~Ph2_Bepi_Weapon()
{
	

}

void Ph2_Bepi_Weapon::Start()
{
	Bullet_Stop = CreateComponent<GameEngineSpriteRenderer>();
	Bullet_Stop->CreateAnimation({ .AnimationName = "Dogs_Appear", .SpriteName = "Dogs_Appear", .FrameInter = 0.1f, .Loop = false, .ScaleToTexture = true ,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12}  });
	Bullet_Stop->ChangeAnimation("Dogs_Appear");
	

	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "Dogs_Appear", .SpriteName = "Dogs_Appear", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true ,.FrameIndex = {13,14,15,16,17,18,19,20} });
	Bullet->ChangeAnimation("Dogs_Appear");
	Bullet->Off(); 


	Bullet_Destroy = CreateComponent<GameEngineSpriteRenderer>();
	Bullet_Destroy->CreateAnimation({ .AnimationName = "Dogs_Appear", .SpriteName = "Dogs_Appear", .FrameInter = 0.1f, .Loop = false, .ScaleToTexture = true ,.FrameIndex = {21,22,23,24,25,26,27} });
	Bullet_Destroy->ChangeAnimation("Dogs_Appear");
	Bullet_Destroy->Off();

	Pink_Bullet_Stop = CreateComponent<GameEngineSpriteRenderer>();
	Pink_Bullet_Stop->CreateAnimation({ .AnimationName = "pink_balloon_dog_intro", .SpriteName = "pink_balloon_dog_intro", .FrameInter = 0.1f, .Loop = false, .ScaleToTexture = true  });
	Pink_Bullet_Stop->ChangeAnimation("pink_balloon_dog_intro");
	Pink_Bullet_Stop->Off(); 

	Pink_Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Pink_Bullet->CreateAnimation({ .AnimationName = "pink_balloon_dog_chomp", .SpriteName = "pink_balloon_dog_chomp", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Pink_Bullet->ChangeAnimation("pink_balloon_dog_chomp");
	Pink_Bullet->Off();


	Pink_Bullet_Destroy = CreateComponent<GameEngineSpriteRenderer>();
	Pink_Bullet_Destroy->CreateAnimation({ .AnimationName = "pink_balloon_dog_death", .SpriteName = "pink_balloon_dog_death", .FrameInter = 0.1f, .Loop = false, .ScaleToTexture = true });
	Pink_Bullet_Destroy->ChangeAnimation("pink_balloon_dog_death");
	Pink_Bullet_Destroy->Off();


	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision->SetOrder((int)CollisionType::BossAttack);
	Collision->SetColType(ColType::AABBBOX2D);

	Collision2 = CreateComponent<GameEngineCollision>();
	Collision2->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision2->SetOrder((int)CollisionType::ph2_Bepi_Attack);
	Collision2->SetColType(ColType::AABBBOX2D);

	Pink_Collision = CreateComponent<GameEngineCollision>();
	Pink_Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Pink_Collision->SetOrder((int)CollisionType::BossAttack);
	Pink_Collision->SetColType(ColType::AABBBOX2D);
	Pink_Collision->Off(); 

	Pink_Collision2 = CreateComponent<GameEngineCollision>();
	Pink_Collision2->GetTransform()->SetLocalScale({ 100.0f, 100.0f, 50.0f });
	Pink_Collision2->SetOrder((int)CollisionType::ph2_Bepi_Attack_Pink);
	Pink_Collision2->SetColType(ColType::AABBBOX2D);
	Pink_Collision2->Off();



	ParryEffect = CreateComponent<GameEngineSpriteRenderer>();
	ParryEffect->CreateAnimation({ .AnimationName = "ParryEffect", .SpriteName = "ParryEffect", .FrameInter = 0.08f, .Loop = false, .ScaleToTexture = true, });
	ParryEffect->ChangeAnimation("ParryEffect");
	ParryEffect->GetTransform()->AddLocalPosition({ 0.0f,0.0f });
	ParryEffect->Off();


}

void Ph2_Bepi_Weapon::Update(float _Delta)
{
	switch (color)
	{
	case Color::Idle:
	{
		if (GetLiveTime() > 1.5)
		{
			if (Collision->Collision((int)CollisionType::RollerCoaster) && CollisionCheck == false)
			{
				Bullet_Destroy->On();
				Bullet->Off();
				Collision->Off();
				CollisionCheck = true;
			}

			if (Collision->Collision((int)CollisionType::BepiMap) && CollisionCheck == false)
			{
				Bullet_Destroy->On();
				Bullet->Off();
				Collision->Off();
				CollisionCheck = true;
			}


			std::vector<std::shared_ptr<GameEngineCollision>> collision;

			if (Collision2->CollisionAll((int)CollisionType::Bullet, collision) && CollisionCheck == false)
			{
				Bullet_Destroy->On();
				Bullet->Off();
				Collision->Off();
				Collision2->Off();
				CollisionCheck = true;

				for (size_t i = 0; i < collision.size(); i++)
				{
					collision[i].get()->Off();
				}

			}

			if (CollisionCheck == true)
			{
				GetTransform()->AddLocalPosition(-MoveDir * 2 * _Delta * 200.0f);
			}
		}

		switch (directon)
		{
		case Dir::Left:
		{
			if (MoveDirCheck == false)
			{
				float4 MoveDir1 = { Player::MainPlayer->GetTransform()->GetLocalPosition() - GetTransform()->GetLocalPosition() };
				MoveDir1.Normalize();

				MoveDir = MoveDir1.NormalizeReturn();
				/*Collision->Off();
				PinkCollision->Off();*/

				std::vector<float> a = { -600, 0 };
				std::vector<float> b = { MoveDir.x, MoveDir.y };

				// 두 벡터의 내적을 구합니다.
				float dot_product = 0;
				for (size_t i = 0; i < a.size(); i++) {
					dot_product += a[i] * b[i];
				}

				// 두 벡터의 크기를 구합니다.
				float a_norm = 0;
				for (size_t i = 0; i < a.size(); i++) {
					a_norm += a[i] * a[i];
				}
				a_norm = sqrt(a_norm);

				float b_norm = 0;
				for (size_t i = 0; i < b.size(); i++) {
					b_norm += b[i] * b[i];
				}
				b_norm = sqrt(b_norm);

				// 두 벡터 사이의 각을 구합니다.
				float angle = acos(dot_product / (float)(a_norm * b_norm));

				GetTransform()->AddLocalRotation({ 0,0,-(float)angle * 40.0f * _Delta * 200.0f });

				MoveDirCheck = true;
			}
		}
		break;
		case Dir::Right:
		{
			if (MoveDirCheck == false)
			{
				float4 MoveDir1 = { Player::MainPlayer->GetTransform()->GetLocalPosition() - GetTransform()->GetLocalPosition() };
				MoveDir1.Normalize();

				MoveDir = MoveDir1.NormalizeReturn();
				/*Collision->Off();
				PinkCollision->Off();*/

				std::vector<float> a = { 600, 0 };
				std::vector<float> b = { MoveDir.x, MoveDir.y };

				// 두 벡터의 내적을 구합니다.
				float dot_product = 0;
				for (size_t i = 0; i < a.size(); i++) {
					dot_product += a[i] * b[i];
				}

				// 두 벡터의 크기를 구합니다.
				float a_norm = 0;
				for (size_t i = 0; i < a.size(); i++) {
					a_norm += a[i] * a[i];
				}
				a_norm = sqrt(a_norm);

				float b_norm = 0;
				for (size_t i = 0; i < b.size(); i++) {
					b_norm += b[i] * b[i];
				}
				b_norm = sqrt(b_norm);

				// 두 벡터 사이의 각을 구합니다.
				float angle = acos(dot_product / (float)(a_norm * b_norm));

				GetTransform()->AddLocalRotation({ 0,0,-(float)angle * 40.0f * _Delta * 200.0f });

				MoveDirCheck = true;
			}
		}
		break;
		default:
			break;
		}

		if (Bullet_Stop->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet->On();
			BulletCheck = true;
		}

		if (Bullet_Stop->IsAnimationEnd())
		{
			Bullet_Stop->Off();
			//Bullet->On();

			GetTransform()->AddLocalPosition(MoveDir * 2 * _Delta * 200.0f);

		}

		if (Bullet_Destroy->IsAnimationEnd())
		{
			this->Death();
		}
	}
		break;
	case Color::Pink:
	{
		if (ColorCheck == false)
		{
			Bullet_Stop->Off();
			Bullet->Off();
			Bullet_Destroy->Off();
			Pink_Bullet_Stop->On(); 
			Collision->Off();
			Collision2->Off();
			ColorCheck = true; 
			Pink_Collision->On();
			Pink_Collision2->On(); 
		}
	
		if (GetLiveTime() > 1.5)
		{
			if (Pink_Collision->Collision((int)CollisionType::RollerCoaster) && CollisionCheck == false)
			{
				Pink_Bullet_Destroy->On();
				Pink_Bullet->Off();
				Pink_Collision->Off();
				CollisionCheck = true;
			}

			if (Pink_Collision->Collision((int)CollisionType::BepiMap) && CollisionCheck == false)
			{
				Pink_Bullet_Destroy->On();
				Pink_Bullet->Off();
				Pink_Collision->Off();
				CollisionCheck = true;
			}


			std::vector<std::shared_ptr<GameEngineCollision>> collision;

			if (Pink_Collision2->CollisionAll((int)CollisionType::Bullet, collision) && CollisionCheck == false)
			{
				Pink_Bullet_Destroy->On();
				Pink_Bullet->Off();
				Pink_Collision->Off();
				Pink_Collision2->Off();
				CollisionCheck = true;

				for (size_t i = 0; i < collision.size(); i++)
				{
					collision[i].get()->Off();
				}

			}

			if (CollisionCheck == true)
			{
				GetTransform()->AddLocalPosition(-MoveDir * 2 * _Delta * 200.0f);
			}
		}

		switch (directon)
		{
		case Dir::Left:
		{
			if (MoveDirCheck == false)
			{
				float4 MoveDir1 = { Player::MainPlayer->GetTransform()->GetLocalPosition() - GetTransform()->GetLocalPosition() };
				MoveDir1.Normalize();

				MoveDir = MoveDir1.NormalizeReturn();
				/*Collision->Off();
				PinkCollision->Off();*/

				std::vector<float> a = { -600, 0 };
				std::vector<float> b = { MoveDir.x, MoveDir.y };

				// 두 벡터의 내적을 구합니다.
				float dot_product = 0;
				for (size_t i = 0; i < a.size(); i++) {
					dot_product += a[i] * b[i];
				}

				// 두 벡터의 크기를 구합니다.
				float a_norm = 0;
				for (size_t i = 0; i < a.size(); i++) {
					a_norm += a[i] * a[i];
				}
				a_norm = sqrt(a_norm);

				float b_norm = 0;
				for (size_t i = 0; i < b.size(); i++) {
					b_norm += b[i] * b[i];
				}
				b_norm = sqrt(b_norm);

				// 두 벡터 사이의 각을 구합니다.
				float angle = acos(dot_product / (float)(a_norm * b_norm));

				GetTransform()->AddLocalRotation({ 0,0,-(float)angle * 40.0f * _Delta * 200.0f });

				MoveDirCheck = true;
			}
		}
		break;
		case Dir::Right:
		{
			if (MoveDirCheck == false)
			{
				float4 MoveDir1 = { Player::MainPlayer->GetTransform()->GetLocalPosition() - GetTransform()->GetLocalPosition() };
				MoveDir1.Normalize();

				MoveDir = MoveDir1.NormalizeReturn();
				/*Collision->Off();
				PinkCollision->Off();*/

				std::vector<float> a = { 600, 0 };
				std::vector<float> b = { MoveDir.x, MoveDir.y };

				// 두 벡터의 내적을 구합니다.
				float dot_product = 0;
				for (size_t i = 0; i < a.size(); i++) {
					dot_product += a[i] * b[i];
				}

				// 두 벡터의 크기를 구합니다.
				float a_norm = 0;
				for (size_t i = 0; i < a.size(); i++) {
					a_norm += a[i] * a[i];
				}
				a_norm = sqrt(a_norm);

				float b_norm = 0;
				for (size_t i = 0; i < b.size(); i++) {
					b_norm += b[i] * b[i];
				}
				b_norm = sqrt(b_norm);

				// 두 벡터 사이의 각을 구합니다.
				float angle = acos(dot_product / (float)(a_norm * b_norm));

				GetTransform()->AddLocalRotation({ 0,0,-(float)angle * 40.0f * _Delta * 200.0f });

				MoveDirCheck = true;
			}
		}
		break;
		default:
			break;
		}

		if (Pink_Bullet_Stop->IsAnimationEnd() && BulletCheck == false)
		{
			Pink_Bullet->On();
			BulletCheck = true;
		}

		if (Pink_Bullet_Stop->IsAnimationEnd())
		{
			Pink_Bullet_Stop->Off();
			//Bullet->On();

			GetTransform()->AddLocalPosition(MoveDir * 2 * _Delta * 200.0f);

		}

		if (Pink_Bullet_Destroy->IsAnimationEnd())
		{
			this->Death();
		}
	}
		break;
	default:
		break;
	}
	
	if (ParryEffect->GetCurrentFrame() > 0)
	{
		GetTransform()->AddLocalPosition(-MoveDir * 2 * _Delta * 200.0f);
	}

	if (ParryEffect->IsAnimationEnd())
	{
		ParryEffect->Off();
	
	}


}
