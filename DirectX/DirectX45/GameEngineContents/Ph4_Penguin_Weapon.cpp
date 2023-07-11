#include "PrecompileHeader.h"
#include "Ph4_Penguin_Weapon.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Player.h"
#include "EnumClass.h"

Ph4_Penguin_Weapon::Ph4_Penguin_Weapon()
{
}

Ph4_Penguin_Weapon::~Ph4_Penguin_Weapon()
{
}

void Ph4_Penguin_Weapon::Start()
{

	Bullet = CreateComponent<GameEngineSpriteRenderer>();
	Bullet->CreateAnimation({ .AnimationName = "penguin_baseball", .SpriteName = "penguin_baseball", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });
	Bullet->ChangeAnimation("penguin_baseball");

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 50.0f });
	Collision->SetOrder((int)CollisionType::BossAttack);
	Collision->SetColType(ColType::AABBBOX2D);

}

void Ph4_Penguin_Weapon::Update(float _Delta)
{
	if (MoveDirCheck == false)
	{
		float4 MoveDir1 = { Player::MainPlayer->GetTransform()->GetLocalPosition() - GetTransform()->GetLocalPosition() };
		MoveDir1.Normalize();

		MoveDir = MoveDir1.NormalizeReturn();
		//Collision->Off();
		MoveDirCheck = true;
	}

    GetTransform()->AddLocalPosition({ MoveDir * 2 * _Delta * 200.0f });
	
	if (MoveDirCheck == true)
	{
		//Collision->On();
	}
}
