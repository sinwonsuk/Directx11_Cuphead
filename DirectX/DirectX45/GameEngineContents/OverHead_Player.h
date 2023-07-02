#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class OverHead_PlayerState
{
	DownIdle,
	UpIlde,
	RightIdle,
	LeftIdle,

	LeftMove,
	DownMove,
	RightMove,
	UpMove,

    Right_diagonal_Up,
    Right_diagonal_Up_Move,
    Right_diagonal_Down,
    Right_diagonal_Down_Move,

	Left_diagonal_Up,
	Left_diagonal_Up_Move,
	Left_diagonal_Down,
	Left_diagonal_Down_Move,


};
// Ό³Έν :
class OverHead_Player : public GameEngineActor
{
public:

	//static Player* MainPlayer;
	OverHead_Player();
	~OverHead_Player();

	// delete Function
	OverHead_Player(const OverHead_Player& _Other) = delete;
	OverHead_Player(OverHead_Player&& _Other) noexcept = delete;
	OverHead_Player& operator=(const OverHead_Player& _Other) = delete;
	OverHead_Player& operator=(OverHead_Player&& _Other) noexcept = delete;

	void ChangeState(OverHead_PlayerState _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	void AnimationCheck(const std::string_view& _AnimationName, bool Force, size_t Frame);

	void DownIldeUpdate(float _Time);
	void UpIldeUpdate(float _Time);
	void RightIdleUpdate(float _Time);
	void LeftIdleUpdate(float _Time);

	void LeftMoveUpdate(float _Time);
	void DownMoveUpdate(float _Time);
	void RightMoveUpdate(float _Time);
	void UpMoveUpdate(float _Time);

	void Right_diagonal_Up_Update(float _Time);
	void Right_diagonal_Up_Move_Update(float _Time);
	void Right_diagonal_Down_Update(float _Time);
	void Right_diagonal_Down_Move_Update(float _Time);

	void Left_diagonal_Up_Update(float _Time);
	void Left_diagonal_Up_Move_Update(float _Time);
	void Left_diagonal_Down_Update(float _Time);
	void Left_diagonal_Down_Move_Update(float _Time);




protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	OverHead_PlayerState StateValue = OverHead_PlayerState::DownIdle;
	float Speed = 300.0f;
	float4 MoveDir = { 0,0 };

	std::shared_ptr<class GameEngineSpriteRenderer> Player;
	std::shared_ptr<class GameEngineSpriteRenderer> Render1;
	std::shared_ptr<class GameEngineSpriteRenderer> Render2;
	std::shared_ptr<class GameEngineCollision> Collision;

	int UpCheck = 0;
	int GravityCheck = 0;
	int RightCheck = 0;
	int LeftCheck = 0;

	int Right_diagonal_Check = 0;
	int Right_diagonal_Down_Check = 0;
	int	Left_diagonal_Check = 0;
	int	Left_diagonal_Down_Check = 0;


	bool Right_diagonal_Move= false;
	bool Right_diagonal_Down_Move = false;
	bool Left_diagonal_Move = false;
	bool Left_diagonal_Down_Move = false;




	bool UpMove = false;
	bool RightMove = false;
	bool CheckCamera = false;
	bool LeftMove = false;
	bool Gravity = false;

};

