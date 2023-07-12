#pragma once
#include <GameEngineCore/GameEngineActor.h>

class DogAirPlane_Loading : public GameEngineActor
{
public:
	// constrcuter destructer
	DogAirPlane_Loading();
	~DogAirPlane_Loading();

	// delete Function
	DogAirPlane_Loading(const DogAirPlane_Loading& _Other) = delete;
	DogAirPlane_Loading(DogAirPlane_Loading&& _Other) noexcept = delete;
	DogAirPlane_Loading& operator=(const DogAirPlane_Loading& _Other) = delete;
	DogAirPlane_Loading& operator=(DogAirPlane_Loading&& _Other) noexcept = delete;



	static bool Finish;




protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	int Hp = 10;

	int AttackCheck = 0;
	int AttackColor = 0;

	std::shared_ptr<class GameEngineSpriteRenderer> Loading;
	





};

