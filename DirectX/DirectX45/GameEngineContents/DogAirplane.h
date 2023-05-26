#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class DogAirplaneState
{
	BossIntro,
	BossIntro2,
	BossIntroRock,
	BossIntroDust,
	bulldog_Idle,
	BossIdleHand,
	noumIntro,
	bulldog_Jump,

};

class DogAirplane : public GameEngineActor
{
public:
	// constrcuter destructer
	DogAirplane();
	~DogAirplane();

	// delete Function
	DogAirplane(const DogAirplane& _Other) = delete;
	DogAirplane(DogAirplane&& _Other) noexcept = delete;
	DogAirplane& operator=(const DogAirplane& _Other) = delete;
	DogAirplane& operator=(DogAirplane&& _Other) noexcept = delete;

	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	void BossIdleUpdate(float _Time);
	void BossIntroUpdate(float _Time);
	void BossIntro2Update(float _Time);
	void ChangeState(DogAirplaneState _State);
	void BossJumpUpdate(float _Time); 
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	std::vector<int> a;
	float DownSpeed = 600;
	float Speed = 75;
	DogAirplaneState StateValue = DogAirplaneState::BossIntro;

	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> GirlDog;
	std::shared_ptr<class GameEngineSpriteRenderer> dogcopter;
	std::shared_ptr<class GameEngineSpriteRenderer> bulldogIntro;
	std::shared_ptr<class GameEngineSpriteRenderer> AirplaneSpin;
	std::shared_ptr<class GameEngineSpriteRenderer> Airplane_Back;
	std::shared_ptr<class GameEngineSpriteRenderer> Airplane_Front;
	std::shared_ptr<class GameEngineSpriteRenderer> bulldogIdle;
	
	std::shared_ptr<class GameEngineSpriteRenderer> bulldog_Jump;
	int bulldogIdleCheck = 0;
	float4 CurPos = { 0,0 };
	bool test = false;
	bool test1 = false;
};
