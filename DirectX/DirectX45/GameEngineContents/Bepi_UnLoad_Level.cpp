#include "PrecompileHeader.h"
#include "Bepi_UnLoad_Level.h"
#include "Bepi_UnLoad.h"
#include <GameEngineCore/BlurEffect.h>
#include "OldFilm.h"
#include "OldTVEffect.h"

Bepi_UnLoad_Level::Bepi_UnLoad_Level()
{
}

Bepi_UnLoad_Level::~Bepi_UnLoad_Level()
{
}

void Bepi_UnLoad_Level::Update(float _DeltaTime)
{
}

void Bepi_UnLoad_Level::Start()
{
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);

	std::shared_ptr<Bepi_UnLoad> Object = CreateActor<Bepi_UnLoad>();


	GetLastTarget()->CreateEffect<OldFilm>();
	GetLastTarget()->CreateEffect<BlurEffect>();


}

void Bepi_UnLoad_Level::LevelChangeStart()
{
}

void Bepi_UnLoad_Level::LevelChangeEnd()
{
}
