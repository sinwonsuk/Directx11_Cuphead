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
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Airplane").GetFullPath());
	}

	GirlDog = CreateComponent<GameEngineSpriteRenderer>(5);
	GirlDog->CreateAnimation({ .AnimationName = "Chinook_Pilot_Saluki", .SpriteName = "Chinook_Pilot_Saluki", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	GirlDog->ChangeAnimation("Chinook_Pilot_Saluki");
	 
	dogcopter = CreateComponent<GameEngineSpriteRenderer>(4);
	dogcopter->CreateAnimation({ .AnimationName = "ph1_dogcopter_intro", .SpriteName = "ph1_dogcopter_intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	dogcopter->ChangeAnimation("ph1_dogcopter_intro");

	bulldog = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::Boss);
	bulldog->CreateAnimation({ .AnimationName = "ph1_bulldog_intro", .SpriteName = "ph1_bulldog_intro", .FrameInter = 0.07f,.Loop = false, .ScaleToTexture = true, });
	bulldog->ChangeAnimation("ph1_bulldog_intro");
	bulldog->Off();

	AirplaneSpin = CreateComponent<GameEngineSpriteRenderer>(4);
	AirplaneSpin->CreateAnimation({ .AnimationName = "DogAirplane", .SpriteName = "DogAirplane", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	AirplaneSpin->ChangeAnimation("DogAirplane"); 
	AirplaneSpin->GetTransform()->AddLocalPosition({ 0,500 });
	AirplaneSpin->Off();

	Airplane = CreateComponent<GameEngineSpriteRenderer>(DogAirplaneType::Boss);
	Airplane->CreateAnimation({ .AnimationName = "Airplane", .SpriteName = "Airplane", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Airplane->ChangeAnimation("Airplane");
	Airplane->GetTransform()->AddLocalPosition({ 0,500 });
	Airplane->Off();
}

void DogAirplane::Update(float _Delta)
{

	UpdateState(_Delta);
}
void DogAirplane::Render(float _Delta)
{

}
