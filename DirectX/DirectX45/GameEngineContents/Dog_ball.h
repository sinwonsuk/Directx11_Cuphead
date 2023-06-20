#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Dog_ball : public GameEngineActor
{
public:
	// constrcuter destructer
	Dog_ball();
	~Dog_ball();

	// delete Function
	Dog_ball(const Dog_ball& _Other) = delete;
	Dog_ball(Dog_ball&& _Other) noexcept = delete;
	Dog_ball& operator=(const Dog_ball& _Other) = delete;
	Dog_ball& operator=(Dog_ball&& _Other) noexcept = delete;

	//void ChangeState(NpcAirplaneState _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	float4 MoveDir = { 0,0 };
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
	
	float4 TestColor;

private:
//	NpcAirplaneState StateValue = NpcAirplaneState::Intro;

	std::shared_ptr<class GameEngineCollision> LeftCollision;

	std::shared_ptr<class GameEngineCollision> RightCollision;

	std::shared_ptr<class GameEngineCollision> MiddleCollision;
	std::shared_ptr<class GameEngineSpriteRenderer> Left_Ball;
	std::shared_ptr<class GameEngineSpriteRenderer> Middle_Ball;
	std::shared_ptr<class GameEngineSpriteRenderer> Right_Ball;
	float4 Gravity = { 0,0 };
	float4 LeftMoveDir = {-0.5,1};
	float4 MiddleMoveDir = { 0,1 };
	float4 RightMoveDir = { 0.5,1 };


};


