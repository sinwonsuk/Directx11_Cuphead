#include "PrecompileHeader.h"
#include "ExWeapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "EnumClass.h"
#include "UserInterface.h"
ExWeapon::ExWeapon()
{
}

ExWeapon::~ExWeapon()
{
}

void ExWeapon::Start()
{
	if (nullptr == GameEngineSprite::Find("Peashooter_EX_Death.png"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");


		NewDir.Move("Texture");

		GameEngineSprite::LoadSheet(NewDir.GetPlusFileName("Weapon\\Peashooter_EX_Death.png").GetFullPath(), 5, 2);
		GameEngineSprite::LoadSheet(NewDir.GetPlusFileName("Weapon\\Peashooter_EX_Loop.png").GetFullPath(), 5, 2);
	}
	if (nullptr == GameEngineSprite::Find("EX_Dust"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Character");
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("EX_Dust").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("EX_ChargeUp").GetFullPath());
	}



	Bullet = CreateComponent<GameEngineSpriteRenderer>();

	Bullet->CreateAnimation({ .AnimationName = "Peashooter_EX_Loop", .SpriteName = "Peashooter_EX_Loop.png", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true,.FrameIndex = {2,3,4,5,6,7} });
	Bullet->CreateAnimation({ .AnimationName = "Peashooter_EX_Death", .SpriteName = "Peashooter_EX_Death.png", .FrameInter = 0.05f, .Loop = false,.ScaleToTexture = true, });
	Bullet->ChangeAnimation("Peashooter_EX_Loop");
	Bullet->SetScaleRatio(0.8f);

	Sfx = CreateComponent<GameEngineSpriteRenderer>();
	Sfx->CreateAnimation({ .AnimationName = "EX_ChargeUp", .SpriteName = "EX_ChargeUp", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	Sfx->ChangeAnimation("EX_ChargeUp");
	Sfx->SetScaleRatio(0.8f);
	Sfx_Dust = CreateComponent<GameEngineSpriteRenderer>();
	Sfx_Dust->CreateAnimation({ .AnimationName = "EX_Dust", .SpriteName = "EX_Dust", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	Sfx_Dust->ChangeAnimation("EX_Dust");
	
	Sfx_Dust->SetScaleRatio(0.8f);

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision->SetOrder((int)CollisionType::Bullet);

}

void ExWeapon::Update(float _Delta)
{
	Collision->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });

	if (CollisionCheck == false)
	{
		Bullet->GetTransform()->AddLocalPosition({ MoveDir * _Delta * 1500.0f });
	}



	if (Collision->Collision((int)CollisionType::BossBody) && CollisionCheck == false)
	{
		Bullet->ChangeAnimation("Peashooter_EX_Death");
		CollisionCheck = true;
	}
	if (Sfx_Dust->IsAnimationEnd())
	{
		Sfx_Dust->Death();
	}

	if (Sfx->IsAnimationEnd())
	{
		Sfx->Death();
	}

	if (GetLiveTime() > 5)
	{
		this->Death();
	}

	


}