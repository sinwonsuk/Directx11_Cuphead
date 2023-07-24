#include "PrecompileHeader.h"
#include "PlayLevel.h"
#include "Player.h"
#include "TestObject.h"
#include "TutorialMap.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include  "TutorialObject.h"
#include "UserInterface.h"
#include <GameEngineCore/BlurEffect.h>
#include "OldFilm.h"
#include "OldTVEffect.h"
PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Update(float _DeltaTime)
{

}

void PlayLevel::PlayerCreate(/*Playlevel* this*/)
{
	

}

void PlayLevel::Start()
{
	
	


	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Tutorial");

	

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("MapOrObject").GetFullPath());
		
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


	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetCamera(100)->SetProjectionType(CameraType::Orthogonal);
	GetCamera(100)->SetSortType(0, SortType::ZSort);
	GetMainCamera()->GetTransform()->AddLocalPosition({ -320.0f,-80.0f,0.0f });
	GetCamera(100)->GetTransform()->AddLocalPosition({ 0.0f,-80.0f,0.0f });
	

	std::shared_ptr<GameEngineCoreWindow> Window = GameEngineGUI::FindGUIWindowConvert<GameEngineCoreWindow>("CoreWindow");

	{
		if (nullptr == Window)
		{
			MsgAssert("윈도우 테스트 코드 미작동");
		}

		Window->Test = std::bind(&PlayLevel::PlayerCreate, this);
	}

	

	

	{
		std::shared_ptr<TutorialMap> Object = CreateActor<TutorialMap>();
	//	Object->GetTransform()->SetLocalPosition({ 2450.0f,0 });
	}

	{
		std::shared_ptr<Player> Object = CreateActor<Player>();

		Object->GetTransform()->SetLocalPosition({ -320.0f,-70.0f });
		Object->SetCameraCheck(true);
		Object->SetTutorialCheck(true);
	}

	{
		std::shared_ptr<TutorialObject> Object = CreateActor<TutorialObject>(10);
		Object->GetTransform()->SetLocalPosition({0.0f,0.0f });
	}

	{
		std::shared_ptr<UserInterface> Object = CreateActor<UserInterface>();
		Object->GetTransform()->AddLocalPosition({ 0,-80.0f });
	}
	/*{
		std::shared_ptr<TutorialObject> Object = CreateActor<TutorialObject>(10);
		Object->GetTransform()->SetLocalPosition({ 3345.0f,-10.0f });
	}

	{
		std::shared_ptr<TutorialObject> Object = CreateActor<TutorialObject>(10);
		Object->GetTransform()->SetLocalPosition({ 3150.0f,-10.0f });

	}*/


	/*{
		std::shared_ptr<TutorialMap> Object = CreateActor<TutorialMap>();
		Object->GetTransform()->SetLocalPosition({ 2450.0f,0 });
	}*/
	//{
	//	std::shared_ptr<TestObject> Object = CreateActor<TestObject>(1);
	//}

	GetLastTarget()->CreateEffect<OldFilm>();
	GetLastTarget()->CreateEffect<BlurEffect>();

}
void PlayLevel::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
	int a = 0;
}

void PlayLevel::LevelChangeEnd() 
{
	TutorialMap::BG.Stop(); 
	UserInterface::CardNumber = 0;
	UserInterface::Cut = 0;
	Player::MainPlayer->Death(); 
	Player::MainPlayer = nullptr;
	GameEngineSprite::UnLoad("MapOrObject");

	GameEngineLevel::LevelChangeEnd();
	int a = 0;
}