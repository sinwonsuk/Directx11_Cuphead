#include "PrecompileHeader.h"
#include "Rollercoaster.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineCollision.h>

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
	Rollercoaster_Midcart_Red_2->GetTransform()->AddLocalPosition({ 630.0f,-48.0f,31.0f });
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


	Rollercoaster_Passenger2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Passenger2->CreateAnimation({ .AnimationName = "Rollercoaster_Passenger2", .SpriteName = "Rollercoaster_Passenger", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Passenger2->ChangeAnimation("Rollercoaster_Passenger2");
	Rollercoaster_Passenger2->GetTransform()->AddLocalPosition({ 530.0f,50.0f,32.0f });
	Rollercoaster_Passenger2->On();

	Rollercoaster_Passenger = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Passenger->CreateAnimation({ .AnimationName = "Rollercoaster_Passenger", .SpriteName = "Rollercoaster_Passenger", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Passenger->ChangeAnimation("Rollercoaster_Passenger");
	Rollercoaster_Passenger->GetTransform()->AddLocalPosition({ 570.0f,30.0f,32.0f });
	Rollercoaster_Passenger->On();



	Rollercoaster_Back = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Back->CreateAnimation({ .AnimationName = "Rollercoaster_Back", .SpriteName = "Rollercoaster_Back", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Back->ChangeAnimation("Rollercoaster_Back");
	Rollercoaster_Back->Off();
	//Rollercoaster_Back->GetTransform()->AddLocalPosition({ -55.0f,-135.0f });

	Rollercoaster_Back2 = CreateComponent<GameEngineSpriteRenderer>();
	Rollercoaster_Back2->CreateAnimation({ .AnimationName = "Rollercoaster_Back2", .SpriteName = "Rollercoaster_Back2", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	Rollercoaster_Back2->ChangeAnimation("Rollercoaster_Back2");
	Rollercoaster_Back2->Off();

	
	

	
	
	
	

	

	GetTransform()->AddLocalPosition({ -400.0f,-140.0f });
}

void Rollercoaster::Update(float _Delta)
{



}

void Rollercoaster::Render(float _Delta)
{
}
