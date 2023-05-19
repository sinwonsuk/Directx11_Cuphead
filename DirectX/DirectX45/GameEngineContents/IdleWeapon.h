#pragma once
#include <GameEngineCore/GameEngineActor.h>

class IdleWeapon : public GameEngineActor
{
public:
	// constrcuter destructer
	IdleWeapon();
	~IdleWeapon();

	// delete Function
	IdleWeapon(const IdleWeapon& _Other) = delete;
	IdleWeapon(IdleWeapon&& _Other) noexcept = delete;
	IdleWeapon& operator=(const IdleWeapon& _Other) = delete;
	IdleWeapon& operator=(IdleWeapon&& _Other) noexcept = delete;
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
	float4 MoveDir = { 0,0 };

	std::shared_ptr<class GameEngineSpriteRenderer> Sfx;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;
	bool Check = false;
};