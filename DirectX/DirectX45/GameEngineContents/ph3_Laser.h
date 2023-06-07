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

	std::shared_ptr<class GameEngineSpriteRenderer> GetSfx()
	{
		return Sfx;
	}
	std::shared_ptr<class GameEngineSpriteRenderer> GetBullet()
	{
		return Bullet;
	}




protected:
	void Start();
	void Update(float _Delta) override;

private:
	LaserDir laserDir = LaserDir::Left_Top;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_beam_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_aura_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_particle_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_top;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_ring_top;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_particle_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_beam_mid;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_laser_warning_electric_mid;
	



	float4 MoveDir = { 0,0 };
	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineSpriteRenderer> Sfx;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;

	
};

