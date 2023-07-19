#include "PrecompileHeader.h"
#include "Ending.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
Ending::Ending()
{
}
Ending::~Ending()
{
}
void Ending::Start()
{

	ending = CreateComponent<GameEngineSpriteRenderer>();
	ending->CreateAnimation({ .AnimationName = "Page_18", .SpriteName = "Page_18", .FrameInter = 0.2f,.Loop = false, .ScaleToTexture = true, });
	ending->ChangeAnimation("Page_18");
	//ending->Off();

	cuphead_End_screen = CreateComponent<GameEngineSpriteRenderer>();
	cuphead_End_screen->CreateAnimation({ .AnimationName = "Page_18-End", .SpriteName = "Page_18-End", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true, });
	cuphead_End_screen->ChangeAnimation("Page_18-End");
	cuphead_End_screen->Off(); 

	


	start = CreateComponent<GameEngineSpriteRenderer>(150);
	start->CreateAnimation({ .AnimationName = "Start", .SpriteName = "Start", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
	start->ChangeAnimation("Start");

}

void Ending::Update(float _Delta)
{
	if (start->IsAnimationEnd())
	{
		start->Off(); 
	}

	if (ending->IsAnimationEnd())
	{
		cuphead_End_screen->On(); 
	}

}

void Ending::Render(float _Delta)
{
}
