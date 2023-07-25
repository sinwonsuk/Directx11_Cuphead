#include "PrecompileHeader.h"
#include "OverWorld_Map.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "EnumClass.h"
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEnginePlatform/GameEngineInput.h>
OverWorld_Map::OverWorld_Map()
{
}

OverWorld_Map::~OverWorld_Map()
{
}

void OverWorld_Map::Start()
{
	Map = CreateComponent<GameEngineSpriteRenderer>();

	Map->SetScaleToTexture("Overworld_Map.png");
	Map->GetTransform()->AddLocalPosition({ 0.0f,0.0f,100.0f });

	House = CreateComponent<GameEngineSpriteRenderer>();
	House->CreateAnimation({ .AnimationName = "House", .SpriteName = "To_WaittingRoom.png", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	House->GetTransform()->AddLocalPosition({ -1210.0f , 400.0f,90.0f });
	House->ChangeAnimation("House");



	AirPlane = CreateComponent<GameEngineSpriteRenderer>();
	AirPlane->CreateAnimation({ .AnimationName = "To_Tutorial_Fly", .SpriteName = "To_Tutorial_Fly.png", .FrameInter = 0.1f,.Loop = true, .ScaleToTexture = true, });
	AirPlane->ChangeAnimation("To_Tutorial_Fly");
	AirPlane->GetTransform()->AddLocalPosition({ 250.0f,-50.0f,90.0f });

	Bepi = CreateComponent<GameEngineSpriteRenderer>();
	Bepi->CreateAnimation({ .AnimationName = "Bepi_Map", .SpriteName = "Bepi_Map", .FrameInter = 0.1f,.Loop = true });
	Bepi->ChangeAnimation("Bepi_Map");
	Bepi->GetTransform()->SetLocalScale({ -320.0f,320.0f });
	Bepi->GetTransform()->AddLocalPosition({ -100.0f,-340.0f,90.0f });


	AirPlane_Collision = CreateComponent<GameEngineCollision>();
	AirPlane_Collision->GetTransform()->SetLocalScale({ 100.0f, 100.0f, 100.0f });
	AirPlane_Collision->GetTransform()->AddLocalPosition({ 250.0f,-50.0f,90.0f });
	AirPlane_Collision->SetOrder((int)CollisionType::OverWorldAirPlane);
	AirPlane_Collision->SetColType(ColType::OBBBOX2D);

	Bepi_Collision = CreateComponent<GameEngineCollision>();
	Bepi_Collision->GetTransform()->SetLocalScale({ 150.0f, 150.0f, 100.0f });
	Bepi_Collision->GetTransform()->AddLocalPosition({ -100.0f,-370.0f,90.0f });
	Bepi_Collision->SetOrder((int)CollisionType::OverWorldBepi);
	Bepi_Collision->SetColType(ColType::OBBBOX2D);
	



	Left_Map_Layer = CreateComponent<GameEngineSpriteRenderer>();
	Left_Map_Layer->SetScaleToTexture("Overworld_Bush_Left.png");
	Left_Map_Layer->GetTransform()->AddLocalPosition({ -651,65,-55.0f });


	Render1 = CreateComponent<GameEngineSpriteRenderer>();
	Render1->SetScaleToTexture("Overworld_ColMap.png");
	Render1->Off();




}

void OverWorld_Map::Update(float _Delta)
{
	if (GameEngineInput::IsDown("Tutorial"))
	{
		if (Colmap_Check == false)
		{
			Render1->On();
			Colmap_Check = true;
		}
		else if (Colmap_Check == true)
		{
			Render1->Off();
			Colmap_Check = false;
		}

	}

}

void OverWorld_Map::Render(float _Delta)
{
}
