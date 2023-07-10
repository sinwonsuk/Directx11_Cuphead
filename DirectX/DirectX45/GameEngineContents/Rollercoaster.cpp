#include "PrecompileHeader.h"
#include "Rollercoaster.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"
#include "Player.h"
Rollercoaster::Rollercoaster()
{
}

Rollercoaster::~Rollercoaster()
{
}

void Rollercoaster::Start()
{



	Rollercoaster_Front = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Front->CreateAnimation({ .AnimationName = "Rollercoaster_Front", .SpriteName = "Rollercoaster_Front", .FrameInter = 0.06f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Front->ChangeAnimation("Rollercoaster_Front");
	Rollercoaster_Front->GetTransform()->AddLocalPosition({ -500.0f,0.0f,30.0f });
	Rollercoaster_Front->On();

	Rollercoaster_Frontcart = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Frontcart->CreateAnimation({ .AnimationName = "Rollercoaster_Frontcart", .SpriteName = "Rollercoaster_Frontcart", .FrameInter = 0.06f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Frontcart->ChangeAnimation("Rollercoaster_Frontcart");
	Rollercoaster_Frontcart->GetTransform()->AddLocalPosition({ -170.0f,-28.0f,31.0f });
	Rollercoaster_Frontcart->On();


	Rollercoaster_Frontcart2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Frontcart2->CreateAnimation({ .AnimationName = "Rollercoaster_Frontcart2", .SpriteName = "Rollercoaster_Frontcart2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Frontcart2->ChangeAnimation("Rollercoaster_Frontcart2");
	Rollercoaster_Frontcart2->GetTransform()->AddLocalPosition({ -170.0f,0.0f,32.0f });
	Rollercoaster_Frontcart2->On();

	Rollercoaster_Midcart_Red = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart_Red->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart_Red", .SpriteName = "Rollercoaster_Midcart_Red", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart_Red->ChangeAnimation("Rollercoaster_Midcart_Red");
	Rollercoaster_Midcart_Red->GetTransform()->AddLocalPosition({ 110.0f,-48.0f,31.0f });
	Rollercoaster_Midcart_Red->On();
	
	Rollercoaster_Midcart2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart2->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart2", .SpriteName = "Rollercoaster_Midcart2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart2->ChangeAnimation("Rollercoaster_Midcart2");
	Rollercoaster_Midcart2->GetTransform()->AddLocalPosition({ 90.0f,0.0f,32.0f });
	Rollercoaster_Midcart2->On();

	Rollercoaster_Midcart_Blue = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart_Blue->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart_Blue", .SpriteName = "Rollercoaster_Midcart_Blue", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart_Blue->ChangeAnimation("Rollercoaster_Midcart_Blue");
	Rollercoaster_Midcart_Blue->GetTransform()->AddLocalPosition({ 370.0f,-48.0f,31.0f });
	Rollercoaster_Midcart_Blue->On();

	Rollercoaster_Midcart2_2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart2_2->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart2", .SpriteName = "Rollercoaster_Midcart2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart2_2->ChangeAnimation("Rollercoaster_Midcart2");
	Rollercoaster_Midcart2_2->GetTransform()->AddLocalPosition({ 350.0f,0.0f,32.0f });
	Rollercoaster_Midcart2_2->On();

	Rollercoaster_Midcart_Red_2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart_Red_2->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart_Red", .SpriteName = "Rollercoaster_Midcart_Red", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart_Red_2->ChangeAnimation("Rollercoaster_Midcart_Red");
	Rollercoaster_Midcart_Red_2->GetTransform()->AddLocalPosition({ 630.0f,-48.0f,29.0f });
	Rollercoaster_Midcart_Red_2->On();

	Rollercoaster_Midcart2_3 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart2_3->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart2", .SpriteName = "Rollercoaster_Midcart2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart2_3->ChangeAnimation("Rollercoaster_Midcart2");
	Rollercoaster_Midcart2_3->GetTransform()->AddLocalPosition({ 610.0f,0.0f,32.0f });
	Rollercoaster_Midcart2_3->On();

	Rollercoaster_Seat = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Seat->CreateAnimation({ .AnimationName = "Rollercoaster_Seat", .SpriteName = "Rollercoaster_Seat", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Seat->ChangeAnimation("Rollercoaster_Seat");
	//Rollercoaster_Seat->GetTransform()->AddLocalRotation({ 0.0f,-20.0f,0.0f });
	Rollercoaster_Seat->GetTransform()->AddLocalPosition({ 570.0f,0.0f,32.0f });
	Rollercoaster_Seat->On();


	Rollercoaster_Seat_2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Seat_2->CreateAnimation({ .AnimationName = "Rollercoaster_Seat", .SpriteName = "Rollercoaster_Seat", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Seat_2->ChangeAnimation("Rollercoaster_Seat");
	//Rollercoaster_Seat->GetTransform()->AddLocalRotation({ 0.0f,-20.0f,0.0f });
	Rollercoaster_Seat_2->GetTransform()->AddLocalPosition({ 690.0f,0.0f,31.0f });
	Rollercoaster_Seat_2->On();



	Rollercoaster_Passenger2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Passenger2->CreateAnimation({ .AnimationName = "Rollercoaster_Passenger2", .SpriteName = "Rollercoaster_Passenger2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Passenger2->ChangeAnimation("Rollercoaster_Passenger2");
	Rollercoaster_Passenger2->GetTransform()->AddLocalPosition({ 530.0f,50.0f,32.0f });
	Rollercoaster_Passenger2->On();

	Rollercoaster_Passenger = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Passenger->CreateAnimation({ .AnimationName = "Rollercoaster_Passenger", .SpriteName = "Rollercoaster_Passenger", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Passenger->ChangeAnimation("Rollercoaster_Passenger");
	Rollercoaster_Passenger->GetTransform()->AddLocalPosition({ 570.0f,30.0f,32.0f });
	Rollercoaster_Passenger->On();


	Rollercoaster_Passenger2_2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Passenger2_2->CreateAnimation({ .AnimationName = "Rollercoaster_Passenger2", .SpriteName = "Rollercoaster_Passenger2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Passenger2_2->ChangeAnimation("Rollercoaster_Passenger2");
	Rollercoaster_Passenger2_2->GetTransform()->AddLocalPosition({ 650.0f,60.0f,30.0f });
	Rollercoaster_Passenger2_2->On();

	Rollercoaster_Passenger_2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Passenger_2->CreateAnimation({ .AnimationName = "Rollercoaster_Passenger", .SpriteName = "Rollercoaster_Passenger", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Passenger_2->ChangeAnimation("Rollercoaster_Passenger");
	Rollercoaster_Passenger_2->GetTransform()->AddLocalPosition({ 680.0f,30.0f,30.0f });
	Rollercoaster_Passenger_2->On();


	Rollercoaster_Midcart_Blue_2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart_Blue_2->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart_Blue", .SpriteName = "Rollercoaster_Midcart_Blue", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart_Blue_2->ChangeAnimation("Rollercoaster_Midcart_Blue");
	Rollercoaster_Midcart_Blue_2->GetTransform()->AddLocalPosition({ 890.0f,-48.0f,31.0f });
	Rollercoaster_Midcart_Blue_2->On();

	Rollercoaster_Midcart2_4 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart2_4->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart2", .SpriteName = "Rollercoaster_Midcart2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart2_4->ChangeAnimation("Rollercoaster_Midcart2");
	Rollercoaster_Midcart2_4->GetTransform()->AddLocalPosition({ 870.0f,0.0f,33.0f });
	Rollercoaster_Midcart2_4->On();


	Rollercoaster_Midcart_Red_3 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart_Red_3->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart_Red", .SpriteName = "Rollercoaster_Midcart_Red", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart_Red_3->ChangeAnimation("Rollercoaster_Midcart_Red");
	Rollercoaster_Midcart_Red_3->GetTransform()->AddLocalPosition({ 1150.0f,-48.0f,31.0f });
	Rollercoaster_Midcart_Red_3->On();

	Rollercoaster_Midcart2_5 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart2_5->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart2", .SpriteName = "Rollercoaster_Midcart2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart2_5->ChangeAnimation("Rollercoaster_Midcart2");
	Rollercoaster_Midcart2_5->GetTransform()->AddLocalPosition({ 1130.0f,0.0f,32.0f });
	Rollercoaster_Midcart2_5->On();

	Rollercoaster_Midcart_Blue_3 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart_Blue_3->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart_Blue", .SpriteName = "Rollercoaster_Midcart_Blue", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart_Blue_3->ChangeAnimation("Rollercoaster_Midcart_Blue");
	Rollercoaster_Midcart_Blue_3->GetTransform()->AddLocalPosition({ 1410.0f,-48.0f,31.0f });
	Rollercoaster_Midcart_Blue_3->On();

	Rollercoaster_Midcart2_6 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart2_6->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart2", .SpriteName = "Rollercoaster_Midcart2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart2_6->ChangeAnimation("Rollercoaster_Midcart2");
	Rollercoaster_Midcart2_6->GetTransform()->AddLocalPosition({ 1390.0f,0.0f,33.0f });
	Rollercoaster_Midcart2_6->On();

	Rollercoaster_Midcart_Red_4 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart_Red_4->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart_Red", .SpriteName = "Rollercoaster_Midcart_Red", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart_Red_4->ChangeAnimation("Rollercoaster_Midcart_Red");
	Rollercoaster_Midcart_Red_4->GetTransform()->AddLocalPosition({ 1670.0f,-48.0f,29.0f });
	Rollercoaster_Midcart_Red_4->On();

	Rollercoaster_Midcart2_7 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart2_7->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart2", .SpriteName = "Rollercoaster_Midcart2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart2_7->ChangeAnimation("Rollercoaster_Midcart2");
	Rollercoaster_Midcart2_7->GetTransform()->AddLocalPosition({ 1650.0f,0.0f,32.0f });
	Rollercoaster_Midcart2_7->On();

	Rollercoaster_Seat_3 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Seat_3->CreateAnimation({ .AnimationName = "Rollercoaster_Seat", .SpriteName = "Rollercoaster_Seat", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Seat_3->ChangeAnimation("Rollercoaster_Seat");
	Rollercoaster_Seat_3->GetTransform()->AddLocalPosition({ 1610.0f,0.0f,32.0f });
	Rollercoaster_Seat_3->On();


	Rollercoaster_Seat_4 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Seat_4->CreateAnimation({ .AnimationName = "Rollercoaster_Seat", .SpriteName = "Rollercoaster_Seat", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Seat_4->ChangeAnimation("Rollercoaster_Seat");
	Rollercoaster_Seat_4->GetTransform()->AddLocalPosition({ 1730.0f,0.0f,31.0f });
	Rollercoaster_Seat_4->On();


	Rollercoaster_Passenger2_3 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Passenger2_3->CreateAnimation({ .AnimationName = "Rollercoaster_Passenger2", .SpriteName = "Rollercoaster_Passenger2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Passenger2_3->ChangeAnimation("Rollercoaster_Passenger2");
	Rollercoaster_Passenger2_3->GetTransform()->AddLocalPosition({ 1570.0f,60.0f,32.0f });
	Rollercoaster_Passenger2_3->On();

	Rollercoaster_Passenger_3 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Passenger_3->CreateAnimation({ .AnimationName = "Rollercoaster_Passenger", .SpriteName = "Rollercoaster_Passenger", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Passenger_3->ChangeAnimation("Rollercoaster_Passenger");
	Rollercoaster_Passenger_3->GetTransform()->AddLocalPosition({ 1610.0f,30.0f,32.0f });
	Rollercoaster_Passenger_3->On();


	Rollercoaster_Passenger2_4 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Passenger2_4->CreateAnimation({ .AnimationName = "Rollercoaster_Passenger2", .SpriteName = "Rollercoaster_Passenger2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Passenger2_4->ChangeAnimation("Rollercoaster_Passenger2");
	Rollercoaster_Passenger2_4->GetTransform()->AddLocalPosition({ 1690.0f,60.0f,30.0f });
	Rollercoaster_Passenger2_4->On();

	Rollercoaster_Passenger_4 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Passenger_4->CreateAnimation({ .AnimationName = "Rollercoaster_Passenger", .SpriteName = "Rollercoaster_Passenger", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Passenger_4->ChangeAnimation("Rollercoaster_Passenger");
	Rollercoaster_Passenger_4->GetTransform()->AddLocalPosition({ 1720.0f,30.0f,30.0f });
	Rollercoaster_Passenger_4->On();

	
	Rollercoaster_Midcart_Blue_4 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart_Blue_4->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart_Blue", .SpriteName = "Rollercoaster_Midcart_Blue", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart_Blue_4->ChangeAnimation("Rollercoaster_Midcart_Blue");
	Rollercoaster_Midcart_Blue_4->GetTransform()->AddLocalPosition({ 1930.0f,-48.0f,31.0f });
	Rollercoaster_Midcart_Blue_4->On();

	Rollercoaster_Midcart2_8 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart2_8->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart2", .SpriteName = "Rollercoaster_Midcart2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart2_8->ChangeAnimation("Rollercoaster_Midcart2");
	Rollercoaster_Midcart2_8->GetTransform()->AddLocalPosition({ 1910.0f,0.0f,33.0f });
	Rollercoaster_Midcart2_8->On();

	
	Rollercoaster_Midcart_Red_5 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart_Red_5->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart_Red", .SpriteName = "Rollercoaster_Midcart_Red", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart_Red_5->ChangeAnimation("Rollercoaster_Midcart_Red");
	Rollercoaster_Midcart_Red_5->GetTransform()->AddLocalPosition({ 2190.0f,-48.0f,31.0f });
	Rollercoaster_Midcart_Red_5->On();

	Rollercoaster_Midcart2_9 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Midcart2_9->CreateAnimation({ .AnimationName = "Rollercoaster_Midcart2", .SpriteName = "Rollercoaster_Midcart2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Midcart2_9->ChangeAnimation("Rollercoaster_Midcart2");
	Rollercoaster_Midcart2_9->GetTransform()->AddLocalPosition({ 2170.0f,0.0f,32.0f });
	Rollercoaster_Midcart2_9->On();
	
	Rollercoaster_Back2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Back2->CreateAnimation({ .AnimationName = "Rollercoaster_Back2", .SpriteName = "Rollercoaster_Back2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Back2->ChangeAnimation("Rollercoaster_Back2");
	Rollercoaster_Back2->GetTransform()->AddLocalPosition({ 2390.0f,10.0f,33.0f });
	Rollercoaster_Back2->On();

	Rollercoaster_Back = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Back->CreateAnimation({ .AnimationName = "Rollercoaster_Back", .SpriteName = "Rollercoaster_Back", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Back->ChangeAnimation("Rollercoaster_Back");
	Rollercoaster_Back->GetTransform()->AddLocalPosition({ 2430.0f,-30.0f,32.0f });
	Rollercoaster_Back->On();

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 2600.0f, 50.0f, 200.0f });
	Collision->GetTransform()->AddLocalPosition({ 1000.0f,-50.0f });
	Collision->SetOrder((int)CollisionType::RollerCoaster);
	Collision->SetColType(ColType::AABBBOX2D);


	Collision2 = CreateComponent<GameEngineCollision>();
	Collision2->GetTransform()->SetLocalScale({ 200.0f, 200.0f, 200.0f });
	Collision2->GetTransform()->AddLocalPosition({ -500.0f,-30.0f });
	Collision2->SetOrder((int)CollisionType::BossAttack);
	Collision2->SetColType(ColType::AABBBOX2D);


	Collision5 = CreateComponent<GameEngineCollision>();
	Collision5->GetTransform()->SetLocalScale({ 200.0f, 200.0f, 200.0f });
	Collision5->GetTransform()->AddLocalPosition({ -500.0f,-30.0f });
	Collision5->SetOrder((int)CollisionType::RollerCoaster_Attack);
	Collision5->SetColType(ColType::AABBBOX2D);



	Collision3 = CreateComponent<GameEngineCollision>();
	Collision3->GetTransform()->SetLocalScale({ 200.0f, 150.0f, 200.0f });
	Collision3->GetTransform()->AddLocalPosition({ 620.0f,0.0f });
	Collision3->SetOrder((int)CollisionType::BossAttack);
	Collision3->SetColType(ColType::AABBBOX2D);

	Collision4 = CreateComponent<GameEngineCollision>();
	Collision4->GetTransform()->SetLocalScale({ 200.0f, 150.0f, 200.0f });
	Collision4->GetTransform()->AddLocalPosition({ 1650.0f,0.0f });
	Collision4->SetOrder((int)CollisionType::BossAttack);
	Collision4->SetColType(ColType::AABBBOX2D);

	Collision->Off();
	Collision2->Off();
	Collision3->Off();
	Collision4->Off();
	Collision5->Off();

}

void Rollercoaster::Update(float _Delta)
{

	


	switch (MoveCheck)
	{
	case 0:
	{
		Collision->Off(); 
		Collision2->Off();
		Collision3->Off();
		Collision4->Off();
		Collision5->Off(); 
		if (test == false)
		{
			GetTransform()->SetLocalScale({ 0.3f,0.3f, 1.2f });
			GetTransform()->SetLocalNegativeScaleX();
			GetTransform()->AddLocalRotation({ 0.0f,0.0f,18.5f });
			GetTransform()->AddLocalPosition({ -720.0f,-330.0f,50.0f });
			test = true;
		}
		
		float4 ad = { 1.0f,0.33f };
		GetTransform()->AddLocalPosition({ ad * Speed * _Delta });
	}
	break;
	case 1:
	{
		if (GetLiveTime() > 0.5)
		{
			Collision->On();
			Collision2->On();
			Collision3->On();
			Collision4->On();
			Collision5->On();
		}

		GetTransform()->AddLocalPosition({ float4::Left * (Speed + 100.0f) * _Delta });

		if (Collision->Collision((int)CollisionType::Player, ColType::AABBBOX2D, ColType::AABBBOX2D))
		{
			Player::MainPlayer->SetGravity(false);

			Player::MainPlayer->GetTransform()->AddLocalPosition({ float4::Left * (Speed+100.0f) * _Delta });
		}

		

		if (test == false)
		{
			GetTransform()->AddLocalPosition({ 1400.0f,-140.0f });
			test = true;
		}

	
	}
	break;

	default:
		break;
	}


	CurPos = GetTransform()->GetLocalPosition(); 
	if (GetLiveTime() > 10)
	{
		this->Death(); 
	}
}

void Rollercoaster::Render(float _Delta)
{
}
