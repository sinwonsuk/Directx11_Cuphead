#include "PrecompileHeader.h"
#include "IdleWeapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.cpp"
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

	Bullet->CreateAnimation({ .AnimationName = "IdleWeapon", .SpriteName = "IdleWeapon.png", .FrameInter = 0.1f, .Loop = false, .ScaleToTexture = true, });
	Bullet->CreateAnimation({ .AnimationName = "Peashooter_Death", .SpriteName = "Peashooter_Death.png", .FrameInter = 0.05f, .Loop = false,.ScaleToTexture = true, });
	Bullet->ChangeAnimation("IdleWeapon");

	Sfx = CreateComponent<GameEngineSpriteRenderer>();
	Sfx->CreateAnimation({ .AnimationName = "IdleWeaponSfx", .SpriteName = "IdleWeaponSfx.png", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	Sfx->ChangeAnimation("IdleWeaponSfx");
	
	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 100.0f, 100.0f, 100.0f });
	Collision->SetOrder((int)CollisionType::Bullet);

}

void IdleWeapon::Update(float _Delta)
{

	Collision->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });


	if (CollisionCheck == false)
	{
		Bullet->GetTransform()->AddLocalPosition({ MoveDir * _Delta * 1500 });
	}

	if (Collision->Collision((int)CollisionType::DogAirPlane_Pase1) && CollisionCheck == false)
	{

		
		Bullet->ChangeAnimation("Peashooter_Death");

		
		CollisionCheck = true;
		
	}

	if (Bullet->IsAnimationEnd())
	{
		Bullet->Death();
	}


	/*if (CollisionCheck == true)
	{
		
	}*/

	
	
	
	if (Sfx->IsAnimationEnd())
	{
		Sfx->Death();
	}

	



	
}
