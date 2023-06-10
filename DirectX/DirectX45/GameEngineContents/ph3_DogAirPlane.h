#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class Ph3_DogAirPlaneState
{
	Intro,
	Idle,
	Pase1_Attack,
	Pase1_Attack_Reverse,
	Pase2_Attack,
	Pase2_Attack_Reverse,
	Pase3_Attack,
	Pase3_Attack_Reverse,
	Rotation,
	Rotation_Attack,
	Rotation_Laser_Idle,
	Rotation_Pase1_Laser_Attack,
	Rotation_Pase1_Laser_Attack_Reverse,
	Rotation_Pase2_Laser_Attack,
	Rotation_Pase2_Laser_Attack_Reverse,
	Rotation_Pase3_Laser_Attack,
	Rotation_Pase3_Laser_Attack_Reverse,

	

	
	
	

};

class Ph3_DogAirplane : public GameEngineActor
{
public:

	static Ph3_DogAirplane* ph3_mainBoss;
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

	void Pase1_AttackUpdate(float _Time); 
	void Pase1_Attack_Reverse_Update(float _Time);
	void Pase2_AttackUpdate(float _Time);
	void Pase2_Attack_Reverse_Update(float _Time);
	void Pase3_AttackUpdate(float _Time);
	void Pase3_Attack_Reverse_Update(float _Time);
	void Rotation_Attack_Update(float _Time);

	void Rotation_Update(float _Time); 
	void Rotation_Laser_Update(float _Time);
	void Rotation_Laser_Attack_Update(float _Time);



	void Rotation_Pase2_Laser_Attack_Update(float _Time);
	void Rotation_Pase2_Laser_Attack_Reverse_Update(float _Time);

	void Rotation_Pase3_Laser_Attack_Update(float _Time);
	void Rotation_Pase3_Laser_Attack_Reverse_Update(float _Time);






	void LeftIdleUpdate(float _Time);
	void UpIdleUpdate(float _Time);
	void RightIdleUpdate(float _Time);
	void DownIdleUpdate(float _Time);

	int GetBowlCheck()
	{
		return BowlCheck;
	}
	
	std::shared_ptr<class GameEngineSpriteRenderer> Get_ph3_dogcopter_rotate_camera()
	{
		return ph3_dogcopter_rotate_camera;
	}

	int GetRotationCheck()
	{
		return RotationCheck; 
	}


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	Ph3_DogAirPlaneState StateValue = Ph3_DogAirPlaneState::Pase3_Attack_Reverse;
	

	std::shared_ptr<class GameEngineSpriteRenderer> Ph3_Boss_Intro;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Left_top_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Left_top_paw_pad_opens_Reverse;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_top_backer;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Left_mid_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Left_mid_paw_pad_opens_Reverse;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_mid_backer;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Left_low_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Left_low_paw_pad_opens_Reverse;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_low;
    std::shared_ptr<class GameEngineSpriteRenderer> ph3_left_paw_hole_low_backer;


	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Right_top_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Right_top_paw_pad_opens_Reverse;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_top_backer;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Right_mid_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Right_mid_paw_pad_opens_Reverse;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_mid_backer;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Right_low_paw_pad_opens;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Right_low_paw_pad_opens_Reverse;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_low;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_paw_hole_low_backer;
	
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_paw_merge;
	std::shared_ptr<class GameEngineSpriteRenderer> Idle_Arom;
	std::shared_ptr<class GameEngineSpriteRenderer> Idle_Body;
    std::shared_ptr<class GameEngineSpriteRenderer> Idle_Arom_Hand;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Left_laser_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Left_laser_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Left_laser_low;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Left_laser_mid_Reverse;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Left_laser_top_Reverse;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Left_laser_low_Reverse;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_laser_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_laser_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_laser_low;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_laser_mid_Reverse;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_laser_top_Reverse;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_Right_laser_low_Reverse;


	std::shared_ptr<class GameEngineSpriteRenderer> ph3_tongue_rotate_camera;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_dogcopter_rotate_camera;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_dogcopter_rotated_idle;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_dogcopter_rotate_camera_out_blades;


	std::shared_ptr<class GameEngineSpriteRenderer> ph3_dogcopter_rotate_camera_out;

	std::shared_ptr<class GameEngineCollision> Collision;

	bool TopLaserCheck = false;
	bool MidLaserCheck = false;
	bool LowLaserCheck = false;
	int BowlDirCheck = 0;
	int BowlCheck = 0;
	int RotationCheck = -1; 
	bool ph3_Npc_Check = false; 
};
