#include "PrecompileHeader.h"
#include "ph3_DogAirPlane.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ph3_Laser.h"
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"
#include "IdleWeapon.h"
Ph3_DogAirplane* Ph3_DogAirplane::ph3_mainBoss;
int Ph3_DogAirplane::Hp = 20;
Ph3_DogAirplane::Ph3_DogAirplane()
{
}

Ph3_DogAirplane::~Ph3_DogAirplane()
{
}

void Ph3_DogAirplane::AnimationCheck(const std::string_view& _AnimationName)
{

}


void Ph3_DogAirplane::Start()
{
	ph3_mainBoss = this; 
	if (nullptr == GameEngineSprite::Find("ph3_Intro"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");

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

		/*GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_beam_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_aura_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_particle_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_ring_top").GetFullPath());*/


		/*GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_left_paw_hole_top_backer").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_right_paw_hole_top_backer").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_right_paw_hole_top").GetFullPath());*/

	}

	Object = GetLevel()->CreateActor<Boss_Finish>(50);
	Object->Off(); 


	Ph3_Boss_Intro = CreateComponent<GameEngineSpriteRenderer>();
	Ph3_Boss_Intro->CreateAnimation({ .AnimationName = "ph3_Intro", .SpriteName = "ph3_Intro", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Ph3_Boss_Intro->ChangeAnimation("ph3_Intro");

	
	{
		Idle_Arom = CreateComponent<GameEngineSpriteRenderer>();
		Idle_Arom->CreateAnimation({ .AnimationName = "ph3_Idle_Arom", .SpriteName = "ph3_Idle_Arom", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true,  . FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,10,9,8,7,6,5,4,3,2,1,0} });
		Idle_Arom->ChangeAnimation("ph3_Idle_Arom");
		Idle_Arom->GetTransform()->AddLocalPosition({ 0,0,56.0f });
		Idle_Arom->Off();

		Idle_Body = CreateComponent<GameEngineSpriteRenderer>();
		Idle_Body->CreateAnimation({ .AnimationName = "ph3_Idle_body", .SpriteName = "ph3_Idle_body", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true ,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		Idle_Body->ChangeAnimation("ph3_Idle_body");
		Idle_Body->GetTransform()->AddLocalPosition({ 0,0,56.0f });
		Idle_Body->Off();

		Idle_Arom_Hand = CreateComponent<GameEngineSpriteRenderer>();
		Idle_Arom_Hand->CreateAnimation({ .AnimationName = "Ph3_Idle_Arom_Hand", .SpriteName = "Ph3_Idle_Arom_Hand", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
		Idle_Arom_Hand->ChangeAnimation("Ph3_Idle_Arom_Hand");
		Idle_Arom_Hand->GetTransform()->AddLocalPosition({ 0,0,56.0f });
		Idle_Arom_Hand->Off();

		ph3_paw_merge = CreateComponent<GameEngineSpriteRenderer>();
		ph3_paw_merge->CreateAnimation({ .AnimationName = "ph3_right_paw_merge", .SpriteName = "ph3_right_paw_merge", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
		ph3_paw_merge->ChangeAnimation("ph3_right_paw_merge");
		ph3_paw_merge->GetTransform()->AddLocalPosition({ 0,0,55.0f });
		ph3_paw_merge->Off(); 
	}

	{	
		ph3_left_paw_hole_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_top->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_top", .SpriteName = "ph3_left_paw_hole_top", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_left_paw_hole_top->ChangeAnimation("ph3_left_paw_hole_top");
		ph3_left_paw_hole_top->GetTransform()->AddLocalPosition({ 0,0,52.0f });
		ph3_left_paw_hole_top->Off(); 

		ph3_left_paw_hole_top_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_top_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_top_backer", .SpriteName = "ph3_left_paw_hole_top_backer", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_left_paw_hole_top_backer->ChangeAnimation("ph3_left_paw_hole_top_backer");
		ph3_left_paw_hole_top_backer->GetTransform()->AddLocalPosition({ -0,0,50.0f });
		ph3_left_paw_hole_top_backer->Off(); 

		ph3_laser_Left_top_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Left_top_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_top_paw_pad_opens", .SpriteName = "ph3_laser_top_paw_pad_opens",.FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph3_laser_Left_top_paw_pad_opens->ChangeAnimation("ph3_laser_top_paw_pad_opens");
		ph3_laser_Left_top_paw_pad_opens->Off(); 

		ph3_laser_Left_top_paw_pad_opens_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Left_top_paw_pad_opens_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_top_paw_pad_opens", .SpriteName = "ph3_laser_top_paw_pad_opens",.FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true ,.FrameIndex = {3,2,1,0} });
		ph3_laser_Left_top_paw_pad_opens_Reverse->ChangeAnimation("ph3_laser_top_paw_pad_opens");
		ph3_laser_Left_top_paw_pad_opens_Reverse->Off();


	}
	
	{
		ph3_left_paw_hole_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_mid->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_mid", .SpriteName = "ph3_left_paw_hole_mid", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_left_paw_hole_mid->ChangeAnimation("ph3_left_paw_hole_mid");
		ph3_left_paw_hole_mid->GetTransform()->AddLocalPosition({ 0,0,52.0f });
		ph3_left_paw_hole_mid->Off(); 

		

		ph3_left_paw_hole_mid_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_mid_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_mid_backer", .SpriteName = "ph3_left_paw_hole_mid_backer", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_left_paw_hole_mid_backer->ChangeAnimation("ph3_left_paw_hole_mid_backer");
		ph3_left_paw_hole_mid_backer->GetTransform()->AddLocalPosition({ -0,0,50.0f }); 
		ph3_left_paw_hole_mid_backer->Off(); 
	
		ph3_laser_Left_mid_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Left_mid_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_mid_paw_pad_opens", .SpriteName = "ph3_laser_mid_paw_pad_opens", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_laser_Left_mid_paw_pad_opens->ChangeAnimation("ph3_laser_mid_paw_pad_opens");
    	ph3_laser_Left_mid_paw_pad_opens->Off();

		ph3_laser_Left_mid_paw_pad_opens_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Left_mid_paw_pad_opens_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_mid_paw_pad_opens", .SpriteName = "ph3_laser_mid_paw_pad_opens",.FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true ,.FrameIndex = {2,1,0} });
		ph3_laser_Left_mid_paw_pad_opens_Reverse->ChangeAnimation("ph3_laser_mid_paw_pad_opens");
		ph3_laser_Left_mid_paw_pad_opens_Reverse->Off();


	}
	{
		ph3_left_paw_hole_low_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_low_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_low_backer", .SpriteName = "ph3_left_paw_hole_low_backer", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
		ph3_left_paw_hole_low_backer->ChangeAnimation("ph3_left_paw_hole_low_backer");
		ph3_left_paw_hole_low_backer->GetTransform()->AddLocalPosition({ 0,5.0f });
		ph3_left_paw_hole_low_backer->Off();

		ph3_left_paw_hole_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_left_paw_hole_low->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_low", .SpriteName = "ph3_left_paw_hole_low", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
		ph3_left_paw_hole_low->ChangeAnimation("ph3_left_paw_hole_low");
		ph3_left_paw_hole_low->GetTransform()->AddLocalPosition({ 0,5.0f });
		ph3_left_paw_hole_low->Off(); 

		ph3_laser_Left_low_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Left_low_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_low_paw_pad_opens", .SpriteName = "ph3_laser_low_paw_pad_opens", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_laser_Left_low_paw_pad_opens->ChangeAnimation("ph3_laser_low_paw_pad_opens");
		ph3_laser_Left_low_paw_pad_opens->GetTransform()->AddLocalPosition({ 0,5.0f });
		ph3_laser_Left_low_paw_pad_opens->Off();

		ph3_laser_Left_low_paw_pad_opens_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Left_low_paw_pad_opens_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_low_paw_pad_opens", .SpriteName = "ph3_laser_low_paw_pad_opens",.FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true ,.FrameIndex = {2,1,0} });
		ph3_laser_Left_low_paw_pad_opens_Reverse->ChangeAnimation("ph3_laser_low_paw_pad_opens");
		ph3_laser_Left_low_paw_pad_opens_Reverse->Off();

	}

	{
		ph3_Right_paw_hole_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_top->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_top", .SpriteName = "ph3_left_paw_hole_top", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_Right_paw_hole_top->ChangeAnimation("ph3_left_paw_hole_top");
		ph3_Right_paw_hole_top->GetTransform()->AddLocalRotation({ 0,-165.0f,0 }); 
		ph3_Right_paw_hole_top->GetTransform()->AddLocalPosition({ -3.0f,7.0f,0 });
		ph3_Right_paw_hole_top->Off(); 

		ph3_Right_paw_hole_top_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_top_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_top_backer", .SpriteName = "ph3_left_paw_hole_top_backer", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_Right_paw_hole_top_backer->ChangeAnimation("ph3_left_paw_hole_top_backer");
		ph3_Right_paw_hole_top_backer->GetTransform()->AddLocalRotation({ 0,-165.0f,0 });
		ph3_Right_paw_hole_top_backer->GetTransform()->AddLocalPosition({ -3.0f,7.0f,0 });
		ph3_Right_paw_hole_top_backer->Off(); 

		ph3_laser_Right_top_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Right_top_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_top_paw_pad_opens", .SpriteName = "ph3_laser_top_paw_pad_opens", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_laser_Right_top_paw_pad_opens->ChangeAnimation("ph3_laser_top_paw_pad_opens");
		ph3_laser_Right_top_paw_pad_opens->GetTransform()->AddLocalRotation({ 0,-165.0f,0 });
		ph3_laser_Right_top_paw_pad_opens->GetTransform()->AddLocalPosition({ -3.0f,7.0f,0 });
		ph3_laser_Right_top_paw_pad_opens->Off(); 

		ph3_laser_Right_top_paw_pad_opens_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Right_top_paw_pad_opens_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_top_paw_pad_opens", .SpriteName = "ph3_laser_top_paw_pad_opens", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {3,2,1,0} });
		ph3_laser_Right_top_paw_pad_opens_Reverse->ChangeAnimation("ph3_laser_top_paw_pad_opens");
		ph3_laser_Right_top_paw_pad_opens_Reverse->GetTransform()->AddLocalRotation({ 0,-165.0f,0 });
		ph3_laser_Right_top_paw_pad_opens_Reverse->GetTransform()->AddLocalPosition({ -3.0f,7.0f,0 });
		ph3_laser_Right_top_paw_pad_opens_Reverse->Off();


	}

	{
		ph3_Right_paw_hole_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_mid->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_mid", .SpriteName = "ph3_left_paw_hole_mid", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_Right_paw_hole_mid->ChangeAnimation("ph3_left_paw_hole_mid");
		ph3_Right_paw_hole_mid->GetTransform()->AddLocalRotation({ 0,-180,0 }); 
		ph3_Right_paw_hole_mid->GetTransform()->AddLocalPosition({ -20,0 ,0 });
		ph3_Right_paw_hole_mid->Off(); 

		ph3_Right_paw_hole_mid_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_mid_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_mid_backer", .SpriteName = "ph3_left_paw_hole_mid_backer", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_Right_paw_hole_mid_backer->ChangeAnimation("ph3_left_paw_hole_mid_backer");
		ph3_Right_paw_hole_mid_backer->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_Right_paw_hole_mid_backer->GetTransform()->AddLocalPosition({ -20,0,0 });
		ph3_Right_paw_hole_mid_backer->Off(); 

		ph3_laser_Right_mid_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Right_mid_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_mid_paw_pad_opens", .SpriteName = "ph3_laser_mid_paw_pad_opens", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_laser_Right_mid_paw_pad_opens->ChangeAnimation("ph3_laser_mid_paw_pad_opens");
		ph3_laser_Right_mid_paw_pad_opens->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_laser_Right_mid_paw_pad_opens->GetTransform()->AddLocalPosition({ -20,0,0 });
		ph3_laser_Right_mid_paw_pad_opens->Off();

		ph3_laser_Right_mid_paw_pad_opens_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Right_mid_paw_pad_opens_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_mid_paw_pad_opens", .SpriteName = "ph3_laser_mid_paw_pad_opens", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {2,1,0} });
		ph3_laser_Right_mid_paw_pad_opens_Reverse->ChangeAnimation("ph3_laser_mid_paw_pad_opens");
		ph3_laser_Right_mid_paw_pad_opens_Reverse->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_laser_Right_mid_paw_pad_opens_Reverse->GetTransform()->AddLocalPosition({ -20,0,0 });
		ph3_laser_Right_mid_paw_pad_opens_Reverse->Off();

	}

	{
		ph3_Right_paw_hole_low_backer = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_low_backer->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_low_backer", .SpriteName = "ph3_left_paw_hole_low_backer", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
		ph3_Right_paw_hole_low_backer->ChangeAnimation("ph3_left_paw_hole_low_backer");
		ph3_Right_paw_hole_low_backer->GetTransform()->AddLocalRotation({ 0,-180 });
		ph3_Right_paw_hole_low_backer->GetTransform()->AddLocalPosition({ -12,5 });
		ph3_Right_paw_hole_low_backer->Off(); 

		ph3_Right_paw_hole_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_paw_hole_low->CreateAnimation({ .AnimationName = "ph3_left_paw_hole_low", .SpriteName = "ph3_left_paw_hole_low", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
		ph3_Right_paw_hole_low->ChangeAnimation("ph3_left_paw_hole_low");
		ph3_Right_paw_hole_low->GetTransform()->AddLocalRotation({ 0,-180 });
		ph3_Right_paw_hole_low->GetTransform()->AddLocalPosition({ -12,5 });
		ph3_Right_paw_hole_low->Off(); 

		ph3_laser_Right_low_paw_pad_opens = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Right_low_paw_pad_opens->CreateAnimation({ .AnimationName = "ph3_laser_low_paw_pad_opens", .SpriteName = "ph3_laser_low_paw_pad_opens", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
		ph3_laser_Right_low_paw_pad_opens->ChangeAnimation("ph3_laser_low_paw_pad_opens");
		ph3_laser_Right_low_paw_pad_opens->GetTransform()->AddLocalRotation({ 0,-180 });
		ph3_laser_Right_low_paw_pad_opens->GetTransform()->AddLocalPosition({ -12,5 });
		ph3_laser_Right_low_paw_pad_opens->Off();
		
		ph3_laser_Right_low_paw_pad_opens_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Right_low_paw_pad_opens_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_low_paw_pad_opens", .SpriteName = "ph3_laser_low_paw_pad_opens", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {2,1,0} });
		ph3_laser_Right_low_paw_pad_opens_Reverse->ChangeAnimation("ph3_laser_low_paw_pad_opens");
		ph3_laser_Right_low_paw_pad_opens_Reverse->GetTransform()->AddLocalRotation({ 0,-180 });
		ph3_laser_Right_low_paw_pad_opens_Reverse->GetTransform()->AddLocalPosition({ -12,5 });
		ph3_laser_Right_low_paw_pad_opens_Reverse->Off();
	}

	{
		ph3_Left_laser_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Left_laser_mid->CreateAnimation({ .AnimationName = "ph3_laser_mid", .SpriteName = "ph3_laser_mid", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,13} }); 
		ph3_Left_laser_mid->ChangeAnimation("ph3_laser_mid");
		ph3_Left_laser_mid->GetTransform()->AddLocalPosition({ 30,0,-51 });
		ph3_Left_laser_mid->Off(); 

		ph3_Left_laser_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Left_laser_top->CreateAnimation({ .AnimationName = "ph3_laser_top", .SpriteName = "ph3_laser_top", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14} });
		ph3_Left_laser_top->ChangeAnimation("ph3_laser_top");
		ph3_Left_laser_top->GetTransform()->AddLocalPosition({ 30,0,0 });
		ph3_Left_laser_top->Off(); 

		ph3_Left_laser_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Left_laser_low->CreateAnimation({ .AnimationName = "ph3_laser_low", .SpriteName = "ph3_laser_low", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true/*,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0}*/ });
		ph3_Left_laser_low->ChangeAnimation("ph3_laser_low");
		ph3_Left_laser_low->GetTransform()->AddLocalPosition({ 0,0,0 });
		ph3_Left_laser_low->Off(); 
	}

	{
		ph3_Right_laser_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_laser_mid->CreateAnimation({ .AnimationName = "ph3_laser_mid", .SpriteName = "ph3_laser_mid", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true/*,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,13,13,12,11,10,9,8,7,6,5,4,3,2,1,0}*/ });
		ph3_Right_laser_mid->ChangeAnimation("ph3_laser_mid");
		ph3_Right_laser_mid->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_Right_laser_mid->GetTransform()->AddLocalPosition({ -30,0,-51 });
		ph3_Right_laser_mid->Off(); 
		
		ph3_Right_laser_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_laser_top->CreateAnimation({ .AnimationName = "ph3_laser_top", .SpriteName = "ph3_laser_top", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true/*,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0}*/ });
		ph3_Right_laser_top->ChangeAnimation("ph3_laser_top");
		ph3_Right_laser_top->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_Right_laser_top->GetTransform()->AddLocalPosition({- 30,0,0 });
		ph3_Right_laser_top->Off(); 
		
		ph3_Right_laser_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_laser_low->CreateAnimation({ .AnimationName = "ph3_laser_low", .SpriteName = "ph3_laser_low", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true/*,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0}*/ });
		ph3_Right_laser_low->ChangeAnimation("ph3_laser_low");
		ph3_Right_laser_low->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_Right_laser_low->GetTransform()->AddLocalPosition({ 0,0,0 });
		ph3_Right_laser_low->Off(); 
	}

	{
		ph3_Left_laser_mid_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Left_laser_mid_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_mid", .SpriteName = "ph3_laser_mid", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {13,13,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		ph3_Left_laser_mid_Reverse->ChangeAnimation("ph3_laser_mid");
		ph3_Left_laser_mid_Reverse->GetTransform()->AddLocalPosition({ 30,0,0 });
		ph3_Left_laser_mid_Reverse->Off();

		ph3_Left_laser_top_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Left_laser_top_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_top", .SpriteName = "ph3_laser_top", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {14,13,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		ph3_Left_laser_top_Reverse->ChangeAnimation("ph3_laser_top");
		ph3_Left_laser_top_Reverse->GetTransform()->AddLocalPosition({ 30,0,0 });
		ph3_Left_laser_top_Reverse->Off();

		ph3_Left_laser_low_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Left_laser_low_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_low", .SpriteName = "ph3_laser_low", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {14,13,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		ph3_Left_laser_low_Reverse->ChangeAnimation("ph3_laser_low");
		ph3_Left_laser_low_Reverse->GetTransform()->AddLocalPosition({ 0,0,0 });
		ph3_Left_laser_low_Reverse->Off();
	}

	{
		ph3_Right_laser_mid_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_laser_mid_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_mid", .SpriteName = "ph3_laser_mid", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {13,13,12,11,10,9,8,7,6,5,4,3,2,1,0}});
		ph3_Right_laser_mid_Reverse->ChangeAnimation("ph3_laser_mid");
		ph3_Right_laser_mid_Reverse->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_Right_laser_mid_Reverse->GetTransform()->AddLocalPosition({ -30,0,0 });
		ph3_Right_laser_mid_Reverse->Off();

		ph3_Right_laser_top_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_laser_top_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_top", .SpriteName = "ph3_laser_top", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {14,13,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		ph3_Right_laser_top_Reverse->ChangeAnimation("ph3_laser_top");
		ph3_Right_laser_top_Reverse->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_Right_laser_top_Reverse->GetTransform()->AddLocalPosition({ -30,0,0 });
		ph3_Right_laser_top_Reverse->Off();

		ph3_Right_laser_low_Reverse = CreateComponent<GameEngineSpriteRenderer>();
		ph3_Right_laser_low_Reverse->CreateAnimation({ .AnimationName = "ph3_laser_low", .SpriteName = "ph3_laser_low", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {14,13,12,11,10,9,8,7,6,5,4,3,2,1,0} });
		ph3_Right_laser_low_Reverse->ChangeAnimation("ph3_laser_low");
		ph3_Right_laser_low_Reverse->GetTransform()->AddLocalRotation({ 0,-180,0 });
		ph3_Right_laser_low_Reverse->GetTransform()->AddLocalPosition({ 0,0,0 });
		ph3_Right_laser_low_Reverse->Off();
	}

	{

		/*ph3_tongue_rotate_camera = CreateComponent<GameEngineSpriteRenderer>();
		ph3_tongue_rotate_camera->CreateAnimation({ .AnimationName = "ph3_tongue_rotate_camera", .SpriteName = "ph3_tongue_rotate_camera", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,13} });
		ph3_tongue_rotate_camera->ChangeAnimation("ph3_tongue_rotate_camera");
		ph3_tongue_rotate_camera->Off(); */
	
		ph3_dogcopter_rotate_camera = CreateComponent<GameEngineSpriteRenderer>();
		ph3_dogcopter_rotate_camera->CreateAnimation({ .AnimationName = "ph3_dogcopter_rotate_camera", .SpriteName = "ph3_dogcopter_rotate_camera", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph3_dogcopter_rotate_camera->ChangeAnimation("ph3_dogcopter_rotate_camera");
		ph3_dogcopter_rotate_camera->GetTransform()->AddLocalPosition({ 0,0,56 });
		ph3_dogcopter_rotate_camera->Off();

		ph3_dogcopter_rotated_idle = CreateComponent<GameEngineSpriteRenderer>();
		ph3_dogcopter_rotated_idle->CreateAnimation({ .AnimationName = "ph3_dogcopter_rotated_idle", .SpriteName = "ph3_dogcopter_rotated_idle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true ,.FrameIndex = {0,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1} });
		ph3_dogcopter_rotated_idle->CreateAnimation({ .AnimationName = "ph3_dogcopter_sideways_death", .SpriteName = "ph3_dogcopter_sideways_death", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true ,.FrameIndex = {0,1,2,3,4,5,6,5,4,3,2,1 } });
		ph3_dogcopter_rotated_idle->ChangeAnimation("ph3_dogcopter_rotated_idle");
		ph3_dogcopter_rotated_idle->GetTransform()->AddLocalPosition({ 0,0,12 });
		ph3_dogcopter_rotated_idle->Off();


		ph3_dogcopter_rotate_camera_out_blades = CreateComponent<GameEngineSpriteRenderer>();
		ph3_dogcopter_rotate_camera_out_blades->CreateAnimation({ .AnimationName = "ph3_dogcopter_rotate_camera_out_blades", .SpriteName = "ph3_dogcopter_rotate_camera_out_blades", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true /*,.FrameIndex = {0,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1}*/ });
		ph3_dogcopter_rotate_camera_out_blades->CreateAnimation({ .AnimationName = "ph3_dogcopter_death_blades", .SpriteName = "ph3_dogcopter_death_blades", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true /*,.FrameIndex = {0,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1}*/ });
		ph3_dogcopter_rotate_camera_out_blades->ChangeAnimation("ph3_dogcopter_rotate_camera_out_blades");
		ph3_dogcopter_rotate_camera_out_blades->GetTransform()->AddLocalPosition({ -100,0,0 });
		ph3_dogcopter_rotate_camera_out_blades->Off();

		ph3_dogcopter_rotate_camera_out = CreateComponent<GameEngineSpriteRenderer>();
		ph3_dogcopter_rotate_camera_out->CreateAnimation({ .AnimationName = "ph3_dogcopter_rotate_camera_out", .SpriteName = "ph3_dogcopter_rotate_camera_out", .FrameInter = 0.08f,.Loop = false, .ScaleToTexture = true /*,.FrameIndex = {0,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1}*/ });
		ph3_dogcopter_rotate_camera_out->ChangeAnimation("ph3_dogcopter_rotate_camera_out");
		ph3_dogcopter_rotate_camera_out->GetTransform()->AddLocalPosition({ 0,0,0 });
		ph3_dogcopter_rotate_camera_out->Off();

	}

	FightText_KO = CreateComponent<GameEngineSpriteRenderer>(100);
	FightText_KO->CreateAnimation({ .AnimationName = "FightText_KO", .SpriteName = "FightText_KO", .FrameInter = 0.08f,.Loop = false, .ScaleToTexture = true /*,.FrameIndex = {0,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1}*/ });
	FightText_KO->ChangeAnimation("FightText_KO");
	FightText_KO->GetTransform()->AddLocalPosition({ 0,0,-300.0f});
	FightText_KO->Off();

	
	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 300.0f, 250.0f, 300.0f });
	Collision->SetOrder((int)CollisionType::BossBody);


}

void Ph3_DogAirplane::Update(float _Delta)
{
	
	UpdateCheck = true;


	/*if (Collision->Collision((int)CollisionType::Bullet))
	{
		Hp -= 1;

		if (CollisonCheck == false)
		{
			Idle_Body->ColorOptionValue.PlusColor = { 1,1,1,0 };
			Idle_Body->ResetLiveTime();
			CollisonCheck = true;

		}
		std::shared_ptr<GameEngineCollision> collision = Collision->Collision((int)CollisionType::Bullet);

		collision->Death();
	}

	if (CollisonCheck == true && Idle_Body->GetLiveTime() > 0.05f)
	{
		Idle_Body->ColorOptionValue.PlusColor = { 0,0,0,0 };
		CollisonCheck = false;
	}*/


	/*if (Collision->Collision((int)CollisionType::Bullet))
	{
		if (CollisonCheck == false)
		{

			Idle_Body->ColorOptionValue.PlusColor = { 1,1,1,0 };
			Idle_Body->ResetLiveTime();
			Hp -= 1;
			CollisonCheck = true;
			
		}
		
	}

	if (CollisonCheck == true && Idle_Body->GetLiveTime() > 0.03f)
	{
		
		Idle_Body->ColorOptionValue.PlusColor = { 0,0,0,0 };
		CollisonCheck = false;
	}*/



	UpdateState(_Delta);
}

void Ph3_DogAirplane::Render(float _Delta)
{

}
