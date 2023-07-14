#pragma once
#include <GameEngineCore\GameEngineLevel.h>

class Bepi_UnLoad_Level : public GameEngineLevel
{

public:
	// constrcuter destructer
	Bepi_UnLoad_Level();
	~Bepi_UnLoad_Level();

	// delete Function
	Bepi_UnLoad_Level(const Bepi_UnLoad_Level& _Other) = delete;
	Bepi_UnLoad_Level(Bepi_UnLoad_Level&& _Other) noexcept = delete;
	Bepi_UnLoad_Level& operator=(const Bepi_UnLoad_Level& _Other) = delete;
	Bepi_UnLoad_Level& operator=(Bepi_UnLoad_Level&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineVideo> Video;

protected:
	void Update(float _DeltaTime) override;
	void Start() override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;


private:



};


