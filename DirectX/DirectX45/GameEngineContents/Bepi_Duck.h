#pragma once

#include <GameEngineCore/GameEngineActor.h>

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

	

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	float4 MoveDir = { -1,-1 };
	float4 MoveDir2 = { -1,1 };
	std::shared_ptr<class GameEngineCollision> LeftCollision;

	std::shared_ptr<class GameEngineCollision> RightCollision;

	std::shared_ptr<class GameEngineCollision> MiddleCollision;

	std::shared_ptr<class GameEngineSpriteRenderer> DuckHead;
	std::shared_ptr<class GameEngineSpriteRenderer> DuckBody;
	std::shared_ptr<class GameEngineSpriteRenderer> DuckSpin;

	std::shared_ptr<class GameEngineSpriteRenderer> P_DuckHead;
	std::shared_ptr<class GameEngineSpriteRenderer> P_DuckBody;
	std::shared_ptr<class GameEngineSpriteRenderer> P_DuckSpin;

	int ColorCheck = 0;


};
;

