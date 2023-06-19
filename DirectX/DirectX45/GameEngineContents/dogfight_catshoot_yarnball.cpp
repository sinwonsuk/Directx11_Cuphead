#include "PrecompileHeader.h"
#include "dogfight_catshoot_yarnball.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>

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
}

void dogfight_catshoot_yarnball::Update(float _Delta)
{
	switch (Check)
	{
	case 0:
	{
		MoveDir = { 1,0 };
		Bullet->GetTransform()->AddWorldPosition({ MoveDir * _Delta * 800 });

	}
	break;
	case 1:
	{
		MoveDir = { -1,0 };
		Bullet->GetTransform()->AddWorldPosition({ MoveDir * _Delta * 800 });

	}
	break;

	default:
		break;
	}

}
