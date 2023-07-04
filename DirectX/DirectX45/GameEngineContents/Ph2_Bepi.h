#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class Ph2_Bepi_State
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

class Ph2_Bepi : public GameEngineActor
{
public:
	// constrcuter destructer
	Ph2_Bepi();
	~Ph2_Bepi();

	// delete Function
	Ph2_Bepi(const Ph2_Bepi& _Other) = delete;
	Ph2_Bepi(Ph2_Bepi&& _Other) noexcept = delete;
	Ph2_Bepi& operator=(const Ph2_Bepi& _Other) = delete;
	Ph2_Bepi& operator=(Ph2_Bepi&& _Other) noexcept = delete;

	void UpdateState(float _Time);

	void AnimationCheck(const std::string_view& _AnimationName);

	void BossIdleUpdate(float _Time);
	void BossIntroUpdate(float _Time);
	

	void LevelChangeStart() override;

	void ChangeState(Ph2_Bepi_State _State);

	


	

	
	static int Hp;
	static bool Finish;




protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	
	
	int AttackCheck = 0;

	
	Ph2_Bepi_State StateValue = Ph2_Bepi_State::BossIntro;

	


	std::shared_ptr<class GameEngineSpriteRenderer> Phase2_Intro;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase2_Idle_Head;
	std::shared_ptr<class GameEngineSpriteRenderer> Phase2_Body_Front;

	std::shared_ptr<class GameEngineSpriteRenderer> LeftHeliumBottle;
	std::shared_ptr<class GameEngineSpriteRenderer> RightHeliumBottle;


	std::shared_ptr<class GameEngineSpriteRenderer> Phase2_Intro_Texture;
	std::shared_ptr<class GameEngineSpriteRenderer> LeftHeliumBottle_Texture;
	std::shared_ptr<class GameEngineSpriteRenderer> RightHeliumBottle_Texture;

	std::shared_ptr<class GameEngineSpriteRenderer> LeftHeliumPipes_Intro;
	std::shared_ptr<class GameEngineSpriteRenderer> RightHeliumPipes_Intro;

	std::shared_ptr<class GameEngineSpriteRenderer> Helium_Tank_Back;

	std::shared_ptr<class GameEngineSpriteRenderer> Helium_Tank_Front;
	std::shared_ptr<class GameEngineCollision> Collision;






};

