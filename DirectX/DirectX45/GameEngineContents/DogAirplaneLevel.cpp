#include "PrecompileHeader.h"
#include "DogAirplaneLevel.h"
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "UserInterface.h"
#include "TimeFlow.h"
DogAirplaneLevel::DogAirplaneLevel()
{
}

DogAirplaneLevel::~DogAirplaneLevel()
{
}

void DogAirplaneLevel::Update(float _DeltaTime)
{
	sd += _DeltaTime;
	switch (ad)
	{
	case 0:
	{
		Ph1_DogAirplane->On();
		Ph2_DogAirpalne_Left->Off();
		Ph2_DogAirpalne_Right->Off();
		Ph2_DogAirpalne_Top->Off();
		Ph2_DogAirpalne_Bottom->Off();
		Ph3_DogAirpalne->Off();
	}
	break;

	case 1:
	{
		Ph2_DogAirpalne_Left->On();
		Ph2_DogAirpalne_Right->On();
		Ph2_DogAirpalne_Top->On();
		Ph2_DogAirpalne_Bottom->On();
	}
	break;
	case 2:
	{

		Ph2_DogAirpalne_Left->Off();
		Ph2_DogAirpalne_Right->Off();
		Ph2_DogAirpalne_Top->Off();
		Ph2_DogAirpalne_Bottom->Off();
		Ph3_DogAirpalne->On(); 
	}

	break;



	default:
		break;
	}














	if (Ph3_DogAirplane::ph3_mainBoss != nullptr)
	{
		switch (Ph3_DogAirplane::ph3_mainBoss->GetRotationCheck())
		{
		case 0:
		{
			if (GetLevel()->GetMainCamera()->GetTransform()->GetLocalRotation().z < -90.0f)
			{
				break;
			}

			float test = std::lerp(0.0f, 700.0f, _DeltaTime);
			float test1 = std::lerp(0.0f, -250.0f, _DeltaTime);
			float test2 = std::lerp(0.0f, 50.0f, _DeltaTime);

			Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalRotation({ 0,0,test1 });
			Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalPosition({ test2 , test ,0 });

			if (ph3_Dog_Npc::ph3_Npc != nullptr)
			{
				ph3_Dog_Npc::ph3_Npc->GetTransform()->SetLocalRotation(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalRotation());
				ph3_Dog_Npc::ph3_Npc->GetTransform()->SetLocalPosition(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalPosition());
			}
			if (DogAirplaneBackground::Background != nullptr)
			{
				DogAirplaneBackground::Background->GetTransform()->SetLocalRotation(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalRotation());
				DogAirplaneBackground::Background->GetTransform()->SetLocalPosition(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalPosition());
			}


			GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,test1 });
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ test2,test ,0 });
		}
		break;
		case 1:
		{	
			if (GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef().Rotation.z < -179.5f)
			{

				break;
			}

			float test = std::lerp(0.0f, -700.0f, _DeltaTime);
			float test1 = std::lerp(0.0f, -250.0f, _DeltaTime);
			float test2 = std::lerp(0.0f, 50.0f, _DeltaTime);


			Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalRotation({ 0,0,test1 });
			Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalPosition({ test2,test ,0 });


			if (ph3_Dog_Npc::ph3_Npc != nullptr)
			{
				ph3_Dog_Npc::ph3_Npc->GetTransform()->SetLocalRotation(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalRotation());
				ph3_Dog_Npc::ph3_Npc->GetTransform()->SetLocalPosition(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalPosition());
			}

			if (DogAirplaneBackground::Background != nullptr)
			{
				DogAirplaneBackground::Background->GetTransform()->SetLocalRotation(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalRotation());
				DogAirplaneBackground::Background->GetTransform()->SetLocalPosition(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalPosition());
			}


			GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,test1 });
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ test2,test ,0 });
		}
		break;
		case 2:
		{
			if (GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef().Rotation.z < -269.0f)
			{
				break;
			}

			float test = std::lerp(0.0f, 700.0f, _DeltaTime);
			float test1 = std::lerp(0.0f, -250.0f, _DeltaTime);
			float test2 = std::lerp(0.0f, -230.0f, _DeltaTime);


			GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,test1 });
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ test2,test ,0 });


			Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalRotation({ 0,0,test1 });
			Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalPosition({ test2,test ,0 });


			if (ph3_Dog_Npc::ph3_Npc != nullptr)
			{
				ph3_Dog_Npc::ph3_Npc->GetTransform()->SetLocalRotation(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalRotation());
				ph3_Dog_Npc::ph3_Npc->GetTransform()->SetLocalPosition(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalPosition());
			}

			if (DogAirplaneBackground::Background != nullptr)
			{
				DogAirplaneBackground::Background->GetTransform()->SetLocalRotation(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalRotation());
				DogAirplaneBackground::Background->GetTransform()->SetLocalPosition(Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetLocalPosition());
			}
		}
		break;
		case 3:
		{

			//if (GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef().Rotation.z > 360)
			//{
			//	GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,-1 });
			//	GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ -3,0,0 });
			//	//GetTransform()->SetLocalPosition({ 0,0 });
			//	RotationCheck = 0;
			//}
			//GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,1 });
			//GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ 3,0,0 });

		}
		break;

		default:
			break;
		}
	}
}
	




void DogAirplaneLevel::Start()
{
	
	GetMainCamera()->SetSortType(0, SortType::ZSort);
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);


	player = CreateActor<Player>();
	player->GetTransform()->AddLocalPosition({ 0,0,0 });
	std::shared_ptr<TimeFlow> Object = CreateActor<TimeFlow>(10);
	{
		std::shared_ptr<UserInterface> Object = CreateActor<UserInterface>();
	}
	
	BackGround = CreateActor<DogAirplaneBackground>();

	Npc = CreateActor<NpcAirplane>();



	
	Ph1_DogAirplane = CreateActor<DogAirplane>();

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
	}
	
	
	Ph3_DogAirpalne = CreateActor<Ph3_DogAirplane>();


}

void DogAirplaneLevel::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
	int a = 0;
}


void DogAirplaneLevel::LevelChangeEnd()
{
	GameEngineLevel::LevelChangeEnd();
	int a = 0;
}

void DogAirplaneLevel::PlayerCreate()
{
}
