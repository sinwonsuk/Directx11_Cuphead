#include "PrecompileHeader.h"
#include "Ph4_Penguin.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineContents/EnumClass.h>
Ph4_Penguin::Ph4_Penguin()
{
}

Ph4_Penguin::~Ph4_Penguin()
{
}

void Ph4_Penguin::Start()
{

	clown_ph3_penguin_clapspark = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_clapspark->CreateAnimation({ .AnimationName = "clown_ph3_penguin_clapspark", .SpriteName = "clown_ph3_penguin_clapspark", .FrameInter = 0.1f, .Loop = false, .ScaleToTexture = true });
	clown_ph3_penguin_clapspark->ChangeAnimation("clown_ph3_penguin_clapspark");
	clown_ph3_penguin_clapspark->GetTransform()->AddLocalPosition({ 0.0f,90.0f });
	clown_ph3_penguin_clapspark->Off();

	clown_ph3_penguin_clap = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_clap->CreateAnimation({ .AnimationName = "clown_ph3_penguin_clap", .SpriteName = "clown_ph3_penguin_clap", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true  ,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,10,10,10} });
	clown_ph3_penguin_clap->ChangeAnimation("clown_ph3_penguin_clap");
	clown_ph3_penguin_clap->Off();

	clown_ph3_penguin_idle = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_idle->CreateAnimation({ .AnimationName = "clown_ph3_penguin_idle", .SpriteName = "clown_ph3_penguin_idle", .FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	clown_ph3_penguin_idle->ChangeAnimation("clown_ph3_penguin_idle");
	clown_ph3_penguin_idle->Off();


	clown_ph3_penguin_roll_Jump = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_roll_Jump->CreateAnimation({ .AnimationName = "clown_ph3_penguin_roll_Jump", .SpriteName = "clown_ph3_penguin_roll_Jump", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	clown_ph3_penguin_roll_Jump->ChangeAnimation("clown_ph3_penguin_roll_Jump");
	clown_ph3_penguin_roll_Jump->Off();


	clown_ph3_penguin_roll_ground = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_roll_ground->CreateAnimation({ .AnimationName = "clown_ph3_penguin_roll_ground", .SpriteName = "clown_ph3_penguin_roll_ground", .FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	clown_ph3_penguin_roll_ground->ChangeAnimation("clown_ph3_penguin_roll_ground");
	clown_ph3_penguin_roll_ground->Off();


	clown_ph3_penguin_roll = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_roll->CreateAnimation({ .AnimationName = "clown_ph3_penguin_roll", .SpriteName = "clown_ph3_penguin_roll", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	clown_ph3_penguin_roll->ChangeAnimation("clown_ph3_penguin_roll");

	clown_ph3_penguin_explode = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_explode->CreateAnimation({ .AnimationName = "clown_ph3_penguin_explode", .SpriteName = "clown_ph3_penguin_explode", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	clown_ph3_penguin_explode->ChangeAnimation("clown_ph3_penguin_explode");
	clown_ph3_penguin_explode->Off();

	//clown_ph3_penguin_roll->Off();

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision->SetOrder((int)CollisionType::ph4_Bepi_penguin);
	Collision->GetTransform()->AddLocalPosition({ 0.0f,-50.0f });
	Collision->SetColType(ColType::AABBBOX2D);

	/*HitCollision = CreateComponent<GameEngineCollision>();
	HitCollision->GetTransform()->SetLocalScale({ 50.0f, 100.0f, 200.0f });
	HitCollision->SetOrder((int)CollisionType::BossBody);
	HitCollision->GetTransform()->AddLocalPosition({ 0.0f,0.0f });
	HitCollision->SetColType(ColType::AABBBOX2D);*/
}

void Ph4_Penguin::Update(float _Delta)
{
	



         if (clown_ph3_penguin_clapspark->IsAnimationEnd())
         {
         	clown_ph3_penguin_clapspark->ChangeAnimation("clown_ph3_penguin_clapspark");
         	clown_ph3_penguin_clapspark->Off();
         }

         UpdateState(_Delta);
}