#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
enum class EffectState
{
	RunEffect,
	JumpEffect, 
	DashEffect, 
};


class PlayerRunEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	PlayerRunEffect();
	~PlayerRunEffect();

	// delete Function
	PlayerRunEffect(const PlayerRunEffect& _Other) = delete;
	PlayerRunEffect(PlayerRunEffect&& _Other) noexcept = delete;
	PlayerRunEffect& operator=(const PlayerRunEffect& _Other) = delete;
	PlayerRunEffect& operator=(PlayerRunEffect&& _Other) noexcept = delete;
	EffectState SetState(const EffectState& _State)
	{
		State = _State;

		return State;
	}
	
	
protected:
	void Start();
	void Update(float _Delta) override;

private:
	EffectState State = EffectState::DashEffect;

	std::shared_ptr<class GameEngineSpriteRenderer> Render1;
	std::shared_ptr<class GameEngineSpriteRenderer> Render;
	bool Check = false;
};

