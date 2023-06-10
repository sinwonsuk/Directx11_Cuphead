#pragma once
#include <GameEngineCore/GameEngineActor.h>



enum class LaserDir
{
	Left_Top,
	Left_Mid,
	Left_Low,
	Right_Top,
	Right_Mid,
	Right_Low,

	Left_Top_Reverse,
	Right_Top_Reverse,

};

class ph3_Laser : public GameEngineActor
{
public:
	// constrcuter destructer
	ph3_Laser();
	~ph3_Laser();

	// delete Function
	ph3_Laser(const ph3_Laser& _Other) = delete;
	ph3_Laser(ph3_Laser&& _Other) noexcept = delete;
	ph3_Laser& operator=(const ph3_Laser& _Other) = delete;
	ph3_Laser& operator=(ph3_Laser&& _Other) noexcept = delete;
	float4 SetMoveDir(const float4& _MoveDir)
	{
		MoveDir = _MoveDir;
		return MoveDir;
	}

	std::shared_ptr<class GameEngineSpriteRenderer> Get_ph3_beam_top()
	{
		return ph3_beam_top; 
	}




	std::shared_ptr<class GameEngineSpriteRenderer> Get_ph3_beam_mid()
	{
		return ph3_beam_mid;
	}

	std::shared_ptr<class GameEngineSpriteRenderer> Get_ph3_beam_low()
	{
		return ph3_beam_low;
	}


	LaserDir laserDir = LaserDir::Right_Mid;

protected:
	void Start();
	void Update(float _Delta) override;

private:
	

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_beam_top = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_aura_top = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_particle_top = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_top = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_ring_top = nullptr;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_mid = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_particle_mid = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_beam_mid = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_electric_mid = nullptr;
	
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_beam_low = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Right_warning_aura_low = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_Left__warning_aura_low = nullptr;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_low = nullptr;
	
	bool dirCheck = false;

	float4 MoveDir = { 0,0 };
	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineSpriteRenderer> Sfx;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;

	
};

