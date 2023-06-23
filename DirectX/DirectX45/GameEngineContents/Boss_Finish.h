#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Boss_Finish : public GameEngineActor
{
public:
	// constrcuter destructer
	Boss_Finish();
	~Boss_Finish();

	// delete Function
	Boss_Finish(const Boss_Finish& _Other) = delete;
	Boss_Finish(Boss_Finish&& _Other) noexcept = delete;
	Boss_Finish& operator=(const Boss_Finish& _Other) = delete;
	Boss_Finish& operator=(Boss_Finish&& _Other) noexcept = delete;
	float4 SetMoveDir(const float4& _MoveDir)
	{
		MoveDir = _MoveDir;
		return MoveDir;
	}

	std::shared_ptr<class GameEngineSpriteRenderer> GetSfx()
	{
		return Sfx;
	}
	std::shared_ptr<class GameEngineSpriteRenderer> GetFinish()
	{
		return Finish;
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
	float4 MoveDir = { 0,0 };
	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineSpriteRenderer> Sfx;
	std::shared_ptr<class GameEngineSpriteRenderer> Finish;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_dog_bowl_shoot_lines;
	float4 Gravity = { 0,0 };



	float4 LeftMoveDir = { -0.5,1 };
	float4 MiddleMoveDir = { 0,1 };
	float4 RightMoveDir = { 0.5,1 };


	int ColorCheck = 0;

	bool HeightCheck = false;

	bool CollisionCheck = false;
	int DirCheck = false;
};


