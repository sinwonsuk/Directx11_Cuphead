#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineSound.h>
enum class Ph2_Bepi_State
{
	BossIntro,
	BossIdle,
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
	void BossFinishUpdate(float _Time);

	void LevelChangeStart() override;

	void ChangeState(Ph2_Bepi_State _State);

	


	

	
	
	static bool Finish;




protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	int Hp = 50;
	
	int AttackCheck = 0;
	int AttackColor = 0; 
	
	Ph2_Bepi_State StateValue = Ph2_Bepi_State::BossIntro;

	GameEngineSoundPlayer Intro;
	GameEngineSoundPlayer Attack;


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

	std::shared_ptr<class GameEngineSpriteRenderer> BossExploision;


	std::shared_ptr<class GameEngineSpriteRenderer> helium_pipe_puff;
	std::shared_ptr<class GameEngineSpriteRenderer> helium_pipe_puff2;

	float helium_pipe_puff_Time = 0; 

	bool helium_pipe_puff_Cehck = false;

	float4 Boss_Exploision_Pos = { 0,0 }; 
	bool Boss_Exploision_Check = false;
	int Boss_Exploision_Number = 0;


	int helium_pipe_puff_location = 0;
	bool CollisonCheck = false;

	bool Sound_Intro_Check = false;
	bool Sound_Attack_Check = false;

};

