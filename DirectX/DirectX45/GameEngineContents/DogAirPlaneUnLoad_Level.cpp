#include "PrecompileHeader.h"
#include "DogAirPlaneUnLoad_Level.h"
#include "DogAirPlane_UnLoad.h"
DogAirPlaneUnLoad_Level::DogAirPlaneUnLoad_Level()
{
}

DogAirPlaneUnLoad_Level::~DogAirPlaneUnLoad_Level()
{
}

void DogAirPlaneUnLoad_Level::Update(float _DeltaTime)
{
}

void DogAirPlaneUnLoad_Level::Start()
{
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);

	std::shared_ptr<DogAirPlane_UnLoad> Object = CreateActor<DogAirPlane_UnLoad>();
}

void DogAirPlaneUnLoad_Level::LevelChangeStart()
{
}

void DogAirPlaneUnLoad_Level::LevelChangeEnd()
{
}
