#include "PrecompileHeader.h"
#include "DogAirplaneLevel.h"
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "UserInterface.h"
#include "TimeFlow.h"
#include <GameEngineCore/BlurEffect.h>
#include "OldFilm.h"
#include "OldTVEffect.h"
bool DogAirplaneLevel::Finsh_Check = false;
DogAirplaneLevel::DogAirplaneLevel()
{
}

DogAirplaneLevel::~DogAirplaneLevel()
{
}

void DogAirplaneLevel::Update(float _DeltaTime)
{
	sd += _DeltaTime;
	switch (Pase)
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
		Ph2_DogAirpalne_Left.get()->Sound_Loop.Stop(); 
		Ph2_DogAirpalne_Left->Off();
		Ph2_DogAirpalne_Right->Off();
		Ph2_DogAirpalne_Top->Off();
		Ph2_DogAirpalne_Bottom->Off();
		Ph3_DogAirpalne->On(); 
	}
	break;
	case 3:
	{

		
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


	
	GetLastTarget()->CreateEffect<OldFilm>();
	GetLastTarget()->CreateEffect<BlurEffect>();

}

void DogAirplaneLevel::LevelChangeStart()
{
	
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Sound");

		GameEngineSound::Load(NewDir.GetPlusFileName("mus_dlc_title.wav").GetFullPath());

		GameEngineSound::Load(NewDir.GetPlusFileName("cuphead-opening-theme.mp3").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_peashot_death_001.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_upshot_loop_01.wav").GetFullPath());

		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_upshot_loop_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("MUS_Tutorial.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_jump_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_dash_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_crackshot_turret_parryexplode.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_parry_slap_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("bgm_map_world_1.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("a-good-day-for-a-swell-battle.mp3").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("cuphead-a-knockout.mp3").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_BulldogPlane_Loop.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("mus_dlc_dogfight_a.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_BulldogPlane_IntroFlyby.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_PlayerPlane_Loop.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_Bulldog_EjectUp.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_Bulldog_EjectDown.wav").GetFullPath());

		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_TerrierPlane_Bark_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_DogFlexHugoVocal_02.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_DogFlexHugoVocal_04.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_Bulldog_Boneshot_01.wav").GetFullPath());

		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_TerrierPlane_Baseball_Whistle_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_CatGun_Shoot_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_Bulldog_PlaneExplodes.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P2_TerrierJetpack_BarkShoot_06.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P2_TerrierJetpack_Loop.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P2_TerrierJetpack_Explosion_01.wav").GetFullPath());

		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Intro.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Laser_BuildOut_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Laser_Fire_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Laser_Fire_03.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Settle_GrabScreen.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Laser_Fire_03.wav").GetFullPath());	
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_ScreenRotate.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_DogBowl_Fire_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("cuphead-a-knockout.mp3").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_hit_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_death_01.wav").GetFullPath());
	}
	
	
	//sfx_DLC_Dogfight_P1_CatGun_Shoot_01
	//sfx_DLC_Dogfight_P1_TerrierPlane_Bark_01
	//	sfx_DLC_Dogfight_P1_DogFlexHugoVocal_02
	//	sfx_DLC_Dogfight_P1_DogFlexHugoVocal_04
	//	sfx_DLC_Dogfight_P1_Bulldog_Boneshot_01
	player = CreateActor<Player>();

	player->GetTransform()->AddLocalPosition({ 0,0,0 });

	timeFlow = CreateActor<TimeFlow>(10);


	userInterface = CreateActor<UserInterface>();
	


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



	int a = 0;
}


void DogAirplaneLevel::LevelChangeEnd()
{
	Ph1_DogAirplane->AirplaneLoop.Stop(); 
	Ph1_DogAirplane->Bone_Sound.Stop();
	GetMainCamera()->GetTransform()->SetLocalRotation({ 0.0f,0.0f,0.0f }); 
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	if (ph3_Dog_Npc::ph3_Npc != nullptr)
	{
		ph3_Dog_Npc::ph3_Npc->Death();
	}
	
	ph3_Dog_Npc::ph3_Npc = nullptr;

	UserInterface::CardNumber = 0;
	UserInterface::Cut = 0; 
	UserInterface::HpBar = 3;
	userInterface->Death(); 
	if (Ph3_DogAirplane::ph3_mainBoss != nullptr)
	{
		Ph3_DogAirplane::ph3_mainBoss->Death();
	}
	Ph3_DogAirplane::ph3_mainBoss = nullptr;
	DogAirplane::Hp = 20;
	TimeFlow::Time = 0; 
	Ph3_DogAirpalne->Off(); 
	Player::MainPlayer->Death(); 
	Player::MainPlayer = nullptr;
	Ph3_DogAirplane::Hp = 20;
	DogAirplane::Finish = false;
	DogAirplane::Sound_BG_Check = false;
	DogAirplane::BG.Stop();
	Pase = 0;

	timeFlow->Death(); 
	Ph1_DogAirplane->Death();
	Ph2_DogAirpalne_Left->Death();
	Ph2_DogAirpalne_Right->Death();
	Ph2_DogAirpalne_Top->Death();
	Ph2_DogAirpalne_Bottom->Death();
	Ph3_DogAirpalne->Death();

	BackGround->Death();
	Npc->Death();
	player->Death();

	GameEngineLevel::LevelChangeEnd();
	int a = 0;
}

void DogAirplaneLevel::PlayerCreate()
{
}
