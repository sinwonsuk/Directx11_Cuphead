#include "PrecompileHeader.h"
#include "DogAirPlaneManager.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
DogAirplaneManager::DogAirplaneManager()
{

}

DogAirplaneManager::~DogAirplaneManager()
{

}

void DogAirplaneManager::Start()
{
	/*BackGround = GetLevel()->CreateActor<DogAirplaneBackground>();

	Npc = GetLevel()->CreateActor<NpcAirplane>();

	Ph1_DogAirplane = GetLevel()->CreateActor<DogAirplane>();

	player = GetLevel()->CreateActor<Player>();
	player->GetTransform()->AddLocalPosition({ 0,0,0 });



	{
		Ph2_DogAirpalne_Left = GetLevel()->CreateActor<Ph2_DogAirpalne>(4);
		Ph2_DogAirpalne_Left->Get_Ph2_Boss()->GetTransform()->AddLocalPosition({ -700.0f,0.0f,82.0f });
		Ph2_DogAirpalne_Left->Get_jetpack()->GetTransform()->AddLocalPosition({ -750.0f,-50.0f,82.0f });
		Ph2_DogAirpalne_Left->ChangeState(Ph2_DogAirPlaneState::LeftIntro);
	}

	{
		Ph2_DogAirpalne_Top = GetLevel()->CreateActor<Ph2_DogAirpalne>(4);
		Ph2_DogAirpalne_Top->ChangeState(Ph2_DogAirPlaneState::UpIntro);
		Ph2_DogAirpalne_Top->Get_Ph2_Boss()->GetTransform()->AddLocalPosition({ 0.0f,400.0f,82.0f });
		Ph2_DogAirpalne_Top->Get_jetpack()->GetTransform()->AddLocalPosition({ 0.0f,350.0f,82.0f });
	}

	{
		Ph2_DogAirpalne_Right = GetLevel()->CreateActor<Ph2_DogAirpalne>(4);
		Ph2_DogAirpalne_Right->ChangeState(Ph2_DogAirPlaneState::RightIntro);
		Ph2_DogAirpalne_Right->Get_Ph2_Boss()->GetTransform()->AddLocalPosition({ 700.0f,0.0f,82.0f });
		Ph2_DogAirpalne_Right->Get_jetpack()->GetTransform()->AddLocalPosition({ 750.0f,-50.0f,82.0f });
	}

	{
		Ph2_DogAirpalne_Bottom = GetLevel()->CreateActor<Ph2_DogAirpalne>(4);
		Ph2_DogAirpalne_Bottom->ChangeState(Ph2_DogAirPlaneState::DownIntro);
		Ph2_DogAirpalne_Bottom->Get_Ph2_Boss()->GetTransform()->AddLocalPosition({ 0.0f,-400.0f,82.0f });
		Ph2_DogAirpalne_Bottom->Get_jetpack()->GetTransform()->AddLocalPosition({ 0.0f, -450.0f,82.0f });
	}*/

}

void DogAirplaneManager::Update(float _Delta)
{
	/*switch (ad)
	{
	case 0:
	{
		Ph1_DogAirplane->On();
		Ph2_DogAirpalne_Left->Off();
		Ph2_DogAirpalne_Right->Off();
		Ph2_DogAirpalne_Top->Off();
		Ph2_DogAirpalne_Bottom->Off();

	}
	break;

	case 1:
	{
		Ph2_DogAirpalne_Left->On();
		Ph2_DogAirpalne_Right->On();
		Ph2_DogAirpalne_Top->On();
		Ph2_DogAirpalne_Bottom->On();
	}

	case 2:
	{

	}

	break;



	default:
		break;
	}*/
}
