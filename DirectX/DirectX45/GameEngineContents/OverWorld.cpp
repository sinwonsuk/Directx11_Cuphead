#include "PrecompileHeader.h"
#include "OverWorld.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include "OverHead_Player.h"
#include "OverWorld_Map.h"
#include <GameEngineCore/BlurEffect.h>
#include "OldFilm.h"
#include "OldTVEffect.h"

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
	



	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->SetSortType(0,SortType::ZSort);
	GetMainCamera()->GetTransform()->AddLocalPosition({ -1300,300 });
	
	
	GetLastTarget()->CreateEffect<OldFilm>();
	GetLastTarget()->CreateEffect<BlurEffect>();
	

}

void OverWorld::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();

	if (OneCheck == false)
	{
		{
			std::shared_ptr<OverWorld_Map> Object = CreateActor<OverWorld_Map>();
		}
		{
			std::shared_ptr<OverHead_Player> Object = CreateActor<OverHead_Player>();
			Object->GetTransform()->AddLocalPosition({ 120.0f,120.0f });
		}
		OneCheck = true;
	}
	  
}

void OverWorld::LevelChangeEnd()
{
	

	GameEngineSprite::UnLoad("DD_Idle");
	GameEngineSprite::UnLoad("DD_Move");
	GameEngineSprite::UnLoad("Down_Idle");
	GameEngineSprite::UnLoad("Down_Move");
	GameEngineSprite::UnLoad("DU_Idle");
	GameEngineSprite::UnLoad("DU_Move");
	GameEngineSprite::UnLoad("InterAction_Win");
	GameEngineSprite::UnLoad("Side_Idle");
	GameEngineSprite::UnLoad("Side_Move");
	GameEngineSprite::UnLoad("Up_Idle");
	GameEngineSprite::UnLoad("Up_Move");
	GameEngineSprite::UnLoad("Map");
	GameEngineSprite::UnLoad("To_Tutorial_Fly.png");
	GameEngineSprite::UnLoad("To_WaittingRoom.png");

	GameEngineLevel::LevelChangeEnd();
}
