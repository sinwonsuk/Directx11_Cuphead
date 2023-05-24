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



	Render1 = CreateComponent<GameEngineSpriteRenderer>();
	Render1->SetScaleToTexture("TutorialBackGround.png");

	
}

void TutorialMap::Update(float _Delta)
{
}

void TutorialMap::Render(float _Delta)
{
}
