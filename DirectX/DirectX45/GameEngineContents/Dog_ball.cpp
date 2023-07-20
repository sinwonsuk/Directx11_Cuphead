#include "PrecompileHeader.h"
#include "Dog_ball.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"
#include "Player.h"
Dog_ball::Dog_ball()
{
}

Dog_ball::~Dog_ball()
{
}

void Dog_ball::Start()
{
	if (nullptr == GameEngineSprite::Find("ph1_dog_ball"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_dog_ball").GetFullPath());
	
	
	}



	Left_Ball = CreateComponent<GameEngineSpriteRenderer>();
	Left_Ball->CreateAnimation({ .AnimationName = "ph1_dog_ball", .SpriteName = "ph1_dog_ball", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Left_Ball->ChangeAnimation("ph1_dog_ball");
	Left_Ball->GetTransform()->AddLocalPosition({ 0.0f, 0.0f, -100.0f });


	Middle_Ball = CreateComponent<GameEngineSpriteRenderer>();
	Middle_Ball->CreateAnimation({ .AnimationName = "ph1_dog_ball", .SpriteName = "ph1_dog_ball", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Middle_Ball->ChangeAnimation("ph1_dog_ball");
	Middle_Ball->GetTransform()->AddLocalPosition({ 0.0f, 0.0f, -100.0f });

	Right_Ball = CreateComponent<GameEngineSpriteRenderer>();
	Right_Ball->CreateAnimation({ .AnimationName = "ph1_dog_ball", .SpriteName = "ph1_dog_ball", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Right_Ball->ChangeAnimation("ph1_dog_ball");
	Right_Ball->GetTransform()->AddLocalPosition({ 0.0f, 0.0f, -100.0f });

	LeftCollision = CreateComponent<GameEngineCollision>();
	
	LeftCollision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 300.0f });
	
	LeftCollision->SetOrder((int)CollisionType::BossAttack);

	RightCollision = CreateComponent<GameEngineCollision>();
	RightCollision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 300.0f });
	
	RightCollision->SetOrder((int)CollisionType::BossAttack);

	MiddleCollision = CreateComponent<GameEngineCollision>();
	MiddleCollision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 300.0f });

	MiddleCollision->SetOrder((int)CollisionType::BossAttack);


}


void Dog_ball::Update(float _Delta)
{
	

	LeftCollision->GetTransform()->SetLocalPosition({ Left_Ball->GetTransform()->GetLocalPosition() });

	MiddleCollision->GetTransform()->SetLocalPosition({ Middle_Ball->GetTransform()->GetLocalPosition() });

	RightCollision->GetTransform()->SetLocalPosition({ Right_Ball->GetTransform()->GetLocalPosition() });

	Gravity += float4::Down * 30.0f * _Delta;

	if (Gravity.y > 100.0f)
	{
		Gravity.y = 100.0f;

		
	}

	if (Gravity.y < -100)
	{
		if (Sound_BaseBall == false)
		{
			Sound = GameEngineSound::Play("sfx_DLC_Dogfight_P1_TerrierPlane_Baseball_Whistle_01.wav");
			Sound.SetVolume(0.5f);
			Sound_BaseBall = true;
		}
	}




	GetTransform()->AddLocalPosition({ Gravity });

	Left_Ball->GetTransform()->AddLocalPosition(LeftMoveDir *_Delta *650.0f);
	Middle_Ball->GetTransform()->AddLocalPosition(MiddleMoveDir *_Delta * 650.0f);
	Right_Ball->GetTransform()->AddLocalPosition( RightMoveDir *_Delta * 650.0f);

	if (Player::MainPlayer->Hp <= 0)
	{
		this->Death(); 
	}

}

void Dog_ball::Render(float _Delta)
{
}

