#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class DogAirplaneLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	DogAirplaneLevel();
	~DogAirplaneLevel();

	// delete Function
	DogAirplaneLevel(const DogAirplaneLevel& _Other) = delete;
	DogAirplaneLevel(DogAirplaneLevel&& _Other) noexcept = delete;
	DogAirplaneLevel& operator=(const DogAirplaneLevel& _Other) = delete;
	DogAirplaneLevel& operator=(DogAirplaneLevel&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineVideo> Video;

protected:
	void Update(float _DeltaTime) override;
	void Start() override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;


private:
	void PlayerCreate();


};
