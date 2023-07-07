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




	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision->SetOrder((int)CollisionType::BossAttack);
	Collision->SetColType(ColType::AABBBOX2D);

	Collision2 = CreateComponent<GameEngineCollision>();
	Collision2->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision2->SetOrder((int)CollisionType::ph2_Bepi_Attack);
	Collision2->SetColType(ColType::AABBBOX2D);




}

void Ph2_Bepi_Weapon::Update(float _Delta)
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
				//collision[i].get().



				collision[i].get()->Off();
			}
		
		}

		if (CollisionCheck == true)
		{
			GetTransform()->AddLocalPosition(-MoveDir * 2);
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

			GetTransform()->AddLocalRotation({ 0,0,-(float)angle * 40.0f });

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

			GetTransform()->AddLocalRotation({ 0,0,-(float)angle * 40.0f });

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
		
		GetTransform()->AddLocalPosition(MoveDir * 2);
	
	}

	

	if (Bullet_Destroy->IsAnimationEnd())
	{
		this->Death();
	}


}
