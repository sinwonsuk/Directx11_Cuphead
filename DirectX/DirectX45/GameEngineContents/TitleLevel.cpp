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
	}
	
	
	

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

	{
		std::shared_ptr<Title> Object = CreateActor<Title>();
	}

	GetLastTarget()->CreateEffect<OldFilm>();
	GetLastTarget()->CreateEffect<BlurEffect>();
	
}

void TitleLevel::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
}

void TitleLevel::LevelChangeEnd()
{

	GameEngineSprite::UnLoad("cuphead_title_screen");
	GameEngineSprite::UnLoad("title_screen_background");
	GameEngineSprite::UnLoad("Title_Logo");

	GameEngineLevel::LevelChangeEnd();
}

