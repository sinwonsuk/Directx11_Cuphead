#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class Ph3_DogAirPlaneState
{
	Intro,
	Idle,
	
	
	

	
	
	
	

	
	
	

};

class Ph3_DogAirplane : public GameEngineActor
{
public:
	// constrcuter destructer
	Ph3_DogAirplane();
	~Ph3_DogAirplane();

	// delete Function
	Ph3_DogAirplane(const Ph3_DogAirplane& _Other) = delete;
	Ph3_DogAirplane(Ph3_DogAirplane&& _Other) noexcept = delete;
	Ph3_DogAirplane& operator=(const Ph3_DogAirplane& _Other) = delete;
	Ph3_DogAirplane& operator=(Ph3_DogAirplane&& _Other) noexcept = delete;

	void ChangeState(Ph3_DogAirPlaneState _State);
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
	Ph3_DogAirPlaneState StateValue = Ph3_DogAirPlaneState::Intro;
	

	std::shared_ptr<class GameEngineSpriteRenderer> Ph3_Boss;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_pad_low;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_pad_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_pad_top;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_right_paw_pad_low;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_right_paw_pad_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_right_paw_pad_top;


	std::shared_ptr<class GameEngineCollision> Collision;

	int IntroCheck = 0;
	float4 CurPos = { 0,0 };
	float Speed = 300;
	float4 SpeedControll = { 0,0 };
	float Speed1 = 0;
};
