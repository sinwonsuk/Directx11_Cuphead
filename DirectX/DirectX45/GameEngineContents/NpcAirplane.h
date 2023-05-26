#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class NpcAirplaneState
{
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

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	NpcAirplaneState StateValue = NpcAirplaneState::Idle;


	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Back;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Front;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Reg;
	std::shared_ptr<class GameEngineSpriteRenderer> Npc_Airplane_Spin;

	std::shared_ptr<class GameEngineSpriteRenderer> Npc;
	std::shared_ptr<class GameEngineSpriteRenderer> C_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> D_Left_Clouds;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro3;
	bool test1 = false;
	int test = 0;



};


