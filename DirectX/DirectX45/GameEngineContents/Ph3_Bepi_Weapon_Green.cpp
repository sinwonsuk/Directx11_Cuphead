#include "PrecompileHeader.h"
#include "Ph3_Bepi_Weapon_Green.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>

Ph3_Bepi_Weapon_Green::Ph3_Bepi_Weapon_Green()
{
}

Ph3_Bepi_Weapon_Green::~Ph3_Bepi_Weapon_Green()
{
}

void Ph3_Bepi_Weapon_Green::Start()
{
	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "Horseshoe_Green", .SpriteName = "Horseshoe_Green", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Bullet->ChangeAnimation("Horseshoe_Green");

}

void Ph3_Bepi_Weapon_Green::Update(float _Delta)
{
	
	

	
	
	switch (MoveDir)
	{
	case 0:
	{
		AccTime += _Delta * 3;
		Pos_y = sin(AccTime) * 250;
		GetTransform()->SetLocalPosition({ ( - AccTime * 100) + 270.0f, Pos_y+100.0f});

	}
	break;

	case 1:
	{
		AccTime += _Delta * 3;
		Pos_y = sin(AccTime) * 250;
		GetTransform()->SetLocalPosition({ (AccTime * 100) -270.0f, Pos_y+100.0f });
	}
	break;


	default:
		break;
	}






	 
}
