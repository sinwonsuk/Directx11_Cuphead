#pragma once
#include <GameEngineCore/GameEngineActor.h>

class OverWorld_Map : public GameEngineActor
{
public:

	//static Player* MainPlayer;
	OverWorld_Map();
	~OverWorld_Map();

	// delete Function
	OverWorld_Map(const OverWorld_Map& _Other) = delete;
	OverWorld_Map(OverWorld_Map&& _Other) noexcept = delete;
	OverWorld_Map& operator=(const OverWorld_Map& _Other) = delete;
	OverWorld_Map& operator=(OverWorld_Map&& _Other) noexcept = delete;

	
	



protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	



	std::shared_ptr<class GameEngineSpriteRenderer> Map;
	std::shared_ptr<class GameEngineSpriteRenderer> House;
	std::shared_ptr<class GameEngineSpriteRenderer> AirPlane;
	std::shared_ptr<class GameEngineSpriteRenderer> Left_Map_Layer;
	std::shared_ptr<class GameEngineCollision> AirPlane_Collision;
	std::shared_ptr<class GameEngineCollision> Bepi_Collision;




};

