#include "PrecompileHeader.h"
#include "Ph2_Bepi_Weapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>

Ph2_Bepi_Weapon::Ph2_Bepi_Weapon()
{
}

Ph2_Bepi_Weapon::~Ph2_Bepi_Weapon()
{
	

}

void Ph2_Bepi_Weapon::Start()
{
	Bullet_Stop = CreateComponent<GameEngineSpriteRenderer>();
	Bullet_Stop->CreateAnimation({ .AnimationName = "Dogs_Appear", .SpriteName = "Dogs_Appear", .FrameInter = 0.1f, .Loop = false, .ScaleToTexture = true ,.FrameIndex = {0,1,2,3,4,5,6,7,8,9,10,11,12}  });
	Bullet_Stop->ChangeAnimation("Dogs_Appear");
	

	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "Dogs_Appear", .SpriteName = "Dogs_Appear", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true ,.FrameIndex = {13,14,15,16,17,18,19,20} });
	Bullet->ChangeAnimation("Dogs_Appear");
	Bullet->Off(); 

}

void Ph2_Bepi_Weapon::Update(float _Delta)
{
	if (MoveDirCheck == false)
	{
		float4 MoveDir1 = { MoveDir4 - GetTransform()->GetLocalPosition() };
		MoveDir1.Normalize();

		MoveDir = MoveDir1.NormalizeReturn();
		/*Collision->Off();
		PinkCollision->Off();*/
		MoveDirCheck = true;
	}

	if (Bullet_Stop->IsAnimationEnd())
	{
		Bullet_Stop->Off();
		Bullet->On();
		GetTransform()->AddLocalPosition(MoveDir * 2);
	}
}
