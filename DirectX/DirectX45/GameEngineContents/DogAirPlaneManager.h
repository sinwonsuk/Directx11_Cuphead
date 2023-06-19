#pragma once
#include <GameEngineCore/GameEngineActor.h>

#include "DogAirplane.h"
#include "Player.h"
#include "NpcAirplane.h"
#include "Ph2_DogAirpalne.h"
#include "DogAirplaneBackground.h"
#include "ph3_DogAirPlane.h"
#include "ph3_Laser.h"
#include "ph3_food_bowl.h"
#include "ph3_Dog_Npc.h"
class DogAirplaneManager : public GameEngineActor
{
public:
	// constrcuter destructer
	DogAirplaneManager();
	~DogAirplaneManager();

	// delete Function
	DogAirplaneManager(const DogAirplaneManager& _Other) = delete;
	DogAirplaneManager(DogAirplaneManager&& _Other) noexcept = delete;
	DogAirplaneManager& operator=(const DogAirplaneManager& _Other) = delete;
	DogAirplaneManager& operator=(DogAirplaneManager&& _Other) noexcept = delete;
	
	int ad = 0;


protected:
	void Start();
	void Update(float _Delta) override;

private:
	/*std::shared_ptr<NpcAirplane> Npc;
	std::shared_ptr<Player> player;
	std::shared_ptr<DogAirplane> Ph1_DogAirplane;
	std::shared_ptr<Ph2_DogAirpalne> Ph2_DogAirpalne_Left;
	std::shared_ptr<Ph2_DogAirpalne> Ph2_DogAirpalne_Right;
	std::shared_ptr<Ph2_DogAirpalne> Ph2_DogAirpalne_Top;
	std::shared_ptr<Ph2_DogAirpalne> Ph2_DogAirpalne_Bottom;
	std::shared_ptr<DogAirplaneBackground> BackGround;*/

};;

