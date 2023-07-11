#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Crown_Bepi_Map : public GameEngineActor
{
public:
	static bool Ph4_Check;
	///static DogAirplaneBackground* Background;
	// constrcuter destructer
	Crown_Bepi_Map();
	~Crown_Bepi_Map();

	// delete Function
	Crown_Bepi_Map(const Crown_Bepi_Map& _Other) = delete;
	Crown_Bepi_Map(Crown_Bepi_Map&& _Other) noexcept = delete;
	Crown_Bepi_Map& operator=(const Crown_Bepi_Map& _Other) = delete;
	Crown_Bepi_Map& operator=(Crown_Bepi_Map&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:

	std::shared_ptr<class GameEngineSpriteRenderer> MainMap;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_back_coaster;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_sky;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_ferris_light;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_mid_coaster;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_track;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_ferris_Circle;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_back_mist;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_top_clouds;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_low_cloud;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_balloon;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_cloud;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_cloud2;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_moon;


	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_light_off;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_light_on;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_cart_blue;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_cart_blue2;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_cart_blue3;


	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_cart_red;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_cart_red2;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_cart_red3;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_cart_yellow;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_cart_yellow2;

	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_track_top;
	std::shared_ptr<class GameEngineSpriteRenderer> clown_bg_main2;
	std::shared_ptr<class GameEngineCollision> Collision;
	
	


	float yellow = 0.0f;
	float Ph4_TimeCheck = 0;
	float Ph4_Rollercoaster_Time = 14; 
	float Ph4_Rollercoaster_Time_BG = 14;
	float Rollercoaster_Time_BG = 14; 
	float Rollercoaster_Time = 14;

	//float yellow2 = 0.0f;
	float Red = 0.7f;
	float Red2 = 2.4f;
	float Red3 = -0.7f;

	float Yellow2 = -2.4f;
	float Blue = 1.5f;
	float Blue2 = -1.5f;
	float Blue3 = 3.1f;

	float balloon = 0.0f;

	float cloud = 0.0f;
	float cloud2 = 0.0f;

	float moon = 0.0f;

	float sdasd = 0;

	bool Ph4_Time_bool = false;
};

