#include "PrecompileHeader.h"
#include "IdleWeapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
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
		
	}

	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "IdleWeapon", .SpriteName = "IdleWeapon.png", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet->ChangeAnimation("IdleWeapon");
	Sfx = CreateComponent<GameEngineSpriteRenderer>();
	Sfx->CreateAnimation({ .AnimationName = "IdleWeaponSfx", .SpriteName = "IdleWeaponSfx.png", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	Sfx->ChangeAnimation("IdleWeaponSfx");
	
}

void IdleWeapon::Update(float _Delta)
{
	Bullet->GetTransform()->AddWorldPosition({ MoveDir * _Delta*1500 });
	
	if (Sfx->IsAnimationEnd())
	{
		Sfx->Death();
	}

	/*if (GetTransform()->GetLocalScale().x > 0 )
	{
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			GetTransform()->SetLocalNegativeScaleX();
		}
	}

	if (GetTransform()->GetLocalScale().x < 0 )
	{
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			GetTransform()->SetLocalPositiveScaleX();
		}
	}*/




	/*if (GetLiveTime() > 3)
	{
		this->Death();
	}*/
}
