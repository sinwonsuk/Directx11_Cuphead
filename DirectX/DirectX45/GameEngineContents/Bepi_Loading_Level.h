#pragma once
#include <GameEngineCore\GameEngineLevel.h>

class Bepi_Loading_Level : public GameEngineLevel
{

public:
	// constrcuter destructer
	Bepi_Loading_Level();
	~Bepi_Loading_Level();

	// delete Function
	Bepi_Loading_Level(const Bepi_Loading_Level& _Other) = delete;
	Bepi_Loading_Level(Bepi_Loading_Level&& _Other) noexcept = delete;
	Bepi_Loading_Level& operator=(const Bepi_Loading_Level& _Other) = delete;
	Bepi_Loading_Level& operator=(Bepi_Loading_Level&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineVideo> Video;

protected:
	void Update(float _DeltaTime) override;
	void Start() override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;


private:



};


