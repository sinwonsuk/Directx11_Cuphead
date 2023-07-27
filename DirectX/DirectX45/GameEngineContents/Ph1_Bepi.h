#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineSound.h>
enum class Ph1_Beppi_State
{
	BossIntro,
	BossIntro2,
	BossIntro3,
	BossIdle, 

	BossLeftStartAttack,
	BossLeftRunAttack,
	BossLeftFinishAttack,
	BossRightIdle,

	BossRightStartAttack,
	BossRightRunAttack,
	BossRightFinishAttack,
	BossLeftIdle,
	BossFinish,

};

class Ph1_Bepi : public GameEngineActor
{
public:
	// constrcuter destructer
	Ph1_Bepi();
	~Ph1_Bepi();
	GameEngineSoundPlayer BG;
	// delete Function
	Ph1_Bepi(const Ph1_Bepi& _Other) = delete;
	Ph1_Bepi(Ph1_Bepi&& _Other) noexcept = delete;
	Ph1_Bepi& operator=(const Ph1_Bepi& _Other) = delete;
	Ph1_Bepi& operator=(Ph1_Bepi&& _Other) noexcept = delete;

	void UpdateState(float _Time);

	void AnimationCheck(const std::string_view& _AnimationName);

	void BossIdleUpdate(float _Time);
	void BossIntroUpdate(float _Time);
	void BossIntro2Update(float _Time);
	void BossIntro3Update(float _Time);

	void LevelChangeStart() override;

	void ChangeState(Ph1_Beppi_State _State);

	void LeftStartAttackUpdate(float _Time);
	void LeftRunAttackUpdate(float _Time);
	void LeftFinishAttackUpdate(float _Time);

	void RightIdleUpdate(float _Time);


	void RightStartAttackUpdate(float _Time);
	void RightRunAttackUpdate(float _Time);
	void RightFinishAttackUpdate(float _Time);
	void LeftIdleUpdate(float _Time);

	void BossFinsihUpdate(float _Time);
	void UnloadUpdate(float _Time);

	static bool Finish;




protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:

	GameEngineSoundPlayer Dash;
	GameEngineSoundPlayer Death_Sound;
	GameEngineSoundPlayer Intro_Start;
	GameEngineSoundPlayer End;
	GameEngineSoundPlayer Move;
	GameEngineSoundPlayer Intro;
	bool FinishDown = false;
	bool DuckStart = false;
	float introFinish = 0;
	float DuckTime = 1.5f;

	float RunSpeed = 1300;
	float LastSpeed = 1000;
	float Speed = 600;
	float Speed1 = 800;

	int IdleCheck = 0;
	Ph1_Beppi_State StateValue = Ph1_Beppi_State::BossIntro;

	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> Loading;
	std::shared_ptr<class GameEngineSpriteRenderer> Beppi_Intro;
	std::shared_ptr<class GameEngineSpriteRenderer> Beppi_Intro2;

	std::shared_ptr<class GameEngineSpriteRenderer> Ready;

	std::shared_ptr<class GameEngineCollision> Collision;
	std::shared_ptr<class GameEngineCollision> Collision2;
	int FinishCheck = 0;
	bool CollisonCheck = false;
	int Random_Duck = 0; 
	bool Sound_Intro_Check = false;
	bool Sound_Death_Check = false;
	bool Sound_End_Check = false;
	bool Sound_Dash_Check = false;
	bool Sound_Dash_Check2 = false;
	bool Sound_Dash_Check3 = false;

};