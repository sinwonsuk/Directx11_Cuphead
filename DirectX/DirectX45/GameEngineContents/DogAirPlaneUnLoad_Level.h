#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class DogAirPlaneUnLoad_Level : public GameEngineLevel
{

public:
	// constrcuter destructer
	DogAirPlaneUnLoad_Level();
	~DogAirPlaneUnLoad_Level();

	// delete Function
	DogAirPlaneUnLoad_Level(const DogAirPlaneUnLoad_Level& _Other) = delete;
	DogAirPlaneUnLoad_Level(DogAirPlaneUnLoad_Level&& _Other) noexcept = delete;
	DogAirPlaneUnLoad_Level& operator=(const DogAirPlaneUnLoad_Level& _Other) = delete;
	DogAirPlaneUnLoad_Level& operator=(DogAirPlaneUnLoad_Level&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineVideo> Video;

protected:
	void Update(float _DeltaTime) override;
	void Start() override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;


private:



};

