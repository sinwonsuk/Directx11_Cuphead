#pragma once
#include <GameEngineCore/GameEngineActor.h>

class ph2_Boss_Weapon : public GameEngineActor
{
public:
	// constrcuter destructer
	ph2_Boss_Weapon();
	~ph2_Boss_Weapon();

	// delete Function
	ph2_Boss_Weapon(const ph2_Boss_Weapon& _Other) = delete;
	ph2_Boss_Weapon(ph2_Boss_Weapon&& _Other) noexcept = delete;
	ph2_Boss_Weapon& operator=(const ph2_Boss_Weapon& _Other) = delete;
	ph2_Boss_Weapon& operator=(ph2_Boss_Weapon&& _Other) noexcept = delete;
	


	std::shared_ptr<class GameEngineSpriteRenderer> GetSfx()
	{
		return Sfx;
	}
	std::shared_ptr<class GameEngineSpriteRenderer> GetBullet()
	{
		return Bullet_First;
	}
	int SetDirCheck(int _Dircheck)
	{
		DirCheck = _Dircheck;

		return DirCheck;
	}



protected:
	void Start();
	void Update(float _Delta) override;

private:
	
	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineSpriteRenderer> Sfx;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet_First;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_dog_bowl_shoot_lines;
	
	int AttackCheck = 0;
	
	bool MoveDirCheck = false;
	bool AnimationCheck = false;
	float4 MoveDir = {0,0};
	bool CollisionCheck = false;
	int DirCheck = false;
};

