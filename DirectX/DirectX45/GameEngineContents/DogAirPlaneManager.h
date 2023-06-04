#pragma once
#include <GameEngineCore/GameEngineActor.h>

class DogAirplaneManager : public GameEngineActor
{
public:
	// constrcuter destructer
	DogAirplaneManager();
	~DogAirplaneManager();

	// delete Function
	DogAirplaneManager(const DogAirplaneManager& _Other) = delete;
	DogAirplaneManager(DogAirplaneManager&& _Other) noexcept = delete;
	DogAirplaneManager& operator=(const DogAirplaneManager& _Other) = delete;
	DogAirplaneManager& operator=(DogAirplaneManager&& _Other) noexcept = delete;
	



protected:
	void Start();
	void Update(float _Delta) override;

private:
	float4 MoveDir = { 0,0 };

	bool CollisionCheck = false;
	bool Check = false;
};;

