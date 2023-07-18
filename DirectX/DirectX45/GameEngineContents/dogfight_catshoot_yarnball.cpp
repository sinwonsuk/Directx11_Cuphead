#include "PrecompileHeader.h"
#include "dogfight_catshoot_yarnball.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"
#include "Player.h"
dogfight_catshoot_yarnball::dogfight_catshoot_yarnball()
{

}

dogfight_catshoot_yarnball::~dogfight_catshoot_yarnball()
{

}

void dogfight_catshoot_yarnball::Start()
{
	if (nullptr == GameEngineSprite::Find("dogfight_catshoot_red_yarnball"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");


		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("dogfight_catshoot_red_yarnball").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("dogfight_catshoot_green_yarnball").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("dogfight_catshoot_yellow_yarnball").GetFullPath());
	}

	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "dogfight_catshoot_red_yarnball", .SpriteName = "dogfight_catshoot_red_yarnball", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet->CreateAnimation({ .AnimationName = "dogfight_catshoot_green_yarnball", .SpriteName = "dogfight_catshoot_green_yarnball", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet->CreateAnimation({ .AnimationName = "dogfight_catshoot_yellow_yarnball", .SpriteName = "dogfight_catshoot_yellow_yarnball", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet->ChangeAnimation("dogfight_catshoot_yellow_yarnball");

	Bullet->GetTransform()->SetLocalPosition({ 0,0,50 });

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 60.0f, 60.0f, 300.0f });

	Collision->SetOrder((int)CollisionType::BossAttack);

}

void dogfight_catshoot_yarnball::Update(float _Delta)
{

	Collision->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });
	switch (Check)
	{
	case 0:
	{
		MoveDir = { 1,0 };
		Bullet->GetTransform()->AddWorldPosition({ MoveDir * _Delta * 800.0f });

	}
	break;
	case 1:
	{
		MoveDir = { -1,0 };
		Bullet->GetTransform()->AddWorldPosition({ MoveDir * _Delta * 800.0f });

	}
	break;

	default:
		break;
	}

	if (Player::MainPlayer->Hp <= 0)
	{
		this->Death();
	}
}
