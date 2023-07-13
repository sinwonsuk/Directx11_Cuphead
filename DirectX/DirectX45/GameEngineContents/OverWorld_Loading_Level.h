#pragma once
#include <GameEngineCore\GameEngineLevel.h>

class OverWorld_Loading_Level : public GameEngineLevel
{

public:
	// constrcuter destructer
	OverWorld_Loading_Level();
	~OverWorld_Loading_Level();

	// delete Function
	OverWorld_Loading_Level(const OverWorld_Loading_Level& _Other) = delete;
	OverWorld_Loading_Level(OverWorld_Loading_Level&& _Other) noexcept = delete;
	OverWorld_Loading_Level& operator=(const OverWorld_Loading_Level& _Other) = delete;
	OverWorld_Loading_Level& operator=(OverWorld_Loading_Level&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineVideo> Video;

protected:
	void Update(float _DeltaTime) override;
	void Start() override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;


private:



};

