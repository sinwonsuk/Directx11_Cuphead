#pragma once
#include <GameEngineCore/GameEngineActor.h>

class ExWeapon : public GameEngineActor
{
public:

	// constrcuter destructer
	ExWeapon();
	~ExWeapon();

	// delete Function
	ExWeapon(const ExWeapon& _Other) = delete;
	ExWeapon(ExWeapon&& _Other) noexcept = delete;
	ExWeapon& operator=(const ExWeapon& _Other) = delete;
	ExWeapon& operator=(ExWeapon&& _Other) noexcept = delete;
	float4 SetMoveDir(const float4& _MoveDir)
	{
		MoveDir = _MoveDir;
		return MoveDir;
	}

	std::shared_ptr<class GameEngineSpriteRenderer> GetSfx()
	{
		return Sfx;
	}
	std::shared_ptr<class GameEngineSpriteRenderer> GetSfx_Dust()
	{
		return Sfx_Dust;
	}

	std::shared_ptr<class GameEngineSpriteRenderer> GetBullet()
	{
		return Bullet;
	}




protected:
	void Start();
	void Update(float _Delta) override;

private:
	float4 MoveDir = { 0,0 };
	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineSpriteRenderer> Sfx;
	std::shared_ptr<class GameEngineSpriteRenderer> Sfx_Dust;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;
	bool CollisionCheck = false;
	bool Check = false;
};
