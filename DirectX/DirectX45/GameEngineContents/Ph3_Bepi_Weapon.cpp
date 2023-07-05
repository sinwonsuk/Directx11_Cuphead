#include "PrecompileHeader.h"
#include "Ph3_Bepi_Weapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>

Ph3_Bepi_Weapon::Ph3_Bepi_Weapon()
{
}

Ph3_Bepi_Weapon::~Ph3_Bepi_Weapon()
{
}

void Ph3_Bepi_Weapon::Start()
{
	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "HorseShoe_Gold", .SpriteName = "HorseShoe_Gold", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Bullet->ChangeAnimation("HorseShoe_Gold");
}

void Ph3_Bepi_Weapon::Update(float _Delta)
{





	switch (YellowPattern)
	{
	case 1:
	{
		if (GetLiveTime() < 1.0)
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed * _Delta });
		}

		if (GetLiveTime() > 1.0 && Stop == false)
		{
			GetTransform()->AddLocalPosition({ 0.0f,200.0f });
			Stop = true;
		}

		if (GetLiveTime() > 1.0)
		{
			GetTransform()->AddLocalPosition({ float4::Left * Speed * _Delta });
		}

		if (StopPos > GetTransform()->GetLocalPosition().x && Stop == true)
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed * _Delta });

		}
		if (DownCheck == true)
		{
			GetTransform()->AddLocalPosition({ float4::Down * Speed * _Delta });
		}
	}
	break;
	case 0:
	{
		if (GetLiveTime() < 1.0)
		{
			GetTransform()->AddLocalPosition({ float4::Left * Speed * _Delta });
		}

		if (GetLiveTime() > 1.0 && Stop == false)
		{
			GetTransform()->AddLocalPosition({ 0.0f,200.0f });
			Stop = true;
		}

		if (GetLiveTime() > 1.0)
		{
			GetTransform()->AddLocalPosition({ float4::Right * Speed * _Delta });
		}

		if (StopPos < GetTransform()->GetLocalPosition().x && Stop == true)
		{
			GetTransform()->AddLocalPosition({ float4::Left * Speed * _Delta });
		}
		if (DownCheck == true)
		{
			GetTransform()->AddLocalPosition({ float4::Down * Speed * _Delta });
		}
	}
	break;
	
	case 2:
	{

	}
	break;



	default:
		break;
	}

	

}
