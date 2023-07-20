#include "PrecompileHeader.h"
#include "TutorialMap.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

#include "Player.h"

GameEngineSoundPlayer TutorialMap::BG;
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

	Loading = CreateComponent<GameEngineUIRenderer>();
	Loading->CreateAnimation({ .AnimationName = "Start", .SpriteName = "Start", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	Loading->ChangeAnimation("Start");
	Loading->GetTransform()->AddLocalPosition({ 0,0.0f,-200.0f });
	
	


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
	if (Loading->IsAnimationEnd())
	{
		Loading->Off();

		if (Sound_Check == false)
		{
			BG = GameEngineSound::Play("MUS_Tutorial.wav");
			Sound_Check = true; 
		}

	}

	



	Render3->GetTransform()->SetLocalPosition({ Player::MainPlayer->GetTransform()->GetLocalPosition().x,-80.0f,0.0f });
	
}

void TutorialMap::Render(float _Delta)
{
}
