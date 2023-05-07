#include "PrecompileHeader.h"
#include "TutorialMap.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>

TutorialMap::TutorialMap()
{
}

TutorialMap::~TutorialMap()
{
}

void TutorialMap::Start()
{
	CreateComponent<GameEngineSpriteRenderer>();


	Render1 = CreateComponent<GameEngineSpriteRenderer>();
	Render1->SetScaleToTexture("TestMap.png");


}

void TutorialMap::Update(float _Delta)
{
}

void TutorialMap::Render(float _Delta)
{
}
