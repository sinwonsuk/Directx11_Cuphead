#include "PrecompileHeader.h"
#include "PlayerRunEffect.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>



PlayerRunEffect::PlayerRunEffect()
{
}

PlayerRunEffect::~PlayerRunEffect()
{
}

void PlayerRunEffect::Start()
{
	if (nullptr == GameEngineSprite::Find("RunDust"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Character");
	
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("RunDust").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("JumpDust").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DashDust").GetFullPath());
	}

	Render = CreateComponent<GameEngineSpriteRenderer>();
	Render->CreateAnimation({ .AnimationName = "RunDust", .SpriteName = "RunDust", .FrameInter = 0.05f, .Loop= false, .ScaleToTexture = true, });
	Render->CreateAnimation({ .AnimationName = "JumpDust", .SpriteName = "JumpDust", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	Render->CreateAnimation({ .AnimationName = "DashDust", .SpriteName = "DashDust", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	Render->GetTransform()->AddLocalPosition({ 0.0f,0.0f,-100.0f });
	//Render->CreateAnimation({ .AnimationName = "RunDust", .SpriteName = "RunDust", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	Render->ChangeAnimation("RunDust"); 

	



}

void PlayerRunEffect::Update(float _Delta)
{


	if (Check == false)
	{
		switch (State)
		{
		case EffectState::RunEffect:
		{
			Render->ChangeAnimation("RunDust");
			break;
		}
		case EffectState::JumpEffect:
		{
			Render->ChangeAnimation("JumpDust");
			break;
		}
		case EffectState::DashEffect:
		{
			Render->ChangeAnimation("DashDust");
			break;
		}
		default:
			break;
		}
		Check = true; 
	}






	if (Render->IsAnimationEnd())
	{
		this->Death(); 
	}
	
	
}
