#include "PrecompileHeader.h"
#include "Bpei_Loading.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "Bepi_UnLoad.h"
#include "OverHead_Player.h"
bool Bpei_Loading::Check = false;
Bpei_Loading::Bpei_Loading()
{
}

Bpei_Loading::~Bpei_Loading()
{
}
void Bepi_Function(GameEngineThread* Thread)
{
	if (nullptr != GameEngineSprite::Find("Beppi_Bg"))
	{
		GameEngineSprite::ReLoad("Beppi_Bg");
		GameEngineSprite::ReLoad("Beppi_Intro");
		GameEngineSprite::ReLoad("Beppi_Idle");
		GameEngineSprite::ReLoad("Beppi_Rush_Attack");
		GameEngineSprite::ReLoad("Ph1_Beppi_End");
						
		GameEngineSprite::ReLoad("duck_head");
		GameEngineSprite::ReLoad("duck_spin");
		GameEngineSprite::ReLoad("duck_body");
						
		GameEngineSprite::ReLoad("p_duck_spin");
		GameEngineSprite::ReLoad("p_duck_body");
		GameEngineSprite::ReLoad("p_duck_head");
						 
		GameEngineSprite::ReLoad("Rollercoaster_Back");
		GameEngineSprite::ReLoad("Rollercoaster_Back2");
		GameEngineSprite::ReLoad("Rollercoaster_Front");
						
		GameEngineSprite::ReLoad("Rollercoaster_Frontcart");
		GameEngineSprite::ReLoad("Rollercoaster_Frontcart2");
		GameEngineSprite::ReLoad("Rollercoaster_Midcart_Blue");
		GameEngineSprite::ReLoad("Rollercoaster_Midcart_Red");
						
		GameEngineSprite::ReLoad("Rollercoaster_Midcart2");
						 
		GameEngineSprite::ReLoad("Rollercoaster_Passenger");
		GameEngineSprite::ReLoad("Rollercoaster_Passenger2");
		GameEngineSprite::ReLoad("Rollercoaster_Seat");
					
		GameEngineSprite::ReLoad("Phase2_Intro");
		GameEngineSprite::ReLoad("LeftHeliumBottle");
		GameEngineSprite::ReLoad("RightHeliumBottle");
		GameEngineSprite::ReLoad("Helium_Tank");
		GameEngineSprite::ReLoad("HeliumPipes_Intro");
						
		GameEngineSprite::ReLoad("HeliumPipes_Idle");
		GameEngineSprite::ReLoad("Phase2_Idle_Head");
		GameEngineSprite::ReLoad("Phase2_Body_Back");
		GameEngineSprite::ReLoad("Phase2_Body_Front");
		GameEngineSprite::ReLoad("Dogs_Appear");
						
		GameEngineSprite::ReLoad("Horseshoe_Green");
		GameEngineSprite::ReLoad("HorseShoe_Gold");
		GameEngineSprite::ReLoad("Green_Horse_Attack");
		GameEngineSprite::ReLoad("Yellow_Horse_Attack");
		GameEngineSprite::ReLoad("Phase3_Idle");
		GameEngineSprite::ReLoad("Green_Horse_Head");
		GameEngineSprite::ReLoad("Yellow_Horse_Head");
		GameEngineSprite::ReLoad("Green_Horse_Body");
		GameEngineSprite::ReLoad("Yellow_Horse_Body");

		GameEngineSprite::ReLoad("Swing_Rope_Back");
		GameEngineSprite::ReLoad("Swing_Platform_Back");
		GameEngineSprite::ReLoad("Swing_Rope");
		GameEngineSprite::ReLoad("Swing_Platform");
		GameEngineSprite::ReLoad("Phase4_Intro");
		GameEngineSprite::ReLoad("Phase4_Lights");
		GameEngineSprite::ReLoad("Phase4_Idle");
		GameEngineSprite::ReLoad("Phase4_Attack_Start");
		GameEngineSprite::ReLoad("Phase4_Attack_Middle");
		GameEngineSprite::ReLoad("Phase4_Attack_End");
		GameEngineSprite::ReLoad("Phase4_Spin");
		GameEngineSprite::ReLoad("umbrella_bk");

		GameEngineSprite::ReLoad("clown_bg_light_on");
		GameEngineSprite::ReLoad("clown_bg_light_off");

		GameEngineSprite::ReLoad("pink_balloon_dog_death");
		GameEngineSprite::ReLoad("pink_balloon_dog_chomp");
		GameEngineSprite::ReLoad("pink_balloon_dog_intro");
		GameEngineSprite::ReLoad("helium_pipe_puff");
		GameEngineSprite::ReLoad("Phase2_End");
		GameEngineSprite::ReLoad("Bepi_boss_explosion");

		GameEngineSprite::ReLoad("clown_ph3_horse_spit");

		GameEngineSprite::ReLoad("clown_ph3_horse_horseshoe_puff");
		GameEngineSprite::ReLoad("clown_ph3_horse_horseshoe_explode_yellow");
		GameEngineSprite::ReLoad("clown_ph3_horse_horseshoe_pink");

		GameEngineSprite::ReLoad("Phase3_End_Finish");
		GameEngineSprite::ReLoad("Phase3_End");
		GameEngineSprite::ReLoad("Yellow_Horse_End");
		GameEngineSprite::ReLoad("Green_Horse_End");

		GameEngineSprite::ReLoad("clown_ph3_penguin_clapspark");
		GameEngineSprite::ReLoad("clown_ph3_penguin_clap");
		GameEngineSprite::ReLoad("clown_ph3_penguin_idle");
		GameEngineSprite::ReLoad("clown_ph3_penguin_roll_Jump");
		GameEngineSprite::ReLoad("clown_ph3_penguin_roll_ground");
		GameEngineSprite::ReLoad("clown_ph3_penguin_roll");
		GameEngineSprite::ReLoad("clown_ph3_penguin_explode");

		GameEngineSprite::ReLoad("penguin_baseball");
		GameEngineSprite::ReLoad("Phase4_End");




		Bepi_UnLoad::Check = false;



		GameEngineCore::ChangeLevel("Crown_Bepi_Level");
	}



	
	if (nullptr == GameEngineSprite::Find("Beppi_Bg"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Crown_Bepi");


		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Beppi_Bg").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Beppi_Intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Beppi_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Beppi_Rush_Attack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Ph1_Beppi_End").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("duck_head").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("duck_spin").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("duck_body").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("p_duck_spin").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("p_duck_body").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("p_duck_head").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Rollercoaster_Back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Rollercoaster_Back2").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Rollercoaster_Front").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Rollercoaster_Frontcart").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Rollercoaster_Frontcart2").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Rollercoaster_Midcart_Blue").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Rollercoaster_Midcart_Red").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Rollercoaster_Midcart2").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Rollercoaster_Passenger").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Rollercoaster_Passenger2").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Rollercoaster_Seat").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase2_Intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("LeftHeliumBottle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("RightHeliumBottle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Helium_Tank").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("HeliumPipes_Intro").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("HeliumPipes_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase2_Idle_Head").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase2_Body_Back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase2_Body_Front").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Dogs_Appear").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Horseshoe_Green").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("HorseShoe_Gold").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Green_Horse_Attack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Yellow_Horse_Attack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase3_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Green_Horse_Head").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Yellow_Horse_Head").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Green_Horse_Body").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Yellow_Horse_Body").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Swing_Rope_Back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Swing_Platform_Back").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Swing_Rope").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Swing_Platform").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase4_Intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase4_Lights").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase4_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase4_Attack_Start").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase4_Attack_Middle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase4_Attack_End").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase4_Spin").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("umbrella_bk").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_bg_light_on").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_bg_light_off").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("pink_balloon_dog_death").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("pink_balloon_dog_chomp").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("pink_balloon_dog_intro").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("helium_pipe_puff").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase2_End").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Bepi_boss_explosion").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_ph3_horse_spit").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_ph3_horse_horseshoe_puff").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_ph3_horse_horseshoe_explode_yellow").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_ph3_horse_horseshoe_pink").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase3_End_Finish").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase3_End").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Yellow_Horse_End").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Green_Horse_End").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_ph3_penguin_clapspark").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_ph3_penguin_clap").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_ph3_penguin_idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_ph3_penguin_roll_Jump").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_ph3_penguin_roll_ground").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_ph3_penguin_roll").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("clown_ph3_penguin_explode").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("penguin_baseball").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Phase4_End").GetFullPath());


		if (nullptr == GameEngineSprite::Find("FightText_GetReady"))
		{
			GameEngineDirectory NewDir;
			NewDir.MoveParentToDirectory("ContentResources");
			NewDir.Move("ContentResources");
			NewDir.Move("Texture");
			NewDir.Move("DogAirplane");
			GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("FightText_GetReady").GetFullPath());
		}

		if (nullptr == GameEngineSprite::Find("FightText_KO"))
		{
			GameEngineDirectory NewDir;
			NewDir.MoveParentToDirectory("ContentResources");
			NewDir.Move("ContentResources");
			NewDir.Move("Texture");
			NewDir.Move("DogAirplane");
			GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("FightText_KO").GetFullPath());
		}

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




		GameEngineCore::ChangeLevel("Crown_Bepi_Level");
	}

	
	

}
void Bpei_Loading::Start()
{
	if (nullptr == GameEngineSprite::Find("Loading"))
	{

		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Loading").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("BlackBG").GetFullPath());
	}

	BG = CreateComponent<GameEngineSpriteRenderer>();
	BG->SetScaleToTexture("BlackBG.png");


	Loading = CreateComponent<GameEngineSpriteRenderer>();
	Loading->CreateAnimation({ .AnimationName = "Loading", .SpriteName = "Loading", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });

	Loading->GetTransform()->AddLocalPosition({ 520.0f,-200.0f });


	Loading->ChangeAnimation("Loading");
}

void Bpei_Loading::Update(float _Delta)
{
	if (Check == false)
	{
		OverHead_Player::Sound_Check = false;
		GameEngineCore::JobQueue.Work(Bepi_Function);
		OverHead_Player::Exit2->ChangeAnimation("Exit");
		OverHead_Player::Exit2->Off();
		Check = true;
	}

}

void Bpei_Loading::Render(float _Delta)
{
}
