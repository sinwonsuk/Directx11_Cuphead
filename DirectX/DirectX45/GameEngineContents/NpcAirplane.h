#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "DogAirPlaneManager.h"
enum class NpcAirplaneState
{
	Intro,
	Intro2,
	Idle,
	Win,
	FinishWin

};

class NpcAirplane : public GameEngineActor
{
public:
	// constrcuter destructer
	NpcAirplane();
	~NpcAirplane();

	// delete Function
	NpcAirplane(const NpcAirplane& _Other) = delete;
	NpcAirplane(NpcAirplane&& _Other) noexcept = delete;
	NpcAirplane& operator=(const NpcAirplane& _Other) = delete;
	NpcAirplane& operator=(NpcAirplane&& _Other) noexcept = delete;

	void ChangeState(NpcAirplaneState _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	void Intro2Update(float _Time);
	void IntroUpdate(float _Time);
	void IdleUpdate(float _Time); 

	void collision(float _Delta);

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;
	float4 test = {0,0};
	bool axccs = false;
private:
	NpcAirplaneState StateValue = NpcAirplaneState::Intro;


	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Back;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Front;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Reg;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Spin;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc;
	std::shared_ptr<class GameEngineSpriteRenderer> C_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> D_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro3;

	std::shared_ptr<class GameEngineCollision> Collision;

	std::shared_ptr<class GameEngineCollision> DownCollision;
	bool ph3_main_boss_Check =false;

	bool fdasd = false;

	

	float Player_Pos_Y_Check = -150.0f;

	int IntroCheck = 0;
	int RotationCheck = 0; 
	float4 CurPos = {0,0};
	float Speed = 0;
	float SpeedControll = 0.03f;
	float Speed1 = 0;
};


