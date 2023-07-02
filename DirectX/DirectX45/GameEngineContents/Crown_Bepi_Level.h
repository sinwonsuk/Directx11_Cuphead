#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class Crown_Bepi_Level : public GameEngineLevel
{
public:
	// constrcuter destructer
	Crown_Bepi_Level();
	~Crown_Bepi_Level();

	// delete Function
	Crown_Bepi_Level(const Crown_Bepi_Level& _Other) = delete;
	Crown_Bepi_Level(Crown_Bepi_Level&& _Other) noexcept = delete;
	Crown_Bepi_Level& operator=(const Crown_Bepi_Level& _Other) = delete;
	Crown_Bepi_Level& operator=(Crown_Bepi_Level&& _Other) noexcept = delete;



protected:
	void Update(float _DeltaTime) override;
	void Start() override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;


private:



};