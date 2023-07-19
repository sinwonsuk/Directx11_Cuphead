#include "PrecompileHeader.h"
#include "EndingLevel.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "Ending.h"
#include "OldFilm.h"
#include "OldTVEffect.h"
#include <GameEngineCore/BlurEffect.h>
EndingLevel::EndingLevel()
{
}

EndingLevel::~EndingLevel()
{
}

void EndingLevel::Start()
{
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->SetSortType(0, SortType::ZSort);

	if (nullptr == GameEngineSprite::Find("Page_18-End"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Ending");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Page_18-End").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Page_18").GetFullPath());
	}

	std::shared_ptr<Ending> Object = CreateActor<Ending>();

	GetLastTarget()->CreateEffect<OldFilm>();
	GetLastTarget()->CreateEffect<BlurEffect>();


	

}

void EndingLevel::LevelChangeStart()
{
}

void EndingLevel::LevelChangeEnd()
{
}
