#pragma once

#include <GameEngineCore/GameEngineActor.h>

enum class DuckCheck
{
	Idle,
	Pink,

};


class Bepi_Duck : public GameEngineActor
{
public:
	
	// constrcuter destructer
	Bepi_Duck();
	~Bepi_Duck();

	// delete Function
	Bepi_Duck(const Bepi_Duck& _Other) = delete;
	Bepi_Duck(Bepi_Duck&& _Other) noexcept = delete;
	Bepi_Duck& operator=(const Bepi_Duck& _Other) = delete;
	Bepi_Duck& operator=(Bepi_Duck&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineSpriteRenderer> GetBullet()
	{
		return P_DuckBody;
	}
	std::shared_ptr<class GameEngineSpriteRenderer> GetParryEffect()
	{
		return ParryEffect;
	}
	std::shared_ptr<class GameEngineCollision> GetPinkCollision()
	{
		return PinkCollision;
	}
	std::shared_ptr<class GameEngineSpriteRenderer> DuckHead;
	std::shared_ptr<class GameEngineSpriteRenderer> DuckBody;
	std::shared_ptr<class GameEngineSpriteRenderer> DuckSpin;

	std::shared_ptr<class GameEngineSpriteRenderer> P_DuckHead;
	std::shared_ptr<class GameEngineSpriteRenderer> P_DuckBody;
	std::shared_ptr<class GameEngineSpriteRenderer> P_DuckSpin;
	std::shared_ptr<class GameEngineCollision> PinkCollision;

	std::shared_ptr<class GameEngineCollision> Body_Pink_Collision;
	std::shared_ptr<class GameEngineCollision> Body_Collision;


	DuckCheck Check = DuckCheck::Idle;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	float4 MoveDir = { -1,-1 };
	float4 MoveDir2 = { -1,1 };
	
	
	bool CollisonCheck = false;

	std::shared_ptr<class GameEngineSpriteRenderer> ParryEffect;
	int ColorCheck = 0;
	bool CollisionCheck = false;

};
;

