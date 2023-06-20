#include "PrecompileHeader.h"
#include "UserInterface.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.cpp"
#include <GameEngineCore/GameEngineUIRenderer.h>

float UserInterface::Cut = 0.0f;
UserInterface::UserInterface()
{

}

UserInterface::~UserInterface()
{

}

void UserInterface::Start()
{
	
	if (nullptr == GameEngineSprite::Find("FrontCard"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("UI");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("FrontCard").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("BackCard").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("FlipCard").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("HPBar").GetFullPath());
	}


	Hp3 = CreateComponent<GameEngineUIRenderer>();
	Hp3->GetTransform()->AddLocalPosition({ -570,-320 });
	Hp3->SetScaleToTexture("hud_hp_3.png");
	Hp3->On(); 

	Hp2 = CreateComponent<GameEngineUIRenderer>();
	Hp2->SetScaleToTexture("hud_hp_2.png");
	Hp2->GetTransform()->AddLocalPosition({ -570,-320 });
	Hp2->Off();

	Hp1 = CreateComponent<GameEngineUIRenderer>();
	Hp1->GetTransform()->AddLocalPosition({ -570,-320 });
	Hp1->SetScaleToTexture("hud_hp_1.png");
	Hp1->Off();

	BackCard = CreateComponent<GameEngineUIRenderer>();
	BackCard->GetTransform()->AddLocalPosition({ -510,-320 });
	BackCard->SetScaleToTexture("hud_ch_card_Back.png");
	BackCard->On();

	BackCard2 = CreateComponent<GameEngineUIRenderer>();
	BackCard2->GetTransform()->AddLocalPosition({ -490,-320 });
	BackCard2->SetScaleToTexture("hud_ch_card_Back.png");
	BackCard2->On();

	BackCard3 = CreateComponent<GameEngineUIRenderer>();
	BackCard3->GetTransform()->AddLocalPosition({ -470,-320 });
	BackCard3->SetScaleToTexture("hud_ch_card_Back.png");
	BackCard3->On();

	BackCard4 = CreateComponent<GameEngineUIRenderer>();
	BackCard4->GetTransform()->AddLocalPosition({ -450,-320 });
	BackCard4->SetScaleToTexture("hud_ch_card_Back.png");
	BackCard4->On();

	BackCard5 = CreateComponent<GameEngineUIRenderer>();
	BackCard5->GetTransform()->AddLocalPosition({ -430,-320 });
	BackCard5->SetScaleToTexture("hud_ch_card_Back.png");
	BackCard5->On();

	BackCard->ImageClippingY(0.0f, ClipYDir::Top);
	BackCard2->ImageClippingY(0.0f, ClipYDir::Top);
	BackCard3->ImageClippingY(0.0f, ClipYDir::Top);
	BackCard4->ImageClippingY(0.0f, ClipYDir::Top);
	BackCard5->ImageClippingY(0.0f, ClipYDir::Top);

	FlipCard = CreateComponent<GameEngineUIRenderer>();
	FlipCard->CreateAnimation({ .AnimationName = "FlipCard", .SpriteName = "FlipCard", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	FlipCard->ChangeAnimation("FlipCard");
	FlipCard->Off();
	FlipCard->GetTransform()->AddLocalPosition({ -510,-320 });


	FlipCard2 = CreateComponent<GameEngineUIRenderer>();
	FlipCard2->CreateAnimation({ .AnimationName = "FlipCard", .SpriteName = "FlipCard", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	FlipCard2->ChangeAnimation("FlipCard");
	FlipCard2->Off();
	FlipCard2->GetTransform()->AddLocalPosition({ -490,-320 });

	FlipCard3 = CreateComponent<GameEngineUIRenderer>();
	FlipCard3->CreateAnimation({ .AnimationName = "FlipCard", .SpriteName = "FlipCard", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	FlipCard3->ChangeAnimation("FlipCard");
	FlipCard3->Off();
	FlipCard3->GetTransform()->AddLocalPosition({ -470,-320 });


	FlipCard4 = CreateComponent<GameEngineUIRenderer>();
	FlipCard4->CreateAnimation({ .AnimationName = "FlipCard", .SpriteName = "FlipCard", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	FlipCard4->ChangeAnimation("FlipCard");
	FlipCard4->Off();
	FlipCard4->GetTransform()->AddLocalPosition({ -450,-320 });


	FlipCard5 = CreateComponent<GameEngineUIRenderer>();
	FlipCard5->CreateAnimation({ .AnimationName = "FlipCard", .SpriteName = "FlipCard", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	FlipCard5->ChangeAnimation("FlipCard");
	FlipCard5->Off();
	FlipCard5->GetTransform()->AddLocalPosition({ -430,-320 });


	/*FlipCard = CreateComponent<GameEngineSpriteRenderer>();
	FlipCard->CreateAnimation({ .AnimationName = "FlipCard", .SpriteName = "FlipCard", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	FlipCard->ChangeAnimation("FlipCard");
	FlipCard->Off();*/

//GameEngineCamera
}

void UserInterface::Update(float _Delta)
{
	
	


	switch (CardNumber)	
	{
		case 0:
		{
			if (Cut >= 1.0f)
			{
				BackCard->Off();
				BackCard2->On();
				Cut = 0.0f;
				FlipCard->On();
				++CardNumber;
				break;
			}
			BackCard->ImageClippingY(Cut, ClipYDir::Bot);
		}
		break;

		case 1:
		{
			if (Cut >= 1.0f)
			{
				BackCard2->Off();
				BackCard3->On();
				FlipCard2->On();
				Cut = 0.0f;
				++CardNumber;
				break;
			}
			BackCard2->ImageClippingY(Cut, ClipYDir::Bot);
		}
		break;
		case 2:
		{
			if (Cut >= 1.0f)
			{
				BackCard3->Off();
				BackCard4->On();
				FlipCard3->On();
				Cut = 0.0f;
				++CardNumber;
				break;
			}
			BackCard3->ImageClippingY(Cut, ClipYDir::Bot);
		}
		break;
		case 3:
		{
			if (Cut >= 1.0f)
			{
				BackCard4->Off();
				BackCard5->On();
				FlipCard4->On();
				Cut = 0.0f;
				++CardNumber;
				break;
			}
			BackCard4->ImageClippingY(Cut, ClipYDir::Bot);
		}
		break;
		case 4:
		{
			if (Cut >= 1.0f)
			{
				BackCard5->Off();
				FlipCard5->On();
				Cut = 0.0f;
				++CardNumber;
				break;
			}
			BackCard5->ImageClippingY(Cut, ClipYDir::Bot);
		}
		break;

	default:
		break;
	}
	










}
