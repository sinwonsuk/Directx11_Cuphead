#include "PrecompileHeader.h"
#include "DogAirplaneLevel.h"
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
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
			float test2 = std::lerp(0, 150, _DeltaTime);

				Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalRotation({ 0,0,test1 });
				Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalPosition({ test2 , test ,0 });

				GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,test1 });
				GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ test2,test ,0 });
			
		}
		break;
		case 1:
		{


			TransformData date = GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef();

			if (GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef().Rotation.z < -179.5f)
			{	
				TransformData date = GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef();
				TransformData date1 = Ph3_DogAirplane::ph3_mainBoss->GetTransform()->GetTransDataRef();
				int a = 0;
				break;
			}
		

			float test = std::lerp(0, -700, _DeltaTime);
			float test1 = std::lerp(0, -250, _DeltaTime);
			float test2 = std::lerp(0, 150, _DeltaTime);
				Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalRotation({ 0,0,test1 });
				Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalPosition({ test2,test ,0 });

				GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,test1 });
				GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ test2,test ,0 });
			


				float a = { _DeltaTime * 1500.0f };
				int ad= 0;
		}
		break;
		case 2:
		{

			if (GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef().Rotation.z < -269.0f)
			{
				break;
			}

			GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,-500.0f * _DeltaTime });
			GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ 150.0f * _DeltaTime, 1500.0f * _DeltaTime ,0 });
			Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalRotation({ 0,0,-500.0f * _DeltaTime });
			Ph3_DogAirplane::ph3_mainBoss->GetTransform()->AddLocalPosition({ 150 * _DeltaTime,1500.0f * _DeltaTime ,0 });

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
	}
	{
		std::shared_ptr<DogAirplaneBackground> Object = CreateActor<DogAirplaneBackground>();
	}*/
	{
		std::shared_ptr<NpcAirplane> Object = CreateActor<NpcAirplane>();
	}
	//{
	//	std::shared_ptr<Player> Object = CreateActor<Player>();
	//	Object->GetTransform()->AddLocalPosition({ 0,0,0 });
	//}
	//{
	//	std::shared_ptr<Ph2_DogAirpalne> Object = CreateActor<Ph2_DogAirpalne>(4);
	//	//Object->GetTransform()->AddLocalPosition({ -350,0,0 });
	//}
	

	{
		std::shared_ptr<Ph3_DogAirplane> Object = CreateActor<Ph3_DogAirplane>();		
	}
	
	
		
	
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
