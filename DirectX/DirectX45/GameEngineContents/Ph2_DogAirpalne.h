#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class Ph2_DogAirPlaneState
{
	LeftIntro,
	UpIntro,
	RightIntro,
	DownIntro,
     Rotation,
	


};
enum class DirectionCheck
{
	Left,
	Up,
	Right,
	Down, 
};

class Ph2_DogAirpalne : public GameEngineActor
{
public:
	// constrcuter destructer
	Ph2_DogAirpalne();
	~Ph2_DogAirpalne();

	// delete Function
	Ph2_DogAirpalne(const Ph2_DogAirpalne& _Other) = delete;
	Ph2_DogAirpalne(Ph2_DogAirpalne&& _Other) noexcept = delete;
	Ph2_DogAirpalne& operator=(const Ph2_DogAirpalne& _Other) = delete;
	Ph2_DogAirpalne& operator=(Ph2_DogAirpalne&& _Other) noexcept = delete;

	void ChangeState(Ph2_DogAirPlaneState _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);

	void LeftIntroUpdate(float _Time);
	void UpIntroUpdate(float _Time);
	void RightIntroUpdate(float _Time);
	void DownIntroUpdate(float _Time);

	void RotationUpdate(float _Time);
	void UpIdleUpdate(float _Time);
	void RightIdleUpdate(float _Time);
	void DownIdleUpdate(float _Time);


	std::shared_ptr<class GameEngineSpriteRenderer> Get_Ph2_Boss()
	{
		return Ph2_Boss; 
	}

	std::shared_ptr<class GameEngineSpriteRenderer> Get_jetpack()
	{
		return jetpack;

	}
	Ph2_DogAirPlaneState SetState(Ph2_DogAirPlaneState _StateValue)
	{
		StateValue = _StateValue; 
		return StateValue; 
	}


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	int f = 0;
	Ph2_DogAirPlaneState StateValue = Ph2_DogAirPlaneState::LeftIntro;
	DirectionCheck directionCheck = DirectionCheck::Left;
	float test1 = 0;
	std::shared_ptr<class GameEngineSpriteRenderer> Ph2_Boss;
	std::shared_ptr<class GameEngineSpriteRenderer> jetpack;
	std::shared_ptr<class GameEngineSpriteRenderer> ph2_jetpack_smoke_a;
	std::shared_ptr<class GameEngineSpriteRenderer> ph2_jetpack_smoke_a1;
	std::shared_ptr<class GameEngineSpriteRenderer> ph2_jetpack_smoke_a2;
	std::shared_ptr<class GameEngineSpriteRenderer> ph2_jetpack_smoke_a3;
	std::shared_ptr<class GameEngineSpriteRenderer> ph2_jetpack_smoke_a4;
	std::shared_ptr<class GameEngineSpriteRenderer> ph2_jetpack_smoke_a5;
	std::shared_ptr<class GameEngineSpriteRenderer> ph2_jetpack_smoke_a6;
	std::shared_ptr<class GameEngineSpriteRenderer> ph2_jetpack_smoke_a7;

	std::shared_ptr<class GameEngineSpriteRenderer> ph2_jetpack_smoke_b;
	std::shared_ptr<class GameEngineSpriteRenderer> ph2_jetpack_smoke_c;
	bool dsda = false;


	std::shared_ptr<class GameEngineCollision> Collision;


	float Left_Pos_x = -620.0f;
	float Up_Pos_x = 300.0f;
	float Right_Pos_x = 620.0f;
	float Down_Pos_x = -300.0f;

	float Pos_x = 0.0f;
	float Pos_y = 0.0f;
	float test = 0;
	int RotationAnimation = 0;
	bool RotationCheck = false;
	int IntroCheck = 0;
	float4 CurPos = { 0,0 };
	float Speed = 300;
	float4 SpeedControll = {0,0};
	float Speed1 = 0;
};

