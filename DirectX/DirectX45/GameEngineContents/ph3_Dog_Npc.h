#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class ph3_Dog_Npc_State
{
	Intro,
	Idle,
	Pase1_Attack,
	Pase1_Attack_Reverse,
	Pase2_Attack,
	Pase2_Attack_Reverse,
	Pase3_Attack,
	Pase3_Attack_Reverse,
	Rotation_Attack,
};

class ph3_Dog_Npc : public GameEngineActor
{
public:
	// constrcuter destructer
	ph3_Dog_Npc();
	~ph3_Dog_Npc();

	// delete Function
	ph3_Dog_Npc(const ph3_Dog_Npc& _Other) = delete;
	ph3_Dog_Npc(ph3_Dog_Npc&& _Other) noexcept = delete;
	ph3_Dog_Npc& operator=(const ph3_Dog_Npc& _Other) = delete;
	ph3_Dog_Npc& operator=(ph3_Dog_Npc&& _Other) noexcept = delete;

	void ChangeState(ph3_Dog_Npc_State _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	void Intro2Update(float _Time);
	void IntroUpdate(float _Time);
	void IdleUpdate(float _Time);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	bool ph3_main_boss_Check = false;
	ph3_Dog_Npc_State StateValue = ph3_Dog_Npc_State::Intro;


	std::shared_ptr<class GameEngineSpriteRenderer> ph3_tongue_rotate_camera;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_leader_sideways_body;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_leader_sideways_body_Attack;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_leader_sideways_arms;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_leader_sideways_body_Finish;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_leader_sideways_body_Finish_0;

	std::shared_ptr<class GameEngineSpriteRenderer> ph3_leader_sideways_arms_backer;
	std::shared_ptr<class GameEngineSpriteRenderer> ph3_tongue_rotate_camera_tongue;
	std::shared_ptr<class GameEngineSpriteRenderer> D_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro3;
	std::shared_ptr<class GameEngineCollision> Collision;

	int RotationCheck = 0;
	bool test = false;
};


