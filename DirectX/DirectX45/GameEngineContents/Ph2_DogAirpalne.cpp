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
		
	
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_3_4_front").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_front_front").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_front_side").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_side").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_front").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_side_back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_3_4_back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_3_4_back_back").GetFullPath());



		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_jetpack_flame_straight").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_jetpack_smoke_a").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_jetpack_smoke_b").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_jetpack_smoke_c").GetFullPath());

		
	



	
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

	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_3_4_front", .SpriteName = "SD_Idle_3_4_front", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_front_front", .SpriteName = "SD_Idle_front_front", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_front_side", .SpriteName = "SD_Idle_front_side", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_side", .SpriteName = "SD_Idle_side", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_front_Up", .SpriteName = "SD_Idle_front_Up", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });

	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_back", .SpriteName = "SD_Idle_back", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_side_back", .SpriteName = "SD_Idle_side_back", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_3_4_back", .SpriteName = "SD_Idle_3_4_back", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Idle_3_4_back_back", .SpriteName = "SD_Idle_3_4_back_back", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, .FrameIndex = {0,1,2,3,4,3,2,1} });
	
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Attack_3_4_front", .SpriteName = "SD_Attack_3_4_front", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Attack_front_front", .SpriteName = "SD_Attack_front_front", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true,  });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Attack_front_side", .SpriteName = "SD_Attack_front_side", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true,  });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Attack_side", .SpriteName = "SD_Attack_side", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Attack_front", .SpriteName = "SD_Attack_front", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true,  });

	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Attack_back", .SpriteName = "SD_Attack_back", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true,  });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Attack_side_back", .SpriteName = "SD_Attack_side_back", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true, });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Attack_3_4_back", .SpriteName = "SD_Attack_3_4_back", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true,  });
	Ph2_Boss->CreateAnimation({ .AnimationName = "SD_Attack_3_4_back_back", .SpriteName = "SD_Attack_3_4_back_back", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true  });


	Ph2_Boss->ChangeAnimation("ph2_dog_a_intro");

	for (size_t i = 0; i < 20; i++)
	{
		
		ph2_jetpack_smoke_a1 = CreateComponent<GameEngineSpriteRenderer>();
		ph2_jetpack_smoke_a1->CreateAnimation({ .AnimationName = "ph2_jetpack_smoke_a", .SpriteName = "ph2_jetpack_smoke_a", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph2_jetpack_smoke_a1->ChangeAnimation("ph2_jetpack_smoke_a");
		ph2_jetpack_smoke_a1->SetScaleRatio(1.2f);
		ph2_jetpack_smoke_a1->Off();

		ph2_jetpack_smoke_a.push_back(ph2_jetpack_smoke_a1);
	}

	

	ph2_jetpack_smoke_b = CreateComponent<GameEngineSpriteRenderer>();
	ph2_jetpack_smoke_b->CreateAnimation({ .AnimationName = "ph2_jetpack_smoke_b", .SpriteName = "ph2_jetpack_smoke_b", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	ph2_jetpack_smoke_b->ChangeAnimation("ph2_jetpack_smoke_b");
	ph2_jetpack_smoke_b->On();
	

	ph2_jetpack_smoke_c = CreateComponent<GameEngineSpriteRenderer>();
	ph2_jetpack_smoke_c->CreateAnimation({ .AnimationName = "ph2_jetpack_smoke_c", .SpriteName = "ph2_jetpack_smoke_c", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	ph2_jetpack_smoke_c->ChangeAnimation("ph2_jetpack_smoke_c");
	ph2_jetpack_smoke_c->On();


}

void Ph2_DogAirpalne::Update(float _Delta)
{
	


	

	

	/*ph2_jetpack_smoke_a->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x,jetpack->GetTransform()->GetLocalPosition().y });

	//TransformData date1 = Ph2_Boss->GetTransform()->GetTransDataRef(); 

	//ph2_jetpack_smoke_a->GetTransform()->SetLocalPosition({ jetpack->GetTransform()->GetLocalPosition().x, jetpack->GetTransform()->GetLocalPosition().y, -85.0f});
	
	/*jetpack->GetTransform()->SetWorldScale({ 100,100,0 });
	jetpack->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition().x,Ph2_Boss->GetTransform()->GetLocalPosition().y -50 });
	TransformData date = jetpack->GetTransform()->GetTransDataRef();*/
	UpdateState(_Delta);
}

void Ph2_DogAirpalne::Render(float _Delta)
{

}

void Ph2_DogAirpalne::AnimationCheck(const std::string_view& _AnimationName)
{
	Ph2_Boss->ChangeAnimation(_AnimationName);
}


