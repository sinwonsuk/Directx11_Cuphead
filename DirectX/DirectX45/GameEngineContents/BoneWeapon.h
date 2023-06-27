#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BoneWeapon : public GameEngineActor
{
public:
	// constrcuter destructer
	BoneWeapon();
	~BoneWeapon();

	// delete Function
	BoneWeapon(const BoneWeapon& _Other) = delete;
	BoneWeapon(BoneWeapon&& _Other) noexcept = delete;
	BoneWeapon& operator=(const BoneWeapon& _Other) = delete;
	BoneWeapon& operator=(BoneWeapon&& _Other) noexcept = delete;
	float4 SetMoveDir(const float4& _MoveDir)
	{
		MoveDir = _MoveDir;
		return MoveDir;
	}
	float SetTime(const float& _Time)
	{
		Time = _Time;
		return Time;
	}

	int SetCheck(const int& _Check)
	{
		Check = _Check;
		return Check;
	}
	
	std::shared_ptr<class GameEngineSpriteRenderer> GetBullet()
	{
		return Bullet;
	}
	std::shared_ptr<class GameEngineCollision> GetCollision()
	{
		return Collision;
	}
	std::shared_ptr<class GameEngineCollision> GetPinkCollision()
	{
		return PinkCollision;
	}




protected:
	void Start();
	void Update(float _Delta) override;

private:
	float4 MoveDir = { 1,0 };
	bool CollisionCheck = false;
	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineCollision> PinkCollision;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;
	int BulletCheck = 0;
	int a = 0;
	int b = 0;
	int Check = 0;
	float Time = 0;

};

