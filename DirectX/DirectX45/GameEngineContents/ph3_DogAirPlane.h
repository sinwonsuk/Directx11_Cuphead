#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Boss_Finish.h"
#include <GameEnginePlatform/GameEngineSound.h>
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
	Left_Rotation,
	Left_Rotation_Attack,
	Right_Rotation_Attack,
	Death, 
};

class Ph3_DogAirplane : public GameEngineActor
{
public:
	std::shared_ptr<class GameEngineSpriteRenderer> Idle_Body;
	bool UpdateCheck = false;
	static  int Hp; 
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
	void Rotation_Laser_Attack_Reverse_Update(float _Time);


	void Rotation_Pase2_Laser_Attack_Update(float _Time);
	void Rotation_Pase2_Laser_Attack_Reverse_Update(float _Time);

	void Rotation_Pase3_Laser_Attack_Update(float _Time);
	void Rotation_Pase3_Laser_Attack_Reverse_Update(float _Time);

	void Left_Rotation_Update(float _Time); 

	void Left_Rotation_Attack_Update(float _Time);
	void Right_Rotation_Attack_Update(float _Time);

	void DeathUpdate(float _Time);
	


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
	std::shared_ptr<class GameEngineCollision> GetCollision()
	{
		return Collision; 
	}

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	Ph3_DogAirPlaneState StateValue = Ph3_DogAirPlaneState::Intro;

	GameEngineSoundPlayer Intro;
	GameEngineSoundPlayer GrabScreen;
	GameEngineSoundPlayer Laser_Build;
	GameEngineSoundPlayer Laser_Build2;
	GameEngineSoundPlayer Laser_Build3;
	GameEngineSoundPlayer Laser_Attack;
	GameEngineSoundPlayer Laser_Attack2;
	GameEngineSoundPlayer Rotation;
	GameEngineSoundPlayer Bowl;

	//GameEngineSoundPlayer Laser_Attack3;



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

	std::shared_ptr<class GameEngineSpriteRenderer> FightText_KO;

	std::shared_ptr<Boss_Finish> Object;

	std::shared_ptr<class GameEngineCollision> Collision;


	std::shared_ptr<class GameEngineSpriteRenderer> Exit;

	float4 trsd = { 0,0,-500 };
	float4 tsdds = { 150,1500,0 };

	bool Sound_Intro_Check = false;
	bool Sound_Grab_Check = false;
	bool Sound_Laser_Build_Check = false;
	bool Sound_Laser_Build_Check2 = false;
	bool Sound_Laser_Build_Check3 = false;
	bool Sound_Laser_Attack_Check = false;
	bool Sound_Laser_Attack_Check2 = false;
	bool Sound_Laser_Attack_Check3 = false;
	bool Sound_Rotation_Check = false;
	bool Sound_Bowl_Check = false;

	bool CollisonCheck = false;
	bool TopLaserCheck = false;
	bool MidLaserCheck = false;
	bool LowLaserCheck = false;
	int BowlDirCheck = 0;
	int BowlCheck = 0;
	int RotationCheck = -1; 
	bool ph3_Npc_Check = false; 
};
