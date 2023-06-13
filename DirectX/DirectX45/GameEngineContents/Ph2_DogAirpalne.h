#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class Ph2_DogAirPlaneState
{
	LeftIntro,
	UpIntro,
	RightIntro,
	DownIntro,

	LeftIdle,
	UpIdle,
	RightIdle,
	DownIdle,

	Attack, 
	Win,
	FinishWin,

	LeftIdle1,
	LeftSide,
    LeftFront,
	LeftFrontFront,


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

	void LeftIdleUpdate(float _Time);
	void UpIdleUpdate(float _Time);
	void RightIdleUpdate(float _Time);
	void DownIdleUpdate(float _Time);






protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	Ph2_DogAirPlaneState StateValue = Ph2_DogAirPlaneState::LeftIntro;
	DirectionCheck directionCheck = DirectionCheck::Left;

	std::shared_ptr<class GameEngineSpriteRenderer> Ph2_Boss;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Front;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Reg;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Spin;

	std::shared_ptr<class GameEngineSpriteRenderer> Npc;
	std::shared_ptr<class GameEngineSpriteRenderer> C_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> D_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro3;



	std::shared_ptr<class GameEngineCollision> Collision;


	float Left_Pos_x = -620.0f;
	float Up_Pos_x = 300.0f;
	float Right_Pos_x = 620.0f;
	float Down_Pos_x = -300.0f;


	int RotationAnimation = 0;
	bool RotationCheck = false;
	int IntroCheck = 0;
	float4 CurPos = { 0,0 };
	float Speed = 300;
	float4 SpeedControll = {0,0};
	float Speed1 = 0;
};

