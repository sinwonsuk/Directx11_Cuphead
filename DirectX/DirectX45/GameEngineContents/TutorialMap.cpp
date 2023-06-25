#include "PrecompileHeader.h"
#include "TutorialMap.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "Player.h"
TutorialMap::TutorialMap()
{
}

TutorialMap::~TutorialMap()
{
}

void TutorialMap::Start()
{


	Render2 = CreateComponent<GameEngineSpriteRenderer>();
	Render2->SetScaleToTexture("Tutorial_Map.png");

	/*Render1 = CreateComponent<GameEngineSpriteRenderer>();
	Render1->SetScaleToTexture("TutorialBackGround.png");*/

}

void TutorialMap::Update(float _Delta)
{
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
