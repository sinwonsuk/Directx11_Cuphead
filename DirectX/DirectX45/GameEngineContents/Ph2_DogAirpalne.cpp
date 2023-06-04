#include "PrecompileHeader.h"
#include "Ph2_DogAirpalne.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>

Ph2_DogAirpalne::Ph2_DogAirpalne()
{
}

Ph2_DogAirpalne::~Ph2_DogAirpalne()
{
}

void Ph2_DogAirpalne::Start()
{
	if (nullptr == GameEngineSprite::Find("Chinook_Pilot_Saluki"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_a_intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_a_intro_transition").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_b_intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_b_intro_transition").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_c_intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_c_intro_transition").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_d_intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_d_intro_transition").GetFullPath());
	
	}

	Ph2_Boss = CreateComponent<GameEngineSpriteRenderer>();
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_a_intro", .SpriteName = "ph2_dog_a_intro", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_a_intro_transition", .SpriteName = "ph2_dog_a_intro_transition", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_b_intro", .SpriteName = "ph2_dog_b_intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_b_intro_transition", .SpriteName = "ph2_dog_b_intro_transition", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_c_intro", .SpriteName = "ph2_dog_c_intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_c_intro_transition", .SpriteName = "ph2_dog_c_intro_transition", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_d_intro", .SpriteName = "ph2_dog_d_intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_d_intro_transition", .SpriteName = "ph2_dog_d_intro_transition", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });

	
	Ph2_Boss->ChangeAnimation("ph2_dog_a_intro");
	
	
	Ph2_Boss->GetTransform()->SetWorldPosition({ -620,0,82 });




}

void Ph2_DogAirpalne::Update(float _Delta)
{
	switch (directionCheck)
	{
	case DirectionCheck::Left:
	{

	}

		break;
	case DirectionCheck::Up:
	{

	}

		break;
	case DirectionCheck::Right:
	{

	}

		break;
	case DirectionCheck::Down:
	{

	}

		break;
	default:
		break;
	}
	UpdateState(_Delta);
}

void Ph2_DogAirpalne::Render(float _Delta)
{

}

void Ph2_DogAirpalne::AnimationCheck(const std::string_view& _AnimationName)
{
	Ph2_Boss->ChangeAnimation(_AnimationName);
}


