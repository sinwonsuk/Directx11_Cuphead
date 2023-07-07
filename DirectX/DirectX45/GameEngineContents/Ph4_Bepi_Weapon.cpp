#include "PrecompileHeader.h"
#include "Ph4_Bepi_Weapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>

Ph4_Bepi_Weapon::Ph4_Bepi_Weapon()
{
}

Ph4_Bepi_Weapon::~Ph4_Bepi_Weapon()
{
}

void Ph4_Bepi_Weapon::Start()
{
	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "HorseShoe_Gold", .SpriteName = "HorseShoe_Gold", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Bullet->ChangeAnimation("HorseShoe_Gold");

}

void Ph4_Bepi_Weapon::Update(float _Delta)
{
}
