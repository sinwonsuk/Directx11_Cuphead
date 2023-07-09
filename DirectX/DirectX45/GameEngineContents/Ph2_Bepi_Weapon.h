#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class Color
{
	Idle,
	Pink,
};


enum class Dir
{
	Left,
	Right
};

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


	std::shared_ptr<class GameEngineSpriteRenderer> GetBullet()
	{
		return Pink_Bullet;
	}
	std::shared_ptr<class GameEngineSpriteRenderer> GetParryEffect()
	{
		return ParryEffect;
	}

	std::shared_ptr<class GameEngineCollision> GetPinkCollision()
	{
		return Pink_Collision;
	}
	std::shared_ptr<class GameEngineCollision> GetPinkCollision2()
	{
		return Pink_Collision2;
	}
	
	Dir directon = Dir::Right;
	Color color = Color::Idle;

protected:
	void Start();
	void Update(float _Delta) override;

private:

	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineCollision> Collision2;

	std::shared_ptr<class GameEngineCollision> Pink_Collision;
	std::shared_ptr<class GameEngineCollision> Pink_Collision2;


	std::shared_ptr<class GameEngineCollision> PinkCollision;
	std::shared_ptr<class GameEngineSpriteRenderer> ParryEffect;

	std::shared_ptr<class GameEngineSpriteRenderer> Bullet_Stop;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet_Destroy;

	std::shared_ptr<class GameEngineSpriteRenderer> Pink_Bullet_Stop;
	std::shared_ptr<class GameEngineSpriteRenderer> Pink_Bullet;
	std::shared_ptr<class GameEngineSpriteRenderer> Pink_Bullet_Destroy;

	
	int AttackCheck = 0;
	bool CollisionCheck = false;
	bool BulletCheck = false;
	bool MoveDirCheck = false;
	bool ColorCheck = false;
	float4 MoveDir4 = { 0,0 };
	float4 MoveDir = { 1,0 };

};

