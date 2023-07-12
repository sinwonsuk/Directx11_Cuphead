#include "PrecompileHeader.h"
#include "DogAirPlane_Loading_Level.h"
#include "DogAirPlane_Loading.h"
void DogAirPlane_Loading_Level::LevelChangeStart()
{

}

void DogAirPlane_Loading_Level::LevelChangeEnd()
{

}

DogAirPlane_Loading_Level::DogAirPlane_Loading_Level()
{
}

DogAirPlane_Loading_Level::~DogAirPlane_Loading_Level()
{
}

void DogAirPlane_Loading_Level::Update(float _DeltaTime)
{

}

void DogAirPlane_Loading_Level::Start()
{
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);

	std::shared_ptr<DogAirPlane_Loading> Object = CreateActor<DogAirPlane_Loading>();
}
