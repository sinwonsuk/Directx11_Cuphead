#pragma once
#include <GameEngineCore\GameEngineLevel.h>
#include "Ph1_Bepi.h"
#include "Ph2_Bepi.h"
#include "Ph3_Bepi.h"
#include "Ph4_Bepi.h"
#include "Player.h"
#include "UserInterface.h"
#include "Crown_Bepi_Map.h"
enum class Pase
{
	Pase1,
	Pase2,
	Pase3,
	Pase4,

};


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


	Pase PaseCheck = Pase::Pase1;

protected:
	void Update(float _DeltaTime) override;
	void Start() override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;


private:
	std::shared_ptr<Crown_Bepi_Map> Map;
	std::shared_ptr<Ph1_Bepi> ph1_Bepi;
	std::shared_ptr<Ph2_Bepi> ph2_Bepi;
	std::shared_ptr<Ph3_Bepi> ph3_Bepi;
	std::shared_ptr<Ph4_Bepi> ph4_Bepi;
	std::shared_ptr<Player> player;
	std::shared_ptr<UserInterface> userInterface;


};