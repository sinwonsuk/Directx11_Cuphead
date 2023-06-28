#include "PrecompileHeader.h"
#include "ph2_Boss_Weapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "Player.h"
#include "EnumClass.h"
ph2_Boss_Weapon::ph2_Boss_Weapon()
{
}

ph2_Boss_Weapon::~ph2_Boss_Weapon()
{
}

void ph2_Boss_Weapon::Start()
{
	if (nullptr == GameEngineSprite::Find("SD_bow"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_bow").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_bow_First").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_bow_pink").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_bow_pink_First").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_wow").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_wow_First").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_wow_pink").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_wow_pink_First").GetFullPath());
	}

	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "SD_bow", .SpriteName = "SD_bow", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });	
	Bullet->CreateAnimation({ .AnimationName = "SD_bow_pink", .SpriteName = "SD_bow_pink", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet->CreateAnimation({ .AnimationName = "SD_wow", .SpriteName = "SD_wow", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet->CreateAnimation({ .AnimationName = "SD_wow_pink", .SpriteName = "SD_wow_pink", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet->ChangeAnimation("SD_bow");
	Bullet->Off();


	Bullet_First = CreateComponent<GameEngineSpriteRenderer>();	
	Bullet_First->CreateAnimation({ .AnimationName = "SD_bow_First", .SpriteName = "SD_bow_First", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true,.FrameIndex = {} });	
	Bullet_First->CreateAnimation({ .AnimationName = "SD_bow_pink_First", .SpriteName = "SD_bow_pink_First", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet_First->CreateAnimation({ .AnimationName = "SD_wow_First", .SpriteName = "SD_wow_First", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet_First->CreateAnimation({ .AnimationName = "SD_wow_pink_First", .SpriteName = "SD_wow_pink_First", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet_First->ChangeAnimation("SD_bow_First");
	Bullet_First->Off();


	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 30.0f, 30.0f, 100.0f });
	Collision->SetOrder((int)CollisionType::BossAttack);
	Collision->Off();

	PinkCollision = CreateComponent<GameEngineCollision>();
	PinkCollision->GetTransform()->SetLocalScale({ 100.0f, 100.0f, 300.0f });
	PinkCollision->SetOrder((int)CollisionType::Ph2_Dog_Boss_Pink_Bullet);
	PinkCollision->Off();

	ParryEffect = CreateComponent<GameEngineSpriteRenderer>();
	ParryEffect->CreateAnimation({ .AnimationName = "ParryEffect", .SpriteName = "ParryEffect", .FrameInter = 0.08f, .Loop = false, .ScaleToTexture = true, });
	ParryEffect->ChangeAnimation("ParryEffect");
	ParryEffect->Off();

}

void ph2_Boss_Weapon::Update(float _Delta)
{
	

	


	/*TransformData date = Player::MainPlayer->GetTransform()->GetTransDataRef();
	TransformData date1 = Bullet_First->GetTransform()->GetTransDataRef();*/

	Bullet->GetTransform()->SetLocalPosition({ Bullet_First->GetTransform()->GetLocalPosition() });


	
	if (MoveDirCheck == false)
	{
		float4 MoveDir1 = { Player::MainPlayer->GetTransform()->GetLocalPosition() - Bullet_First->GetTransform()->GetLocalPosition() };
		MoveDir1.Normalize();

		MoveDir = MoveDir1.NormalizeReturn();
		Collision->Off();
		PinkCollision->Off(); 
		MoveDirCheck = true;
	}

	Bullet_First->GetTransform()->AddLocalPosition({ MoveDir * 2 });
	Collision->GetTransform()->SetLocalPosition({ Bullet_First->GetTransform()->GetLocalPosition() });
	PinkCollision->GetTransform()->SetLocalPosition({ Bullet_First->GetTransform()->GetLocalPosition() });

	if (MoveDirCheck == true)
	{
		//Collision->On();
		PinkCollision->Off();
	}

		


	switch (AttackCheck)
	{
	case 0:
	{
		Collision->On();

		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_bow_First");
			Bullet_First->On();
			AnimationCheck = true;
		}
	

		if (Bullet_First->IsAnimationEnd() && BulletCheck ==false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_bow");
			Bullet->On();
			BulletCheck = true;
		}

		
	}
		break;
	case 1:
	{
		Collision->On();

		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_wow_First");
			Bullet_First->On();
			AnimationCheck = true;
		}


		if (Bullet_First->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_wow");
			Bullet->On();
			BulletCheck = true;
		}
	}
		break;

	case 2:
	{
		PinkCollision->On(); 
		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_bow_pink_First");
			Bullet_First->On();
			AnimationCheck = true;
		}


		if (Bullet_First->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_bow_pink");
			Bullet->On();
			BulletCheck = true;
		}
	}
		break;
	case 3:
	{
		
		PinkCollision->On();
		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_wow_pink_First");
			Bullet_First->On();
			AnimationCheck = true;
		}
		if (Bullet_First->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_wow_pink");
			Bullet->On();
			BulletCheck = true;

		}

	}
		break;
	case 4:
	{
		
		Collision->On();
		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_bow_First");
			Bullet_First->On();
			AnimationCheck = true;
		}


		if (Bullet_First->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_bow");
			Bullet->On();
			BulletCheck = true;
		}


	}
	break;
	case 5:
	{
		Collision->On();
		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_wow_First");
			Bullet_First->On();
			AnimationCheck = true;
		}


		if (Bullet_First->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_wow");
			Bullet->On();
			BulletCheck = true;
		}
	}
	break;
	case 6:
	{
		
		Collision->On();
		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_bow_First");
			Bullet_First->On();
			AnimationCheck = true;
		}


		if (Bullet_First->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_bow");
			Bullet->On();
			BulletCheck = true;
		}


	}
	break;
	case 7:
	{
		Collision->On();

		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_wow_First");
			Bullet_First->On();
			AnimationCheck = true;
		}


		if (Bullet_First->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_wow");
			Bullet->On();
			BulletCheck = true;
		}
	}
	break;
	case 8:
	{
		Collision->On();
		
		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_bow_First");
			Bullet_First->On();
			AnimationCheck = true;
		}


		if (Bullet_First->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_bow");
			Bullet->On();
			BulletCheck = true;
		}


	}
	break;
	case 9:
	{
		Collision->On();

		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_wow_First");
			Bullet_First->On();
			AnimationCheck = true;
		}


		if (Bullet_First->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_wow");
			Bullet->On();
			BulletCheck = true;
		}
	}
	break;
	case 10:
	{
		Collision->On();

		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_bow_First");
			Bullet_First->On();
			AnimationCheck = true;
		}


		if (Bullet_First->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_bow");
			Bullet->On();
			BulletCheck = true;
		}


	}
	break;
	case 11:
	{
		Collision->On();

		if (AnimationCheck == false)
		{
			Bullet_First->ChangeAnimation("SD_wow_First");
			Bullet_First->On();
			AnimationCheck = true;
		}


		if (Bullet_First->IsAnimationEnd() && BulletCheck == false)
		{
			Bullet_First->Off();
			Bullet->ChangeAnimation("SD_wow");
			Bullet->On();
			BulletCheck = true;
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
