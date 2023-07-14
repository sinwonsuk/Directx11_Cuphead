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
#include "EnumClass.h"
#include "IdleWeapon.h"
#include <algorithm>
Ph4_Bepi* Ph4_Bepi::ph4_Bepi;

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
	ph4_Bepi = this;

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
	Phase4_Idle->CreateAnimation({ .AnimationName = "Phase4_End", .SpriteName = "Phase4_End", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Phase4_Idle->ChangeAnimation("Phase4_Idle");
	Phase4_Idle->GetTransform()->AddLocalPosition({ 0.0f,-20.0f,57.0f });
	
	Phase4_Lights = CreateComponent<GameEngineSpriteRenderer>();
	Phase4_Lights->CreateAnimation({ .AnimationName = "Phase4_Lights", .SpriteName = "Phase4_Lights", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Phase4_Lights->ChangeAnimation("Phase4_Lights");
	Phase4_Lights->GetTransform()->AddLocalPosition({ 0.0f,375.0f,57.0f });

	Phase4_Intro_Texture = CreateComponent<GameEngineSpriteRenderer>();
	Phase4_Intro_Texture->SetScaleToTexture("Phase4_Intro_0.png");
	Phase4_Intro_Texture->GetTransform()->AddLocalPosition({ 0.0f,415.0f,55.0f });

	Phase4_Intro = CreateComponent<GameEngineSpriteRenderer>();
	Phase4_Intro->CreateAnimation({ .AnimationName = "Phase4_Intro", .SpriteName = "Phase4_Intro", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	Phase4_Intro->ChangeAnimation("Phase4_Intro");
	Phase4_Intro->GetTransform()->AddLocalPosition({ 0.0f,415.0f,55.0f });
	Phase4_Intro->Off(); 

	Phase4_Intro_Spin = CreateComponent<GameEngineSpriteRenderer>();
	Phase4_Intro_Spin->CreateAnimation({ .AnimationName = "Phase4_Spin", .SpriteName = "Phase4_Spin", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true });
	Phase4_Intro_Spin->ChangeAnimation("Phase4_Spin");
	Phase4_Intro_Spin->GetTransform()->AddLocalPosition({ 0.0f,385.0f,55.0f });
	Phase4_Intro_Spin->Off(); 
	
	Bepi_boss_explosion = CreateComponent<GameEngineSpriteRenderer>();
	Bepi_boss_explosion->CreateAnimation({ .AnimationName = "Bepi_boss_explosion", .SpriteName = "Bepi_boss_explosion", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	Bepi_boss_explosion->ChangeAnimation("Bepi_boss_explosion");
	Bepi_boss_explosion->GetTransform()->AddLocalPosition({ 0.0f,385.0f,55.0f });
	Bepi_boss_explosion->Off();

	Exit = CreateComponent<GameEngineSpriteRenderer>(150);
	Exit->CreateAnimation({ .AnimationName = "Exit", .SpriteName = "Exit", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	Exit->GetTransform()->AddLocalPosition({ 0.0f,20.0f,-500.0f });
	Exit->ChangeAnimation("Exit");
	Exit->Off();

	

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 200.0f, 300.0f, 100.0f });
	Collision->GetTransform()->AddLocalPosition({ 0.0f,100.0f });

	Collision->SetOrder((int)CollisionType::Ph4_Beppi_Body);
	Collision->SetColType(ColType::AABBBOX2D);

	Ph4_Swing_Platforms.reserve(1000); 

	for (size_t i = 0; i < 200; i++)
	{
		std::shared_ptr<class Ph4_Swing_Platform> Object = GetLevel()->CreateActor<Ph4_Swing_Platform>();
		Object->choic = Choice::Idle;
		Object->GetTransform()->AddLocalPosition({ -900.0f,70.0f });
		Object->Off(); 
		Ph4_Swing_Platforms.push_back(Object);
	}

	for (size_t i = 0; i < 50; i++)
	{
		std::shared_ptr<class Ph4_Penguin> Object = GetLevel()->CreateActor<Ph4_Penguin>();
		Object->Off();
		Ph4_Penguins.push_back(Object);
	}


	GetTransform()->AddLocalPosition({ 0.0f,-900.0f });


}

void Ph4_Bepi::Update(float _Delta)
{
	if (GetTransform()->GetLocalPosition().y > -100.0f)
	{
		Platform += _Delta;
	}


	
	UpdateState(_Delta);

	
	if (GetTransform()->GetLocalPosition().y > -100.0f)
	{
		if (Swing_Platform_Intro == true && Platform > 1.3)
		{
			Ph4_Swing_Platforms[Platform_Number]->On(); 
			++Platform_Number;
			Platform = 0;
		}
	}

	if (Platform_Number == 200)
	{
		for (size_t i = 0; i < Ph4_Swing_Platforms.size(); i++)
		{
			Ph4_Swing_Platforms.clear(); 
		}

		for (size_t i = 0; i < 200; i++)
		{
			std::shared_ptr<class Ph4_Swing_Platform> Object = GetLevel()->CreateActor<Ph4_Swing_Platform>();
			Object->choic = Choice::Idle;
			Object->GetTransform()->AddLocalPosition({ -900.0f,70.0f });
			Object->Off();
			Ph4_Swing_Platforms.push_back(Object);

		}
		Platform_Number = 0; 
	}
	if (Ph4_Penguin_Number == 50)
	{

		for (size_t i = 0; i < Ph4_Swing_Platforms.size(); i++)
		{
			Ph4_Penguins.clear();
		}
		for (size_t i = 0; i < Ph4_Swing_Platforms.size(); i++)
		{
			std::shared_ptr<class Ph4_Penguin> Object = GetLevel()->CreateActor<Ph4_Penguin>();
			Object->Off();
			Ph4_Penguins.push_back(Object);
		}
		
		Ph4_Penguin_Number = 0;
	}
	
}

void Ph4_Bepi::Render(float _Delta)
{


}
