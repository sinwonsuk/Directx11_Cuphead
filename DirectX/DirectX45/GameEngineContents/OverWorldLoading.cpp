#include "PrecompileHeader.h"
#include "OverWorldLoading.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>
OverWorldLoading::OverWorldLoading()
{
}

OverWorldLoading::~OverWorldLoading()
{
}

void OverWorldLoading::Start()
{
	if (nullptr == GameEngineSprite::Find("Loading"))
	{

		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Loading").GetFullPath());
	}

	BG = CreateComponent<GameEngineSpriteRenderer>();
	BG->SetScaleToTexture("BlackBG.png");

	Loading = CreateComponent<GameEngineSpriteRenderer>();
	Loading->CreateAnimation({ .AnimationName = "Loading", .SpriteName = "Loading", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true, });
	Loading->ChangeAnimation("Loading");

	Loading->GetTransform()->AddLocalPosition({ 520.0f,-200.0f });
}

void OverWorld_Function(GameEngineThread* Thread)
{
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


	if (nullptr == GameEngineSprite::Find("Map"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("OverWorld");
		NewDir.Move("Map");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Map").GetFullPath());
		GameEngineSprite::LoadSheet(NewDir.GetPlusFileName("Object\\To_Tutorial_Fly.png").GetFullPath(), 3, 1);
		GameEngineSprite::LoadSheet(NewDir.GetPlusFileName("Object\\To_WaittingRoom.png").GetFullPath(), 3, 1);
	}

	GameEngineCore::ChangeLevel("OverWorld");

}

void OverWorldLoading::Update(float _Delta)
{
	if (Check == false)
	{
		GameEngineCore::JobQueue.Work(OverWorld_Function);
		Check = true;
	}

}

void OverWorldLoading::Render(float _Delta)
{
}
