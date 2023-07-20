#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineSound.h>
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
	MapOut,
	Fail,
	Hit,
	Ex_DiagonalDown,
	Ex_DiagonalUp,
	Ex_Down,
	Ex_Straight, 
	Ex_Up, 
	PinkObject, 
	TutorlalPotal,
	Death,
	Goast, 
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
	void AnimationCheck(const std::string_view& _AnimationName,bool Force, size_t Frame);

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
	void MapOutUpdate(float _Time); 
	void FailUpdate(float _Time);
	void HitUpdate(float _Time); 
	void PinkObjectUpdate(float _Time);
	void TutorlalPotalUpdate(float _Time);
	void Ex_DiagonalDown_Update(float _Time);
	void Ex_DiagonalUp_Update(float _Time);
	void Ex_Down_Update(float _Time);
	void Ex_Straight_Update(float _Time);
	void Ex_Up_Update(float _Time);
	void DeathUpdate(float _Time);
	void GoastUpdate(float _Time);
	bool GetGravity()
	{
		return Gravity;
	}
	bool SetGravity(bool _Gravity)
	{
		Gravity = _Gravity;
		return Gravity;
	}
	bool GetJumpCheck()
	{
		return JumpCheck;
	}
	bool GetTutorialCheck()
	{
		return TuritualCheck;
	}

	bool SetTutorialCheck(bool _TuritualCheck)
	{
		TuritualCheck = _TuritualCheck;

		return TuritualCheck;
	}
	bool SetCameraCheck(bool _CheckCamera)
	{
		CheckCamera = _CheckCamera;

		return _CheckCamera;
	}


	std::shared_ptr<class GameEngineCollision> GetCollision()
	{
		return Collision;
	}
	PlayerState GetStateValue()
	{
		return StateValue; 
	}




	std::shared_ptr<class GameEngineSpriteRenderer> GetPlayer()
	{
		return Render0;
	}
	bool RightMove = true;
	int Hp = 3;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:

	GameEngineSoundPlayer Jump;
	GameEngineSoundPlayer Dash;
	GameEngineSoundPlayer Attack;
	GameEngineSoundPlayer Attack_Loop;
	GameEngineSoundPlayer Parry;
	PlayerState StateValue = PlayerState::Idle;
	float Angle = 0.0f;


	std::shared_ptr<class GameEngineSpriteRenderer> Render0;
	std::shared_ptr<class GameEngineSpriteRenderer> Black_BG;
	std::shared_ptr<class GameEngineSpriteRenderer> Dided;
	std::shared_ptr<class GameEngineSpriteRenderer> Exit;
	std::shared_ptr<class GameEngineSpriteRenderer> HitEffect;
	std::shared_ptr<class GameEngineSpriteRenderer> Render1;
	std::shared_ptr<class GameEngineSpriteRenderer> Render2;
	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineCollision> Collision2;
	bool DiedAiphaColor = false;
	float DiedAlpha = 1.0f;
	int DownBlockCheck = 0; 
	int GravityCheck = 0; 
	int RightCheck = 0;
	int LeftCheck = 0;
	int HitNumber = 0;
	
	float HitTime = 0;
	float Speed = 400;
	float GravitySpeed = 1000;
	float JumpSpeed = 1200;
	 
	bool Sound_Jump_Check = false;
	bool Sound_Attack_Loop_Check = false;
	bool Sound_Dash_Check = false;
	bool Sound_Parry_Check = false;

	bool DeathCheck = false;
	bool Block = false;
	bool Gravity = true;
	
	bool PinkObject = false;
	bool LeftMove = true;
	bool JumpCheck = false;
	bool CheckCamera = false;
	bool TuritualCheck = false;
	bool test = false;
	bool DashCheck = true;
	bool DownCheck = false;
	bool HitCheck = false;
	bool Ex_Attack_Check = true;
	bool DashEffectCheck = false;
	bool TutorialObjectCheck = false;
	float CurPos_y = 0;
	int EffectCheck = 0; 
	size_t Frame = 0;
	float BulletTime = 0;
	float ExBulletTime = 0; 
	float RunTime = 0;
	int Bulletlocation = 0;

		


};

