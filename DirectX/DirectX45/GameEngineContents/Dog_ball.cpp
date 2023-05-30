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



	Ball_Monster = CreateComponent<GameEngineSpriteRenderer>();
	Ball_Monster->CreateAnimation({ .AnimationName = "ph1_dog_ball", .SpriteName = "ph1_dog_ball", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Ball_Monster->ChangeAnimation("ph1_dog_ball");
	



	


}


void Dog_ball::Update(float _Delta)
{
	GetTransform()->AddLocalPosition(MoveDir* _Delta);
}

void Dog_ball::Render(float _Delta)
{
}

