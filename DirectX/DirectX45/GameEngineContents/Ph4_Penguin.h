#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class Ph4_Penguin_State
{
	Intro,
	Ground,
	Jump,
	Idle,
	Attack, 

};
enum class Ph4_Penguin_Dir
{
	Left,
	Right

};
class Ph4_Penguin : public GameEngineActor
{
public:

	Ph4_Penguin();
	~Ph4_Penguin();

	// delete Function
	Ph4_Penguin(const Ph4_Penguin& _Other) = delete;
	Ph4_Penguin(Ph4_Penguin&& _Other) noexcept = delete;
	Ph4_Penguin& operator=(const Ph4_Penguin& _Other) = delete;
	Ph4_Penguin& operator=(Ph4_Penguin&& _Other) noexcept = delete;




	void UpdateState(float _Time);
	void ChangeState(Ph4_Penguin_State _State);
	
	void IntroUpdate(float _Time);
	void GroundUpdate(float _Time);
	void IdleUpdate(float _Time);
	void JumpUpdate(float _Time);
	void AttackUpdate(float _Time);

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
	Ph4_Penguin_State StateValue = Ph4_Penguin_State::Intro;
	float StopPos = 0;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_clapspark;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_clap;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_idle;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_roll_Jump;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_roll_ground;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_penguin_roll;

	std::shared_ptr<class GameEngineCollision> Collision;
	float Speed = 500;
	
	int IdleNumber = 0; 
	bool MoveCheck = false;
	float4 CurPos = {0.0f,0.0f};
};

