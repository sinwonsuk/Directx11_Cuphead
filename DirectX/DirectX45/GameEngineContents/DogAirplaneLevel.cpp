#include "PrecompileHeader.h"
#include "DogAirplaneLevel.h"
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "DogAirplane.h"
#include "Player.h"
#include "NpcAirplane.h"
#include "Ph2_DogAirpalne.h"
#include "DogAirplaneBackground.h"
#include "ph3_DogAirPlane.h"
#include "ph3_Laser.h"
#include "ph3_food_bowl.h"
#include "ph3_Dog_Npc.h"


DogAirplaneLevel::DogAirplaneLevel()
{
}

DogAirplaneLevel::~DogAirplaneLevel()
{
}

void DogAirplaneLevel::Update(float _DeltaTime)
{
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

			float test = std::lerp(0, 700, _DeltaTime);
			float test1 = std::lerp(0, -250, _DeltaTime);
			float test2 = std::lerp(0, 50, _DeltaTime);

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
			TransformData date = GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef();

			if (GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef().Rotation.z < -179.5f)
			{

				break;
			}

			float test = std::lerp(0, -700, _DeltaTime);
			float test1 = std::lerp(0, -250, _DeltaTime);
			float test2 = std::lerp(0, 50, _DeltaTime);


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

			float test = std::lerp(0, 700, _DeltaTime);
			float test1 = std::lerp(0, -250, _DeltaTime);
			float test2 = std::lerp(0, -230, _DeltaTime);


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
	/*if (GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef().Rotation.z > 360)
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,0});
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ 0,0,0 });
		RotationCheck = 0;
		TransformData data = GetTransform()->GetTransDataRef();
		int a = 0;
	}*/




void DogAirplaneLevel::Start()
{
	
	GetMainCamera()->SetSortType(0,SortType::ZSort);
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);


	/*{
		std::shared_ptr<DogAirplane> Object = CreateActor<DogAirplane>();
	}*/

	{
		std::shared_ptr<DogAirplaneBackground> Object = CreateActor<DogAirplaneBackground>();
	}




	{
		std::shared_ptr<NpcAirplane> Object = CreateActor<NpcAirplane>();
	}
	{
		std::shared_ptr<Player> Object = CreateActor<Player>();
		Object->GetTransform()->AddLocalPosition({ 0,0,0 });
	}





	{
		std::shared_ptr<Ph2_DogAirpalne> Object = CreateActor<Ph2_DogAirpalne>(4);
		 Object->Get_Ph2_Boss()->GetTransform()->AddLocalPosition({ -700.0f,0.0f,82.0f });
		 Object->Get_jetpack()->GetTransform()->AddLocalPosition({ -750.0f,-50.0f,82.0f });

		 Object->ChangeState(Ph2_DogAirPlaneState::LeftIntro); 
	}
	
	{
		std::shared_ptr<Ph2_DogAirpalne> Object = CreateActor<Ph2_DogAirpalne>(4);
		Object->ChangeState(Ph2_DogAirPlaneState::UpIntro);
		Object->Get_Ph2_Boss()->GetTransform()->AddLocalPosition({ 0.0f,400.0f,82.0f });
		Object->Get_jetpack()->GetTransform()->AddLocalPosition({  0.0f,350.0f,82.0f });
	}

	{
		std::shared_ptr<Ph2_DogAirpalne> Object = CreateActor<Ph2_DogAirpalne>(4);
		Object->ChangeState(Ph2_DogAirPlaneState::RightIntro);
		Object->Get_Ph2_Boss()->GetTransform()->AddLocalPosition({ 700.0f,0.0f,82.0f });
		Object->Get_jetpack()->GetTransform()->AddLocalPosition({  750.0f,-50.0f,82.0f });
	}

	{
		std::shared_ptr<Ph2_DogAirpalne> Object = CreateActor<Ph2_DogAirpalne>(4);
		Object->ChangeState(Ph2_DogAirPlaneState::DownIntro);
		Object->Get_Ph2_Boss()->GetTransform()->AddLocalPosition({ 0.0f,-400.0f,82.0f });
		Object->Get_jetpack()->GetTransform()->AddLocalPosition({ 0.0f, -450.0f,82.0f });
	}

	
	/*{
		std::shared_ptr<Ph3_DogAirplane> Object = CreateActor<Ph3_DogAirplane>();		
	}
	
	
		*/
	
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
