#include "PrecompileHeader.h"
#include "Crown_Bepi_Map.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"
#include "Player.h"
#include "Rollercoaster.h"
#include "Crown_Bepi_Level.h"
Crown_Bepi_Map::Crown_Bepi_Map()
{
}

Crown_Bepi_Map::~Crown_Bepi_Map()
{
}

void Crown_Bepi_Map::Start()
{

	clown_bg_sky = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_sky->SetScaleToTexture("clown_bg_sky.png");
	clown_bg_sky->GetTransform()->AddLocalPosition({ 0.0f,300.0f,300.0f });

	clown_bg_low_cloud = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_low_cloud->SetScaleToTexture("clown_bg_low_cloud.png");
	clown_bg_low_cloud->GetTransform()->AddLocalPosition({ 0.0f,270.0f,290.0f });

	clown_bg_top_clouds = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_top_clouds->SetScaleToTexture("clown_bg_top_clouds.png");
	clown_bg_top_clouds->GetTransform()->AddLocalPosition({ 0.0f,270.0f,280.0f });

	MainMap = CreateComponent<GameEngineSpriteRenderer>();
	MainMap->SetScaleToTexture("clown_bg_main.png");
	MainMap->GetTransform()->AddLocalPosition({ 0.0f,-40.0f,100.0f });

	clown_bg_main2 = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_main2->SetScaleToTexture("clown_bg_main2.png");
	clown_bg_main2->GetTransform()->AddLocalPosition({ 0.0f,-280.0f,80.0f });






	clown_bg_cloud = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_cloud->SetScaleToTexture("clown_bg_cloud_0003.png");
	clown_bg_cloud->GetTransform()->AddLocalPosition({ -600.0f,300.0f,270.0f });

	clown_bg_cloud2 = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_cloud2->SetScaleToTexture("clown_bg_cloud_0002.png");
	clown_bg_cloud2->GetTransform()->AddLocalPosition({ -250.0f,330.0f,260.0f });



	clown_bg_balloon = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_balloon->SetScaleToTexture("clown_bg_balloon.png");
	clown_bg_balloon->GetTransform()->AddLocalPosition({ 60.0f,280.0f,250.0f });

	clown_bg_moon = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_moon->SetScaleToTexture("clown_bg_moon.png");
	clown_bg_moon->GetTransform()->AddLocalPosition({ -140.0f,200.0f,240.0f });




	clown_bg_back_coaster = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_back_coaster->SetScaleToTexture("clown_bg_back_coaster.png");
	clown_bg_back_coaster->GetTransform()->AddLocalPosition({ 620.0f,500.0f,230.0f });


	clown_bg_cart_blue = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_cart_blue->SetScaleToTexture("clown_bg_cart_blue.png");
	clown_bg_cart_blue->GetTransform()->AddLocalPosition({ 308.0f,300.0f,220.0f });

	clown_bg_cart_blue2 = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_cart_blue2->SetScaleToTexture("clown_bg_cart_blue.png");
	clown_bg_cart_blue2->GetTransform()->AddLocalPosition({ 412.0f,50.0f,210.0f });

	clown_bg_cart_blue3 = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_cart_blue3->SetScaleToTexture("clown_bg_cart_blue.png");
	clown_bg_cart_blue3->GetTransform()->AddLocalPosition({ 157.0f,155.0f,200.0f });


	clown_bg_cart_red = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_cart_red->SetScaleToTexture("clown_bg_cart_red.png");
	clown_bg_cart_red->GetTransform()->AddLocalPosition({ 415.0f,290.0f,190.0f });
	

	clown_bg_cart_red2 = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_cart_red2->SetScaleToTexture("clown_bg_cart_red.png");
	clown_bg_cart_red2->GetTransform()->AddLocalPosition({ 308.0f,150.0f,180.0f });

	clown_bg_cart_red3 = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_cart_red3->SetScaleToTexture("clown_bg_cart_red.png");
	clown_bg_cart_red3->GetTransform()->AddLocalPosition({ 200.0f,260.0f,170.0f });




	clown_bg_cart_yellow = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_cart_yellow->SetScaleToTexture("clown_bg_cart_yellow.png");
	clown_bg_cart_yellow->GetTransform()->AddLocalPosition({ 457.0f,155.0f,160.0f });

	clown_bg_cart_yellow2 = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_cart_yellow2->SetScaleToTexture("clown_bg_cart_yellow.png");
	clown_bg_cart_yellow2->GetTransform()->AddLocalPosition({ 200.0f,50.0f,150.0f });


	clown_bg_ferris_Circle = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_ferris_Circle->SetScaleToTexture("clown_bg_ferris_0004.png");
	clown_bg_ferris_Circle->GetTransform()->AddLocalPosition({ 308.0f,180.0f,100.0f });

	clown_bg_ferris_light = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_ferris_light->SetScaleToTexture("clown_bg_ferris_light_0003.png");
	clown_bg_ferris_light->GetTransform()->AddLocalPosition({ 300.0f,80.0f,100.0f });

	clown_bg_mid_coaster = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_mid_coaster->SetScaleToTexture("clown_bg_mid_coaster.png");
	clown_bg_mid_coaster->GetTransform()->AddLocalPosition({ 160.0f,-70.0f,90.0f });

	clown_bg_back_mist = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_back_mist->SetScaleToTexture("clown_bg_back_mist_0001.png");
	clown_bg_back_mist->GetTransform()->AddLocalPosition({ 0.0f,-70.0f,80.0f });
	
	


	clown_bg_track = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_track->SetScaleToTexture("clown_bg_track 1.png");
	clown_bg_track->GetTransform()->AddLocalPosition({ 0.0f,-270.0f,50.0f });

	clown_bg_light_off = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_light_off->SetScaleToTexture("clown_bg_light_off.png");
	clown_bg_light_off->GetTransform()->AddLocalPosition({ 320.0f,-120.0f,51.0f });

	clown_bg_light_on = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_light_on->CreateAnimation({ .AnimationName = "clown_bg_light_on", .SpriteName = "clown_bg_light_on", .FrameInter = 0.2f,.Loop = true, .ScaleToTexture = true, });
	clown_bg_light_on->ChangeAnimation("clown_bg_light_on");
	clown_bg_light_on->GetTransform()->AddLocalPosition({ 320.0f,-120.0f,51.0f });
	clown_bg_light_on->Off();


	clown_bg_track_top = CreateComponent<GameEngineSpriteRenderer>();
	clown_bg_track_top->SetScaleToTexture("clown_bg_track_top.png");
	clown_bg_track_top->GetTransform()->AddLocalPosition({ 0.0f,-250.0f,-1.0f });


	
	

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 1500.0f, 300.0f, 300.0f });
	Collision->GetTransform()->AddLocalPosition({ 0.0f,-350.0f });

	Collision->SetOrder((int)CollisionType::BepiMap);
	Collision->SetColType(ColType::AABBBOX2D);

	
	
}

void Crown_Bepi_Map::Update(float _Delta)
{

	Rollercoaster_Time += _Delta; 
	Rollercoaster_Time_BG += _Delta;


	if (Collision->Collision((int)CollisionType::Player,ColType::AABBBOX2D , ColType::AABBBOX2D))
	{
		Player::MainPlayer->SetGravity(false);
	}

	if (Collision->Collision((int)CollisionType::Player, ColType::AABBBOX2D, ColType::AABBBOX2D) == nullptr)
	{
		Player::MainPlayer->SetGravity(true);
	}


	Crown_Bepi_Level* Level = (Crown_Bepi_Level*)GetLevel();

	if (Level->PaseCheck == Pase::Pase1)
	{
		if (Rollercoaster_Time_BG > 15)
		{
			std::shared_ptr<Rollercoaster> Object = GetLevel()->CreateActor<Rollercoaster>();
			Rollercoaster_Time_BG = 0;
			Rollercoaster_Time = 14;
			clown_bg_light_on->Off();
		}

		if (Rollercoaster_Time > 20)
		{
			clown_bg_light_on->On(); 

			std::shared_ptr<Rollercoaster> Object = GetLevel()->CreateActor<Rollercoaster>();

			TransformData Date = Object->GetTransform()->GetTransDataRef(); 

			Object->MoveCheck = 1;
			Rollercoaster_Time = 0;
		}





	}



	clown_bg_ferris_Circle->GetTransform()->AddLocalRotation({ 0,0,1.0f * 28.8f * _Delta });

	// 타원의 중심
	float x = 300.0f;
	float y = 160.0f;

	float Pos_x = 0.0f;
	float Pos_y = 0.0f;

	// 타원의 반지름
	float a = 150;
	float b = 150;


	{
	
		yellow += 0.5f * _Delta;

		Pos_x = x + a * cos(yellow);
		Pos_y = y + b * sin(yellow);
		clown_bg_cart_yellow->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}



	{
	

		Red += 0.5f * _Delta;

		Pos_x = x + a * cos(Red);
		Pos_y = y + b * sin(Red);
		clown_bg_cart_red->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}

	{
	

		Blue += 0.5f * _Delta;

		Pos_x = x + a * cos(Blue);
		Pos_y = y + b * sin(Blue);
		clown_bg_cart_blue->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}

	{
	

		Red2 += 0.5f * _Delta;

		Pos_x = x + a * cos(Red2);
		Pos_y = y + b * sin(Red2);
		clown_bg_cart_red2->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}
	{
	

		Blue2 += 0.5f * _Delta;

		Pos_x = x + a * cos(Blue2);
		Pos_y = y + b * sin(Blue2);
		clown_bg_cart_blue2->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}

	{
		Yellow2 += 0.5f * _Delta;
		Pos_x = x + a * cos(Yellow2);
		Pos_y = y + b * sin(Yellow2);
		clown_bg_cart_yellow2->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}

	{
		Red3 += 0.5f * _Delta;
		Pos_x = x + a * cos(Red3);
		Pos_y = y + b * sin(Red3);
		clown_bg_cart_red3->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}
	{
		Blue3 += 0.5f * _Delta;

		Pos_x = x + a * cos(Blue3);
		Pos_y = y + b * sin(Blue3);
		clown_bg_cart_blue3->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}

	{
		float x = 80.0f;
		float y = 300.0f;

		float Pos_x = 0.0f;
		float Pos_y = 0.0f;

		// 타원의 반지름
		float a = 8;
		float b = 8;

		balloon += 1.4f * _Delta;

		Pos_x = x + a * cos(balloon);
		Pos_y = y + b * sin(balloon);

		clown_bg_balloon->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}

	{
		float x = 80.0f;
		float y = 300.0f;

		float Pos_x = 0.0f;
		float Pos_y = 0.0f;

		// 타원의 반지름
		float a = 8;
		float b = 8;

		balloon += 1.4f * _Delta;

		Pos_x = x + a * cos(balloon);
		Pos_y = y + b * sin(balloon);

		clown_bg_balloon->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}
	{
		float x = -200.0f;
		float y = 300.0f;

		float Pos_x = 0.0f;
		float Pos_y = 0.0f;

		// 타원의 반지름
		float a = 7;
		float b = 2;

		cloud2 += 1.2f * _Delta;

		Pos_x = x + a * cos(cloud2);
		Pos_y = y + b * sin(cloud2);

		clown_bg_cloud2->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}

	{
		float x = -600.0f;
		float y = 300.0f;

		float Pos_x = 0.0f;
		float Pos_y = 0.0f;

		// 타원의 반지름
		float a = 9;
		float b = 3;

		cloud += 1.2f * _Delta;

		Pos_x = x + a * cos(cloud);
		Pos_y = y + b * sin(cloud);

		clown_bg_cloud->GetTransform()->SetLocalPosition({ Pos_x, Pos_y,100.0f });
	}

	{
		float x = 100.0f;
		float y = 200.0f;

		float Pos_x = 0.0f;
		float Pos_y = 0.0f;

		// 타원의 반지름
		float a = 5;
		float b = 5;

		moon += 1.2f * _Delta;

		Pos_x = x + a * cos(moon);
		Pos_y = y + b * sin(moon);

		clown_bg_moon->GetTransform()->SetLocalPosition({ -Pos_x, Pos_y,100.0f });
	}

	



}

void Crown_Bepi_Map::Render(float _Delta)
{
}
