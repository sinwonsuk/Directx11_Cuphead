#include "PrecompileHeader.h"
#include "Dog_ball.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>

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
	
	Middle_Ball = CreateComponent<GameEngineSpriteRenderer>();
	Middle_Ball->CreateAnimation({ .AnimationName = "ph1_dog_ball", .SpriteName = "ph1_dog_ball", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Middle_Ball->ChangeAnimation("ph1_dog_ball");

	Right_Ball = CreateComponent<GameEngineSpriteRenderer>();
	Right_Ball->CreateAnimation({ .AnimationName = "ph1_dog_ball", .SpriteName = "ph1_dog_ball", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Right_Ball->ChangeAnimation("ph1_dog_ball");
	


}


void Dog_ball::Update(float _Delta)
{
	Gravity += float4::Down * 30.0f * _Delta;

	if (Gravity.y > 1500)
	{
		Gravity.y = 1500;
	}


	GetTransform()->AddLocalPosition({ Gravity });

	Left_Ball->GetTransform()->AddLocalPosition(LeftMoveDir *_Delta *650);
	Middle_Ball->GetTransform()->AddLocalPosition(MiddleMoveDir *_Delta * 650);
	Right_Ball->GetTransform()->AddLocalPosition( RightMoveDir *_Delta * 650);
}

void Dog_ball::Render(float _Delta)
{
}

