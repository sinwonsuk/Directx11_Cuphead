#pragma once
#include <GameEngineCore/GameEngineActor.h>


class Ph4_Penguin_Weapon : public GameEngineActor
{
public:
	// constrcuter destructer
	Ph4_Penguin_Weapon();
	~Ph4_Penguin_Weapon();

	// delete Function
	Ph4_Penguin_Weapon(const Ph4_Penguin_Weapon& _Other) = delete;
	Ph4_Penguin_Weapon(Ph4_Penguin_Weapon&& _Other) noexcept = delete;
	Ph4_Penguin_Weapon& operator=(const Ph4_Penguin_Weapon& _Other) = delete;
	Ph4_Penguin_Weapon& operator=(Ph4_Penguin_Weapon&& _Other) noexcept = delete;

	


protected:
	void Start();
	void Update(float _Delta) override;

private:
	float4 MoveDir = { 1,0 };

	bool MoveDirCheck = false;
	bool CollisionCheck = false;
	std::shared_ptr<class GameEngineSpriteRenderer> ParryEffect;
	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineCollision> PinkCollision;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;
	int BulletCheck = 0;
	int a = 0;
	int b = 0;
	int Check = 0;
	float Time = 0;

};



