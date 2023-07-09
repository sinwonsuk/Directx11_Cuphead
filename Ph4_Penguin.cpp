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
	clown_ph3_penguin_clapspark->CreateAnimation({ .AnimationName = "HorseShoe_Gold", .SpriteName = "HorseShoe_Gold", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	clown_ph3_penguin_clapspark->ChangeAnimation("HorseShoe_Gold");
	clown_ph3_penguin_clapspark->Off();

	clown_ph3_penguin_clap = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_clap->CreateAnimation({ .AnimationName = "clown_ph3_horse_horseshoe_puff", .SpriteName = "clown_ph3_horse_horseshoe_puff", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	clown_ph3_penguin_clap->ChangeAnimation("clown_ph3_horse_horseshoe_puff");
	clown_ph3_penguin_clap->Off();

	clown_ph3_penguin_idle = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_idle->CreateAnimation({ .AnimationName = "clown_ph3_horse_horseshoe_explode_yellow", .SpriteName = "clown_ph3_horse_horseshoe_explode_yellow", .FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	clown_ph3_penguin_idle->ChangeAnimation("clown_ph3_horse_horseshoe_explode_yellow");
	clown_ph3_penguin_idle->Off();


	clown_ph3_penguin_roll_Jump = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_roll_Jump->CreateAnimation({ .AnimationName = "clown_ph3_horse_horseshoe_explode_yellow", .SpriteName = "clown_ph3_horse_horseshoe_explode_yellow", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	clown_ph3_penguin_roll_Jump->ChangeAnimation("clown_ph3_horse_horseshoe_explode_yellow");
	clown_ph3_penguin_roll_Jump->Off();


	clown_ph3_penguin_roll_ground = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_roll_ground->CreateAnimation({ .AnimationName = "clown_ph3_horse_horseshoe_explode_yellow", .SpriteName = "clown_ph3_horse_horseshoe_explode_yellow", .FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	clown_ph3_penguin_roll_ground->ChangeAnimation("clown_ph3_horse_horseshoe_explode_yellow");
	clown_ph3_penguin_roll_ground->Off();


	clown_ph3_penguin_roll = CreateComponent<GameEngineSpriteRenderer>();
	clown_ph3_penguin_roll->CreateAnimation({ .AnimationName = "clown_ph3_horse_horseshoe_explode_yellow", .SpriteName = "clown_ph3_horse_horseshoe_explode_yellow", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });
	clown_ph3_penguin_roll->ChangeAnimation("clown_ph3_horse_horseshoe_explode_yellow");
	//clown_ph3_penguin_roll->Off();

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision->GetTransform()->AddLocalPosition({ 0.0f,0.0f });


	Collision->SetOrder((int)CollisionType::ph4_Bepi_penguin);
	Collision->SetColType(ColType::AABBBOX2D);

}

void Ph4_Penguin::Update(float _Delta)
{
	if (clown_ph3_penguin_roll->GetCurrentFrame() > 10 && CoiisionCheck == false)
	{
		GetTransform()->AddLocalPosition({ float4::Down * _Delta * Speed });
	}

	if (Collision->Collision((int)CollisionType::BepiMap) && CoiisionCheck == false)
	{
		clown_ph3_penguin_roll->Off();
		clown_ph3_penguin_roll_ground->On();
		CoiisionCheck = true;

	}
	if (CoiisionCheck == true)
	{
		switch (dir)
		{
		case Ph4_Penguin_Dir::Left:
		{


			if (MoveCheck == false)
			{
				GetTransform()->AddLocalPosition({ float4::Left * _Delta * Speed });

			}
			if (GetTransform()->GetLocalPosition().x < StopPos && MoveCheck == false)
			{

				clown_ph3_penguin_roll_ground->Off();
				clown_ph3_penguin_roll_Jump->On();
				MoveCheck = true;
			}

			if (clown_ph3_penguin_roll_Jump->IsAnimationEnd() && MoveCheck == true)
			{
				clown_ph3_penguin_idle->On();
			}

			if (GetLiveTime() > 3 && MoveCheck == true)
			{
				clown_ph3_penguin_idle->Off();
				clown_ph3_penguin_clap->On();
			}
			if (clown_ph3_penguin_clap->IsAnimationEnd())
			{
				clown_ph3_penguin_clap->Off();
				clown_ph3_penguin_idle->On();
				ResetLiveTime();
			}


		}
		break;
		case Ph4_Penguin_Dir::Right:
		{
			if (MoveCheck == false)
			{
				GetTransform()->AddLocalPosition({ float4::Right * _Delta * Speed });
			}
			if (GetTransform()->GetLocalPosition().x < StopPos && MoveCheck == false)
			{
				clown_ph3_penguin_roll_ground->Off();
				clown_ph3_penguin_roll_Jump->On();
				MoveCheck = true;
			}

			if (clown_ph3_penguin_roll_Jump->IsAnimationEnd() && MoveCheck == true)
			{
				clown_ph3_penguin_idle->On();
			}

			if (GetLiveTime() > 3 && MoveCheck == true)
			{
				clown_ph3_penguin_idle->Off();
				clown_ph3_penguin_clap->On();
			}
			if (clown_ph3_penguin_clap->IsAnimationEnd())
			{
				clown_ph3_penguin_clap->Off();
				clown_ph3_penguin_idle->On();
				ResetLiveTime();
			}
		}
		break;
		default:
			break;
		}
	}

}