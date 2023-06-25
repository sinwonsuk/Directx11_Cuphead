#include "PrecompileHeader.h"
#include "TutorialMap.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include "Player.h"
TutorialMap::TutorialMap()
{
}

TutorialMap::~TutorialMap()
{
}

void TutorialMap::Start()
{
	/*Render1 = CreateComponent<GameEngineUIRenderer>();
	Render1->SetScaleToTexture("TutorialBackGround.png");*/

	Render1 = CreateComponent<GameEngineUIRenderer>();
	Render1->SetScaleToTexture("TutorialBackGround.png");
	Render1->GetTransform()->AddLocalPosition({ 0,-80.0f,100.0f });

	Render3 = CreateComponent<GameEngineSpriteRenderer>();
	Render3->SetTexture("Tutorial_BackLayer_001.png");
	Render3->GetTransform()->AddLocalPosition({ 0,-80.0f,0.0f });

	//Render3->SetScaleToTexture("Tutorial_BackLayer_001.png");


	Render3->GetTransform()->AddLocalScale({ 2000.0f,760.0f });

	Render2 = CreateComponent<GameEngineSpriteRenderer>();
	Render2->SetScaleToTexture("Tutorial_Map.png");
	Render2->GetTransform()->SetLocalPosition({ 2450.0f,0.0f });
	

}

void TutorialMap::Update(float _Delta)
{
	Render3->GetTransform()->SetLocalPosition({ Player::MainPlayer->GetTransform()->GetLocalPosition().x,-80.0f,0.0f });
	//if (Player::MainPlayer->GetTransform()->GetLocalPosition().y < -200)
	//{
	//	int a = 0;

	//	
	//}
	//
	//TransformData data = GetTransform()->GetTransDataRef();



	//std::shared_ptr<GameEngineTexture> testMap = GameEngineTexture::Find("TestMap.png");


	//GameEnginePixelColor Pixel = testMap->GetPixel(Player::MainPlayer->GetTransform()->GetLocalPosition().x + 640.0, -Player::MainPlayer->GetTransform()->GetLocalPosition().y + 360.0f+80.0f);
	//GameEnginePixelColor RightPixel = testMap->GetPixel(Player::MainPlayer->GetTransform()->GetLocalPosition().x + 40.0f + 640.0f, -Player::MainPlayer->GetTransform()->GetLocalPosition().y + 55.0f + 425.0f);
	//GameEnginePixelColor LeftPixel = testMap->GetPixel(Player::MainPlayer->GetTransform()->GetLocalPosition().x - 40.0f + 640.0f, -Player::MainPlayer->GetTransform()->GetLocalPosition().y + 55.0f + 425.0f);


	//TransformData date = Player::MainPlayer->GetTransform()->GetTransDataRef();
	//

	//// 마젠타색 임시 변수 
	//unsigned char ColorChar[4] = {255,0,255,255};




	//for (size_t i = 0; i < 4; i++)
	//{
	//	if(ColorChar[i] == Pixel.ColorChar[i])
	//	{
	//		++GravityCheck;			
	//	}		

	//	if (ColorChar[i] == RightPixel.ColorChar[i])
	//	{
	//		++RightCheck;
	//	}

	//	if (ColorChar[i] == LeftPixel.ColorChar[i])
	//	{
	//		++LeftCheck;
	//	}

	//}

	//if (RightCheck == 4)
	//{
	//	RightMove = false;
	//}
	//if (RightCheck != 4)
	//{
	//	RightMove = true;
	//}
	//if (LeftCheck == 4)
	//{
	//	LeftMove = false;
	//}
	//if (LeftCheck != 4)
	//{
	//	LeftMove = true;
	//}

	//if (GravityCheck == 4)
	//{
	//	Player::MainPlayer->SetGravity(false); 
	//}
	//if (GravityCheck != 4)
	//{
	//	Player::MainPlayer->SetGravity(true);
	//}



	//GravityCheck = 0;
	//RightCheck = 0;
	//LeftCheck = 0;
}

void TutorialMap::Render(float _Delta)
{
}
