#include "PrecompileHeader.h"
#include "TutorialObject.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"

TutorialObject::TutorialObject()
{

}

TutorialObject::~TutorialObject()
{

}

void TutorialObject::Start()
{
	
	Render2 = CreateComponent<GameEngineSpriteRenderer>();

	Render2->SetScaleToTexture("tutorial_sphere_1.png");


	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 300.0f });
	Collision->SetOrder((int)CollisionType::TutorialObject);
	
}

void TutorialObject::Update(float _Delta)
{
	
}

void TutorialObject::Render(float _Delta)
{
																		
}

