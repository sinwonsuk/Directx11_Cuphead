#include "PrecompileHeader.h"
#include "TutorialObject.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "EnumClass.h"
#include "Player.h"
TutorialObject::TutorialObject()
{

}

TutorialObject::~TutorialObject()
{

}

void TutorialObject::Start()
{


	CollisionEffectIntro = CreateComponent<GameEngineSpriteRenderer>();
	CollisionEffectIntro->SetScaleToTexture("Ground_ParryEffect_002.png"); 
	CollisionEffectIntro->GetTransform()->AddLocalPosition({ 3153.0f,-10.0f });
	CollisionEffectIntro->Off(); 

	CollisionEffectIntro2 = CreateComponent<GameEngineSpriteRenderer>();
	CollisionEffectIntro2->SetScaleToTexture("Ground_ParryEffect_002.png");
	CollisionEffectIntro2->GetTransform()->AddLocalPosition({ 3345.0f,-10.0f });
	CollisionEffectIntro2->Off(); 


	CollisionEffectIntro3 = CreateComponent<GameEngineSpriteRenderer>();
	CollisionEffectIntro3->SetScaleToTexture("Ground_ParryEffect_002.png");
	CollisionEffectIntro3->GetTransform()->AddLocalPosition({ 3537.0f,-10.0f });

	CollisionEffectIntro3->Off(); 

	CollisionEffect = CreateComponent<GameEngineSpriteRenderer>();
	CollisionEffect->CreateAnimation({ .AnimationName = "ParryEffect", .SpriteName = "ParryEffect", .FrameInter = 0.06f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {} });
	CollisionEffect->ChangeAnimation("ParryEffect");
	CollisionEffect->GetTransform()->AddLocalPosition({ 3153.0f,-10.0f });
	CollisionEffect->Off();


	CollisionEffect2 = CreateComponent<GameEngineSpriteRenderer>();
	CollisionEffect2->CreateAnimation({ .AnimationName = "ParryEffect", .SpriteName = "ParryEffect", .FrameInter = 0.06f,.Loop = false, .ScaleToTexture = true, });
	CollisionEffect2->ChangeAnimation("ParryEffect");
	CollisionEffect2->GetTransform()->AddLocalPosition({ 3345.0f,-10.0f });
	CollisionEffect2->Off();

	CollisionEffect3 = CreateComponent<GameEngineSpriteRenderer>();
	CollisionEffect3->CreateAnimation({ .AnimationName = "ParryEffect", .SpriteName = "ParryEffect", .FrameInter = 0.06f,.Loop = false, .ScaleToTexture = true, });
	CollisionEffect3->ChangeAnimation("ParryEffect");
	CollisionEffect3->GetTransform()->AddLocalPosition({ 3537.0f,-10.0f });
	CollisionEffect3->Off();


	Render1 = CreateComponent<GameEngineSpriteRenderer>();
	Render1->SetScaleToTexture("tutorial_pink_sphere_2.png");

	Render1->GetTransform()->SetLocalPosition({ 3153.0f,-10.0f });
	//Render1->Off(); 
	Render1->SetScaleRatio(1.2f);

	Render2 = CreateComponent<GameEngineSpriteRenderer>();

	Render2->SetScaleToTexture("tutorial_pink_sphere_2.png");
	Render2->GetTransform()->SetLocalPosition({ 3345.0f,-10.0f });
	Render2->SetScaleRatio(1.2f);
	Render2->Off(); 

	Render3 = CreateComponent<GameEngineSpriteRenderer>();
	Render3->SetScaleToTexture("tutorial_pink_sphere_2.png");
	Render3->GetTransform()->SetLocalPosition({ 3537.0f,-10.0f });
	Render3->SetScaleRatio(1.2f);
	Render3->Off(); 

	Collision1 = CreateComponent<GameEngineCollision>();
	Collision1->GetTransform()->SetLocalScale({ 10.0f, 10.0f, 300.0f });
	Collision1->GetTransform()->SetLocalPosition({ 3150.0f,-10.0f });
	Collision1->SetOrder((int)CollisionType::TutorialObject);


	Collision2 = CreateComponent<GameEngineCollision>();
	Collision2->GetTransform()->SetLocalScale({ 10.0f, 10.0f, 300.0f });
	Collision2->GetTransform()->SetLocalPosition({ 3345.0f,-10.0f });
	Collision2->SetOrder((int)CollisionType::TutorialObject);

	Collision3 = CreateComponent<GameEngineCollision>();
	Collision3->GetTransform()->SetLocalScale({ 10.0f, 10.0f, 300.0f });
	Collision3->GetTransform()->SetLocalPosition({ 3540.0f,-10.0f });
	Collision3->SetOrder((int)CollisionType::TutorialObject);


}

void TutorialObject::Update(float _Delta)
{
	if (Player::MainPlayer->GetStateValue() == PlayerState::Parry)
	{
		if (true == GameEngineInput::IsPress("PlayerJump"))
		{
			if (Collision1->Collision((int)CollisionType::Player, ColType::AABBBOX2D, ColType::AABBBOX2D) && LeftCollisionCheck == false)
			{		
				CollisionEffectIntro->On(); 
				CollisionEffect->ChangeAnimation("ParryEffect");
				CollisionEffect->Off(); 

				LeftCollisionCheck = true;
				ResetLiveTime();
				GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 0.0f);
				GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 0.0f);
			}
			if (Collision2->Collision((int)CollisionType::Player, ColType::AABBBOX2D, ColType::AABBBOX2D) && MiddleCollisionCheck == false)
			{
				CollisionEffectIntro2->On();
				CollisionEffect2->ChangeAnimation("ParryEffect");
				CollisionEffect2->Off();


				MiddleCollisionCheck = true;
				ResetLiveTime();
				GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 0.0f);
				GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 0.0f);
			}
			if (Collision3->Collision((int)CollisionType::Player, ColType::AABBBOX2D, ColType::AABBBOX2D) && RightCollisionCheck == false)
			{
				CollisionEffectIntro3->On();
				CollisionEffect3->ChangeAnimation("ParryEffect");
				CollisionEffect3->Off();

				RightCollisionCheck = true;
				ResetLiveTime();
				GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 0.0f);
				GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 0.0f);
			}
		}
	}
	if (GetLiveTime() > 0.1f && LeftCollisionCheck == true)
	{
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 1.0f);
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 1.0f);
		Player::MainPlayer->ChangeState(PlayerState::PinkObject);
	}
	if (GetLiveTime() > 0.1f && MiddleCollisionCheck == true)
	{
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 1.0f);
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 1.0f);
		Player::MainPlayer->ChangeState(PlayerState::PinkObject);
	}
	if (GetLiveTime() > 0.1f && RightCollisionCheck == true)
	{
		GameEngineTime::GlobalTime.SetRenderOrderTimeScale(0, 1.0f);
		GameEngineTime::GlobalTime.SetUpdateOrderTimeScale(0, 1.0f);
		Player::MainPlayer->ChangeState(PlayerState::PinkObject);
	}

	if (GetLiveTime() > 0.2f && LeftCollisionCheck == true)
	{
		CollisionEffectIntro->Off();
		CollisionEffect->On();
		Render1->Off(); 
		Render2->On();
		Render3->Off(); 
		ResetLiveTime();
		LeftCollisionCheck = false;
	}
	if (GetLiveTime() > 0.2f && MiddleCollisionCheck == true)
	{
		CollisionEffectIntro2->Off();
		CollisionEffect2->On();
		Render1->Off();
		Render2->Off();
		Render3->On();
		ResetLiveTime();
		MiddleCollisionCheck = false;
	}
	if (GetLiveTime() > 0.2f && RightCollisionCheck == true)
	{
		CollisionEffectIntro3->Off();
		CollisionEffect3->On();
		Render1->On();
		Render2->Off();
		Render3->Off();
		ResetLiveTime();
		RightCollisionCheck = false;
	}

	if (CollisionEffect->IsAnimationEnd())
	{
		CollisionEffect->Off();
	}
	if (CollisionEffect2->IsAnimationEnd())
	{
		CollisionEffect2->Off();
	}

	if (CollisionEffect3->IsAnimationEnd())
	{
		CollisionEffect3->Off();
	}



}

void TutorialObject::Render(float _Delta)
{
																		
}

