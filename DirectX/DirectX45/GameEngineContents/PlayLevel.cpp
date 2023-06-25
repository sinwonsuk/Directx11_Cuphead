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
	//std::shared_ptr<Player> Object = CreateActor<Player>(3);




}

void PlayLevel::Start()
{
	GameEngineLevel::IsDebugSwitch();


	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Test");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });


		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}
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
	GetMainCamera()->GetTransform()->AddLocalPosition({ 0.0f,-80.0f,0.0f });
	GetCamera(100)->GetTransform()->AddLocalPosition({ 0.0f,-80.0f,0.0f });
	//GetMainCamera()->GetTransform()->AddLocalPosition({ 3488.0f,0.0f,0.0f });
	//GetMainCamera()->GetTransform()->SetLocalPosition({0, 0, -1000.0f});


	std::shared_ptr<GameEngineCoreWindow> Window = GameEngineGUI::FindGUIWindowConvert<GameEngineCoreWindow>("CoreWindow");

	{
		if (nullptr == Window)
		{
			MsgAssert("윈도우 테스트 코드 미작동");
		}

		Window->Test = std::bind(&PlayLevel::PlayerCreate, this);
	}

	{
		std::shared_ptr<Player> Object = CreateActor<Player>();
		Object->GetTransform()->SetLocalPosition({ 0.0f,0.0f });
	}
	{
		std::shared_ptr<TutorialMap> Object = CreateActor<TutorialMap>();
	//	Object->GetTransform()->SetLocalPosition({ 2450.0f,0 });
	}

	{
		std::shared_ptr<TutorialObject> Object = CreateActor<TutorialObject>(10);
		Object->GetTransform()->SetLocalPosition({0.0f,0.0f });
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


}
void PlayLevel::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
	int a = 0;
}

void PlayLevel::LevelChangeEnd() 
{
	GameEngineLevel::LevelChangeEnd();
	int a = 0;
}