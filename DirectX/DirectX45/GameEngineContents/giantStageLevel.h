#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class giantStageLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	giantStageLevel();
	~giantStageLevel();

	// delete Function
	giantStageLevel(const giantStageLevel& _Other) = delete;
	giantStageLevel(giantStageLevel&& _Other) noexcept = delete;
	giantStageLevel& operator=(const giantStageLevel& _Other) = delete;
	giantStageLevel& operator=(giantStageLevel&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineVideo> Video;

protected:
	void Update(float _DeltaTime) override;
	void Start() override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;


private:
	void PlayerCreate();


};

