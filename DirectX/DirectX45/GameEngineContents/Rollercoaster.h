#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Rollercoaster : public GameEngineActor
{
public:
	// constrcuter destructer
	Rollercoaster();
	~Rollercoaster();

	// delete Function
	Rollercoaster(const Rollercoaster& _Other) = delete;
	Rollercoaster(Rollercoaster&& _Other) noexcept = delete;
	Rollercoaster& operator=(const Rollercoaster& _Other) = delete;
	Rollercoaster& operator=(Rollercoaster&& _Other) noexcept = delete;



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

	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Back;
	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Back2;
	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Front;


	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Frontcart;

	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Frontcart2;
	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Midcart_Blue;
	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Midcart_Red;
	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Midcart_Red_2;
	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Midcart2;
	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Midcart2_2;
	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Midcart2_3;
	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Passenger;
	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Passenger2;
	std::shared_ptr<class GameEngineSpriteRenderer> Rollercoaster_Seat;

	int ColorCheck = 0;


};

