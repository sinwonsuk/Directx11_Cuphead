#include "PrecompileHeader.h"
#include "DogAirplane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineSprite.h>
#include "EnumClass.cpp"
#include "IdleWeapon.h"
#include "Dog_ball.h"
int DogAirplane::Hp = 59;
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
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Attack2_Pase1_intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Attack2_Pase1_Attack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_dogcopter_hydrant").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ph1_Buldog_Death").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("acada").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_2_transition_mini_dogs").GetFullPath());

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

	dogcopter_hydrant = CreateComponent<GameEngineSpriteRenderer>();
	dogcopter_hydrant->CreateAnimation({ .AnimationName = "ph1_dogcopter_hydrant", .SpriteName = "ph1_dogcopter_hydrant", .FrameInter = 0.07f,.Loop = false, .ScaleToTexture = true, });
	dogcopter_hydrant->ChangeAnimation("ph1_dogcopter_hydrant");
	dogcopter_hydrant->GetTransform()->AddLocalPosition({ 0,0,88 });
	dogcopter_hydrant->Off();

	Airplane_Tail = CreateComponent<GameEngineSpriteRenderer>();
	Airplane_Tail->CreateAnimation({ .AnimationName = "AirPlane_Tail", .SpriteName = "AirPlane_Tail", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Airplane_Tail->ChangeAnimation("AirPlane_Tail");
	Airplane_Tail->GetTransform()->AddLocalPosition({ 0,600,88 });


	Airplane_Wing = CreateComponent<GameEngineSpriteRenderer>();
	Airplane_Wing->CreateAnimation({ .AnimationName = "bulldog_plane_wing", .SpriteName = "bulldog_plane_wing", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Airplane_Wing->ChangeAnimation("bulldog_plane_wing");
	Airplane_Wing->GetTransform()->AddLocalPosition({ 0,600,87 });
	
	testImage = CreateComponent<GameEngineSpriteRenderer>();
	testImage->CreateAnimation({ .AnimationName = "Ph1_Buldog_Death", .SpriteName = "Ph1_Buldog_Death", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	testImage->ChangeAnimation("Ph1_Buldog_Death");
	testImage->GetTransform()->AddLocalPosition({ 0,0,79 });

	testImage1 = CreateComponent<GameEngineSpriteRenderer>();
	testImage1->CreateAnimation({ .AnimationName = "acada", .SpriteName = "acada", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	testImage1->ChangeAnimation("acada");
	testImage1->GetTransform()->AddLocalPosition({ 0,0,80 });

	testImage2 = CreateComponent<GameEngineSpriteRenderer>();
	testImage2->CreateAnimation({ .AnimationName = "ph1_2_transition_mini_dogs", .SpriteName = "ph1_2_transition_mini_dogs", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	testImage2->ChangeAnimation("ph1_2_transition_mini_dogs");
	testImage2->GetTransform()->AddLocalPosition({ 0,0,80 });


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
	Ball_Monster->CreateAnimation({ .AnimationName = "ph1_dog_a_ball_toss", .SpriteName = "ph1_dog_a_ball_toss", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Ball_Monster->CreateAnimation({ .AnimationName = "ph1_dog_b_ball_toss", .SpriteName = "ph1_dog_b_ball_toss", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Ball_Monster->ChangeAnimation("ph1_dog_a_ball_toss");
	Ball_Monster->GetTransform()->AddLocalPosition({ 170,640,85 });
	Ball_Monster->Off();


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
	bulldogIdle->CreateAnimation({ .AnimationName = "bulldog_Attack2_Pase1_intro", .SpriteName = "bulldog_Attack2_Pase1_intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	bulldogIdle->CreateAnimation({ .AnimationName = "bulldog_Attack2_Pase1_Attack", .SpriteName = "bulldog_Attack2_Pase1_Attack", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	bulldogIdle->ChangeAnimation("bulldog_Idle");
	bulldogIdle->GetTransform()->AddLocalPosition({ 0,650,81 });
	bulldogIdle->On();

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 300.0f, 300.0f, 300.0f });

	Collision->SetOrder((int)CollisionType::DogAirPlane_Pase1);

}

void DogAirplane::Update(float _Delta)
{		
	Collision->GetTransform()->SetLocalPosition({ bulldogIdle->GetTransform()->GetLocalPosition()});

	


	

	if (Hp == 50)
	{
		dogcopter_hydrant->On();
	}

	if (dogcopter_hydrant->IsAnimationEnd())
	{
		dogcopter_hydrant->Death();
	}
	
	Ball_Monster_Time += _Delta;

	if (Ball_Monster_Time > 3)
	{
		int test = GameEngineRandom::MainRandom.RandomInt(0,3);

		if (test == 0)
		{
			Ball_Monster->GetTransform()->SetWorldPosition({ AirplaneFlap_A->GetTransform()->GetWorldPosition().x - 418,AirplaneFlap_A->GetTransform()->GetWorldPosition().y + 80,85});
			Ball_Monster->GetTransform()->SetLocalRotation({ 0,180,0 });
			Ball_Monster->ChangeAnimation("ph1_dog_b_ball_toss");
			Ball_Monster->On();
		}

		 if (test == 1)
		{
			Ball_Monster->ChangeAnimation("ph1_dog_a_ball_toss");
			Ball_Monster->GetTransform()->SetWorldPosition({ AirplaneFlap_A->GetTransform()->GetWorldPosition().x - 160,AirplaneFlap_A->GetTransform()->GetWorldPosition().y + 40 ,85});		
			Ball_Monster->GetTransform()->SetLocalRotation({ 0,180,0 });
			Ball_Monster->On();
		}

		else if (test == 2)
		{
			Ball_Monster->ChangeAnimation("ph1_dog_a_ball_toss");
			Ball_Monster->GetTransform()->SetWorldPosition({ AirplaneFlap_A->GetTransform()->GetWorldPosition().x + 170,AirplaneFlap_A->GetTransform()->GetWorldPosition().y + 40 ,85});	
			Ball_Monster->GetTransform()->SetLocalRotation({ 0,0,0 });
			Ball_Monster->On();
		}

		else if (test == 3)
		{

		 Ball_Monster->GetTransform()->SetWorldPosition({ AirplaneFlap_A->GetTransform()->GetWorldPosition().x + 418,AirplaneFlap_A->GetTransform()->GetWorldPosition().y + 80,85 });
		 Ball_Monster->GetTransform()->SetLocalRotation({ 0,0,0 });
		 Ball_Monster->ChangeAnimation("ph1_dog_b_ball_toss");
		 Ball_Monster->On();

		}

		 Ball_Monster_Time = 0;
	}

	if (Ball_Monster->GetCurrentFrame() == 6 && Ball_MonsterCheck ==false)
	{
		
		std::shared_ptr<Dog_ball> Object = GetLevel()->CreateActor<Dog_ball>(4);
		Object->GetTransform()->SetLocalPosition({ Ball_Monster->GetTransform()->GetLocalPosition().x, Ball_Monster->GetTransform()->GetLocalPosition().y + 50 });
	
		Ball_MonsterCheck = true;
	}


	if (Ball_Monster->IsAnimationEnd())
	{
		
		Ball_MonsterCheck = false;
		Ball_Monster->Off();
	}


	UpdateState(_Delta);
}
void DogAirplane::Render(float _Delta)
{

}
