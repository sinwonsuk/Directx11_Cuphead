#include "PrecompileHeader.h"
#include "Crown_Bepi_Level.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include "Crown_Bepi_Map.h"
#include "Ph1_Bepi.h"
#include "Ph2_Bepi.h"
#include "Ph3_Bepi.h"
#include "Ph4_Bepi.h"
#include "Ph4_Swing_Platform.h"
#include "Player.h"
#include "TimeFlow.h"
#include "UserInterface.h"
#include <GameEngineCore/BlurEffect.h>
#include "OldFilm.h"
#include "OldTVEffect.h"

bool Crown_Bepi_Level::Finish_Check = false;

Crown_Bepi_Level::Crown_Bepi_Level()
{
}

Crown_Bepi_Level::~Crown_Bepi_Level()
{
}

void Crown_Bepi_Level::Update(float _DeltaTime)
{
	switch (PaseCheck)
	{
	case Pase::Pase1:
	{
		ph1_Bepi->On();
		ph2_Bepi->Off(); 
		ph3_Bepi->Off();
		ph4_Bepi->Off();

	}
		break;
	case Pase::Pase2:
	{
		ph1_Bepi->Off();
		ph2_Bepi->On();
		ph3_Bepi->Off();
		ph4_Bepi->Off();
	}
		break;
	case Pase::Pase3:
	{
		ph1_Bepi->Off();
		ph2_Bepi->Off();
		ph3_Bepi->On();
		ph4_Bepi->Off();
	}
		break;
	case Pase::Pase4:
	{
		ph1_Bepi->Off();
		ph2_Bepi->Off();
		ph3_Bepi->Off();
		ph4_Bepi->On();
	}
		break;
	default:
		break;
	}


}

void Crown_Bepi_Level::Start()
{
	GetLastTarget()->CreateEffect<OldFilm>();
	GetLastTarget()->CreateEffect<BlurEffect>();


	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->SetSortType(0, SortType::ZSort);

	


	
	
}

void Crown_Bepi_Level::LevelChangeStart()
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

		GameEngineSound::Load(NewDir.GetPlusFileName("clown_dash_start_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_clown_clown_dash_end_03.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("Clown_Music.mp3").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_bumper_death_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_regular_duck_spin_01.wav").GetFullPath());

		GameEngineSound::Load(NewDir.GetPlusFileName("clown_coaster_main_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_level_clown_warning_lights_loop_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_clown_coaster_ratchet_loop.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_bumper_move_01.wav").GetFullPath());
	}
	{
		player = CreateActor<Player>();
	}
	{
		Map = CreateActor<Crown_Bepi_Map>();
	}
	{
		userInterface = CreateActor<UserInterface>();
	}
	{
		std::shared_ptr<TimeFlow> Object = CreateActor<TimeFlow>(10);
	}

	{
		ph1_Bepi = CreateActor<Ph1_Bepi>();
	}

	{
		ph2_Bepi = CreateActor<Ph2_Bepi>();
	}

	{
		ph3_Bepi = CreateActor<Ph3_Bepi>();
	}
	{
		ph4_Bepi = CreateActor<Ph4_Bepi>();
	}

	GameEngineLevel::LevelChangeStart();
}

void Crown_Bepi_Level::LevelChangeEnd()
{
	PaseCheck = Pase::Pase1;
	ph1_Bepi.get()->BG.Stop(); 
	Crown_Bepi_Map::Ph4_Check = false;
	Map.get()->Coaster.Stop();
	Map.get()->Coaster_Light.Stop();


	for (size_t i = 0; i < Crown_Bepi_Map::Rollercoasters.size(); i++)			
	{			
		Crown_Bepi_Map::Rollercoasters[i].get()->Death(); 	
	}
	Crown_Bepi_Map::Rollercoasters.clear(); 
	TimeFlow::Time = 0; 
	Map->Death(); 
	Player::MainPlayer->Death();
	Player::MainPlayer = nullptr;
	player->Death();
	if (Ph4_Bepi::ph4_Bepi != nullptr)
	{
		Ph4_Bepi::ph4_Bepi->Death();
	}	
	Ph4_Bepi::ph4_Bepi = nullptr;
	UserInterface::Cut = 0;
	UserInterface::CardNumber = 0;
	UserInterface::HpBar = 3;

	userInterface->Death();

	Ph4_Swing_Platform::Ph4_Platform_Check = false;
	ph1_Bepi->Death();
	ph2_Bepi->Death();
	ph3_Bepi->Death();
	ph4_Bepi->Death();

	GameEngineLevel::LevelChangeEnd();
}
