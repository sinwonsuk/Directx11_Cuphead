#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class Ph4_Penguin_Dir
{
	Left,
	Right

};
class Ph4_Penguin : public GameEngineActor
{
public:
	// constrcuter destructer
	
	float SetStopPos(float _StopPos)
	{
		StopPos = _StopPos;
		return StopPos;
	}
	Ph4_Penguin_Dir dir = Ph4_Penguin_Dir::Left;

	bool DownCheck = false;

	int YellowPattern = 0;

protected:
	void Start();
	void Update(float _Delta) override;
	


private:

	float StopPos = 0;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_clapspark;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_clap;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_idle;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_roll_Jump;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_roll_ground;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_roll;

	std::shared_ptr<class GameEngineCollision> Collision;
	float Speed = 500;
	bool MoveCheck = false;
	bool CoiisionCheck = false;
	bool Stop = false;


};

