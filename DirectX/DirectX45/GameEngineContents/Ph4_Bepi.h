#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class Ph4_Bepi_State
{
	BossIntro,
	BossIdle,
	BossRightAttack,
	BossLeftAttack,


	BossRightFinishAttack,
	BossLeftIdle,
	BossFinish,

};

class Ph4_Bepi : public GameEngineActor
{
public:
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

	
	static int Hp;
	static bool Finish;





protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:

	int RandomPos = 0;

	Ph4_Bepi_State StateValue = Ph4_Bepi_State::BossIntro;

	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Intro;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Lights;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Idle;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Attack_Start;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Attack_Middle;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase4_Attack_End;




	std::shared_ptr<class GameEngineCollision> Collision;
	float Time = 0;
	float Time2 = 0;
	int BulletNumber = 0;
	float BulletStopPos = 200;
	float Left_BulletStopPos = -200;
	int BulletCheck = 0;

	int GreenBulletCheck = 0;


	int YellowORGreenCheck = 0;
	int LeftORRightCheck = 0;
	int YellowPattern = 0;

};

