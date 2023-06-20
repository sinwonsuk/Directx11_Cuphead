#pragma once
#include <GameEngineCore/GameEngineActor.h>

class dogfight_catshoot_yarnball : public GameEngineActor
{
public:
	// constrcuter destructer
	dogfight_catshoot_yarnball();
	~dogfight_catshoot_yarnball();

	// delete Function
	dogfight_catshoot_yarnball(const dogfight_catshoot_yarnball& _Other) = delete;
	dogfight_catshoot_yarnball(dogfight_catshoot_yarnball&& _Other) noexcept = delete;
	dogfight_catshoot_yarnball& operator=(const dogfight_catshoot_yarnball& _Other) = delete;
	dogfight_catshoot_yarnball& operator=(dogfight_catshoot_yarnball&& _Other) noexcept = delete;
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

	float SetCheck(const float& _Check)
	{
		Check = _Check;
		return Check;
	}

	std::shared_ptr<class GameEngineSpriteRenderer> GetBullet()
	{
		return Bullet;
	}

protected:
	void Start();
	void Update(float _Delta) override;

private:
	float4 MoveDir = { 1,0 };
	std::shared_ptr<class GameEngineCollision> Collision;

	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;
	int Check = 0;
	float Time = 0;

};