#include "PrecompileHeader.h"
#include "Ph1_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include "Crown_Bepi_Level.h"
#include "Bepi_Duck.h"
#include "EnumClass.h"
Ph1_Bepi::Ph1_Bepi()
{
}

Ph1_Bepi::~Ph1_Bepi()
{
}

void Ph1_Bepi::Start()
{
	Loading = CreateComponent<GameEngineSpriteRenderer>(150);
	Loading->CreateAnimation({ .AnimationName = "Start", .SpriteName = "Start", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	Loading->GetTransform()->AddLocalPosition({ -150.0f,0.0f,0.0f });
	Loading->ChangeAnimation("Start");




	Beppi_Intro = CreateComponent<GameEngineSpriteRenderer>();
	Beppi_Intro->CreateAnimation({ .AnimationName = "Beppi_Intro", .SpriteName = "Beppi_Intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2}});
	Beppi_Intro->ChangeAnimation("Beppi_Intro");

	Beppi_Intro2 = CreateComponent<GameEngineSpriteRenderer>();
	Beppi_Intro2->CreateAnimation({ .AnimationName = "Beppi_Intro", .SpriteName = "Beppi_Intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Beppi_Intro2->CreateAnimation({ .AnimationName = "Beppi_Intro3", .SpriteName = "Beppi_Intro", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true,.FrameIndex = {28,29,30}});
	Beppi_Intro2->CreateAnimation({ .AnimationName = "Beppi_Idle", .SpriteName = "Beppi_Idle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Beppi_Intro2->CreateAnimation({ .AnimationName = "Beppi_Rush_Attack_Start", .SpriteName = "Beppi_Rush_Attack", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,5,6,7,8,9} });
	Beppi_Intro2->CreateAnimation({ .AnimationName = "Beppi_Rush_Attack_Run", .SpriteName = "Beppi_Rush_Attack", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {10,11,12,13,14,15,16} });
	Beppi_Intro2->CreateAnimation({ .AnimationName = "Beppi_Rush_Attack_Finish", .SpriteName = "Beppi_Rush_Attack", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34} });
	Beppi_Intro2->CreateAnimation({ .AnimationName = "Ph1_Beppi_End", .SpriteName = "Ph1_Beppi_End", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true});
	Beppi_Intro2->ChangeAnimation("Beppi_Intro");
	Beppi_Intro2->Off(); 
	

	Ready = CreateComponent<GameEngineSpriteRenderer>();
	Ready->CreateAnimation({ .AnimationName = "FightText_GetReady", .SpriteName = "FightText_GetReady", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Ready->GetTransform()->AddLocalPosition({ -300.0f,0.0f});
	Ready->ChangeAnimation("FightText_GetReady");

	Ready->SetScaleRatio(3.0f);
	Ready->On();

	

	Collision2 = CreateComponent<GameEngineCollision>();
	Collision2->GetTransform()->SetLocalScale({ 200.0f, 200.0f, 200.0f });
	Collision2->GetTransform()->AddLocalPosition({ 0.0f,-100.0f });
	Collision2->SetOrder((int)CollisionType::BossAttack);



	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 200.0f, 200.0f, 200.0f });
	Collision->GetTransform()->AddLocalPosition({ 0.0f,-100.0f });

	Collision->SetOrder((int)CollisionType::BossBody);
	Collision->SetColType(ColType::AABBBOX2D);


	GetTransform()->AddLocalPosition({ 300.0f,20.0f });
}

void Ph1_Bepi::Update(float _Delta)
{

	if (Loading->IsAnimationEnd())
	{
		Loading->Off();
	}



	//Collision->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition() });

	if (StateValue != Ph1_Beppi_State::BossIntro || StateValue != Ph1_Beppi_State::BossIntro2)
	{
		if (Collision->Collision((int)CollisionType::Bullet) && CollisonCheck == false)
		{


			if (CollisonCheck == false)
			{
				Beppi_Intro2->ColorOptionValue.PlusColor = { 1,1,1,0 };
				Beppi_Intro2->ResetLiveTime();
				CollisonCheck = true;

			}

			std::shared_ptr<GameEngineCollision> collision = Collision->Collision((int)CollisionType::Bullet);
			collision->Death();
		}

		if (CollisonCheck == true && Beppi_Intro2->GetLiveTime() > 0.05f)
		{
			Beppi_Intro2->ColorOptionValue.PlusColor = { 0,0,0,0 };
			CollisonCheck = false;
		}
	}

	

	if (Ready->IsAnimationEnd())
	{
		Ready->Off();
	}

	if (DuckStart == true)
	{
		DuckTime += _Delta;
	}


	if (StateValue != Ph1_Beppi_State::BossFinish)
	{
		if (DuckTime > 1.5f)
		{

			Random_Duck = GameEngineRandom::MainRandom.RandomInt(0, 3);

			if (Random_Duck == 1)
			{
				std::shared_ptr<Bepi_Duck> Object = GetLevel()->CreateActor<Bepi_Duck>();
				Object->Check = DuckCheck::Pink;
				DuckTime = 0;
			}

			else
			{
				std::shared_ptr<Bepi_Duck> Object = GetLevel()->CreateActor<Bepi_Duck>();
				DuckTime = 0;
			}


		}
	}




	UpdateState(_Delta);
}

void Ph1_Bepi::Render(float _Delta)
{
}

void Ph1_Bepi::LevelChangeStart()
{
}

void Ph1_Bepi::AnimationCheck(const std::string_view& _AnimationName)
{
	Beppi_Intro2->ChangeAnimation(_AnimationName);
}
