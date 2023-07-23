#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Ph3_Bepi_Weapon.h"
#include <GameEnginePlatform/GameEngineSound.h>
enum class Ph3_Bepi_State
{
	BossIntro,
	BossIdle,
	BossRightAttack,
	BossLeftAttack, 

	Left_Green_Finish,
	Left_Yellow_Finish,
	Right_Green_Finish,
	Right_Yellow_Finish,

	BossFinish_Finish,
	BossFinish,

};

class Ph3_Bepi : public GameEngineActor
{
public:
	// constrcuter destructer
	Ph3_Bepi();
	~Ph3_Bepi();

	// delete Function
	Ph3_Bepi(const Ph3_Bepi& _Other) = delete;
	Ph3_Bepi(Ph3_Bepi&& _Other) noexcept = delete;
	Ph3_Bepi& operator=(const Ph3_Bepi& _Other) = delete;
	Ph3_Bepi& operator=(Ph3_Bepi&& _Other) noexcept = delete;

	void UpdateState(float _Time);

	void AnimationCheck(const std::string_view& _AnimationName);

	void BossIdleUpdate(float _Time);
	void BossIntroUpdate(float _Time);
	
	void LevelChangeStart() override;

	void ChangeState(Ph3_Bepi_State _State);

	void LeftAttackUpdate(float _Time);
	void RightAttackUpdate(float _Time);
	void BossFinishUpdate(float _Time);

	void BossFinish_Finish_Update(float _Time);

	
	static bool Finish;



	

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	int Hp = 10; 
	int RandomPos = 0;

	GameEngineSoundPlayer Attack;
	GameEngineSoundPlayer Attack2;
	GameEngineSoundPlayer Death_Sound;
	GameEngineSoundPlayer Fail;

	

	std::vector<std::shared_ptr<Ph3_Bepi_Weapon>> Bullets;

	Ph3_Bepi_State StateValue = Ph3_Bepi_State::BossIntro;

	std::shared_ptr<class GameEngineSpriteRenderer> Green_Horse_Attack;
	std::shared_ptr<class GameEngineSpriteRenderer> Yellow_Horse_Attack;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase3_Idle;
	std::shared_ptr<class GameEngineSpriteRenderer> Green_Horse_Head;
	std::shared_ptr<class GameEngineSpriteRenderer> Yellow_Horse_Head;
	std::shared_ptr<class GameEngineSpriteRenderer> Green_Horse_Body;
	std::shared_ptr<class GameEngineSpriteRenderer> Yellow_Horse_Body;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_ph3_horse_spit;

	std::shared_ptr<class GameEngineSpriteRenderer> Bepi_boss_explosion;
	std::shared_ptr<class GameEngineCollision> Collision;

	float Time = 0;
	float Time2 = 0;
	int BulletNumber = 0;
	float BulletStopPos = 200;
	float Left_BulletStopPos = -200;
	int BulletCheck = 0;

	int GreenBulletCheck = 0; 
	bool FinishCheck = false;
	bool CollisonCheck =false;

	int YellowORGreenCheck = 0;
	int LeftORRightCheck = 0;
	int YellowPattern = 0; 
	int Boss_Exploision_Number = 0; 
	bool Boss_Exploision_Check = false;
	float4 Boss_Exploision_Pos = {0,0};

	bool Sound_Fail_Check = false;
	bool Sound_Death_Check = false;
	bool Sound_Attack_Check = false;
	bool Sound_Attack_Check2 = false;


};

