#include "PrecompileHeader.h"
#include "DogAirPlane_UnLoad.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "OverWorld.h"
#include "DogAirPlane_Loading.h"
bool DogAirPlane_UnLoad::check = false;
DogAirPlane_UnLoad::DogAirPlane_UnLoad()
{
}

DogAirPlane_UnLoad::~DogAirPlane_UnLoad()
{
}
void AFunction(GameEngineThread* Thread)
{
	
	

		GameEngineSprite::ReLoad("DD_Idle");
		GameEngineSprite::ReLoad("DD_Move");
		GameEngineSprite::ReLoad("Down_Idle");
		GameEngineSprite::ReLoad("Down_Move");
		GameEngineSprite::ReLoad("DU_Idle");
		GameEngineSprite::ReLoad("DU_Move");
		GameEngineSprite::ReLoad("InterAction_Win");
		GameEngineSprite::ReLoad("Side_Idle");
		GameEngineSprite::ReLoad("Side_Move");
		GameEngineSprite::ReLoad("Up_Idle");
		GameEngineSprite::ReLoad("Up_Move");

		GameEngineSprite::ReLoad("Map");
		GameEngineSprite::ReLoad("To_Tutorial_Fly.png");
		GameEngineSprite::ReLoad("To_WaittingRoom.png");
	

	/*if (nullptr == GameEngineSprite::Find("Map"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("OverWorld");
		NewDir.Move("Map");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Map").GetFullPath());
		GameEngineSprite::LoadSheet(NewDir.GetPlusFileName("Object\\To_Tutorial_Fly.png").GetFullPath(), 3, 1);
		GameEngineSprite::LoadSheet(NewDir.GetPlusFileName("Object\\To_WaittingRoom.png").GetFullPath(), 3, 1);
	}*/



	
		GameEngineSprite::UnLoad("Chinook_Pilot_Saluki");
		GameEngineSprite::UnLoad("ph1_dogcopter_intro");
		GameEngineSprite::UnLoad("ph1_bulldog_intro");
		GameEngineSprite::UnLoad("DogAirplane");
		GameEngineSprite::UnLoad("Airplane_Back");
		GameEngineSprite::UnLoad("Airplane_Front");
		GameEngineSprite::UnLoad("bulldog_Idle");
		GameEngineSprite::UnLoad("bulldog_Left");
		GameEngineSprite::UnLoad("bulldog_Right");
		GameEngineSprite::UnLoad("bulldog_Jump");
		GameEngineSprite::UnLoad("bulldog_Attack_Pase1");
		GameEngineSprite::UnLoad("bulldog_Jump_Reverse");
		GameEngineSprite::UnLoad("bulldog_plane_flap_left_a");
		GameEngineSprite::UnLoad("bulldog_plane_flap_left_b");
		GameEngineSprite::UnLoad("bulldog_plane_flap_left_c");
		GameEngineSprite::UnLoad("bulldog_plane_flap_left_d");
		GameEngineSprite::UnLoad("ph1_dog_a_ball_toss");
		GameEngineSprite::UnLoad("ph1_dog_b_ball_toss");
		GameEngineSprite::UnLoad("bulldog_plane_wing");
		GameEngineSprite::UnLoad("AirPlane_Tail");
		GameEngineSprite::UnLoad("bulldog_Attack2_Pase1_intro");
		GameEngineSprite::UnLoad("bulldog_Attack2_Pase1_Attack");
		GameEngineSprite::UnLoad("ph1_dogcopter_hydrant");
		GameEngineSprite::UnLoad("Ph1_Buldog_Death");
		GameEngineSprite::UnLoad("Ph1_Buldog_Death_intro");
		GameEngineSprite::UnLoad("acada");
		GameEngineSprite::UnLoad("Ph1_Death_Front");
		GameEngineSprite::UnLoad("FightText_GetReady");

		// ¹è°æ 			
		GameEngineSprite::UnLoad("Background");
		GameEngineSprite::UnLoad("Sky");
		GameEngineSprite::UnLoad("A_clouds");
		GameEngineSprite::UnLoad("B_clouds");
		GameEngineSprite::UnLoad("C_clouds");
		GameEngineSprite::UnLoad("D_clouds");

		// NPC			  
		GameEngineSprite::UnLoad("Npc_Airplane_Back");
		GameEngineSprite::UnLoad("Npc_Airplane_Front");
		GameEngineSprite::UnLoad("Npc_Airplane_Reg");
		GameEngineSprite::UnLoad("Npc_Airplane_Spin");
		GameEngineSprite::UnLoad("NpcIntro");
		GameEngineSprite::UnLoad("Npc_Intro2");
		GameEngineSprite::UnLoad("Npc_Idle");

		// ph2			  

		GameEngineSprite::UnLoad("ph2_dog_a_intro");
		GameEngineSprite::UnLoad("ph2_dog_a_intro_transition");
		GameEngineSprite::UnLoad("ph2_dog_b_intro");
		GameEngineSprite::UnLoad("ph2_dog_b_intro_transition");
		GameEngineSprite::UnLoad("ph2_dog_c_intro");
		GameEngineSprite::UnLoad("ph2_dog_c_intro_transition");
		GameEngineSprite::UnLoad("ph2_dog_d_intro");
		GameEngineSprite::UnLoad("ph2_dog_d_intro_transition");

		GameEngineSprite::UnLoad("SD_Idle_3_4_front");
		GameEngineSprite::UnLoad("SD_Idle_front_front");
		GameEngineSprite::UnLoad("SD_Idle_front_side");
		GameEngineSprite::UnLoad("SD_Idle_side");
		GameEngineSprite::UnLoad("SD_Idle_front_Up");

		GameEngineSprite::UnLoad("SD_Idle_back");
		GameEngineSprite::UnLoad("SD_Idle_side_back");
		GameEngineSprite::UnLoad("SD_Idle_3_4_back");
		GameEngineSprite::UnLoad("SD_Idle_3_4_back_back");


		GameEngineSprite::UnLoad("SD_Attack_3_4_front");
		GameEngineSprite::UnLoad("SD_Attack_front_front");
		GameEngineSprite::UnLoad("SD_Attack_front_side");
		GameEngineSprite::UnLoad("SD_Attack_side");
		GameEngineSprite::UnLoad("SD_Attack_front");

		GameEngineSprite::UnLoad("SD_Attack_back");
		GameEngineSprite::UnLoad("SD_Attack_side_back");
		GameEngineSprite::UnLoad("SD_Attack_3_4_back");
		GameEngineSprite::UnLoad("SD_Attack_3_4_back_back");

		GameEngineSprite::UnLoad("ph2_jetpack_flame_straight");
		GameEngineSprite::UnLoad("ph2_jetpack_smoke_a");
		GameEngineSprite::UnLoad("ph2_jetpack_smoke_b");
		GameEngineSprite::UnLoad("ph2_jetpack_smoke_c");

		GameEngineSprite::UnLoad("SD_bow_big_spark");
		GameEngineSprite::UnLoad("ph2_dog_death");

		// ph3 			  

		GameEngineSprite::UnLoad("ph3_Intro");
		GameEngineSprite::UnLoad("ph3_laser_low_paw_pad_opens");
		GameEngineSprite::UnLoad("ph3_laser_mid_paw_pad_opens");
		GameEngineSprite::UnLoad("ph3_laser_top_paw_pad_opens");
		GameEngineSprite::UnLoad("ph3_left_paw_hole_low");
		GameEngineSprite::UnLoad("ph3_left_paw_hole_low_backer");
		GameEngineSprite::UnLoad("ph3_left_paw_hole_mid");
		GameEngineSprite::UnLoad("ph3_left_paw_hole_mid_backer");
		GameEngineSprite::UnLoad("ph3_left_paw_hole_top");
		GameEngineSprite::UnLoad("ph3_left_paw_hole_top_backer");
		GameEngineSprite::UnLoad("ph3_right_paw_merge");
		GameEngineSprite::UnLoad("ph3_Idle_body");
		GameEngineSprite::UnLoad("ph3_Idle_Arom");
		GameEngineSprite::UnLoad("Ph3_Idle_Arom_Hand");
		GameEngineSprite::UnLoad("ph3_laser_mid");
		GameEngineSprite::UnLoad("ph3_laser_top");
		GameEngineSprite::UnLoad("ph3_laser_low");
		GameEngineSprite::UnLoad("ph3_dogcopter_rotate_camera");
		GameEngineSprite::UnLoad("ph3_dogcopter_rotated_idle");
		GameEngineSprite::UnLoad("ph3_dogcopter_rotate_camera_out_blades");
		GameEngineSprite::UnLoad("ph3_tongue_rotate_camera");
		GameEngineSprite::UnLoad("ph3_leader_sideways_arms");
		GameEngineSprite::UnLoad("ph3_leader_sideways_body");
		GameEngineSprite::UnLoad("ph3_leader_sideways_body_Attack");
		GameEngineSprite::UnLoad("ph3_leader_sideways_arms_backer");
		GameEngineSprite::UnLoad("ph3_beam_top");
		GameEngineSprite::UnLoad("ph3_laser_warning_aura_top");
		GameEngineSprite::UnLoad("ph3_laser_warning_particle_top");
		GameEngineSprite::UnLoad("ph3_laser_warning_top");
		GameEngineSprite::UnLoad("ph3_laser_warning_ring_top");
		GameEngineSprite::UnLoad("ph3_laser_warning_mid");
		GameEngineSprite::UnLoad("ph3_laser_warning_particle_mid");
		GameEngineSprite::UnLoad("ph3_beam_mid");
		GameEngineSprite::UnLoad("ph3_laser_warning_electric_mid");
		GameEngineSprite::UnLoad("ph3_beam_low");
		GameEngineSprite::UnLoad("ph3_laser_warning_low");
		GameEngineSprite::UnLoad("ph3_laser_warning_aura_Low");
		GameEngineSprite::UnLoad("ph3_tongue_rotate_camera_tongue");
		GameEngineSprite::UnLoad("ph3_leader_sideways_body_Finish");
		GameEngineSprite::UnLoad("ph3_leader_sideways_body_Finish_0");
		GameEngineSprite::UnLoad("ph3_dogcopter_rotate_camera_out");

		GameEngineSprite::UnLoad("ph3_dogcopter_sideways_death_tongue");
		GameEngineSprite::UnLoad("ph3_leader_sideways_death_tears");
		GameEngineSprite::UnLoad("ph3_leader_sideways_death");
		GameEngineSprite::UnLoad("ph3_dogcopter_sideways_death");
		GameEngineSprite::UnLoad("ph3_dogcopter_death_blades");
		GameEngineSprite::UnLoad("FightText_KO");

		
	
	
	

	DogAirPlane_Loading::Check = false;
	
	//GameEngineCore::CreateLevel<OverWorld>();
	GameEngineCore::ChangeLevel("OverWorld");
	//GameEngineCore::ChangeLevel("OverWorld");
}
void DogAirPlane_UnLoad::Start()
{

	//GameEngineCore::JobQueue.Work(AFunction);

	UnLoad = CreateComponent<GameEngineSpriteRenderer>();
	UnLoad->CreateAnimation({ .AnimationName = "Loading", .SpriteName = "Loading", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true});
	UnLoad->ChangeAnimation("Loading");

}

void DogAirPlane_UnLoad::Update(float _Delta)
{

	if (Check == false)
	{
		GameEngineCore::JobQueue.Work(AFunction);
		Check = true;
	}



	

	
}

void DogAirPlane_UnLoad::Render(float _Delta)
{
}
