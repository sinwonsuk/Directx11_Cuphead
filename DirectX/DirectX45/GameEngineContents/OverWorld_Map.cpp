#include "PrecompileHeader.h"
#include "OverWorld_Map.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "EnumClass.h"
#include <GameEngineCore/GameEngineCollision.h>
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


	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 50.0f, 50.0f, 100.0f });
	Collision->GetTransform()->AddLocalPosition({ 250.0f,-50.0f,90.0f });
	Collision->SetOrder((int)CollisionType::OverWorldAirPlane);
	Collision->SetColType(ColType::OBBBOX2D);




	Left_Map_Layer = CreateComponent<GameEngineSpriteRenderer>();
	Left_Map_Layer->SetScaleToTexture("Overworld_Bush_Left.png");
	Left_Map_Layer->GetTransform()->AddLocalPosition({ -651,65,-55.0f });







}

void OverWorld_Map::Update(float _Delta)
{
}

void OverWorld_Map::Render(float _Delta)
{
}
