#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include "DogAirPlaneManager.h"
enum class DogAirplaneState
{
	Black,
	BossIntro,
	BossIntro2,
	BossIntroRock,
	BossIntroDust,
	bulldog_Idle,
	BossIdleHand,
	noumIntro,
	bulldog_Jump,
	bulldog_Jump_Reverse,
	BossAttackPase1, 
	BossAttackPase2,
	BossAttackPase2Intro,
	Ph1_Finish,
	Unload,
};

class DogAirplane : public GameEngineActor
{
public:
	// constrcuter destructer
	DogAirplane();
	~DogAirplane();

	// delete Function
	DogAirplane(const DogAirplane& _Other) = delete;
	DogAirplane(DogAirplane&& _Other) noexcept = delete;
	DogAirplane& operator=(const DogAirplane& _Other) = delete;
	DogAirplane& operator=(DogAirplane&& _Other) noexcept = delete;

	void BlackUpdate(float _Time); 
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	void BossIdleUpdate(float _Time);
	void BossIntroUpdate(float _Time);
	void BossIntro2Update(float _Time);
	void BossJumpReverseUpdate(float _Time);
	void LevelChangeStart() override;
	void BossAttackPase2IntroUpdate(float _Time);
	void BossAttackPase2AttackUpdate(float _Time);
	void ChangeState(DogAirplaneState _State);
	
	
	void BossAttackPase1Update(float _Time);
	void BossJumpUpdate(float _Time); 
	void Ph1FinishUpdate(float _Time); 

	void UnloadUpdate(float _Time);
	static int Hp;
	static bool Finish;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	GameEngineSoundPlayer BG;
	GameEngineSoundPlayer Intro_Start;
	GameEngineSoundPlayer Intro_SFX;

	std::vector<int> a;
	float CollisionMove = 640;
	bool adsdf = false;

	float DownSpeed = 600;
	float Right_Left_Speed = 50;
	float Speed = 75;
	DogAirplaneState StateValue = DogAirplaneState::BossIntro;

	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> GirlDog;
	std::shared_ptr<class GameEngineSpriteRenderer> dogcopter;
	std::shared_ptr<class GameEngineSpriteRenderer> bulldogIntro;
	std::shared_ptr<class GameEngineSpriteRenderer> dogcopter_hydrant;

	std::shared_ptr<class GameEngineSpriteRenderer> Ph1_Buldog_Death;
	std::shared_ptr<class GameEngineSpriteRenderer> testImage1;
	std::shared_ptr<class GameEngineSpriteRenderer> Buldog_Death_Intro;
	std::shared_ptr<class GameEngineSpriteRenderer> testImage3;

	std::shared_ptr<class GameEngineSpriteRenderer> AirplaneSpin;
	std::shared_ptr<class GameEngineSpriteRenderer> Airplane_Back;
	std::shared_ptr<class GameEngineSpriteRenderer> Airplane_Front;
	std::shared_ptr<class GameEngineSpriteRenderer> Airplane_Wing;
	std::shared_ptr<class GameEngineSpriteRenderer> Airplane_Tail;


	std::shared_ptr<class GameEngineSpriteRenderer> AirplaneFlap_A;
	std::shared_ptr<class GameEngineSpriteRenderer> AirplaneFlap_B;
	std::shared_ptr<class GameEngineSpriteRenderer> AirplaneFlap_C;
	std::shared_ptr<class GameEngineSpriteRenderer> AirplaneFlap_D;



	std::shared_ptr<class GameEngineSpriteRenderer> bulldog_Jump;
	std::shared_ptr<class GameEngineSpriteRenderer> bulldog_Jump_Reverse;
	std::shared_ptr<class GameEngineSpriteRenderer> bulldogIdle;
	std::shared_ptr<class GameEngineSpriteRenderer> Ball_Monster;

	std::shared_ptr<class GameEngineSpriteRenderer> Ready;


	std::shared_ptr<class GameEngineCollision> Collision;
	
	std::shared_ptr<class GameEngineSpriteRenderer> Loading;

	float Pase1_Attack = 500;
	float Ball_Monster_Time = 0;
	float4 CurPos = { 0,0 };

	bool Sound_Intro_Check = false;
	bool Sound_BG_Check = false;


	bool CollisonCheck = false;
	bool Ball_MonsterCheck = false;
	bool Intro_Jump_Check = false;
	bool JumpCheck = false;
	bool AttackCheck = false;

	

	int unloadCheck = 0;
	int PinkBone = 0;
	int bulldogAttackPase1 = 0;
	int Ball_Monster_Random = 0;
	int bulldogIdleCheck = 0;
	int BoneCheck = 0;
	int YarnballCheck = 0;
};
