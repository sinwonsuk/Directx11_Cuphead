#include "PrecompileHeader.h"
#include "Ph3_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include "EnumClass.h"
Ph3_Bepi::Ph3_Bepi()
{
}

Ph3_Bepi::~Ph3_Bepi()
{
}

void Ph3_Bepi::Start()
{
	Bullets.reserve(300); 
	
	Yellow_Horse_Body = CreateComponent<GameEngineSpriteRenderer>();
	Yellow_Horse_Body->CreateAnimation({ .AnimationName = "Yellow_Horse_Body", .SpriteName = "Yellow_Horse_Body", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Yellow_Horse_Body->CreateAnimation({ .AnimationName = "Yellow_Horse_End", .SpriteName = "Yellow_Horse_End", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Yellow_Horse_Body->ChangeAnimation("Yellow_Horse_Body");

	Yellow_Horse_Head = CreateComponent<GameEngineSpriteRenderer>();
	Yellow_Horse_Head->CreateAnimation({ .AnimationName = "Yellow_Horse_Head", .SpriteName = "Yellow_Horse_Head", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Yellow_Horse_Head->ChangeAnimation("Yellow_Horse_Head");

	Yellow_Horse_Head->GetTransform()->AddLocalPosition({ -152.0f,-250.0f });

	Phase3_Idle = CreateComponent<GameEngineSpriteRenderer>();
	Phase3_Idle->CreateAnimation({ .AnimationName = "Phase3_Idle", .SpriteName = "Phase3_Idle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Phase3_Idle->CreateAnimation({ .AnimationName = "Phase3_End_Finish", .SpriteName = "Phase3_End_Finish", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	Phase3_Idle->CreateAnimation({ .AnimationName = "Phase3_End", .SpriteName = "Phase3_End", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Phase3_Idle->ChangeAnimation("Phase3_Idle");
	Phase3_Idle->GetTransform()->AddLocalPosition({ -30.0f,-240.0f,-1.0f });



	Green_Horse_Body = CreateComponent<GameEngineSpriteRenderer>();
	Green_Horse_Body->CreateAnimation({ .AnimationName = "Green_Horse_Body", .SpriteName = "Green_Horse_Body", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Green_Horse_Body->CreateAnimation({ .AnimationName = "Green_Horse_End", .SpriteName = "Green_Horse_End", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Green_Horse_Body->ChangeAnimation("Green_Horse_Body");
	Green_Horse_Body->GetTransform()->AddLocalPosition({ 20.0f,-20.0f });
	Green_Horse_Body->Off(); 

	


	Green_Horse_Head = CreateComponent<GameEngineSpriteRenderer>();
	Green_Horse_Head->CreateAnimation({ .AnimationName = "Green_Horse_Head", .SpriteName = "Green_Horse_Head", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Green_Horse_Head->ChangeAnimation("Green_Horse_Head");
	Green_Horse_Head->GetTransform()->AddLocalPosition({ -152.0f,-250.0f });
	Green_Horse_Head->Off(); 

	Green_Horse_Attack = CreateComponent<GameEngineSpriteRenderer>();
	Green_Horse_Attack->CreateAnimation({ .AnimationName = "Green_Horse_Attack", .SpriteName = "Green_Horse_Attack", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	Green_Horse_Attack->ChangeAnimation("Green_Horse_Attack");
	Green_Horse_Attack->GetTransform()->AddLocalPosition({ -160.0f,-270.0f });
	Green_Horse_Attack->Off();

	Yellow_Horse_Attack = CreateComponent<GameEngineSpriteRenderer>();
	Yellow_Horse_Attack->CreateAnimation({ .AnimationName = "Yellow_Horse_Attack", .SpriteName = "Yellow_Horse_Attack", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true ,.FrameIndex = {0,1,2,3}});
	Yellow_Horse_Attack->ChangeAnimation("Yellow_Horse_Attack");
	Yellow_Horse_Attack->GetTransform()->AddLocalPosition({ -160.0f,-270.0f });
	Yellow_Horse_Attack->Off(); 

	clown_ph3_horse_spit = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_horse_spit->CreateAnimation({ .AnimationName = "clown_ph3_horse_spit", .SpriteName = "clown_ph3_horse_spit", .FrameInter = 0.04f,.Loop = false, .ScaleToTexture = true ,.FrameIndex = {0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7} });
	clown_ph3_horse_spit->SetScaleRatio(1.2f);
	clown_ph3_horse_spit->ChangeAnimation("clown_ph3_horse_spit");
	clown_ph3_horse_spit->Off();

	Bepi_boss_explosion = CreateComponent<GameEngineSpriteRenderer>();
	Bepi_boss_explosion->CreateAnimation({ .AnimationName = "Bepi_boss_explosion", .SpriteName = "Bepi_boss_explosion", .FrameInter = 0.04f,.Loop = false, .ScaleToTexture = true });
	Bepi_boss_explosion->ChangeAnimation("Bepi_boss_explosion");
	Bepi_boss_explosion->Off();

	

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 200.0f, 200.0f, 200.0f });
	Collision->GetTransform()->AddLocalPosition({ 0.0f,-200.0f });

	Collision->SetOrder((int)CollisionType::BossBody);
	Collision->SetColType(ColType::AABBBOX2D);

	GetTransform()->AddLocalPosition({ 460.0f,700.0f });
}

void Ph3_Bepi::Update(float _Delta)
{
	if (Collision->Collision((int)CollisionType::Bullet) && CollisonCheck == false)
	{
		Hp -= 1;
		if (CollisonCheck == false)
		{
			Yellow_Horse_Body->ColorOptionValue.PlusColor = { 1,1,1,0 };
			Yellow_Horse_Head->ColorOptionValue.PlusColor = { 1,1,1,0 };
			Phase3_Idle->ColorOptionValue.PlusColor = { 1,1,1,0 };
			Green_Horse_Body->ColorOptionValue.PlusColor = { 1,1,1,0 };
			Green_Horse_Head->ColorOptionValue.PlusColor = { 1,1,1,0 };
			Green_Horse_Attack->ColorOptionValue.PlusColor = { 1,1,1,0 };
			Yellow_Horse_Attack->ColorOptionValue.PlusColor = { 1,1,1,0 };
		
			Phase3_Idle->ResetLiveTime();
			CollisonCheck = true;
		}

		std::shared_ptr<GameEngineCollision> collision = Collision->Collision((int)CollisionType::Bullet);
		collision->Death();
	}

	if (CollisonCheck == true && Phase3_Idle->GetLiveTime() > 0.05f)
	{
		Yellow_Horse_Body->ColorOptionValue.PlusColor = { 0,0,0,0 };
		Yellow_Horse_Head->ColorOptionValue.PlusColor = { 0,0,0,0 };
		Phase3_Idle->ColorOptionValue.PlusColor = { 0,0,0,0 };
		Green_Horse_Body->ColorOptionValue.PlusColor = { 0,0,0,0 };
		Green_Horse_Head->ColorOptionValue.PlusColor = { 0,0,0,0 };
		Green_Horse_Attack->ColorOptionValue.PlusColor = { 0,0,0,0 };
		Yellow_Horse_Attack->ColorOptionValue.PlusColor = { 0,0,0,0 };
		CollisonCheck = false;
	}




	UpdateState(_Delta);
}

void Ph3_Bepi::Render(float _Delta)
{
}

void Ph3_Bepi::AnimationCheck(const std::string_view& _AnimationName)
{

}


void Ph3_Bepi::LevelChangeStart()
{
}
