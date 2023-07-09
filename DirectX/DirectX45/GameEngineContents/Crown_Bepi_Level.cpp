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
Crown_Bepi_Level::Crown_Bepi_Level()
{
}

Crown_Bepi_Level::~Crown_Bepi_Level()
{
}

void Crown_Bepi_Level::Update(float _DeltaTime)
{
	/*switch (PaseCheck)
	{
	case Pase::Pase1:
	{
		ph1_Bepi->On();
		ph2_Bepi->Off(); 


	}
		break;
	case Pase::Pase2:

		ph1_Bepi->Off();
		ph2_Bepi->On();

		break;
	case Pase::Pase3:
		break;
	case Pase::Pase4:
		break;
	default:
		break;
	}*/


}

void Crown_Bepi_Level::Start()
{
	//GameEngineLevel::IsDebugSwitch();

	if (nullptr == GameEngineSprite::Find("DD_Idle"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("OverWorld");
		NewDir.Move("Character");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DD_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DD_Move").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Down_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Down_Move").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DU_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DU_Move").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("InterAction_Win").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Side_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Side_Move").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Up_Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Up_Move").GetFullPath());




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



	}

	if (nullptr == GameEngineSprite::Find("FightText_GetReady"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("FightText_GetReady").GetFullPath());
	}
	

	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->SetSortType(0, SortType::ZSort);

	{
		std::shared_ptr<Player> Object = CreateActor<Player>();
	}
	{
		std::shared_ptr<Crown_Bepi_Map> Object = CreateActor<Crown_Bepi_Map>();
	}

	/*{
		ph1_Bepi = CreateActor<Ph1_Bepi>();
	}*/
	
	/*{
		ph2_Bepi = CreateActor<Ph2_Bepi>();
	}*/


	//{
	//	std::shared_ptr<Ph4_Bepi> Object = CreateActor<Ph4_Bepi>();
	//}

	//{
	//	std::shared_ptr<Ph4_Swing_Platform> Object = CreateActor<Ph4_Swing_Platform>();
	//}
	
	
	
	//{
	//	std::shared_ptr<Bepi_Duck> Object = CreateActor<Bepi_Duck>();
	//}
	// 
	
	{
		std::shared_ptr<Ph3_Bepi> Object = CreateActor<Ph3_Bepi>();
	}

	{
		std::shared_ptr<TimeFlow> Object = CreateActor<TimeFlow>(10);
	}
	
	
}

void Crown_Bepi_Level::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
}

void Crown_Bepi_Level::LevelChangeEnd()
{
	GameEngineLevel::LevelChangeEnd();
}
