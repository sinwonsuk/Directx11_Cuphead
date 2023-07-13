#include "PrecompileHeader.h"
#include "UserInterface.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"
#include <GameEngineCore/GameEngineUIRenderer.h>

float UserInterface::Cut = 0.0f;
int UserInterface::CardNumber = 0;

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
	Hp3->GetTransform()->AddLocalPosition({ -570,-320,-300.0f });
	Hp3->SetScaleToTexture("hud_hp_3.png");
	Hp3->On(); 

	Hp2 = CreateComponent<GameEngineUIRenderer>();
	Hp2->SetScaleToTexture("hud_hp_2.png");
	Hp2->GetTransform()->AddLocalPosition({ -570,-320,-300.0f });
	Hp2->Off();

	Hp1 = CreateComponent<GameEngineUIRenderer>();
	Hp1->GetTransform()->AddLocalPosition({ -570,-320 ,-300.0f });
	Hp1->SetScaleToTexture("hud_hp_1.png");
	Hp1->Off();

	BackCard = CreateComponent<GameEngineUIRenderer>();
	BackCard->GetTransform()->AddLocalPosition({ -510,-320 ,-300.0f });
	BackCard->SetScaleToTexture("hud_ch_card_Back.png");
	BackCard->On();

	BackCard2 = CreateComponent<GameEngineUIRenderer>();
	BackCard2->GetTransform()->AddLocalPosition({ -490,-320 ,-300.0f });
	BackCard2->SetScaleToTexture("hud_ch_card_Back.png");
	BackCard2->On();

	BackCard3 = CreateComponent<GameEngineUIRenderer>();
	BackCard3->GetTransform()->AddLocalPosition({ -470,-320,-300.0f });
	BackCard3->SetScaleToTexture("hud_ch_card_Back.png");
	BackCard3->On();

	BackCard4 = CreateComponent<GameEngineUIRenderer>();
	BackCard4->GetTransform()->AddLocalPosition({ -450,-320 ,-300.0f });
	BackCard4->SetScaleToTexture("hud_ch_card_Back.png");
	BackCard4->On();

	BackCard5 = CreateComponent<GameEngineUIRenderer>();
	BackCard5->GetTransform()->AddLocalPosition({ -430,-320 ,-300.0f });
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
	FlipCard->GetTransform()->AddLocalPosition({ -510,-320,-300.0f });


	FlipCard2 = CreateComponent<GameEngineUIRenderer>();
	FlipCard2->CreateAnimation({ .AnimationName = "FlipCard", .SpriteName = "FlipCard", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	FlipCard2->ChangeAnimation("FlipCard");
	FlipCard2->Off();
	FlipCard2->GetTransform()->AddLocalPosition({ -490,-320,-300.0f });

	FlipCard3 = CreateComponent<GameEngineUIRenderer>();
	FlipCard3->CreateAnimation({ .AnimationName = "FlipCard", .SpriteName = "FlipCard", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	FlipCard3->ChangeAnimation("FlipCard");
	FlipCard3->Off();
	FlipCard3->GetTransform()->AddLocalPosition({ -470,-320 ,-300.0f });


	FlipCard4 = CreateComponent<GameEngineUIRenderer>();
	FlipCard4->CreateAnimation({ .AnimationName = "FlipCard", .SpriteName = "FlipCard", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	FlipCard4->ChangeAnimation("FlipCard");
	FlipCard4->Off();
	FlipCard4->GetTransform()->AddLocalPosition({ -450,-320 ,-300.0f });


	FlipCard5 = CreateComponent<GameEngineUIRenderer>();
	FlipCard5->CreateAnimation({ .AnimationName = "FlipCard", .SpriteName = "FlipCard", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	FlipCard5->ChangeAnimation("FlipCard");
	FlipCard5->Off();
	FlipCard5->GetTransform()->AddLocalPosition({ -430,-320 ,-300.0f });


	/*FlipCard = CreateComponent<GameEngineSpriteRenderer>();
	FlipCard->CreateAnimation({ .AnimationName = "FlipCard", .SpriteName = "FlipCard", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	FlipCard->ChangeAnimation("FlipCard");
	FlipCard->Off();*/

//GameEngineCamera
}

void UserInterface::Update(float _Delta)
{

	if (CardNumber < 5)
	{
		Test = false;
	}

	if (PrevConsumeCard != CardNumber)
	{
		switch (CardNumber)
		{
		case 0:
		{
			if (Cut <= 0.0f)
			{
				Cut = 0.0f;
				CardNumber = 0;
				BackCard->ImageClippingY(Cut, ClipYDir::Top);
				BackCard->On();
				FlipCard->ChangeAnimation("FlipCard");
				FlipCard->Off();
			}

			else 
			{
				CardNumber = 0;

				
				BackCard->Off();
				FlipCard->ChangeAnimation("FlipCard");
				FlipCard->Off();

				BackCard2->Off();
				FlipCard2->ChangeAnimation("FlipCard");
				FlipCard2->Off();

				BackCard->ImageClippingY(Cut, ClipYDir::Top);
				BackCard->On();
			}

		}
		break;

		case 1:
		{

			if (Cut <= 0.0f)
			{
				Cut = 0.0f;
				CardNumber = 1;
				BackCard2->ImageClippingY(Cut, ClipYDir::Top);
				BackCard2->On();
				FlipCard2->ChangeAnimation("FlipCard");
				FlipCard2->Off();
			}

			else
			{
				CardNumber = 1;

				BackCard2->Off();
				FlipCard2->ChangeAnimation("FlipCard");
				FlipCard2->Off();

				BackCard3->Off();
				FlipCard3->ChangeAnimation("FlipCard");
				FlipCard3->Off();

				BackCard2->ImageClippingY(Cut, ClipYDir::Top);
				BackCard2->On();
			}
		}
		break;
		case 2:
		{
			if (Cut <= 0.0f)
			{
				Cut = 0.0f;
				CardNumber = 2;
				BackCard3->ImageClippingY(Cut, ClipYDir::Top);
				BackCard3->On();
				FlipCard3->ChangeAnimation("FlipCard");
				FlipCard3->Off();
			}

			else
			{
				CardNumber = 2;

				BackCard3->Off();
				FlipCard3->ChangeAnimation("FlipCard");
				FlipCard3->Off();

				BackCard4->Off();
				FlipCard4->ChangeAnimation("FlipCard");
				FlipCard4->Off();

				BackCard3->ImageClippingY(Cut, ClipYDir::Top);
				BackCard3->On();
			}
		}
		break;
		case 3:
		{
			if (Cut <= 0.0f)
			{
				Cut = 0.0f;
				CardNumber = 3;
				BackCard4->ImageClippingY(Cut, ClipYDir::Top);
				BackCard4->On();
				FlipCard4->ChangeAnimation("FlipCard");
				FlipCard4->Off();
			}

			else
			{
				CardNumber = 3;

				BackCard4->Off();
				FlipCard4->ChangeAnimation("FlipCard");
				FlipCard4->Off();

				BackCard5->Off();
				FlipCard5->ChangeAnimation("FlipCard");
				FlipCard5->Off();

				BackCard4->ImageClippingY(Cut, ClipYDir::Top);
				BackCard4->On();
			}

		}
		break;

		case 4:
		{
		    if(Cut <= 0.0f)

		    {		       
		    	Cut = 0.0f;
		    	CardNumber = 4;
		    	BackCard5->ImageClippingY(Cut, ClipYDir::Top);
		    	BackCard5->On();
		    	FlipCard5->ChangeAnimation("FlipCard");
		    	FlipCard5->Off();
		    }

			else
			{
				
				CardNumber = 4;
				//BackCard5->ImageClippingY(Cut, ClipYDir::Top);
				BackCard5->Off();
				FlipCard5->ChangeAnimation("FlipCard");
				FlipCard5->Off();
			}



		}
		break;
		default:
			break;
		}
	}





	if (PlusCard != CardNumber)
	{
		switch (CardNumber)
		{
		case 1:
		{
			if (Cut <= 0.0f)
			{
				Cut = 0.0f;
				CardNumber = 1;
				BackCard->ImageClippingY(Cut, ClipYDir::Top);
				BackCard->On();
				FlipCard->ChangeAnimation("FlipCard");
				FlipCard->On();
			}
			else
			{
				float PrevCut = Cut;
				CardNumber = 1;
				Cut = 1.0f;


				BackCard->ImageClippingY(Cut, ClipYDir::Top);
				BackCard->Off();
				FlipCard->On();

			/*	FlipCard->ChangeAnimation("FlipCard");
				FlipCard->On();*/


				BackCard2->On();
				BackCard2->ImageClippingY(PrevCut, ClipYDir::Top);
				BackCard2->On();
				Cut = PrevCut;
				FlipCard2->ChangeAnimation("FlipCard");
				FlipCard2->Off();

			}

		}
		break;

		case 2:
		{

			if (Cut <= 0.0f)
			{
				Cut = 0.0f;
				CardNumber = 2;
				BackCard2->ImageClippingY(Cut, ClipYDir::Top);
				BackCard2->On();
				FlipCard2->ChangeAnimation("FlipCard");
				FlipCard2->On();
			}
			else
			{
				float PrevCut = Cut;
				CardNumber = 2;
				Cut = 1.0f;

				BackCard2->ImageClippingY(Cut, ClipYDir::Top);
				BackCard2->Off();

				FlipCard2->On();

			/*	FlipCard2->ChangeAnimation("FlipCard");
				FlipCard2->On();*/

				BackCard3->On();
				BackCard3->ImageClippingY(PrevCut, ClipYDir::Top);
				BackCard3->On();
				Cut = PrevCut;
				FlipCard3->ChangeAnimation("FlipCard");
				FlipCard3->Off();

			}
		}
		break;
		case 3:
		{
			if (Cut <= 0.0f)
			{
				Cut = 0.0f;
				CardNumber = 3;
				BackCard3->ImageClippingY(Cut, ClipYDir::Top);
				BackCard3->On();
				FlipCard3->ChangeAnimation("FlipCard");
				FlipCard3->On();
			}
			else
			{
				float PrevCut = Cut;
				CardNumber = 3;

				Cut = 1.0f;
				BackCard3->ImageClippingY(Cut, ClipYDir::Top);
				BackCard3->Off();
				FlipCard3->On();

			
				BackCard4->On();
				BackCard4->ImageClippingY(PrevCut, ClipYDir::Top);
				BackCard4->On();
				Cut = PrevCut;
				FlipCard4->ChangeAnimation("FlipCard");
				FlipCard4->Off();

			}
		}
		break;
		case 4:
		{
			if (Cut <= 0.0f)
			{
				Cut = 0.0f;
				CardNumber = 4;
				BackCard4->ImageClippingY(Cut, ClipYDir::Top);
				BackCard4->On();
				FlipCard4->ChangeAnimation("FlipCard");
				FlipCard4->On();
			}
			else
			{
				float Cutad = Cut;
				float PrevCut = Cut;
				CardNumber = 4;
				Cut = 1.0f;
				BackCard4->ImageClippingY(Cut, ClipYDir::Top);
				BackCard4->Off();
				FlipCard4->On();

		

				BackCard5->On();
				BackCard5->ImageClippingY(PrevCut, ClipYDir::Top);
				BackCard5->On();
				Cut = PrevCut;
				FlipCard5->ChangeAnimation("FlipCard");
				FlipCard5->Off();

			}

		}
		break;

		case 5:
		{		
			if (Test == false)
			{
				float PrevCut = Cut;
				CardNumber = 5;
				Cut = 1.0f;
				BackCard5->ImageClippingY(Cut, ClipYDir::Top);
				BackCard5->Off();
				FlipCard5->On();



			}

		}
		break;
		default:
			break;
		}


	}



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
	
	
	if (CardNumber >=5)
	{
		CardNumber = 5;
		Cut = 0.0f;
		Test = true;
	}
	
	if (CardNumber == 0)
	{
		FlipCard2->Off(); 
		FlipCard3->Off(); 
		FlipCard4->Off(); 
		FlipCard5->Off(); 

	}


	PlusCard = CardNumber;
	PrevConsumeCard = CardNumber;

}
