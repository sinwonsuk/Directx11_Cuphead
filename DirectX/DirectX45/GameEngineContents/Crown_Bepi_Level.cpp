#include "PrecompileHeader.h"
#include "Crown_Bepi_Level.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include "Crown_Bepi_Map.h"
#include "Ph1_Bepi.h"
#include "Rollercoaster.h"
#include "Ph2_Bepi.h"
#include "Ph3_Bepi.h"
#include "Ph3_Bepi_Weapon_Green.h"
#include "Ph4_Bepi.h"
Crown_Bepi_Level::Crown_Bepi_Level()
{
}

Crown_Bepi_Level::~Crown_Bepi_Level()
{
}

void Crown_Bepi_Level::Update(float _DeltaTime)
{
}

void Crown_Bepi_Level::Start()
{
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
		std::shared_ptr<Crown_Bepi_Map> Object = CreateActor<Crown_Bepi_Map>();
	}

	{
		std::shared_ptr<Ph4_Bepi> Object = CreateActor<Ph4_Bepi>();
	}

	/*{
		std::shared_ptr<Rollercoaster> Object = CreateActor<Rollercoaster>();
	}*/
	
	
	//{
	//	std::shared_ptr<Bepi_Duck> Object = CreateActor<Bepi_Duck>();
	//}
	// 
	/*{
		std::shared_ptr<Ph2_Bepi> Object = CreateActor<Ph2_Bepi>();
	}*/
	//{
	//	std::shared_ptr<Ph3_Bepi> Object = CreateActor<Ph3_Bepi>();
	//}
	/*{
		std::shared_ptr<Ph3_Bepi_Weapon_Green> Object = CreateActor<Ph3_Bepi_Weapon_Green>();
	}*/


	/*{
		std::shared_ptr<Ph1_Bepi> Object = CreateActor<Ph1_Bepi>();
	}*/
}

void Crown_Bepi_Level::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
}

void Crown_Bepi_Level::LevelChangeEnd()
{
	GameEngineLevel::LevelChangeEnd();
}
