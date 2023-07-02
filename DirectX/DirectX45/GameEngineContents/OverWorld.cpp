#include "PrecompileHeader.h"
#include "OverWorld.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include "OverHead_Player.h"
#include "OverWorld_Map.h"
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



	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->SetSortType(0,SortType::ZSort);
	
	
	{
		std::shared_ptr<OverWorld_Map> Object = CreateActor<OverWorld_Map>();
	}
	{
		std::shared_ptr<OverHead_Player> Object = CreateActor<OverHead_Player>();
	}

	GetMainCamera()->GetTransform()->AddLocalPosition({ -1300,300 });

}

void OverWorld::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
}

void OverWorld::LevelChangeEnd()
{
	GameEngineLevel::LevelChangeEnd();
}
