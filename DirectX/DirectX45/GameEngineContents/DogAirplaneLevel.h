#pragma once
#include <GameEngineCore\GameEngineLevel.h>
#include "DogAirplane.h"
#include "Player.h"
#include "NpcAirplane.h"
#include "Ph2_DogAirpalne.h"
#include "DogAirplaneBackground.h"
#include "ph3_DogAirPlane.h"
#include "ph3_Laser.h"
#include "ph3_food_bowl.h"
#include "ph3_Dog_Npc.h"

// Ό³Έν :
class DogAirplaneLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	DogAirplaneLevel();
	~DogAirplaneLevel();

	// delete Function
	DogAirplaneLevel(const DogAirplaneLevel& _Other) = delete;
	DogAirplaneLevel(DogAirplaneLevel&& _Other) noexcept = delete;
	DogAirplaneLevel& operator=(const DogAirplaneLevel& _Other) = delete;
	DogAirplaneLevel& operator=(DogAirplaneLevel&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineVideo> Video;
	int ad = 0;
	float sd = 0;

	std::shared_ptr<Ph2_DogAirpalne> Get_Ph2_DogAirpalne_Left()
	{
		return Ph2_DogAirpalne_Left;
	}
	std::shared_ptr<Ph2_DogAirpalne> Get_Ph2_DogAirpalne_Right()
	{
		return Ph2_DogAirpalne_Right;
	}
	std::shared_ptr<Ph2_DogAirpalne> Get_Ph2_DogAirpalne_Top()
	{
		return Ph2_DogAirpalne_Top;
	}
	std::shared_ptr<Ph2_DogAirpalne> Get_Ph2_DogAirpalne_Bottom()
	{
		return Ph2_DogAirpalne_Bottom;
	}



protected:
	void Update(float _DeltaTime) override;
	void Start() override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;


private:
	void PlayerCreate();

	std::shared_ptr<NpcAirplane> Npc;
	std::shared_ptr<Player> player;
	std::shared_ptr<DogAirplane> Ph1_DogAirplane;
	std::shared_ptr<Ph2_DogAirpalne> Ph2_DogAirpalne_Left;
	std::shared_ptr<Ph2_DogAirpalne> Ph2_DogAirpalne_Right;
	std::shared_ptr<Ph2_DogAirpalne> Ph2_DogAirpalne_Top;
	std::shared_ptr<Ph2_DogAirpalne> Ph2_DogAirpalne_Bottom;
	std::shared_ptr<Ph3_DogAirplane> Ph3_DogAirpalne;
	std::shared_ptr<DogAirplaneBackground> BackGround;

};
