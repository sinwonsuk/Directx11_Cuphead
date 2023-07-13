#include "PrecompileHeader.h"
#include "DogAirPlane_Loading.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCore.h>
#include "DogAirplaneLevel.h"
#include <GameEnginePlatform/GameEngineInput.h>
bool DogAirPlane_Loading::Check = false;
DogAirPlane_Loading::DogAirPlane_Loading()
{
}

DogAirPlane_Loading::~DogAirPlane_Loading()
{
}

void Function(GameEngineThread* Thread)
{
	if (nullptr != GameEngineSprite::Find("Chinook_Pilot_Saluki"))
	{
		
		

		GameEngineSprite::ReLoad("Chinook_Pilot_Saluki");
		GameEngineSprite::ReLoad("ph1_dogcopter_intro");
		GameEngineSprite::ReLoad("ph1_bulldog_intro");
		GameEngineSprite::ReLoad("DogAirplane");
		GameEngineSprite::ReLoad("Airplane_Back");
		GameEngineSprite::ReLoad("Airplane_Front");
		GameEngineSprite::ReLoad("bulldog_Idle");
		GameEngineSprite::ReLoad("bulldog_Left");
		GameEngineSprite::ReLoad("bulldog_Right");
		GameEngineSprite::ReLoad("bulldog_Jump");
		GameEngineSprite::ReLoad("bulldog_Attack_Pase1");
		GameEngineSprite::ReLoad("bulldog_Jump_Reverse");
		GameEngineSprite::ReLoad("bulldog_plane_flap_left_a");
		GameEngineSprite::ReLoad("bulldog_plane_flap_left_b");
		GameEngineSprite::ReLoad("bulldog_plane_flap_left_c");
		GameEngineSprite::ReLoad("bulldog_plane_flap_left_d");
		GameEngineSprite::ReLoad("ph1_dog_a_ball_toss");
		GameEngineSprite::ReLoad("ph1_dog_b_ball_toss");
		GameEngineSprite::ReLoad("bulldog_plane_wing");
		GameEngineSprite::ReLoad("AirPlane_Tail");
		GameEngineSprite::ReLoad("bulldog_Attack2_Pase1_intro");
		GameEngineSprite::ReLoad("bulldog_Attack2_Pase1_Attack");
		GameEngineSprite::ReLoad("ph1_dogcopter_hydrant");
		GameEngineSprite::ReLoad("Ph1_Buldog_Death");
		GameEngineSprite::ReLoad("Ph1_Buldog_Death_intro");
		GameEngineSprite::ReLoad("acada");
		GameEngineSprite::ReLoad("Ph1_Death_Front");
		GameEngineSprite::ReLoad("FightText_GetReady");

		// 배경 			
		GameEngineSprite::ReLoad("Background");
		GameEngineSprite::ReLoad("Sky");
		GameEngineSprite::ReLoad("A_clouds");
		GameEngineSprite::ReLoad("B_clouds");
		GameEngineSprite::ReLoad("C_clouds");
		GameEngineSprite::ReLoad("D_clouds");

		// NPC			  
		GameEngineSprite::ReLoad("Npc_Airplane_Back");
		GameEngineSprite::ReLoad("Npc_Airplane_Front");
		GameEngineSprite::ReLoad("Npc_Airplane_Reg");
		GameEngineSprite::ReLoad("Npc_Airplane_Spin");
		GameEngineSprite::ReLoad("NpcIntro");
		GameEngineSprite::ReLoad("Npc_Intro2");
		GameEngineSprite::ReLoad("Npc_Idle");

		// ph2			  

		GameEngineSprite::ReLoad("ph2_dog_a_intro");
		GameEngineSprite::ReLoad("ph2_dog_a_intro_transition");
		GameEngineSprite::ReLoad("ph2_dog_b_intro");
		GameEngineSprite::ReLoad("ph2_dog_b_intro_transition");
		GameEngineSprite::ReLoad("ph2_dog_c_intro");
		GameEngineSprite::ReLoad("ph2_dog_c_intro_transition");
		GameEngineSprite::ReLoad("ph2_dog_d_intro");
		GameEngineSprite::ReLoad("ph2_dog_d_intro_transition");

		GameEngineSprite::ReLoad("SD_Idle_3_4_front");
		GameEngineSprite::ReLoad("SD_Idle_front_front");
		GameEngineSprite::ReLoad("SD_Idle_front_side");
		GameEngineSprite::ReLoad("SD_Idle_side");
		GameEngineSprite::ReLoad("SD_Idle_front_Up");

		GameEngineSprite::ReLoad("SD_Idle_back");
		GameEngineSprite::ReLoad("SD_Idle_side_back");
		GameEngineSprite::ReLoad("SD_Idle_3_4_back");
		GameEngineSprite::ReLoad("SD_Idle_3_4_back_back");


		GameEngineSprite::ReLoad("SD_Attack_3_4_front");
		GameEngineSprite::ReLoad("SD_Attack_front_front");
		GameEngineSprite::ReLoad("SD_Attack_front_side");
		GameEngineSprite::ReLoad("SD_Attack_side");
		GameEngineSprite::ReLoad("SD_Attack_front");

		GameEngineSprite::ReLoad("SD_Attack_back");
		GameEngineSprite::ReLoad("SD_Attack_side_back");
		GameEngineSprite::ReLoad("SD_Attack_3_4_back");
		GameEngineSprite::ReLoad("SD_Attack_3_4_back_back");

		GameEngineSprite::ReLoad("ph2_jetpack_flame_straight");
		GameEngineSprite::ReLoad("ph2_jetpack_smoke_a");
		GameEngineSprite::ReLoad("ph2_jetpack_smoke_b");
		GameEngineSprite::ReLoad("ph2_jetpack_smoke_c");

		GameEngineSprite::ReLoad("SD_bow_big_spark");
		GameEngineSprite::ReLoad("ph2_dog_death");

		// ph3 			  

		GameEngineSprite::ReLoad("ph3_Intro");
		GameEngineSprite::ReLoad("ph3_laser_low_paw_pad_opens");
		GameEngineSprite::ReLoad("ph3_laser_mid_paw_pad_opens");
		GameEngineSprite::ReLoad("ph3_laser_top_paw_pad_opens");
		GameEngineSprite::ReLoad("ph3_left_paw_hole_low");
		GameEngineSprite::ReLoad("ph3_left_paw_hole_low_backer");
		GameEngineSprite::ReLoad("ph3_left_paw_hole_mid");
		GameEngineSprite::ReLoad("ph3_left_paw_hole_mid_backer");
		GameEngineSprite::ReLoad("ph3_left_paw_hole_top");
		GameEngineSprite::ReLoad("ph3_left_paw_hole_top_backer");
		GameEngineSprite::ReLoad("ph3_right_paw_merge");
		GameEngineSprite::ReLoad("ph3_Idle_body");
		GameEngineSprite::ReLoad("ph3_Idle_Arom");
		GameEngineSprite::ReLoad("Ph3_Idle_Arom_Hand");
		GameEngineSprite::ReLoad("ph3_laser_mid");
		GameEngineSprite::ReLoad("ph3_laser_top");
		GameEngineSprite::ReLoad("ph3_laser_low");
		GameEngineSprite::ReLoad("ph3_dogcopter_rotate_camera");
		GameEngineSprite::ReLoad("ph3_dogcopter_rotated_idle");
		GameEngineSprite::ReLoad("ph3_dogcopter_rotate_camera_out_blades");
		GameEngineSprite::ReLoad("ph3_tongue_rotate_camera");
		GameEngineSprite::ReLoad("ph3_leader_sideways_arms");
		GameEngineSprite::ReLoad("ph3_leader_sideways_body");
		GameEngineSprite::ReLoad("ph3_leader_sideways_body_Attack");
		GameEngineSprite::ReLoad("ph3_leader_sideways_arms_backer");
		GameEngineSprite::ReLoad("ph3_beam_top");
		GameEngineSprite::ReLoad("ph3_laser_warning_aura_top");
		GameEngineSprite::ReLoad("ph3_laser_warning_particle_top");
		GameEngineSprite::ReLoad("ph3_laser_warning_top");
		GameEngineSprite::ReLoad("ph3_laser_warning_ring_top");
		GameEngineSprite::ReLoad("ph3_laser_warning_mid");
		GameEngineSprite::ReLoad("ph3_laser_warning_particle_mid");
		GameEngineSprite::ReLoad("ph3_beam_mid");
		GameEngineSprite::ReLoad("ph3_laser_warning_electric_mid");
		GameEngineSprite::ReLoad("ph3_beam_low");
		GameEngineSprite::ReLoad("ph3_laser_warning_low");
		GameEngineSprite::ReLoad("ph3_laser_warning_aura_Low");
		GameEngineSprite::ReLoad("FightText_KO");
		//ph3_NPC
		GameEngineSprite::ReLoad("ph3_tongue_rotate_camera_tongue");
		GameEngineSprite::ReLoad("ph3_leader_sideways_body_Finish");
		GameEngineSprite::ReLoad("ph3_leader_sideways_body_Finish_0");
		GameEngineSprite::ReLoad("ph3_dogcopter_rotate_camera_out");
		GameEngineSprite::ReLoad("ph3_dogcopter_sideways_death_tongue");
		GameEngineSprite::ReLoad("ph3_leader_sideways_death_tears");
		GameEngineSprite::ReLoad("ph3_leader_sideways_death");
		GameEngineSprite::ReLoad("ph3_dogcopter_sideways_death");
		GameEngineSprite::ReLoad("ph3_dogcopter_death_blades");

		
		

		GameEngineCore::ChangeLevel("DogAirplaneLevel");
	}


	
	if (nullptr == GameEngineSprite::Find("Chinook_Pilot_Saluki"))
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

		// 배경 
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

		// ph3_Npc

		{
			GameEngineDirectory NewDir;
			NewDir.MoveParentToDirectory("ContentResources");
			NewDir.Move("ContentResources");
			NewDir.Move("Texture");
			NewDir.Move("Character");
			if (nullptr == GameEngineSprite::Find("ParryEffect"))
			{
				GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ParryEffect").GetFullPath());
			}
		}



		GameEngineCore::ChangeLevel("DogAirplaneLevel");
	}
}

void DogAirPlane_Loading::Start()
{
	
	
	
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
	
}




void DogAirPlane_Loading::Update(float _Delta)
{
	if (Check == false)
	{
		GameEngineCore::JobQueue.Work(Function);
		Check = true;
	}

	
	

}

void DogAirPlane_Loading::Render(float _Delta)
{
}
