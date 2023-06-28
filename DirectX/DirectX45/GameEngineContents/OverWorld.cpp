#include "PrecompileHeader.h"
#include "OverWorld.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>

OverWorld::OverWorld()
{

}

OverWorld::~OverWorld()
{

}

void OverWorld::Update(float _DeltaTime)
{

}

void OverWorld::Start()
{
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
}

void OverWorld::LevelChangeStart()
{

}

void OverWorld::LevelChangeEnd()
{

}
