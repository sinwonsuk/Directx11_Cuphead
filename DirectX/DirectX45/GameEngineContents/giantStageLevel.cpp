#include "PrecompileHeader.h"
#include "giantStageLevel.h"
#include "Player.h"
#include "GiantBoss.h"
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>



giantStageLevel::giantStageLevel()
{
}

giantStageLevel::~giantStageLevel()
{
}

void giantStageLevel::Update(float _DeltaTime)
{
}

void giantStageLevel::Start()
{
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);

	std::shared_ptr<GiantBoss> Object1 = CreateActor<GiantBoss>(2);
	std::shared_ptr<Player> Object = CreateActor<Player>(3);

	Object1->GetTransform()->AddLocalPosition({ 0,-50 });


}

void giantStageLevel::LevelChangeStart()
{
}

void giantStageLevel::LevelChangeEnd()
{
	GameEngineLevel::LevelChangeStart();
	int a = 0;
}

void giantStageLevel::PlayerCreate()
{
	GameEngineLevel::LevelChangeEnd();
	int a = 0;
}
