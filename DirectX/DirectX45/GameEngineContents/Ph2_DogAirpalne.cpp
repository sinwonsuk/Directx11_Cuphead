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
	if (nullptr == GameEngineSprite::Find("ph2_dog_a_intro"))
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

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_3_4_front").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_front_front").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_front_side").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_side").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_front_Up").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_side_back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_3_4_back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_3_4_back_back").GetFullPath());
		
	
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_jetpack_flame_straight").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_jetpack_flame_curve").GetFullPath());
	



	
	}


	jetpack = CreateComponent<GameEngineSpriteRenderer>();
	jetpack->CreateAnimation({ .AnimationName = "ph2_jetpack_flame_straight", .SpriteName = "ph2_jetpack_flame_straight", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true  });
	jetpack->ChangeAnimation("ph2_jetpack_flame_straight");


	Ph2_Boss = CreateComponent<GameEngineSpriteRenderer>();
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_a_intro", .SpriteName = "ph2_dog_a_intro", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_a_intro_transition", .SpriteName = "ph2_dog_a_intro_transition", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_b_intro", .SpriteName = "ph2_dog_b_intro", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_b_intro_transition", .SpriteName = "ph2_dog_b_intro_transition", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_c_intro", .SpriteName = "ph2_dog_c_intro", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_c_intro_transition", .SpriteName = "ph2_dog_c_intro_transition", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_d_intro", .SpriteName = "ph2_dog_d_intro", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,3,2,1} });

	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_3_4_front", .SpriteName = "SD_Idle_3_4_front", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_front_front", .SpriteName = "SD_Idle_front_front", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_front_side", .SpriteName = "SD_Idle_front_side", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_side", .SpriteName = "SD_Idle_side", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_front_Up", .SpriteName = "SD_Idle_front_Up", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });

	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_back", .SpriteName = "SD_Idle_back", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_side_back", .SpriteName = "SD_Idle_side_back", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_3_4_back", .SpriteName = "SD_Idle_3_4_back", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_3_4_back_back", .SpriteName = "SD_Idle_3_4_back_back", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	
	Ph2_Boss->ChangeAnimation("ph2_dog_a_intro");

	
	

	jetpack->GetTransform()->SetParent(Ph2_Boss->GetTransform());




}

void Ph2_DogAirpalne::Update(float _Delta)
{
	
	TransformData date1 = Ph2_Boss->GetTransform()->GetTransDataRef(); 

	TransformData date = jetpack->GetTransform()->GetTransDataRef(); 
	//jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x,Ph2_Boss->GetTransform()->GetLocalPosition().y -50 });

	//UpdateState(_Delta);
}

void Ph2_DogAirpalne::Render(float _Delta)
{

}

void Ph2_DogAirpalne::AnimationCheck(const std::string_view& _AnimationName)
{
	Ph2_Boss->ChangeAnimation(_AnimationName);
}


