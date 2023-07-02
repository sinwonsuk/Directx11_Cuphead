#pragma once
#include <GameEngineCore/GameEngineActor.h>

class OverHead_Player : public GameEngineActor
{
public:

	// constrcuter destructer
	OverHead_Player();
	~OverHead_Player();

	// delete Function
	OverHead_Player(const OverHead_Player& _Other) = delete;
	OverHead_Player(OverHead_Player&& _Other) noexcept = delete;
	OverHead_Player& operator=(const OverHead_Player& _Other) = delete;
	OverHead_Player& operator=(OverHead_Player&& _Other) noexcept = delete;

	



protected:
	void Start();
	void Update(float _Delta) override;

private:
	float4 MoveDir = { 0,0 };
	std::shared_ptr<class GameEngineCollision> Collision;
	
	std::shared_ptr<class GameEngineSpriteRenderer> Player;

	int ColorCheck = 0;
	bool CollisionColor = false;
	bool ColorCollisionCheck = false;
	bool CollisionCheck = false;
	bool Check = false;
};
