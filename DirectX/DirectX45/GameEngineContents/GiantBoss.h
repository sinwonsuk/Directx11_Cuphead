#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class GiantBossState
{
	BossIntro,
	BossIntroRock,
    BossIntroDust,
    BossIdle,
    BossIdleHand,
    noumIntro,


};

class GiantBoss : public GameEngineActor
{
public:
	// constrcuter destructer
	GiantBoss();
	~GiantBoss();

	// delete Function
	GiantBoss(const GiantBoss& _Other) = delete;
	GiantBoss(GiantBoss&& _Other) noexcept = delete;
	GiantBoss& operator=(const GiantBoss& _Other) = delete;
	GiantBoss& operator=(GiantBoss&& _Other) noexcept = delete;
	void ChangeState(GiantBossState _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	void BossIdleUpdate(float _Time);
	void BossIntroUpdate(float _Time); 
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	GiantBossState StateValue = GiantBossState::BossIntro;

	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> BossIntro0;
	std::shared_ptr<class GameEngineSpriteRenderer> BossIntroRock;
	std::shared_ptr<class GameEngineSpriteRenderer> BossIntroDust;
	std::shared_ptr<class GameEngineSpriteRenderer> BossIdle;
	std::shared_ptr<class GameEngineSpriteRenderer> BossIdleHand;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro1;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro2;
	std::shared_ptr<class GameEngineSpriteRenderer> noumIntro3;
};

