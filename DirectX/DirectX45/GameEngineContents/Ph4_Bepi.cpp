#include "PrecompileHeader.h"
#include "Ph4_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineSprite.h>
#include "Ph4_Swing_Platform.h"
Ph4_Bepi::Ph4_Bepi()
{
}

Ph4_Bepi::~Ph4_Bepi()
{
}

void Ph4_Bepi::AnimationCheck(const std::string_view& _AnimationName)
{
	Phase4_Idle->ChangeAnimation(_AnimationName);
}



void Ph4_Bepi::LevelChangeStart()
{
}

void Ph4_Bepi::Start()
{
	umbrella_bk = CreateComponent<GameEngineSpriteRenderer>();
	umbrella_bk->CreateAnimation({ .AnimationName = "umbrella_bk", .SpriteName = "umbrella_bk", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true });
	umbrella_bk->ChangeAnimation("umbrella_bk");
	umbrella_bk->GetTransform()->AddLocalPosition({ 0.0f,365.0f ,60.0f });
	umbrella_bk->Off();

	Phase4_Idle = CreateComponent<GameEngineSpriteRenderer>();
	Phase4_Idle->CreateAnimation({ .AnimationName = "Phase4_Idle", .SpriteName = "Phase4_Idle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Phase4_Idle->CreateAnimation({ .AnimationName = "Phase4_Attack_Start", .SpriteName = "Phase4_Attack_Start", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	Phase4_Idle->CreateAnimation({ .AnimationName = "Phase4_Attack_Middle", .SpriteName = "Phase4_Attack_Middle", .FrameInter = 0.08f,.Loop = true, .ScaleToTexture = true });
	Phase4_Idle->CreateAnimation({ .AnimationName = "Phase4_Attack_End", .SpriteName = "Phase4_Attack_End", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	Phase4_Idle->ChangeAnimation("Phase4_Idle");
	Phase4_Idle->GetTransform()->AddLocalPosition({ 0.0f,-20.0f,57.0f });
	
	Phase4_Lights = CreateComponent<GameEngineSpriteRenderer>();
	Phase4_Lights->CreateAnimation({ .AnimationName = "Phase4_Lights", .SpriteName = "Phase4_Lights", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Phase4_Lights->ChangeAnimation("Phase4_Lights");
	Phase4_Lights->GetTransform()->AddLocalPosition({ 0.0f,375.0f,57.0f });


	Phase4_Intro = CreateComponent<GameEngineSpriteRenderer>();
	Phase4_Intro->CreateAnimation({ .AnimationName = "Phase4_Intro", .SpriteName = "Phase4_Intro", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	Phase4_Intro->ChangeAnimation("Phase4_Intro");
	Phase4_Intro->GetTransform()->AddLocalPosition({ 0.0f,415.0f,55.0f });
	
	Phase4_Intro_Spin = CreateComponent<GameEngineSpriteRenderer>();
	Phase4_Intro_Spin->CreateAnimation({ .AnimationName = "Phase4_Spin", .SpriteName = "Phase4_Spin", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true });
	Phase4_Intro_Spin->ChangeAnimation("Phase4_Spin");
	Phase4_Intro_Spin->GetTransform()->AddLocalPosition({ 0.0f,385.0f,55.0f });
	Phase4_Intro_Spin->Off(); 
	
	

	




	

	GetTransform()->AddLocalPosition({ 0.0f,-100.0f });


}

void Ph4_Bepi::Update(float _Delta)
{

	Platform += _Delta;

	
	
	UpdateState(_Delta);


	if (Swing_Platform_Intro == true && Platform > 1.3)
	{
		std::shared_ptr<Ph4_Swing_Platform> Object = GetLevel()->CreateActor<Ph4_Swing_Platform>();
		Object->choic = Choice::Idle;
		Object->GetTransform()->AddLocalPosition({ -1100.0f,70.0f });

		Platform = 0;
	}

}

void Ph4_Bepi::Render(float _Delta)
{


}
