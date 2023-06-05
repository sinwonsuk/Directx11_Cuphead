#include "PrecompileHeader.h"
#include "ph3_DogAirPlane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
Ph3_DogAirplane::Ph3_DogAirplane()
{
}

Ph3_DogAirplane::~Ph3_DogAirplane()
{
}

void Ph3_DogAirplane::AnimationCheck(const std::string_view& _AnimationName)
{
}

void Ph3_DogAirplane::Start()
{

	if (nullptr == GameEngineSprite::Find("ph3_Intro"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_Intro").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_pad_low").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_pad_mid").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_pad_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_Right_paw").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_right_paw_pad_low").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_right_paw_pad_mid").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_right_paw_pad_top").GetFullPath());
		
	}

	Ph3_Boss = CreateComponent<GameEngineSpriteRenderer>();
	Ph3_Boss->CreateAnimation({ .AnimationName = "ph3_Intro", .SpriteName = "ph3_Intro", .FrameInter = 0.01f,.Loop = false, .ScaleToTexture = true, });
	Ph3_Boss->ChangeAnimation("ph3_Intro");

	/*ph3_left_paw = CreateComponent<GameEngineSpriteRenderer>();
	ph3_left_paw->CreateAnimation({ .AnimationName = "ph3_left_paw", .SpriteName = "ph3_left_paw", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	ph3_left_paw->ChangeAnimation("ph3_left_paw");
	ph3_left_paw->GetTransform()->AddLocalPosition({ -550,0 });*/

	ph3_left_paw_pad_low = CreateComponent<GameEngineSpriteRenderer>();
	ph3_left_paw_pad_low->CreateAnimation({ .AnimationName = "ph3_left_paw_pad_low", .SpriteName = "ph3_left_paw_pad_low", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	ph3_left_paw_pad_low->ChangeAnimation("ph3_left_paw_pad_low");
	ph3_left_paw_pad_low->GetTransform()->AddLocalPosition({ -487,-234});

	ph3_left_paw_pad_mid = CreateComponent<GameEngineSpriteRenderer>();
	ph3_left_paw_pad_mid->CreateAnimation({ .AnimationName = "ph3_left_paw_pad_mid", .SpriteName = "ph3_left_paw_pad_mid", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	ph3_left_paw_pad_mid->ChangeAnimation("ph3_left_paw_pad_mid");
	ph3_left_paw_pad_mid->GetTransform()->AddLocalPosition({ -447,-20 });

	ph3_left_paw_pad_top = CreateComponent<GameEngineSpriteRenderer>();
	ph3_left_paw_pad_top->CreateAnimation({ .AnimationName = "ph3_left_paw_pad_top", .SpriteName = "ph3_left_paw_pad_top", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	ph3_left_paw_pad_top->ChangeAnimation("ph3_left_paw_pad_top");
	ph3_left_paw_pad_top->GetTransform()->AddLocalPosition({ -473, 190 });

	/*ph3_Right_paw = CreateComponent<GameEngineSpriteRenderer>();
	ph3_Right_paw->CreateAnimation({ .AnimationName = "ph3_Right_paw", .SpriteName = "ph3_Right_paw", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	ph3_Right_paw->ChangeAnimation("ph3_Right_paw");
	ph3_Right_paw->GetTransform()->AddLocalPosition({ -640,0 });*/

	ph3_right_paw_pad_low = CreateComponent<GameEngineSpriteRenderer>();
	ph3_right_paw_pad_low->CreateAnimation({ .AnimationName = "ph3_right_paw_pad_low", .SpriteName = "ph3_right_paw_pad_low", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
	ph3_right_paw_pad_low->ChangeAnimation("ph3_right_paw_pad_low");

	ph3_right_paw_pad_mid = CreateComponent<GameEngineSpriteRenderer>();
	ph3_right_paw_pad_mid->CreateAnimation({ .AnimationName = "ph3_right_paw_pad_mid", .SpriteName = "ph3_right_paw_pad_mid", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
	ph3_right_paw_pad_mid->ChangeAnimation("ph3_right_paw_pad_mid");

	ph3_right_paw_pad_top = CreateComponent<GameEngineSpriteRenderer>();
	ph3_right_paw_pad_top->CreateAnimation({ .AnimationName = "ph3_right_paw_pad_top", .SpriteName = "ph3_right_paw_pad_top", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
	ph3_right_paw_pad_top->ChangeAnimation("ph3_right_paw_pad_top");

	
}

void Ph3_DogAirplane::Update(float _Delta)
{

}

void Ph3_DogAirplane::Render(float _Delta)
{

}
