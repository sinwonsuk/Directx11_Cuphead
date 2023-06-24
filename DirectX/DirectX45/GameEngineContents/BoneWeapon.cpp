#include "PrecompileHeader.h"
#include "BoneWeapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"
BoneWeapon::BoneWeapon()
{
}

BoneWeapon::~BoneWeapon()
{
}

void BoneWeapon::Start()
{
	if (nullptr == GameEngineSprite::Find("PinkBone"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");

		
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("PinkBone").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("WhiteBone").GetFullPath());
	}

	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "PinkBone", .SpriteName = "PinkBone", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet->CreateAnimation({ .AnimationName = "WhiteBone", .SpriteName = "WhiteBone", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });

	Bullet->ChangeAnimation("WhiteBone");
	
	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 20.0f, 20.0f, 300.0f });
	Collision->SetOrder((int)CollisionType::BossAttack);


}

void BoneWeapon::Update(float _Delta)
{
	Collision->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });

	switch (Check)
	{
	case 0:
	{
		if (Bullet->GetTransform()->GetWorldPosition().x > 580 && Time < 1)
		{
			MoveDir = { 0,0 };

			Time += _Delta;
		}

		else if (Bullet->GetTransform()->GetWorldPosition().x < 580 && Time < 1)
		{
			MoveDir = { 1,0 };
			Bullet->GetTransform()->AddWorldPosition({ MoveDir * _Delta * 800 });
		}

		

		if (Time > 1)
		{
			MoveDir = { -1,0 };
			Bullet->GetTransform()->AddWorldPosition({ MoveDir * _Delta * 800 });
		}


	}
	break;
	case 1:
	{
		if (Bullet->GetTransform()->GetWorldPosition().x < -580 && Time < 1)
		{
			MoveDir = { 0,0 };

			Time += _Delta;
		}

		else if (Bullet->GetTransform()->GetWorldPosition().x > -580 && Time < 1)
		{
			MoveDir = { -1,0 };
			Bullet->GetTransform()->AddWorldPosition({ MoveDir * _Delta * 800 });
		}

		

		if (Time > 1)
		{
			MoveDir = { 1,0 };

			Bullet->GetTransform()->AddWorldPosition({ MoveDir * _Delta * 800 });
		}

	}
	break;

	default:
		break;
	}



	

	/*if (GetLiveTime() > 3)
	{
		this->Death();
	}*/

}
