#include "PrecompileHeader.h"
#include "BoneWeapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"
#include "TimeFlow.h"
#include "DogAirplaneLevel.h"
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
	

	ParryEffect = CreateComponent<GameEngineSpriteRenderer>();
	ParryEffect->CreateAnimation({ .AnimationName = "ParryEffect", .SpriteName = "ParryEffect", .FrameInter = 0.08f, .Loop = false, .ScaleToTexture = true, });
	ParryEffect->ChangeAnimation("ParryEffect");

	ParryEffect->Off(); 


	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 20.0f, 20.0f, 300.0f });
	Collision->SetOrder((int)CollisionType::BossAttack);

	PinkCollision = CreateComponent<GameEngineCollision>();
	PinkCollision->GetTransform()->SetLocalScale({ 100.0f, 100.0f, 300.0f });
	PinkCollision->SetOrder((int)CollisionType::PinkObject);
	PinkCollision->Off();
}

void BoneWeapon::Update(float _Delta)
{
	
	
	/*if (PinkCollision->Collision((int)CollisionType::Player, ColType::AABBBOX2D, ColType::AABBBOX2D)&& CollisionCheck==false)
	{
		CollisionCheck = true;
		ResetLiveTime();
		
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0,0.0f);
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0,0.0f);

		TimeFlow::Time = 0.0f;
	}
	
	if (TimeFlow::Time > 1 && CollisionCheck ==true)
	{
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 1.0f);
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 1.0f);
	}*/

	PinkCollision->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });
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


	if (ParryEffect->IsAnimationEnd())
	{
		ParryEffect->Off(); 
	}
	

	if (GetLiveTime() > 7)
	{
		this->Death();
	}

}
