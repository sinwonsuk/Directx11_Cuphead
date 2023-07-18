#include "PrecompileHeader.h"
#include "OverWorld_Loading_Level.h"
#include "OverWorldLoading.h"
#include <GameEngineCore/BlurEffect.h>
#include "OldFilm.h"
#include "OldTVEffect.h"

OverWorld_Loading_Level::OverWorld_Loading_Level()
{
}

OverWorld_Loading_Level::~OverWorld_Loading_Level()
{
}

void OverWorld_Loading_Level::Update(float _DeltaTime)
{
}

void OverWorld_Loading_Level::Start()
{
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);

	std::shared_ptr<OverWorldLoading> Object = CreateActor<OverWorldLoading>();

	GetLastTarget()->CreateEffect<OldFilm>();
	GetLastTarget()->CreateEffect<BlurEffect>();

}

void OverWorld_Loading_Level::LevelChangeStart()
{
}

void OverWorld_Loading_Level::LevelChangeEnd()
{
}
