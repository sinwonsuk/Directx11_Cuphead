#include "PrecompileHeader.h"
#include "Ph2_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineSprite.h>
#include "EnumClass.h"

Ph2_Bepi::Ph2_Bepi()
{
}

Ph2_Bepi::~Ph2_Bepi()
{
}

void Ph2_Bepi::Start()
{
	
	LeftHeliumBottle_Texture = CreateComponent<GameEngineSpriteRenderer>();
	LeftHeliumBottle_Texture->SetScaleToTexture("LeftHeliumBottle_00.png");
	LeftHeliumBottle_Texture->GetTransform()->AddLocalPosition({ -180.0f,220.0f,55.0f });

	RightHeliumBottle_Texture = CreateComponent<GameEngineSpriteRenderer>();
	RightHeliumBottle_Texture->SetScaleToTexture("RightHeliumBottle_00.png");
	RightHeliumBottle_Texture->GetTransform()->AddLocalPosition({ 180.0f,220.0f,55.0f });


	LeftHeliumPipes_Intro = CreateComponent<GameEngineSpriteRenderer>();
	LeftHeliumPipes_Intro->CreateAnimation({ .AnimationName = "HeliumPipes_Intro", .SpriteName = "HeliumPipes_Intro", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
	LeftHeliumPipes_Intro->CreateAnimation({ .AnimationName = "HeliumPipes_Idle", .SpriteName = "HeliumPipes_Idle", .FrameInter = 0.2f,.Loop = true, .ScaleToTexture = true, });
	LeftHeliumPipes_Intro->ChangeAnimation("HeliumPipes_Intro");
	LeftHeliumPipes_Intro->GetTransform()->AddLocalPosition({ -455.0f,400.0f,55.0f });
	LeftHeliumPipes_Intro->GetTransform()->SetLocalRotation({ 0.0f,180.0f });
	LeftHeliumPipes_Intro->Off();



	RightHeliumPipes_Intro = CreateComponent<GameEngineSpriteRenderer>();
	RightHeliumPipes_Intro->CreateAnimation({ .AnimationName = "HeliumPipes_Intro", .SpriteName = "HeliumPipes_Intro", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
	RightHeliumPipes_Intro->CreateAnimation({ .AnimationName = "HeliumPipes_Idle", .SpriteName = "HeliumPipes_Idle", .FrameInter = 0.2f,.Loop = true, .ScaleToTexture = true, });
	RightHeliumPipes_Intro->ChangeAnimation("HeliumPipes_Intro");
	RightHeliumPipes_Intro->GetTransform()->AddLocalPosition({ 455.0f,400.0f,55.0f });
	RightHeliumPipes_Intro->Off();




	LeftHeliumBottle = CreateComponent<GameEngineSpriteRenderer>();
	LeftHeliumBottle->CreateAnimation({ .AnimationName = "LeftHeliumBottle", .SpriteName = "LeftHeliumBottle", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	LeftHeliumBottle->ChangeAnimation("LeftHeliumBottle");
	LeftHeliumBottle->GetTransform()->AddLocalPosition({ -180.0f,220.0f,55.0f });
	LeftHeliumBottle->Off();

	RightHeliumBottle = CreateComponent<GameEngineSpriteRenderer>();
	RightHeliumBottle->CreateAnimation({ .AnimationName = "RightHeliumBottle", .SpriteName = "RightHeliumBottle", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	RightHeliumBottle->ChangeAnimation("RightHeliumBottle");
	RightHeliumBottle->GetTransform()->AddLocalPosition({ 180.0f,220.0f,55.0f });
	RightHeliumBottle->Off();


	



	Helium_Tank_Back = CreateComponent<GameEngineSpriteRenderer>();
	Helium_Tank_Back->SetScaleToTexture("1_HeliumTank_1.png");
	Helium_Tank_Back->GetTransform()->AddLocalPosition({ 0.0f,0.0f,55.0f });

	Phase2_Intro_Texture = CreateComponent<GameEngineSpriteRenderer>();
	Phase2_Intro_Texture->SetScaleToTexture("Phase2_Intro_00.png");
	Phase2_Intro_Texture->GetTransform()->AddLocalPosition({ 0.0f,450.0f,55.0f });




	

	Phase2_Intro = CreateComponent<GameEngineSpriteRenderer>();
	Phase2_Intro->CreateAnimation({ .AnimationName = "Phase2_Intro", .SpriteName = "Phase2_Intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Phase2_Intro->CreateAnimation({ .AnimationName = "Phase2_Body_Back", .SpriteName = "Phase2_Body_Back", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Phase2_Intro->ChangeAnimation("Phase2_Intro");
	Phase2_Intro->GetTransform()->AddLocalPosition({ 0.0f,450.0f,55.0f });

	Phase2_Intro->Off();

	Phase2_Idle_Head = CreateComponent<GameEngineSpriteRenderer>();
	Phase2_Idle_Head->CreateAnimation({ .AnimationName = "Phase2_Idle_Head", .SpriteName = "Phase2_Idle_Head", .FrameInter = 0.15f,.Loop = true, .ScaleToTexture = true, });
	Phase2_Idle_Head->ChangeAnimation("Phase2_Idle_Head");
	Phase2_Idle_Head->GetTransform()->AddLocalPosition({ 0.0f,550.0f,55.0f });
	Phase2_Idle_Head->Off();

	Phase2_Body_Front = CreateComponent<GameEngineSpriteRenderer>();
	Phase2_Body_Front->CreateAnimation({ .AnimationName = "Phase2_Body_Front", .SpriteName = "Phase2_Body_Front", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Phase2_Body_Front->ChangeAnimation("Phase2_Body_Front");
	Phase2_Body_Front->GetTransform()->AddLocalPosition({ 0.0f,450.0f,55.0f });
	Phase2_Body_Front->Off();

	


	Helium_Tank_Front = CreateComponent<GameEngineSpriteRenderer>();
	Helium_Tank_Front->SetScaleToTexture("0_HeliumTank_1.png");
	Helium_Tank_Front->GetTransform()->AddLocalPosition({ 0.0f,0.0f,55.0f });
	
	

	




	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 200.0f, 200.0f, 200.0f });
	Collision->GetTransform()->AddLocalPosition({ 0.0f,500.0f });

	Collision->SetOrder((int)CollisionType::BossBody);
	Collision->SetColType(ColType::AABBBOX2D);


	




	


	GetTransform()->AddLocalPosition({ 0,-700.0f });
	

}

void Ph2_Bepi::Update(float _Delta)
{

	
		if (Collision->Collision((int)CollisionType::Bullet) && CollisonCheck == false)
		{
			if (CollisonCheck == false)
			{
				Phase2_Idle_Head->ColorOptionValue.PlusColor = { 1,1,1,0 };
				Phase2_Idle_Head->ResetLiveTime();
				CollisonCheck = true;
			}

			std::shared_ptr<GameEngineCollision> collision = Collision->Collision((int)CollisionType::Bullet);
			collision->Death();
		}

		if (CollisonCheck == true && Phase2_Idle_Head->GetLiveTime() > 0.05f)
		{
			Phase2_Idle_Head->ColorOptionValue.PlusColor = { 0,0,0,0 };
			CollisonCheck = false;
		}
	







	UpdateState(_Delta);


}

void Ph2_Bepi::Render(float _Delta)
{
}

void Ph2_Bepi::AnimationCheck(const std::string_view& _AnimationName)
{
}

void Ph2_Bepi::LevelChangeStart()
{

}
