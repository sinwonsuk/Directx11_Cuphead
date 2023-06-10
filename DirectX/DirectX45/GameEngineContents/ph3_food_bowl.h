#pragma once
#include <GameEngineCore/GameEngineActor.h>

class ph3_food_bowl : public GameEngineActor
{
public:
	// constrcuter destructer
	ph3_food_bowl();
	~ph3_food_bowl();

	// delete Function
	ph3_food_bowl(const ph3_food_bowl& _Other) = delete;
	ph3_food_bowl(ph3_food_bowl&& _Other) noexcept = delete;
	ph3_food_bowl& operator=(const ph3_food_bowl& _Other) = delete;
	ph3_food_bowl& operator=(ph3_food_bowl&& _Other) noexcept = delete;
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
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;
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

