#include "PrecompileHeader.h"
#include "DogAirPlane_Loading.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCore.h>
#include "DogAirplaneLevel.h"
DogAirPlane_Loading::DogAirPlane_Loading()
{
}

DogAirPlane_Loading::~DogAirPlane_Loading()
{
}

void Function(GameEngineThread* Thread)
{
	

	GameEngineDirectory NewDir;
	NewDir.MoveParentToDirectory("ContentResources");
	NewDir.Move("ContentResources");
	NewDir.Move("Texture");
	NewDir.Move("DogAirplane");
	// ph1
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Chinook_Pilot_Saluki").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_dogcopter_intro").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_bulldog_intro").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DogAirplane").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Airplane_Back").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Airplane_Front").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Idle").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Left").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Right").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Jump").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Attack_Pase1").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Jump_Reverse").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_plane_flap_left_a").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_plane_flap_left_b").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_plane_flap_left_c").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_plane_flap_left_d").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_dog_a_ball_toss").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_dog_b_ball_toss").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_plane_wing").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("AirPlane_Tail").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Attack2_Pase1_intro").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("bulldog_Attack2_Pase1_Attack").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph1_dogcopter_hydrant").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ph1_Buldog_Death").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ph1_Buldog_Death_intro").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("acada").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ph1_Death_Front").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("FightText_GetReady").GetFullPath());

	// ¹è°æ 
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Background").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Sky").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("A_clouds").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("B_clouds").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("C_clouds").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("D_clouds").GetFullPath());
	
	// NPC
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Airplane_Back").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Airplane_Front").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Airplane_Reg").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Airplane_Spin").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("NpcIntro").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Intro2").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Npc_Idle").GetFullPath());

	// ph2

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_a_intro").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_a_intro_transition").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_b_intro").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_b_intro_transition").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_c_intro").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_c_intro_transition").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_d_intro").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_d_intro_transition").GetFullPath());

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_3_4_front").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_front_front").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_front_side").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_side").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_front_Up").GetFullPath());

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_back").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_side_back").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_3_4_back").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Idle_3_4_back_back").GetFullPath());


	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_3_4_front").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_front_front").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_front_side").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_side").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_front").GetFullPath());

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_back").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_side_back").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_3_4_back").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_Attack_3_4_back_back").GetFullPath());



	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_jetpack_flame_straight").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_jetpack_smoke_a").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_jetpack_smoke_b").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_jetpack_smoke_c").GetFullPath());

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("SD_bow_big_spark").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph2_dog_death").GetFullPath());

	// ph3 

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_Intro").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_low_paw_pad_opens").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_mid_paw_pad_opens").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_top_paw_pad_opens").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_low").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_low_backer").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_mid").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_mid_backer").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_top").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_top_backer").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_right_paw_merge").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_Idle_body").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_Idle_Arom").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ph3_Idle_Arom_Hand").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_mid").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_top").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_low").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dogcopter_rotate_camera").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dogcopter_rotated_idle").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dogcopter_rotate_camera_out_blades").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_tongue_rotate_camera").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_arms").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_body").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_body_Attack").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_arms_backer").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_beam_top").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_aura_top").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_particle_top").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_top").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_ring_top").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_mid").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_particle_mid").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_beam_mid").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_electric_mid").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_beam_low").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_low").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_aura_Low").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_tongue_rotate_camera_tongue").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_body_Finish").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_body_Finish_0").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dogcopter_rotate_camera_out").GetFullPath());

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dogcopter_sideways_death_tongue").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_death_tears").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_death").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dogcopter_sideways_death").GetFullPath());
	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dogcopter_death_blades").GetFullPath());

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("FightText_KO").GetFullPath());

	GameEngineCore::CreateLevel<DogAirplaneLevel>();
	GameEngineCore::ChangeLevel("DogAirplaneLevel");

}

void DogAirPlane_Loading::Start()
{

	GameEngineCore::JobQueue.Work(Function);
	
	if (nullptr == GameEngineSprite::Find("Loading_Hourglass.png"))
	{

		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		//NewDir.Move("Loading");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Loading").GetFullPath());
	}



	Loading = CreateComponent<GameEngineSpriteRenderer>();
	Loading->CreateAnimation({ .AnimationName = "Loading", .SpriteName = "Loading", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Loading->ChangeAnimation("Loading");
	//Loading->GetTransform()->AddLocalPosition({ -180.0f,220.0f,55.0f });
	//Loading->Off();
}




void DogAirPlane_Loading::Update(float _Delta)
{
}

void DogAirPlane_Loading::Render(float _Delta)
{
}
