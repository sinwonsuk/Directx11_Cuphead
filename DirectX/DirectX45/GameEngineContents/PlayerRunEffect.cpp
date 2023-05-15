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

	
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("RunDust").GetFullPath());
	}

	Render = CreateComponent<GameEngineSpriteRenderer>();
	Render->CreateAnimation({ .AnimationName = "RunDust", .SpriteName = "RunDust", .FrameInter = 0.05f, .Loop= false, .ScaleToTexture = true, });
	Render->ChangeAnimation("RunDust"); 

	



}

void PlayerRunEffect::Update(float _Delta)
{
	

	if (Render->IsAnimationEnd())
	{
		this->Death(); 
	}
	
	
}
