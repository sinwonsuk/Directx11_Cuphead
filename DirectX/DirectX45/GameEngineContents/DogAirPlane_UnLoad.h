#pragma once
#include <GameEngineCore/GameEngineActor.h>

class DogAirPlane_UnLoad : public GameEngineActor
{
public:
	// constrcuter destructer
	DogAirPlane_UnLoad();
	~DogAirPlane_UnLoad();

	// delete Function
	DogAirPlane_UnLoad(const DogAirPlane_UnLoad& _Other) = delete;
	DogAirPlane_UnLoad(DogAirPlane_UnLoad&& _Other) noexcept = delete;
	DogAirPlane_UnLoad& operator=(const DogAirPlane_UnLoad& _Other) = delete;
	DogAirPlane_UnLoad& operator=(DogAirPlane_UnLoad&& _Other) noexcept = delete;



	



protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;



private:

	bool Check = false;

	std::shared_ptr<class GameEngineSpriteRenderer> UnLoad;






};

