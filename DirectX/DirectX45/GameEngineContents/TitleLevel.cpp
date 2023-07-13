#include "PrecompileHeader.h"
#include "TitleLevel.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "Title.h"
TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}


void TitleLevel::Start() 
{
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);

	if (nullptr == GameEngineSprite::Find("cuphead_title_screen"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Title");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("cuphead_title_screen").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("title_screen_background").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Title_Logo").GetFullPath());
		
	}
	if (nullptr == GameEngineSprite::Find("Exit"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("UI");
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Exit").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Start").GetFullPath());
	}

	{
		std::shared_ptr<Title> Object = CreateActor<Title>();
	}


	
}

void TitleLevel::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
}

void TitleLevel::LevelChangeEnd()
{

	GameEngineSprite::UnLoad("cuphead_title_screen");
	GameEngineSprite::UnLoad("title_screen_background");
	GameEngineSprite::UnLoad("Title_Logo");

	GameEngineLevel::LevelChangeEnd();
}

