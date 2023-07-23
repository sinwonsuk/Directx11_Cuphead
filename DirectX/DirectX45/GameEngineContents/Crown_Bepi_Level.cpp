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
#include "UserInterface.h"
#include <GameEngineCore/BlurEffect.h>
#include "OldFilm.h"
#include "OldTVEffect.h"

bool Crown_Bepi_Level::Finish_Check = false;

Crown_Bepi_Level::Crown_Bepi_Level()
{
}

Crown_Bepi_Level::~Crown_Bepi_Level()
{
}

void Crown_Bepi_Level::Update(float _DeltaTime)
{
	switch (PaseCheck)
	{
	case Pase::Pase1:
	{
		ph1_Bepi->On();
		ph2_Bepi->Off(); 
		ph3_Bepi->Off();
		ph4_Bepi->Off();

	}
		break;
	case Pase::Pase2:
	{
		ph1_Bepi->Off();
		ph2_Bepi->On();
		ph3_Bepi->Off();
		ph4_Bepi->Off();
	}
		break;
	case Pase::Pase3:
	{
		ph1_Bepi->Off();
		ph2_Bepi->Off();
		ph3_Bepi->On();
		ph4_Bepi->Off();
	}
		break;
	case Pase::Pase4:
	{
		ph1_Bepi->Off();
		ph2_Bepi->Off();
		ph3_Bepi->Off();
		ph4_Bepi->On();
	}
		break;
	default:
		break;
	}


}

void Crown_Bepi_Level::Start()
{
	GetLastTarget()->CreateEffect<OldFilm>();
	GetLastTarget()->CreateEffect<BlurEffect>();


	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->SetSortType(0, SortType::ZSort);

	


	
	
}

void Crown_Bepi_Level::LevelChangeStart()
{
	
	{
		timeFlow = CreateActor<TimeFlow>(10);
	}
	{
		player = CreateActor<Player>();
	}
	{
		Map = CreateActor<Crown_Bepi_Map>();
	}
	{
		userInterface = CreateActor<UserInterface>();
	}
	

	{
		ph1_Bepi = CreateActor<Ph1_Bepi>();
	}

	{
		ph2_Bepi = CreateActor<Ph2_Bepi>();
	}

	{
		ph3_Bepi = CreateActor<Ph3_Bepi>();
	}
	{
		ph4_Bepi = CreateActor<Ph4_Bepi>();
	}

	GameEngineLevel::LevelChangeStart();
}

void Crown_Bepi_Level::LevelChangeEnd()
{
	PaseCheck = Pase::Pase1;
	ph1_Bepi.get()->BG.Stop(); 
	Crown_Bepi_Map::Ph4_Check = false;
	Map.get()->Coaster.Stop();
	Map.get()->Coaster_Light.Stop();

	TimeFlow::Time = 0;
	timeFlow->Death();

	for (size_t i = 0; i < Crown_Bepi_Map::Rollercoasters.size(); i++)			
	{			
		Crown_Bepi_Map::Rollercoasters[i].get()->Death(); 	
	}
	Crown_Bepi_Map::Rollercoasters.clear(); 

	Map->Death(); 
	Player::MainPlayer->Death();
	Player::MainPlayer = nullptr;
	player->Death();
	if (Ph4_Bepi::ph4_Bepi != nullptr)
	{
		Ph4_Bepi::ph4_Bepi->Death();
	}	
	Ph4_Bepi::ph4_Bepi = nullptr;
	UserInterface::Cut = 0;
	UserInterface::CardNumber = 0;
	UserInterface::HpBar = 3;

	userInterface->Death();

	Ph4_Swing_Platform::Ph4_Platform_Check = false;
	ph1_Bepi->Death();
	ph2_Bepi->Death();
	ph3_Bepi->Death();
	ph4_Bepi->Death();

	GameEngineLevel::LevelChangeEnd();
}
