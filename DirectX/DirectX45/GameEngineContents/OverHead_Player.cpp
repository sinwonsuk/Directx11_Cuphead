#include "PrecompileHeader.h"
#include "OverHead_Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>


OverHead_Player::OverHead_Player()
{
}

OverHead_Player::~OverHead_Player()
{
}

void OverHead_Player::Start()
{
	

	Player = CreateComponent<GameEngineSpriteRenderer>();

	Player->CreateAnimation({ .AnimationName = "DD_Idle", .SpriteName = "DD_Idle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Player->CreateAnimation({ .AnimationName = "DD_Move", .SpriteName = "DD_Move", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Player->CreateAnimation({ .AnimationName = "Down_Idle", .SpriteName = "Down_Idle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Player->CreateAnimation({ .AnimationName = "Down_Move", .SpriteName = "Down_Move", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Player->CreateAnimation({ .AnimationName = "DU_Idle", .SpriteName = "DU_Idle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Player->CreateAnimation({ .AnimationName = "DU_Move", .SpriteName = "DU_Move", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Player->CreateAnimation({ .AnimationName = "InterAction_Win", .SpriteName = "InterAction_Win", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Player->CreateAnimation({ .AnimationName = "Side_Idle", .SpriteName = "Side_Idle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Player->CreateAnimation({ .AnimationName = "Side_Move", .SpriteName = "Side_Move", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Player->CreateAnimation({ .AnimationName = "Up_Idle", .SpriteName = "Up_Idle", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	Player->CreateAnimation({ .AnimationName = "Up_Move", .SpriteName = "Up_Move", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });

	GetTransform()->AddLocalPosition({ -1300,200,-1.0f });

	Player->ChangeAnimation("DD_Idle");

	Render1 = CreateComponent<GameEngineSpriteRenderer>();
	Render1->SetScaleToTexture("Overworld_ColMap.png");
	Render1->Off();
}

void OverHead_Player::Update(float _Delta)
{

	
	
		std::shared_ptr<GameEngineTexture> testMap = GameEngineTexture::Find("Overworld_ColMap1.png");
		//2009,368
		float4 Pos = Render1->GetTransform()->GetLocalScale().half();



		GameEnginePixelColor UpPixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x+ Pos.x, -GetTransform()->GetLocalPosition().y +0.0f + Pos.y);
		GameEnginePixelColor Pixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x + Pos.x, -GetTransform()->GetLocalPosition().y +40.0f +Pos.y);

		GameEnginePixelColor Right_diagonal = testMap->GetPixel(GetTransform()->GetLocalPosition().x + Pos.x +35.0f, -GetTransform()->GetLocalPosition().y + Pos.y);
		GameEnginePixelColor Right_diagonal_Down = testMap->GetPixel(GetTransform()->GetLocalPosition().x + Pos.x +35.0f, -GetTransform()->GetLocalPosition().y + Pos.y +40.0f);
		GameEnginePixelColor Left_diagonal = testMap->GetPixel(GetTransform()->GetLocalPosition().x + Pos.x - 35.0f, -GetTransform()->GetLocalPosition().y + Pos.y);
		GameEnginePixelColor Left_diagonal_Down = testMap->GetPixel(GetTransform()->GetLocalPosition().x + Pos.x -35.0f, -GetTransform()->GetLocalPosition().y + 40.0f + Pos.y);








		GameEnginePixelColor RightPixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x + Pos.x +35.0f, -GetTransform()->GetLocalPosition().y+20.0f + Pos.y);
		GameEnginePixelColor LeftPixel = testMap->GetPixel(GetTransform()->GetLocalPosition().x + Pos.x -35.0f, -GetTransform()->GetLocalPosition().y +20.0f + Pos.y);

		// 마젠타색 임시 변수 
		unsigned char ColorChar[4] = { 0,0,0,255 };

	



		for (size_t i = 0; i < 4; i++)
		{

			if (ColorChar[i] == Right_diagonal.ColorChar[i])
			{
				++Right_diagonal_Check;
			}

			if (ColorChar[i] == Right_diagonal_Down.ColorChar[i])
			{
				++Right_diagonal_Down_Check;
			}

			if (ColorChar[i] == Left_diagonal.ColorChar[i])
			{
				++Left_diagonal_Check;
			}

			if (ColorChar[i] == Left_diagonal_Down.ColorChar[i])
			{
				++Left_diagonal_Down_Check;
			}



			if (ColorChar[i] == UpPixel.ColorChar[i])
			{
				++UpCheck;
			}
			
			if (ColorChar[i] == Pixel.ColorChar[i])
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
		

		if (Right_diagonal_Check == 4)
		{
			Right_diagonal_Move = true;
		}
		if (Right_diagonal_Check != 4)
		{
			Right_diagonal_Move = false;
		}

		if (Right_diagonal_Down_Check == 4)
		{
			Right_diagonal_Down_Move = true;
		}
		if (Right_diagonal_Down_Check != 4)
		{
			Right_diagonal_Down_Move = false;
		}
		if (Left_diagonal_Check == 4)
		{
			Left_diagonal_Move = true;
		}
		if (Left_diagonal_Check != 4)
		{
			Left_diagonal_Move = false;
		}
		if (Left_diagonal_Down_Check == 4)
		{
			Left_diagonal_Down_Move = true;
		}
		if (Left_diagonal_Down_Check != 4)
		{
			Left_diagonal_Down_Move = false;
		}




		if (RightCheck == 4)
		{
			RightMove = true;
			CheckCamera = false;
		}
		if (RightCheck != 4)
		{
			RightMove = false;
		}
		if (LeftCheck == 4)
		{
			LeftMove = true;
			CheckCamera = false;
		}
		if (LeftCheck != 4)
		{
			LeftMove = false;
		}

		if (GravityCheck == 4)
		{
			Gravity = true;
			CheckCamera = false;
		}
		if (GravityCheck != 4 )
		{
			Gravity = false;
		}

		if (UpCheck == 4)
		{
			UpMove = true;
			CheckCamera = false;
		}
		if (UpCheck != 4)
		{
			UpMove = false;
		}


		Right_diagonal_Check = 0;
		Right_diagonal_Down_Check = 0;
		Left_diagonal_Check = 0;
		Left_diagonal_Down_Check = 0;
		GravityCheck = 0;
		RightCheck = 0;
		LeftCheck = 0;	
		UpCheck = 0;

	UpdateState(_Delta);
}

void OverHead_Player::Render(float _Delta)
{


}

void OverHead_Player::AnimationCheck(const std::string_view& _AnimationName)
{
	Player->ChangeAnimation(_AnimationName);
}

void OverHead_Player::AnimationCheck(const std::string_view& _AnimationName, bool Force, size_t Frame)
{

}


