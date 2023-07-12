#include "PrecompileHeader.h"
#include "ContentsCore.h"
#include <GameEngineCore\GameEngineCore.h>
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "giantStageLevel.h"
#include "DogAirplaneLevel.h"
#include "OverWorld.h"
#include "Crown_Bepi_Level.h"
#include <GameEngineCore/GameEngineCoreWindow.h>
#include "DogAirPlane_Loading_Level.h"
#include "DogAirPlaneUnLoad_Level.h"
ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::ContentsResourcesCreate()
{
	// 텍스처 로드만 각 레벨별로 하고 정리하는 습관을 들이세요.


}

void ContentsCore::GameStart() 
{
	// 이전에 매쉬는 만들어져 있어야 한다.
	
	new int();

	GameEngineGUI::GUIWindowCreate<GameEngineCoreWindow>("CoreWindow");

	

	ContentsResourcesCreate();

	
	//GameEngineCore::CreateLevel<Crown_Bepi_Level>();
	//GameEngineCore::CreateLevel<TitleLevel>();
	GameEngineCore::CreateLevel<DogAirPlane_Loading_Level>();
	GameEngineCore::CreateLevel<PlayLevel>();
	//GameEngineCore::CreateLevel<DogAirplaneLevel>();
	GameEngineCore::CreateLevel<DogAirPlaneUnLoad_Level>();
	//GameEngineCore::CreateLevel<giantStageLevel>();

	GameEngineCore::ChangeLevel("DogAirPlane_Loading_Level");
}

void ContentsCore::GameEnd() 
{

}