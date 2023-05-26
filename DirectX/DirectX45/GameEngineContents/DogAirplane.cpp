#include "PrecompileHeader.h"
#include "DogAirplane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include "EnumClass.cpp"
DogAirplane::DogAirplane()
{
}

DogAirplane::~DogAirplane()
{
}




void DogAirplane::AnimationCheck(const std::string_view& _AnimationName)
{
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
	}

	GirlDog = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::ChinookIntro);
	GirlDog->CreateAnimation({ .AnimationName = "Chinook_Pilot_Saluki", .SpriteName = "Chinook_Pilot_Saluki", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	GirlDog->ChangeAnimation("Chinook_Pilot_Saluki");
	GirlDog->GetTransform()->AddLocalPosition({ 130,0 }); 
	 
	dogcopter = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::DogCopterIntro);
	dogcopter->CreateAnimation({ .AnimationName = "ph1_dogcopter_intro", .SpriteName = "ph1_dogcopter_intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	dogcopter->ChangeAnimation("ph1_dogcopter_intro");
	dogcopter->GetTransform()->AddLocalPosition({ 130,0 });

	bulldogIntro = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::BulDogIntro);
	bulldogIntro->CreateAnimation({ .AnimationName = "ph1_bulldog_intro", .SpriteName = "ph1_bulldog_intro", .FrameInter = 0.07f,.Loop = false, .ScaleToTexture = true, });
	bulldogIntro->ChangeAnimation("ph1_bulldog_intro");
	bulldogIntro->Off();

	AirplaneSpin = CreateComponent<GameEngineSpriteRenderer>(11);
	AirplaneSpin->CreateAnimation({ .AnimationName = "DogAirplane", .SpriteName = "DogAirplane", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	AirplaneSpin->ChangeAnimation("DogAirplane"); 
	AirplaneSpin->GetTransform()->AddLocalPosition({ 0,600 });
	AirplaneSpin->On();

	Airplane_Back = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::Airplane);
	Airplane_Back->CreateAnimation({ .AnimationName = "Airplane_Back", .SpriteName = "Airplane_Back", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Airplane_Back->ChangeAnimation("Airplane_Back");
	Airplane_Back->GetTransform()->AddLocalPosition({ 0,600 });
	Airplane_Back->On();

	Airplane_Front = CreateComponent<GameEngineSpriteRenderer>(10);
	Airplane_Front->CreateAnimation({ .AnimationName = "Airplane_Front", .SpriteName = "Airplane_Front", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Airplane_Front->ChangeAnimation("Airplane_Front");
	Airplane_Front->GetTransform()->AddLocalPosition({ 0,600 });
	Airplane_Front->On();

	bulldogIdle = CreateComponent<GameEngineSpriteRenderer>(11);
	bulldogIdle->CreateAnimation({ .AnimationName = "bulldog_Idle", .SpriteName = "bulldog_Idle", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	bulldogIdle->ChangeAnimation("bulldog_Idle");
	bulldogIdle->GetTransform()->AddLocalPosition({ 0,650 });
	bulldogIdle->On();

	
	
}

void DogAirplane::Update(float _Delta)
{

	UpdateState(_Delta);
}
void DogAirplane::Render(float _Delta)
{

}
