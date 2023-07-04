#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Ph2_Bepi_Weapon : public GameEngineActor
{
public:
	// constrcuter destructer
	Ph2_Bepi_Weapon();
	~Ph2_Bepi_Weapon();

	// delete Function
	Ph2_Bepi_Weapon(const Ph2_Bepi_Weapon& _Other) = delete;
	Ph2_Bepi_Weapon(Ph2_Bepi_Weapon&& _Other) noexcept = delete;
	Ph2_Bepi_Weapon& operator=(const Ph2_Bepi_Weapon& _Other) = delete;
	Ph2_Bepi_Weapon& operator=(Ph2_Bepi_Weapon&& _Other) noexcept = delete;



	std::shared_ptr<class GameEngineSpriteRenderer> GetSfx()
	{
		return Sfx;
	}
	std::shared_ptr<class GameEngineSpriteRenderer> GetBullet_First()
	{
		return Bullet_First;
	}

	std::shared_ptr<class GameEngineSpriteRenderer> GetParryEffect()
	{
		return ParryEffect;
	}
	std::shared_ptr<class GameEngineSpriteRenderer> GetBullet()
	{
		return Bullet_Stop;
	}


	std::shared_ptr<class GameEngineCollision> GetPinkCollision()
	{
		return PinkCollision;
	}




	int SetDirCheck(int _Dircheck)
	{
		DirCheck = _Dircheck;

		return DirCheck;
	}
	int SetAttackCheck(const int& _AttackCheck)
	{
		AttackCheck = _AttackCheck;

		return AttackCheck;
	}


protected:
	void Start();
	void Update(float _Delta) override;

private:

	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineCollision> PinkCollision;
	std::shared_ptr<class GameEngineSpriteRenderer> ParryEffect;
	std::shared_ptr<class GameEngineSpriteRenderer> Sfx;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet_Stop;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet_First;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_dog_bowl_shoot_lines;

	int AttackCheck = 0;
	bool BulletCheck = false;
	bool MoveDirCheck = false;
	bool AnimationCheck = false;
	float4 MoveDir4 = { 0,0 };
	float4 MoveDir = { 0,0 };
	bool CollisionCheck = false;
	int DirCheck = false;
};

