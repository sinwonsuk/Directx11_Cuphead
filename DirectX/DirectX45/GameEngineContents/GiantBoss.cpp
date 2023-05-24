#include "PrecompileHeader.h"
#include "GiantBoss.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
GiantBoss::GiantBoss()
{
}

GiantBoss::~GiantBoss()
{
}

void GiantBoss::Start()
{
	/*if (nullptr == GameEngineSprite::Find("Boss"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("GiantBoss");
	
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("The Howling Aces").GetFullPath());

	}*/


	
	

	/*BossIntro0 = CreateComponent<GameEngineSpriteRenderer>(1);
	BossIntro0->CreateAnimation({ .AnimationName = "Boss", .SpriteName = "Boss", .FrameInter = 0.07f,.Loop = false, .ScaleToTexture = true, });
	BossIntro0->ChangeAnimation("Boss");

	BossIntroRock = CreateComponent<GameEngineSpriteRenderer>(1);
	BossIntroRock->CreateAnimation({ .AnimationName = "BossIntro", .SpriteName = "BossIntro", .FrameInter = 0.07f,.Loop = false, .ScaleToTexture = true, });
	BossIntroRock->ChangeAnimation("BossIntro");
	BossIntroRock->Off();
	
	BossIntroDust = CreateComponent<GameEngineSpriteRenderer>(2);
	BossIntroDust->CreateAnimation({ .AnimationName = "BossSmoke", .SpriteName = "BossSmoke", .FrameInter = 0.07f,.Loop = false, .ScaleToTexture = true, });
	BossIntroDust->ChangeAnimation("BossSmoke");
	BossIntroDust->Off();

	BossIdle = CreateComponent<GameEngineSpriteRenderer>(2);
	BossIdle->CreateAnimation({ .AnimationName = "BossIdle", .SpriteName = "BossIdle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	BossIdle->ChangeAnimation("BossIdle");
	BossIdle->Off(); 


	BossIdleHand = CreateComponent<GameEngineSpriteRenderer>(2);
	BossIdleHand->CreateAnimation({ .AnimationName = "BossIdleHand", .SpriteName = "BossIdleHand", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	BossIdleHand->ChangeAnimation("BossIdleHand");
	BossIdleHand->Off(); 

	noumIntro1 = CreateComponent<GameEngineSpriteRenderer>();
	noumIntro1->SetScaleToTexture("bg_mid_mountains1.png");

	noumIntro2 = CreateComponent<GameEngineSpriteRenderer>();
	noumIntro2->SetScaleToTexture("bg_mid_rock-platform.png");

	noumIntro2->GetTransform()->AddLocalPosition({ 0,-320 });


	noumIntro3 = CreateComponent<GameEngineSpriteRenderer>(2);
	noumIntro3->CreateAnimation({ .AnimationName = "Bread", .SpriteName = "Bread", .FrameInter = 0.07f,.Loop = true, .ScaleToTexture = true, });
	noumIntro3->ChangeAnimation("Bread");
	noumIntro3->On();*/
}

void GiantBoss::Update(float _Delta)
{
	/*if (BossIntro0->IsAnimationEnd())
	{
		BossIntro0->Death();
	}
	if (BossIntroRock->IsAnimationEnd())
	{
		BossIntroRock->Death();
	}
	if (BossIntroDust->IsAnimationEnd())
	{
		BossIntroDust->Death();
	}

	
	UpdateState(_Delta);*/
}

void GiantBoss::Render(float _Delta)
{

}



void GiantBoss::AnimationCheck(const std::string_view& _AnimationName)
{
	BossIdle->ChangeAnimation(_AnimationName);
}

