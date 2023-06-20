#include "PrecompileHeader.h"
#include "Ph2_DogAirpalne.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.cpp"


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

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_bow_big_spark").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_death").GetFullPath());



	
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
	Ph2_Boss->CreateAnimation({ .AnimationName = "ph2_dog_death", .SpriteName = "ph2_dog_death", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });

	Ph2_Boss->ChangeAnimation("ph2_dog_a_intro");

	for (size_t i = 0; i < 20; i++)
	{
		
		std::shared_ptr<class GameEngineSpriteRenderer> ph2_jetpack_smoke_a1 = CreateComponent<GameEngineSpriteRenderer>();
		ph2_jetpack_smoke_a1->CreateAnimation({ .AnimationName = "ph2_jetpack_smoke_a", .SpriteName = "ph2_jetpack_smoke_a", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph2_jetpack_smoke_a1->ChangeAnimation("ph2_jetpack_smoke_a");
		ph2_jetpack_smoke_a1->SetScaleRatio(1.2f);
		ph2_jetpack_smoke_a1->Off();

		ph2_jetpack_smoke_a.push_back(ph2_jetpack_smoke_a1);
	}

	

	Attack_Effect = CreateComponent<GameEngineSpriteRenderer>();
	Attack_Effect->CreateAnimation({ .AnimationName = "SD_bow_big_spark", .SpriteName = "SD_bow_big_spark", .FrameInter = 0.07f,.Loop = false, .ScaleToTexture = true });
	Attack_Effect->ChangeAnimation("SD_bow_big_spark");
	Attack_Effect->Off();
	
	
	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 300.0f, 250.0f, 300.0f });

	Collision->SetOrder((int)CollisionType::BossBody);

}

void Ph2_DogAirpalne::Update(float _Delta)
{
	


		Collision->GetTransform()->SetLocalPosition({ Ph2_Boss->GetTransform()->GetLocalPosition()});
	

		if (Collision->Collision((int)CollisionType::Bullet))
		{
			if (CollisonCheck == false)
			{

				Ph2_Boss->ColorOptionValue.PlusColor = { 1,1,1,0 };
				Ph2_Boss->ResetLiveTime();
				CollisonCheck = true;

			}
			std::shared_ptr<GameEngineCollision> collision = Collision->Collision((int)CollisionType::Bullet);
			Hp -= 1;
			collision->Death();
		}







		if (CollisonCheck == true && Ph2_Boss->GetLiveTime() > 0.05f)
		{
			Ph2_Boss->ColorOptionValue.PlusColor = { 0,0,0,0 };
			CollisonCheck = false;
		}

		

	

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


