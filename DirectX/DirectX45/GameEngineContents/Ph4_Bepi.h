#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class Ph4_Bepi_State
{
	BossIntro,
	BossIdle,
	
	BossAttackStart,
	BossAttackMiddle,
	BossAttackEnd,
	BossFinish,


	
};

class Ph4_Bepi : public GameEngineActor
{
public:

	static Ph4_Bepi* ph4_Bepi;
	// constrcuter destructer
	Ph4_Bepi();
	~Ph4_Bepi();

	// delete Function
	Ph4_Bepi(const Ph4_Bepi& _Other) = delete;
	Ph4_Bepi(Ph4_Bepi&& _Other) noexcept = delete;
	Ph4_Bepi& operator=(const Ph4_Bepi& _Other) = delete;
	Ph4_Bepi& operator=(Ph4_Bepi&& _Other) noexcept = delete;

	void UpdateState(float _Time);

	void AnimationCheck(const std::string_view& _AnimationName);

	void BossIdleUpdate(float _Time);
	void BossIntroUpdate(float _Time);

	void LevelChangeStart() override;

	void ChangeState(Ph4_Bepi_State _State);

	void BossFinsihUpdate(float _Time);
	void BossAttackStartUpdate(float _Time);
	void BossAttackMiddleUpdate(float _Time);
	void BossAttackEndUpdate(float _Time);
	Ph4_Bepi_State StateValue = Ph4_Bepi_State::BossIntro;
	int Hp = 0;




	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Idle;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	
	int AttackNumber = 0; 
	int RandomPos = 0;

	

	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Intro;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Intro_Spin;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Lights;
	
	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Attack_Start;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Attack_Middle;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Attack_End;
	std::shared_ptr<class GameEngineSpriteRenderer> umbrella_bk;
	std::shared_ptr<class GameEngineSpriteRenderer> Bepi_boss_explosion;
	float4 Boss_Exploision_Pos = {};
	bool Boss_Exploision_Check = false;
	int Boss_Exploision_Number = 0; 
	std::shared_ptr<class GameEngineCollision> Collision;
	bool test = false;
	bool Swing_Platform_Intro = false;

	float Platform = 0;

};