#include "PrecompileHeader.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "Bepi_UnLoad.h"
#include "Bpei_Loading.h"
#include "OverWorld.h"
bool Bepi_UnLoad::Check = false;
Bepi_UnLoad::Bepi_UnLoad()
{
}

Bepi_UnLoad::~Bepi_UnLoad()
{
}

void Beph_UnLoad_Function(GameEngineThread* Thread)
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


	





	GameEngineSprite::UnLoad("Beppi_Bg");
	GameEngineSprite::UnLoad("Beppi_Intro");
	GameEngineSprite::UnLoad("Beppi_Idle");
	GameEngineSprite::UnLoad("Beppi_Rush_Attack");
	GameEngineSprite::UnLoad("Ph1_Beppi_End");

	GameEngineSprite::UnLoad("duck_head");
	GameEngineSprite::UnLoad("duck_spin");
	GameEngineSprite::UnLoad("duck_body");
				
	GameEngineSprite::UnLoad("p_duck_spin");
	GameEngineSprite::UnLoad("p_duck_body");
	GameEngineSprite::UnLoad("p_duck_head");
					
	GameEngineSprite::UnLoad("Rollercoaster_Back");
	GameEngineSprite::UnLoad("Rollercoaster_Back2");
	GameEngineSprite::UnLoad("Rollercoaster_Front");
					
	GameEngineSprite::UnLoad("Rollercoaster_Frontcart");
	GameEngineSprite::UnLoad("Rollercoaster_Frontcart2");
	GameEngineSprite::UnLoad("Rollercoaster_Midcart_Blue");
	GameEngineSprite::UnLoad("Rollercoaster_Midcart_Red");
					
	GameEngineSprite::UnLoad("Rollercoaster_Midcart2");
					
	GameEngineSprite::UnLoad("Rollercoaster_Passenger");
	GameEngineSprite::UnLoad("Rollercoaster_Passenger2");
	GameEngineSprite::UnLoad("Rollercoaster_Seat");
					 
	GameEngineSprite::UnLoad("Phase2_Intro");
	GameEngineSprite::UnLoad("LeftHeliumBottle");
	GameEngineSprite::UnLoad("RightHeliumBottle");
	GameEngineSprite::UnLoad("Helium_Tank");
	GameEngineSprite::UnLoad("HeliumPipes_Intro");
					 
	GameEngineSprite::UnLoad("HeliumPipes_Idle");
	GameEngineSprite::UnLoad("Phase2_Idle_Head");
	GameEngineSprite::UnLoad("Phase2_Body_Back");
	GameEngineSprite::UnLoad("Phase2_Body_Front");
	GameEngineSprite::UnLoad("Dogs_Appear");
					
	GameEngineSprite::UnLoad("Horseshoe_Green");
	GameEngineSprite::UnLoad("HorseShoe_Gold");
	GameEngineSprite::UnLoad("Green_Horse_Attack");
	GameEngineSprite::UnLoad("Yellow_Horse_Attack");
	GameEngineSprite::UnLoad("Phase3_Idle");
	GameEngineSprite::UnLoad("Green_Horse_Head");
	GameEngineSprite::UnLoad("Yellow_Horse_Head");
	GameEngineSprite::UnLoad("Green_Horse_Body");
	GameEngineSprite::UnLoad("Yellow_Horse_Body");
					
	GameEngineSprite::UnLoad("Swing_Rope_Back");
	GameEngineSprite::UnLoad("Swing_Platform_Back");
	GameEngineSprite::UnLoad("Swing_Rope");
	GameEngineSprite::UnLoad("Swing_Platform");
	GameEngineSprite::UnLoad("Phase4_Intro");
	GameEngineSprite::UnLoad("Phase4_Lights");
	GameEngineSprite::UnLoad("Phase4_Idle");
	GameEngineSprite::UnLoad("Phase4_Attack_Start");
	GameEngineSprite::UnLoad("Phase4_Attack_Middle");
	GameEngineSprite::UnLoad("Phase4_Attack_End");
	GameEngineSprite::UnLoad("Phase4_Spin");
	GameEngineSprite::UnLoad("umbrella_bk");
					 
	GameEngineSprite::UnLoad("clown_bg_light_on");
	GameEngineSprite::UnLoad("clown_bg_light_off");
					
	GameEngineSprite::UnLoad("pink_balloon_dog_death");
	GameEngineSprite::UnLoad("pink_balloon_dog_chomp");
	GameEngineSprite::UnLoad("pink_balloon_dog_intro");
	GameEngineSprite::UnLoad("helium_pipe_puff");
	GameEngineSprite::UnLoad("Phase2_End");
	GameEngineSprite::UnLoad("Bepi_boss_explosion");
				
	GameEngineSprite::UnLoad("clown_ph3_horse_spit");
				
	GameEngineSprite::UnLoad("clown_ph3_horse_horseshoe_puff");
	GameEngineSprite::UnLoad("clown_ph3_horse_horseshoe_explode_yellow");
	GameEngineSprite::UnLoad("clown_ph3_horse_horseshoe_pink");
				
	GameEngineSprite::UnLoad("Phase3_End_Finish");
	GameEngineSprite::UnLoad("Phase3_End");
	GameEngineSprite::UnLoad("Yellow_Horse_End");
	GameEngineSprite::UnLoad("Green_Horse_End");
					
	GameEngineSprite::UnLoad("clown_ph3_penguin_clapspark");
	GameEngineSprite::UnLoad("clown_ph3_penguin_clap");
	GameEngineSprite::UnLoad("clown_ph3_penguin_idle");
	GameEngineSprite::UnLoad("clown_ph3_penguin_roll_Jump");
	GameEngineSprite::UnLoad("clown_ph3_penguin_roll_ground");
	GameEngineSprite::UnLoad("clown_ph3_penguin_roll");
	GameEngineSprite::UnLoad("clown_ph3_penguin_explode");
				
	GameEngineSprite::UnLoad("penguin_baseball");
	GameEngineSprite::UnLoad("Phase4_End");





	Bpei_Loading::Check = false;

	
	GameEngineCore::ChangeLevel("OverWorld");
	
}



void Bepi_UnLoad::Start()
{
	if (nullptr == GameEngineSprite::Find("Loading"))
	{

		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		//NewDir.Move("Loading");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Loading").GetFullPath());
	}

	BG = CreateComponent<GameEngineSpriteRenderer>();
	BG->SetScaleToTexture("BlackBG.png");

	Loading = CreateComponent<GameEngineSpriteRenderer>();
	Loading->CreateAnimation({ .AnimationName = "Loading", .SpriteName = "Loading", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Loading->ChangeAnimation("Loading");
	Loading->GetTransform()->AddLocalPosition({ 520.0f,-200.0f });


}

void Bepi_UnLoad::Update(float _Delta)
{
	if (Check == false)
	{
		GameEngineCore::JobQueue.Work(Beph_UnLoad_Function);
		Check = true;
	}
}

void Bepi_UnLoad::Render(float _Delta)
{
}
