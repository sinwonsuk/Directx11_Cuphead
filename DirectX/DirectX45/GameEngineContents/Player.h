#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class PlayerState
{
	Idle,
	Up,
	Run,
	Jump,
	Attack,
	Duck,
	Parry,
	IdleAim,
	UpAim, 
	DownAim, 
	UpAimAttack,
	UpAimAttackPre,
	IdleAimAttackPre,
	IdleAimAttack, 
	DiagonalUpAim,
	DiagonalDownAim,
	Dash,
	IdleAttackPre,
	Idleattack,
	RunAttack, 
	DiagonalUpAttack,
	DiagonalUpAttackPre,
	DiagonalDownAttack,
	DiagonalDownAttackPre,
	UpAttack, 
	UpAttackPre, 
	DiagonalUpRunAttack,
	DuckAttack, 
	DuckAttackPre, 
	DownAttack,
	DownAttackPre,
};
// Ό³Έν :
class Player : public GameEngineActor
{
public:

	static Player* MainPlayer;
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void ChangeState(PlayerState _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	void AnimationCheck(const std::string_view& _AnimationName,bool Force, int Frame);

	void IdleUpdate(float _Time);
	void RunUpdate(float _Time);
	void JumpUpdate(float _Time);
	void DuckUpdate(float _Time);
	void ParryUpdate(float _Time);
	void UpAimUpdate(float _Time);
	void DownAimUpdate(float _Time);
	void IdleAimUpdate(float _Time);
	void DiagonalUpAimUpdate(float _Time);
	void DiagonalDownAimUpdate(float _Time);
	void DashUpdate(float _Time);
	void IdleAttackUpdate(float _Time);
	void IdleAttackPreUpdate(float _Time);
	void RunAttackUpdate(float _Time);
	void DiagonalUpAttackUpdate(float _Time);
	void DiagonalDownAttackUpdate(float _Time);
	void DiagonalUpRunAttackUpdate(float _Time);
	void UpUpdate(float _Time);
	void UpAttackUpdate(float _Time);
	void UpAttackPre(float _Time);
	void DuckAttackUpdate(float _Time);
	void DuckAttackPreUpdate(float _Time);
	void DiagonalDownAttackPreUpdate(float _Time); 
	void DiagonalUpAttackPreUpdate(float _Time);
	void IdleAimAttackUpdate(float _Time);
	void IdleAimAttackPreUpdate(float _Time);
	void UpAimAttackUpdate(float _Time);
	void UpAimAttackPreUpdate(float _Time);
	void DownAttackUpdate(float _Time);
	void DownAttackPreUpdate(float _Time);
	bool GetGravity()
	{
		return Gravity;
	}
	bool SetGravity(bool _Gravity)
	{
		Gravity = _Gravity;
		return Gravity;
	}


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	PlayerState StateValue = PlayerState::Idle;
	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> Render0;
	std::shared_ptr<class GameEngineSpriteRenderer> Render1;
	std::shared_ptr<class GameEngineSpriteRenderer> Render2;
	std::shared_ptr<class GameEngineCollision> Collision;
	int GravityCheck = 0; 
	int RightCheck = 0;
	int LeftCheck = 0;
	float Speed = 300;
	float GravitySpeed = 400;
	float JumpSpeed = 1200;
	bool Gravity = false;
	bool RightMove = true;
	bool LeftMove = true;
	bool JumpCheck = false;
	bool CheckCamera = false;
	bool test = false;
	bool DashCheck = true;

	bool DashEffectCheck = false;
	int EffectCheck = 0; 
	int Frame = 0;
	float BulletTime = 0;
	float RunTime = 0;
	int Bulletlocation = 0;

		


};

