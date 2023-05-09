#include "PrecompileHeader.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineVideo.h>

Player::Player()
{
}

Player::~Player()
{
}


void Player::Update(float _DeltaTime)
{
	if (Gravity == false)
	{
		GetTransform()->AddLocalPosition({ 0, -GravitySpeed * _DeltaTime });
	}
	
	

	float RotSpeed = 180.0f;

	float Speed = 200.0f;

	float ScaleSpeed = 10.0f;
	
	std::shared_ptr<GameEngineTexture> testMap = GameEngineTexture::Find("TestMap.png");
	GameEnginePixelColor Pixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x, -GetTransform()->GetLocalPosition().y+65);
	GameEnginePixelColor RightPixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x+40, -GetTransform()->GetLocalPosition().y+55);
	GameEnginePixelColor LeftPixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x -40, -GetTransform()->GetLocalPosition().y + 55);



	// 마젠타색 임시 변수 
	unsigned char ColorChar[4] = {255,0,255,255};

	
	for (size_t i = 0; i < 4; i++)
	{
		if(ColorChar[i] == Pixel.ColorChar[i])
		{
			++GravityCheck;			
		}		

		if (ColorChar[i] == RightPixel.ColorChar[i])
		{
			++RightCheck;
		}

		if (ColorChar[i] == LeftPixel.ColorChar[i])
		{
			++LeftCheck;
		}

	}

	if (RightCheck == 4)
	{
		RightMove = false;
	}
	if (RightCheck != 4)
	{
		RightMove = true;
	}
	if (LeftCheck == 4)
	{
		LeftMove = false;
	}
	if (LeftCheck != 4)
	{
		LeftMove = true;
	}

	if (GravityCheck == 4)
	{
		Gravity = true;
	}
	if (GravityCheck != 4)
	{
		Gravity = false;
	}



	GravityCheck = 0;
	RightCheck = 0;
	LeftCheck = 0;


	// Render0->GetTransform()->SetWorldRotation(float4::Zero);



	if (true == GameEngineInput::IsPress("PlayerSpeedBoost"))
	{
		Speed = 500.0f;
	}

	
	else if (true == GameEngineInput::IsDown("PlayerMoveRight"))
	{
		// Render0->GetTransform()->SetLocalPositiveScaleX();
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft") && LeftMove  == true)
	{
		GetTransform()->AddLocalPosition(float4::Left * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight") && RightMove == true)
	{
		GetTransform()->AddLocalPosition(float4::Right * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsDown("PlayerJump") && JumpCheck ==false)
	{
		ResetLiveTime();
		JumpCheck = true;	
	}
	if (JumpCheck == true)
	{
		AccLiveTime(_DeltaTime);
	}

	if (GetLiveTime() < 0.4 && JumpCheck ==true)
	{
		GetTransform()->AddLocalPosition(float4::Up * JumpSpeed * _DeltaTime);	
	}
	if (GetLiveTime() > 0.4)
	{
		JumpCheck = false;
	}

	float4 GetLocalScale = Render0->GetTransform()->GetLocalScale();
	float4 GetWorldScale = Render0->GetTransform()->GetWorldScale();

	
	float4 LocalPostion = GetTransform()->GetLocalPosition();

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Left* Speed* _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition(float4::Right* Speed* _DeltaTime);
	}

	if (GetTransform()->GetLocalRotation().y == 0)
	{
		if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
		{
			GetTransform()->SetLocalRotation({ 0,-180,0 });
		}
	}

	if (GetTransform()->GetLocalRotation().y != 0)
	{
		if (true == GameEngineInput::IsPress("PlayerMoveRight"))
		{
			GetTransform()->SetLocalRotation({ 0,0,0 });
		}
	}


}

void Player::Start()
{
	if (false == GameEngineInput::IsKey("PlayerMoveLeft"))
	{
		GameEngineInput::CreateKey("PlayerMoveLeft", 'A');
		GameEngineInput::CreateKey("PlayerMoveRight", 'D');
		GameEngineInput::CreateKey("PlayerMoveUp", 'Q');
		GameEngineInput::CreateKey("PlayerMoveDown", 'E');
		GameEngineInput::CreateKey("PlayerMoveForward", 'W');
		GameEngineInput::CreateKey("PlayerMoveBack", 'S');
		GameEngineInput::CreateKey("PlayerJump", 'J');

		GameEngineInput::CreateKey("PlayerScaleY+", 'Y');
		GameEngineInput::CreateKey("PlayerScaleY-", 'U');
		GameEngineInput::CreateKey("PlayerScaleZ+", 'H');
		GameEngineInput::CreateKey("PlayerScaleZ-", 'J');
		GameEngineInput::CreateKey("PlayerScaleX+", 'N');
		GameEngineInput::CreateKey("PlayerScaleX-", 'M');


		GameEngineInput::CreateKey("PlayerRotY+", VK_NUMPAD1);
		GameEngineInput::CreateKey("PlayerRotY-", VK_NUMPAD2);
		GameEngineInput::CreateKey("PlayerRotZ+", VK_NUMPAD4);
		GameEngineInput::CreateKey("PlayerRotZ-", VK_NUMPAD5);
		GameEngineInput::CreateKey("PlayerRotX+", VK_NUMPAD7);
		GameEngineInput::CreateKey("PlayerRotX-", VK_NUMPAD8);
		GameEngineInput::CreateKey("PlayerSpeedBoost", VK_LSHIFT);
	}


	// 나는 스케일을 1로 고정해 놓는게 좋다.
	Render0 = CreateComponent<GameEngineSpriteRenderer>();
	// Render0->SetOrder(5);
	Render0->SetScaleToTexture("cuphead_idle_0001.png");
	
	TestColor = { 0.0f, 0.0f, 0.0f, 1.0f };
}

// 이건 디버깅용도나 
void Player::Render(float _Delta)
{
	// GetTransform()->AddLocalRotation({0.0f, 0.0f, 360.0f * _Delta});
};
