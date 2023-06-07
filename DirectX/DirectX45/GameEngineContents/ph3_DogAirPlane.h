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

	void IntroUpdate(float _Time);
	void IdleUpdate(float _Time);

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
	

	std::shared_ptr<class GameEngineSpriteRenderer> Ph3_Boss_Intro;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Left_top_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_top_backer;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Left_mid_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_mid_backer;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Left_low_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_low;
    std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_low_backer;


	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Right_top_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_top_backer;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Right_mid_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_mid_backer;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Right_low_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_low;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_low_backer;
	
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_paw_merge;
	std::shared_ptr<class GameEngineSpriteRenderer> Idle_Arom;
	std::shared_ptr<class GameEngineSpriteRenderer> Idle_Body;
    std::shared_ptr<class GameEngineSpriteRenderer> Idle_Arom_Hand;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Left_laser_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Left_laser_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Left_laser_low;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_laser_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_laser_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_laser_low;

	


	std::shared_ptr<class GameEngineCollision> Collision;

	bool test = false;
	int IntroCheck = 0;
	float4 CurPos = { 0,0 };
	float Speed = 300;
	float4 SpeedControll = { 0,0 };
	float Speed1 = 0;
};
