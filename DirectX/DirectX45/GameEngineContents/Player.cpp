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
	GameEnginePixelColor Pixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x, -GetTransform()->GetLocalPosition().y+65.0f);
	GameEnginePixelColor RightPixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x+40.0f, -GetTransform()->GetLocalPosition().y+55.0f);
	GameEnginePixelColor LeftPixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x -40.0f, -GetTransform()->GetLocalPosition().y + 55.0f);



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


	


	
	
	if (true == GameEngineInput::IsDown("PlayerMoveRight"))
	{
		// Render0->GetTransform()->SetLocalPositiveScaleX();
	}

	
	
	/*if (true == GameEngineInput::IsDown("PlayerJump") && JumpCheck ==false)
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

	
	float4 LocalPostion = GetTransform()->GetLocalPosition();*/

	
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
	
	UpdateState(_DeltaTime);
}

void Player::Start()
{
	if (false == GameEngineInput::IsKey("PlayerMoveLeft"))
	{
		GameEngineInput::CreateKey("PlayerMoveLeft", VK_LEFT);
		GameEngineInput::CreateKey("PlayerMoveRight", VK_RIGHT);
		GameEngineInput::CreateKey("PlayerMoveUp", VK_UP);
		GameEngineInput::CreateKey("PlayerMoveDown", VK_DOWN);
		GameEngineInput::CreateKey("PlayerMoveForward", 'W');
		GameEngineInput::CreateKey("PlayerMoveBack", 'S');
		GameEngineInput::CreateKey("PlayerJump", 'Z');
		GameEngineInput::CreateKey("PlayerRock", 'C');
		GameEngineInput::CreateKey("PlayerAttack", 'X');
		GameEngineInput::CreateKey("PlayerDash", VK_LSHIFT);


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
		//GameEngineInput::CreateKey("PlayerSpeedBoost", VK_LSHIFT);
	}

	if (nullptr == GameEngineSprite::Find("Idle"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Idle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Run").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Jump").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Duck").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Parry").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("IdleAim").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DiagonalDownAim").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DiagonalUpAim").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DownAim").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("UpAim").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("GroundDash").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("IdleAttack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("IdleAttackPre").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("RunAttack").GetFullPath());
	}

	// 나는 스케일을 1로 고정해 놓는게 좋다.
	Render0 = CreateComponent<GameEngineSpriteRenderer>();
	


	

	Render0->CreateAnimation({ .AnimationName = "Idle", .SpriteName = "Idle", .FrameInter =0.1f,.Loop = true, .ScaleToTexture = true,});
	Render0->CreateAnimation({ .AnimationName = "Run", .SpriteName = "Run",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Jump", .SpriteName = "Jump",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Duck", .SpriteName = "Duck",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "Parry", .SpriteName = "Parry",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "IdleAim", .SpriteName = "IdleAim",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DiagonalDownAim", .SpriteName = "DiagonalDownAim",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DiagonalUpAim", .SpriteName = "DiagonalUpAim",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "DownAim", .SpriteName = "DownAim",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "UpAim", .SpriteName = "UpAim",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "GroundDash", .SpriteName = "GroundDash",. FrameInter = 0.1f, .Loop = false, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "IdleAttack", .SpriteName = "IdleAttack",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "IdleAttackPre", .SpriteName = "IdleAttackPre",. FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	Render0->CreateAnimation({ .AnimationName = "RunAttack", .SpriteName = "RunAttack",. FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	Render0->ChangeAnimation("Idle");
	

	
}

void Player::AnimationCheck(const std::string_view& _AnimationName)
{
	Render0->ChangeAnimation(_AnimationName);
}



// 이건 디버깅용도나 
void Player::Render(float _Delta)
{
	// GetTransform()->AddLocalRotation({0.0f, 0.0f, 360.0f * _Delta});
};
