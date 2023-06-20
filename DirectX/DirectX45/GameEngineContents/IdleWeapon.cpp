#include "PrecompileHeader.h"
#include "IdleWeapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.cpp"
#include "DogAirplane.h"
#include "UserInterface.h"
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
		UserInterface::Cut += 0.1;
		Bullet->ChangeAnimation("Peashooter_Death");	
		CollisionCheck = true;
		
	}
	

	if (GetLiveTime() > 10)
	{
		this->Death(); 
	}
	
	
	if (Sfx->IsAnimationEnd())
	{
		Sfx->Death();
	}

	



	
}
