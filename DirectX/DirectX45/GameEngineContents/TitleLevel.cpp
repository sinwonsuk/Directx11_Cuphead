#include "PrecompileHeader.h"
#include "TitleLevel.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "Title.h"
#include <GameEngineCore/BlurEffect.h>
#include "OldFilm.h"
#include "OldTVEffect.h"
TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}


void TitleLevel::Start() 
{

	//{
	//	GameEngineDirectory NewDir;
	//	NewDir.MoveParentToDirectory("ContentResources");
	//	NewDir.Move("ContentResources");
	//	NewDir.Move("Sound");

	//	GameEngineSound::Load(NewDir.GetPlusFileName("mus_dlc_title.wav").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("cuphead-opening-theme.mp3").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_peashot_death_001.wav").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_upshot_loop_01.wav").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_upshot_loop_01.wav").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("MUS_Tutorial.wav").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_jump_01.wav").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_dash_01.wav").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_crackshot_turret_parryexplode.wav").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_parry_slap_01.wav").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("bgm_map_world_1.wav").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("a-good-day-for-a-swell-battle.mp3").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("cuphead-a-knockout.mp3").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_BulldogPlane_Loop.wav").GetFullPath());
	//	GameEngineSound::Load(NewDir.GetPlusFileName("mus_dlc_dogfight_a.wav").GetFullPath());
	//}
	//
	//
	

	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);

	if (nullptr == GameEngineSprite::Find("cuphead_title_screen"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Title");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("cuphead_title_screen").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("title_screen_background").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Title_Logo").GetFullPath());
		
	}
	if (nullptr == GameEngineSprite::Find("Exit"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("UI");
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Exit").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Start").GetFullPath());
	}

	if (nullptr == GameEngineSprite::Find("Bepi_Map"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("OverWorld");
		NewDir.Move("Map");
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Bepi_Map").GetFullPath());
	}



	{
		std::shared_ptr<Title> Object = CreateActor<Title>();
	}

	GetLastTarget()->CreateEffect<OldFilm>();
	GetLastTarget()->CreateEffect<BlurEffect>();
	
}

void TitleLevel::LevelChangeStart()
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
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_helium_intro_continue_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_intro_continue_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_dog_balloon_regular_intro_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_dog_balloon_regular_death_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_horse_head_spit_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_horseshoe_land_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_horseshoe_drop_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_horse_clown_fall_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_horse_death_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_swing_face_intro_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_swing_open_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_swing_face_attack_intro_02.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_penguin_roll_end_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_penguin_death_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("clown_penguin_clap_01.wav").GetFullPath());
		GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_peashoot_ex_impact_02.wav").GetFullPath());

		GameEngineSound::Load(NewDir.GetPlusFileName("MUS_GoodEnding.wav").GetFullPath());
	}
	GameEngineLevel::LevelChangeStart();
}

void TitleLevel::LevelChangeEnd()
{

	GameEngineSprite::UnLoad("cuphead_title_screen");
	GameEngineSprite::UnLoad("title_screen_background");
	GameEngineSprite::UnLoad("Title_Logo");

	GameEngineLevel::LevelChangeEnd();
}

