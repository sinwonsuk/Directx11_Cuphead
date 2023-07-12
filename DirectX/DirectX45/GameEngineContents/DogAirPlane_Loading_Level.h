#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class DogAirPlane_Loading_Level : public GameEngineLevel
{

public:
	// constrcuter destructer
	DogAirPlane_Loading_Level();
	~DogAirPlane_Loading_Level();

	// delete Function
	DogAirPlane_Loading_Level(const DogAirPlane_Loading_Level& _Other) = delete;
	DogAirPlane_Loading_Level(DogAirPlane_Loading_Level&& _Other) noexcept = delete;
	DogAirPlane_Loading_Level& operator=(const DogAirPlane_Loading_Level& _Other) = delete;
	DogAirPlane_Loading_Level& operator=(DogAirPlane_Loading_Level&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineVideo> Video;

protected:
	void Update(float _DeltaTime) override;
	void Start() override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;


private:
	void PlayerCreate();


};


