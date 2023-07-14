#include "PrecompileHeader.h"
#include "Bepi_Loading_Level.h"
#include "Bpei_Loading.h"
Bepi_Loading_Level::Bepi_Loading_Level()
{
}

Bepi_Loading_Level::~Bepi_Loading_Level()
{
}

void Bepi_Loading_Level::Update(float _DeltaTime)
{
}

void Bepi_Loading_Level::Start()
{
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);

	std::shared_ptr<Bpei_Loading> Object = CreateActor<Bpei_Loading>();
}

void Bepi_Loading_Level::LevelChangeStart()
{
}

void Bepi_Loading_Level::LevelChangeEnd()
{
}
