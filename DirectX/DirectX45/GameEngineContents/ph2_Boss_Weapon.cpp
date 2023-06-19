#include "PrecompileHeader.h"
#include "ph2_Boss_Weapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "Player.h"
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

		MoveDirCheck = true;
	}
	

	if (GetLiveTime() > 0.2)
	{
		Bullet_First->GetTransform()->AddLocalPosition({ MoveDir*2 });

	}


	switch (AttackCheck)
	{
	case 0:
	{
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



}
