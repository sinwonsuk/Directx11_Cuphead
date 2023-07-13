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
	static bool Check;



protected:

	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	

private:
	
	

	std::shared_ptr<class GameEngineSpriteRenderer> Loading;
	





};

