#pragma once
#include <GameEngineCore/GameEngineActor.h>

class DogAirplaneBackground : public GameEngineActor
{
public:
	// constrcuter destructer
	DogAirplaneBackground();
	~DogAirplaneBackground();

	// delete Function
	DogAirplaneBackground(const DogAirplaneBackground& _Other) = delete;
	DogAirplaneBackground(DogAirplaneBackground&& _Other) noexcept = delete;
	DogAirplaneBackground& operator=(const DogAirplaneBackground& _Other) = delete;
	DogAirplaneBackground& operator=(DogAirplaneBackground&& _Other) noexcept = delete;
	

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	

	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> Sky;
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	std::shared_ptr<class GameEngineSpriteRenderer> BossIntro2;
	std::shared_ptr<class GameEngineSpriteRenderer> A_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> B_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> C_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> D_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro3;

	int CloudCheck1 = 0;
	int CloudCheck2 = 0;
	int CloudCheck3 = 0;
	int CloudCheck4 = 0;

	float a = 0;
	float b = 0;
	float c = 0;
	float d = 0;


};

