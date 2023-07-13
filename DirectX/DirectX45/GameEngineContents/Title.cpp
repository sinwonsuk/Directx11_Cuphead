#include "PrecompileHeader.h"
#include "Title.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
Title::Title()
{
}
Title::~Title()
{
}
void Title::Start()
{

	TitleRoge = CreateComponent<GameEngineSpriteRenderer>();
	TitleRoge->CreateAnimation({ .AnimationName = "Title_Logo", .SpriteName = "Title_Logo", .FrameInter = 0.005f,.Loop = false, .ScaleToTexture = true, });
	TitleRoge->ChangeAnimation("Title_Logo");
	TitleRoge->SetScaleRatio(1.5f);

	//TitleRoge->Off();
	title_screen_background = CreateComponent<GameEngineSpriteRenderer>();
	title_screen_background->SetScaleToTexture("title_screen_background.png");
	title_screen_background->Off(); 

	cuphead_title_screen = CreateComponent<GameEngineSpriteRenderer>();
	cuphead_title_screen->CreateAnimation({ .AnimationName = "cuphead_title_screen", .SpriteName = "cuphead_title_screen", .FrameInter = 0.06f,.Loop = true, .ScaleToTexture = true, });
	cuphead_title_screen->ChangeAnimation("cuphead_title_screen");
	cuphead_title_screen->Off();
	cuphead_title_screen->GetTransform()->AddLocalPosition({ 0.0f,-50.0f });
	

	Exit = CreateComponent<GameEngineSpriteRenderer>();
	Exit->CreateAnimation({ .AnimationName = "Exit", .SpriteName = "Exit", .FrameInter = 0.06f,.Loop = false, .ScaleToTexture = true, });
	Exit->ChangeAnimation("Exit");
	Exit->Off();
	//Exit->GetTransform()->AddLocalPosition({ 0.0f,-50.0f });
	


}

void Title::Update(float _Delta)
{
	if (TitleRoge->IsAnimationEnd())
	{
		TitleRoge->Off(); 
		cuphead_title_screen->On(); 
		title_screen_background->On(); 

		Check = true;

	}




	if (Check ==true && GameEngineInput::IsAnyKey())
	{
		Exit->On(); 
	}

	if (Exit->IsAnimationEnd())
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}
}


void Title::Render(float _Delta)
{
}
