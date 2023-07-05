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



	


protected:
	void Start();
	void Update(float _Delta) override;

private:

	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineCollision> PinkCollision;
	std::shared_ptr<class GameEngineSpriteRenderer> ParryEffect;

	std::shared_ptr<class GameEngineSpriteRenderer> Bullet_Stop;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;



	int AttackCheck = 0;

	bool MoveDirCheck = false;

	float4 MoveDir4 = { 0,0 };
	float4 MoveDir = { 0,0 };

};

