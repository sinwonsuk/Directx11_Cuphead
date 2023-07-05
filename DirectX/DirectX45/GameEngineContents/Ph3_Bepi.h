#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Ph3_Bepi_Weapon.h"
enum class Ph3_Bepi_State
{
	BossIntro,
	BossIdle,
	BossRightAttack,
	BossLeftAttack, 


	BossRightFinishAttack,
	BossLeftIdle,
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

	void RightStartAttackUpdate(float _Time);
	void RightRunAttackUpdate(float _Time);
	void RightFinishAttackUpdate(float _Time);
	void LeftIdleUpdate(float _Time);

	void BossFinsihUpdate(float _Time);
	void UnloadUpdate(float _Time);
	static int Hp;
	static bool Finish;



	

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	
	int RandomPos = 0;

	std::vector<std::shared_ptr<Ph3_Bepi_Weapon>> Bullets;

	Ph3_Bepi_State StateValue = Ph3_Bepi_State::BossIntro;

	std::shared_ptr<class GameEngineSpriteRenderer> Green_Horse_Attack;
	std::shared_ptr<class GameEngineSpriteRenderer> Yellow_Horse_Attack;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase3_Idle;
	std::shared_ptr<class GameEngineSpriteRenderer> Green_Horse_Head;
	std::shared_ptr<class GameEngineSpriteRenderer> Yellow_Horse_Head;
	std::shared_ptr<class GameEngineSpriteRenderer> Green_Horse_Body;
	std::shared_ptr<class GameEngineSpriteRenderer> Yellow_Horse_Body;



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

