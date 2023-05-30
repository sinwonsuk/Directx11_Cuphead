#include "PrecompileHeader.h"
#include "DogAirplane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "EnumClass.cpp"
DogAirplane::DogAirplane()
{
}

DogAirplane::~DogAirplane()
{
}

void DogAirplane::LevelChangeStart()
{
	
}



void DogAirplane::AnimationCheck(const std::string_view& _AnimationName)
{
	bulldogIdle->ChangeAnimation(_AnimationName);
}


void DogAirplane::Start()
{
	if (nullptr == GameEngineSprite::Find("Chinook_Pilot_Saluki"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Chinook_Pilot_Saluki").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_dogcopter_intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_bulldog_intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DogAirplane").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Airplane_Back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Airplane_Front").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Left").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Right").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Jump").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Attack_Pase1").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Jump_Reverse").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_plane_flap_left_a").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_plane_flap_left_b").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_plane_flap_left_c").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_plane_flap_left_d").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_dog_a_ball_toss").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_dog_b_ball_toss").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_plane_wing").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("AirPlane_Tail").GetFullPath());

	}

	GirlDog = CreateComponent<GameEngineSpriteRenderer>();
	GirlDog->CreateAnimation({ .AnimationName = "Chinook_Pilot_Saluki", .SpriteName = "Chinook_Pilot_Saluki", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	GirlDog->ChangeAnimation("Chinook_Pilot_Saluki");
	GirlDog->GetTransform()->AddLocalPosition({ 130,0, 81 }); 
	 
	dogcopter = CreateComponent<GameEngineSpriteRenderer>();
	dogcopter->CreateAnimation({ .AnimationName = "ph1_dogcopter_intro", .SpriteName = "ph1_dogcopter_intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	dogcopter->ChangeAnimation("ph1_dogcopter_intro");
	dogcopter->GetTransform()->AddLocalPosition({ 130,0,82 });

	bulldogIntro = CreateComponent<GameEngineSpriteRenderer>();
	bulldogIntro->CreateAnimation({ .AnimationName = "ph1_bulldog_intro", .SpriteName = "ph1_bulldog_intro", .FrameInter = 0.07f,.Loop = false, .ScaleToTexture = true, });
	bulldogIntro->ChangeAnimation("ph1_bulldog_intro");
	bulldogIntro->GetTransform()->AddLocalPosition({ 0,0,89 });
	bulldogIntro->Off();


	Airplane_Tail = CreateComponent<GameEngineSpriteRenderer>();
	Airplane_Tail->CreateAnimation({ .AnimationName = "AirPlane_Tail", .SpriteName = "AirPlane_Tail", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Airplane_Tail->ChangeAnimation("AirPlane_Tail");
	Airplane_Tail->GetTransform()->AddLocalPosition({ 0,600,88 });


	Airplane_Wing = CreateComponent<GameEngineSpriteRenderer>();
	Airplane_Wing->CreateAnimation({ .AnimationName = "bulldog_plane_wing", .SpriteName = "bulldog_plane_wing", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Airplane_Wing->ChangeAnimation("bulldog_plane_wing");
	Airplane_Wing->GetTransform()->AddLocalPosition({ 0,600,87 });
	
	

	

	AirplaneFlap_A = CreateComponent<GameEngineSpriteRenderer>();
	AirplaneFlap_A->CreateAnimation({ .AnimationName = "bulldog_plane_flap_left_a", .SpriteName = "bulldog_plane_flap_left_a", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	AirplaneFlap_A->ChangeAnimation("bulldog_plane_flap_left_a");
	AirplaneFlap_A->GetTransform()->AddLocalPosition({ 0,600,86 });

	AirplaneFlap_B = CreateComponent<GameEngineSpriteRenderer>();
	AirplaneFlap_B->CreateAnimation({ .AnimationName = "bulldog_plane_flap_left_b", .SpriteName = "bulldog_plane_flap_left_b", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	AirplaneFlap_B->ChangeAnimation("bulldog_plane_flap_left_b");
	AirplaneFlap_B->GetTransform()->AddLocalPosition({ 0,600,86 });

	AirplaneFlap_C = CreateComponent<GameEngineSpriteRenderer>();
	AirplaneFlap_C->CreateAnimation({ .AnimationName = "bulldog_plane_flap_left_c", .SpriteName = "bulldog_plane_flap_left_c", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	AirplaneFlap_C->ChangeAnimation("bulldog_plane_flap_left_c");
	AirplaneFlap_C->GetTransform()->AddLocalPosition({ 0,600,86 });

	AirplaneFlap_D = CreateComponent<GameEngineSpriteRenderer>();
	AirplaneFlap_D->CreateAnimation({ .AnimationName = "bulldog_plane_flap_left_d", .SpriteName = "bulldog_plane_flap_left_d", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	AirplaneFlap_D->ChangeAnimation("bulldog_plane_flap_left_d");
	AirplaneFlap_D->GetTransform()->AddLocalPosition({ 0,600,86 });

	Ball_Monster = CreateComponent<GameEngineSpriteRenderer>();
	Ball_Monster->CreateAnimation({ .AnimationName = "ph1_dog_a_ball_toss", .SpriteName = "ph1_dog_a_ball_toss", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Ball_Monster->CreateAnimation({ .AnimationName = "ph1_dog_b_ball_toss", .SpriteName = "ph1_dog_b_ball_toss", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Ball_Monster->ChangeAnimation("ph1_dog_a_ball_toss");
	Ball_Monster->GetTransform()->AddLocalPosition({ 170,640,85 });



	Airplane_Back = CreateComponent<GameEngineSpriteRenderer>();
	Airplane_Back->CreateAnimation({ .AnimationName = "Airplane_Back", .SpriteName = "Airplane_Back", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Airplane_Back->ChangeAnimation("Airplane_Back");
	Airplane_Back->GetTransform()->AddLocalPosition({ 0,600,85 });
	Airplane_Back->On();


	Airplane_Front = CreateComponent<GameEngineSpriteRenderer>();
	Airplane_Front->CreateAnimation({ .AnimationName = "Airplane_Front", .SpriteName = "Airplane_Front", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Airplane_Front->ChangeAnimation("Airplane_Front");
	Airplane_Front->GetTransform()->AddLocalPosition({ 0,600,83 });
	Airplane_Front->On();

	AirplaneSpin = CreateComponent<GameEngineSpriteRenderer>();
	AirplaneSpin->CreateAnimation({ .AnimationName = "DogAirplane", .SpriteName = "DogAirplane", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	AirplaneSpin->ChangeAnimation("DogAirplane");
	AirplaneSpin->GetTransform()->AddLocalPosition({ 0,600,82 });
	AirplaneSpin->On();
	
	
	bulldogIdle = CreateComponent<GameEngineSpriteRenderer>();
	bulldogIdle->CreateAnimation({ .AnimationName = "bulldog_Idle", .SpriteName = "bulldog_Idle", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	bulldogIdle->CreateAnimation({ .AnimationName = "bulldog_Jump", .SpriteName = "bulldog_Jump", .FrameInter = 0.08f,.Loop = false, .ScaleToTexture = true, });
	bulldogIdle->CreateAnimation({ .AnimationName = "bulldog_Jump_Reverse", .SpriteName = "bulldog_Jump_Reverse", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	bulldogIdle->CreateAnimation({ .AnimationName = "bulldog_Attack_Pase1", .SpriteName = "bulldog_Attack_Pase1", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });


	bulldogIdle->ChangeAnimation("bulldog_Attack_Pase1");
	//bulldogIdle->GetTransform()->AddLocalPosition({ 0,100,81 });
	bulldogIdle->On();



	

	
	

	
}

void DogAirplane::Update(float _Delta)
{
	
//	UpdateState(_Delta);
	float4 ad = bulldogIdle->GetTransform()->GetLocalScale();
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			bulldogIdle->GetTransform()->SetLocalNegativeScaleX();
		}
	

	
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			bulldogIdle->GetTransform()->SetLocalPositiveScaleX();
		}
	



		float4 a = bulldogIdle->GetTransform()->GetLocalScale();

}
void DogAirplane::Render(float _Delta)
{

}
