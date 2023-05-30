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


	std::shared_ptr<class GameEngineSpriteRenderer> Ball_Monster;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Front;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Reg;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Spin;

	std::shared_ptr<class GameEngineSpriteRenderer> Npc;
	std::shared_ptr<class GameEngineSpriteRenderer> C_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> D_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro3;

	int IntroCheck = 0;



};


