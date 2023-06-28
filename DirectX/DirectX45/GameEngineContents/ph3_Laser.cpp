#include "PrecompileHeader.h"
#include "ph3_Laser.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"

ph3_Laser::ph3_Laser()
{
}

ph3_Laser::~ph3_Laser()
{
}

void ph3_Laser::Start()
{
	int a = 0;
	if (nullptr == GameEngineSprite::Find("ph3_laser_warning_mid"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");


		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_beam_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_aura_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_particle_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_top").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_ring_top").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_mid").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_particle_mid").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_beam_mid").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_electric_mid").GetFullPath());

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_beam_low").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_low").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_laser_warning_aura_Low").GetFullPath());
	}


	//Top
	{
		ph3_laser_warning_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_warning_top->CreateAnimation({ .AnimationName = "ph3_laser_warning_top", .SpriteName = "ph3_laser_warning_top", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
		ph3_laser_warning_top->ChangeAnimation("ph3_laser_warning_top");
		ph3_laser_warning_top->Off();
		ph3_laser_warning_top->GetTransform()->AddLocalPosition({ 160,-115 });

		ph3_beam_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_beam_top->CreateAnimation({ .AnimationName = "ph3_beam_top", .SpriteName = "ph3_beam_top", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph3_beam_top->ChangeAnimation("ph3_beam_top");
		ph3_beam_top->GetTransform()->AddLocalPosition({ 30,0,0 });
		ph3_beam_top->Off();


		ph3_laser_warning_aura_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_warning_aura_top->CreateAnimation({ .AnimationName = "ph3_laser_warning_aura_top", .SpriteName = "ph3_laser_warning_aura_top", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
		ph3_laser_warning_aura_top->ChangeAnimation("ph3_laser_warning_aura_top");
		ph3_laser_warning_aura_top->GetTransform()->AddLocalPosition({ -180, 190 });
		ph3_laser_warning_aura_top->Off(); 


		ph3_laser_warning_particle_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_warning_particle_top->CreateAnimation({ .AnimationName = "ph3_laser_warning_particle_top", .SpriteName = "ph3_laser_warning_particle_top", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
		ph3_laser_warning_particle_top->ChangeAnimation("ph3_laser_warning_particle_top");

		ph3_laser_warning_particle_top->GetTransform()->AddLocalPosition({ -180,190 });
		ph3_laser_warning_particle_top->Off();

		ph3_laser_warning_ring_top = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_warning_ring_top->CreateAnimation({ .AnimationName = "ph3_laser_warning_ring_top", .SpriteName = "ph3_laser_warning_ring_top", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
		ph3_laser_warning_ring_top->ChangeAnimation("ph3_laser_warning_ring_top");
		ph3_laser_warning_ring_top->Off();

		ph3_laser_warning_ring_top->GetTransform()->AddLocalPosition({ -180,190 });		
	}

	// mid
	{
		ph3_laser_warning_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_warning_mid->CreateAnimation({ .AnimationName = "ph3_laser_warning_mid", .SpriteName = "ph3_laser_warning_mid", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph3_laser_warning_mid->ChangeAnimation("ph3_laser_warning_mid");
		ph3_laser_warning_mid->GetTransform()->AddLocalPosition({ 0,-190,-50 });
		ph3_laser_warning_mid->Off(); 

		ph3_laser_warning_particle_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_warning_particle_mid->CreateAnimation({ .AnimationName = "ph3_laser_warning_particle_mid", .SpriteName = "ph3_laser_warning_particle_mid", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph3_laser_warning_particle_mid->ChangeAnimation("ph3_laser_warning_particle_mid");
		ph3_laser_warning_particle_mid->GetTransform()->AddLocalPosition({ -320,60 });
		ph3_laser_warning_particle_mid->Off(); 


		ph3_beam_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_beam_mid->CreateAnimation({ .AnimationName = "ph3_beam_mid", .SpriteName = "ph3_beam_mid", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph3_beam_mid->ChangeAnimation("ph3_beam_mid");
		ph3_beam_mid->GetTransform()->AddLocalPosition({ 30,0,-50 });
		ph3_beam_mid->Off();

		ph3_laser_warning_electric_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_warning_electric_mid->CreateAnimation({ .AnimationName = "ph3_laser_warning_electric_mid", .SpriteName = "ph3_laser_warning_electric_mid", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph3_laser_warning_electric_mid->ChangeAnimation("ph3_laser_warning_electric_mid");
		ph3_laser_warning_electric_mid->GetTransform()->AddLocalPosition({ -327,67 });
		ph3_laser_warning_electric_mid->Off(); 
	}
	// low
	{
		ph3_beam_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_beam_low->CreateAnimation({ .AnimationName = "ph3_beam_low", .SpriteName = "ph3_beam_low", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph3_beam_low->ChangeAnimation("ph3_beam_low");
		ph3_beam_low->GetTransform()->AddLocalPosition({ 0,0,-10 });
		ph3_beam_low->Off(); 

		ph3_laser_Right_warning_aura_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Right_warning_aura_low->CreateAnimation({ .AnimationName = "ph3_laser_warning_aura_Low", .SpriteName = "ph3_laser_warning_aura_Low", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph3_laser_Right_warning_aura_low->ChangeAnimation("ph3_laser_warning_aura_Low");
		ph3_laser_Right_warning_aura_low->GetTransform()->AddLocalPosition({ 390,-220 });
		ph3_laser_Right_warning_aura_low->Off(); 


		ph3_laser_Left__warning_aura_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_Left__warning_aura_low->CreateAnimation({ .AnimationName = "ph3_laser_warning_aura_Low", .SpriteName = "ph3_laser_warning_aura_Low", .FrameInter = 0.05f,.Loop = false, .ScaleToTexture = true });
		ph3_laser_Left__warning_aura_low->ChangeAnimation("ph3_laser_warning_aura_Low");
		ph3_laser_Left__warning_aura_low->GetTransform()->AddLocalPosition({ -390,-220 });
		ph3_laser_Left__warning_aura_low->Off(); 


		ph3_laser_warning_low = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_warning_low->CreateAnimation({ .AnimationName = "ph3_laser_warning_low", .SpriteName = "ph3_laser_warning_low", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
		ph3_laser_warning_low->ChangeAnimation("ph3_laser_warning_low");
		ph3_laser_warning_low->GetTransform()->AddLocalPosition({ 0,-220,-10 });
		ph3_laser_warning_low->Off(); 
	}

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 0.0f, 0.0f, 300.0f });
	Collision->SetOrder((int)CollisionType::BossAttack);

	PinkCollision = CreateComponent<GameEngineCollision>();
	PinkCollision->GetTransform()->SetLocalScale({ 0.0f, 0.0f, 300.0f });
	PinkCollision->SetOrder((int)CollisionType::Ph3_Dog_Boss_Pink_Bullet);
	PinkCollision->Off(); 

	
	ParryEffect = CreateComponent<GameEngineSpriteRenderer>();
	ParryEffect->CreateAnimation({ .AnimationName = "ParryEffect", .SpriteName = "ParryEffect", .FrameInter = 0.08f, .Loop = false, .ScaleToTexture = true, });
	ParryEffect->ChangeAnimation("ParryEffect");
	ParryEffect->Off();


}

void ph3_Laser::Update(float _Delta)
{

		switch (laserDir)
		{
		case LaserDir::Left_Top:
		{
				if (LaserCheck == false)
				{
					if (dirCheck == false)
					{
						ph3_laser_warning_ring_top->On();
						ph3_laser_warning_aura_top->On();
						ph3_laser_warning_particle_top->On();
						ph3_laser_warning_top->On();
						dirCheck = true;
					}

					if (ph3_laser_warning_aura_top->IsAnimationEnd())
					{
						ph3_laser_warning_ring_top->Off();
						ph3_laser_warning_aura_top->Off();
						ph3_laser_warning_particle_top->Off();
						ph3_laser_warning_top->Off();
						ph3_beam_top->On();
					}

					if (ph3_laser_warning_aura_top->IsAnimationEnd())
					{
						Collision->On(); 
						Collision->GetTransform()->SetLocalScale({ 1200.0f, 25.0f, 300.0f });
						Collision->GetTransform()->SetLocalRotation({ 0.0f, 0.0f, -45.0f });
						Collision->GetTransform()->SetLocalPosition({ ph3_beam_top->GetTransform()->GetLocalPosition().x,ph3_beam_top->GetTransform()->GetLocalPosition().y, ph3_beam_top->GetTransform()->GetLocalPosition().z });
						ResetLiveTime();
					}

					if (GetLiveTime() > 0.3f)
					{
						Collision->Off();
					}


					if (ph3_beam_top->IsAnimationEnd())
					{
						ph3_beam_top->Off();
						ph3_laser_warning_aura_top->Off();
						ph3_laser_warning_particle_top->Off();
						ph3_laser_warning_top->Off();
						ph3_laser_warning_ring_top->Off();
						Collision->Off();
						LaserCheck = true;

					}
					
				}
		}
			break;
		case LaserDir::Left_Mid:
			if (LaserCheck == false)
			{
				if (dirCheck == false)
				{
					ph3_beam_mid->Off();
					ph3_laser_warning_mid->On();
					ph3_laser_warning_particle_mid->On();
					ph3_laser_warning_electric_mid->On();
					dirCheck = true;
				}
				if (ph3_laser_warning_electric_mid->IsAnimationEnd())
				{
					ph3_laser_warning_mid->Off();
					ph3_laser_warning_particle_mid->Off();
					ph3_laser_warning_electric_mid->Off();
					ph3_beam_mid->On();
				}

				if (ph3_laser_warning_electric_mid->IsAnimationEnd())
				{
					Collision->On();
					Collision->GetTransform()->SetLocalScale({ 1200.0f, 25.0f, 300.0f });
					Collision->GetTransform()->SetLocalRotation({ 0.0f, 0.0f, -45.0f });
					Collision->GetTransform()->SetLocalPosition({ ph3_beam_top->GetTransform()->GetLocalPosition().x,ph3_beam_top->GetTransform()->GetLocalPosition().y-280.0f, ph3_beam_top->GetTransform()->GetLocalPosition().z });
					ResetLiveTime();
				}
			

			    if (GetLiveTime() > 0.3f)
			    {
				   Collision->Off();
			    }


				if (ph3_beam_mid->IsAnimationEnd())
				{
					ph3_beam_mid->Off();
					ph3_laser_warning_mid->Off();
					ph3_laser_warning_particle_mid->Off();
					ph3_laser_warning_electric_mid->Off();
					Collision->Off();
					LaserCheck = true;
				}

			}
			break;
		case LaserDir::Left_Low:
			if (LaserCheck == false)
			{
				if (dirCheck == false)
				{
					ph3_laser_warning_low->On();
					ph3_laser_Left__warning_aura_low->On();
					ph3_laser_Right_warning_aura_low->On();
					dirCheck = true;
				}

				if (ph3_laser_Right_warning_aura_low->IsAnimationEnd())
				{
					ph3_laser_warning_low->Off();
					ph3_laser_Left__warning_aura_low->Off();
					ph3_laser_Right_warning_aura_low->Off();
					ph3_beam_low->On();
				}

				if (ph3_laser_Right_warning_aura_low->IsAnimationEnd())
				{
					PinkCollision->On();
					PinkCollision->GetTransform()->SetLocalScale({ 1200.0f, 50.0f, 300.0f });
					PinkCollision->GetTransform()->SetLocalPosition({ ph3_beam_top->GetTransform()->GetLocalPosition().x,ph3_beam_top->GetTransform()->GetLocalPosition().y-220.0f,ph3_beam_top->GetTransform()->GetLocalPosition().z });
					ResetLiveTime();
				}

				if (GetLiveTime() > 0.3f)
				{
					PinkCollision->Off();
				}

				if (ph3_beam_low->IsAnimationEnd())
				{
					ph3_beam_low->Off();
					ph3_laser_Right_warning_aura_low->Off();
					ph3_laser_Right_warning_aura_low->Off();
					ph3_laser_warning_low->Off();
					LaserCheck = true;
					PinkCollision->Off();

				}
			}
			

			break;
		case LaserDir::Right_Top:
			if (LaserCheck == false)
			{

				if (dirCheck == false)
				{

					ph3_laser_warning_ring_top->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_laser_warning_aura_top->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_laser_warning_particle_top->GetTransform()->SetLocalRotation({ 0,180,0 });

					ph3_laser_warning_ring_top->GetTransform()->SetLocalPosition({ 180,190 });
					ph3_laser_warning_aura_top->GetTransform()->SetLocalPosition({ 180, 190 });
					ph3_laser_warning_particle_top->GetTransform()->SetLocalPosition({ 180,190 });


					ph3_laser_warning_top->GetTransform()->AddLocalRotation({ 0,180,0 });
					ph3_laser_warning_top->GetTransform()->SetLocalPosition({ -160,-115 });


					ph3_beam_top->GetTransform()->AddLocalRotation({ 0,180,0 });
					ph3_beam_top->GetTransform()->SetLocalPosition({ -35,-10,0 });

					ph3_laser_warning_ring_top->On();
					ph3_laser_warning_aura_top->On();
					ph3_laser_warning_particle_top->On();
					ph3_laser_warning_top->On();


					dirCheck = true;
				}

				if (ph3_laser_warning_aura_top->IsAnimationEnd())
				{
					ph3_laser_warning_ring_top->Off();
					ph3_laser_warning_aura_top->Off();
					ph3_laser_warning_particle_top->Off();
					ph3_laser_warning_top->Off();
			
					ph3_beam_top->On();
				}

				if (ph3_laser_warning_aura_top->IsAnimationEnd())
				{
					Collision->On();
					Collision->GetTransform()->SetLocalScale({ 1200.0f, 25.0f, 300.0f });
					Collision->GetTransform()->SetLocalRotation({ 0.0f, 0.0f, -135.0f });
					Collision->GetTransform()->SetLocalPosition({ ph3_beam_top->GetTransform()->GetLocalPosition().x,ph3_beam_top->GetTransform()->GetLocalPosition().y, ph3_beam_top->GetTransform()->GetLocalPosition().z });
					ResetLiveTime(); 
				}

				if (GetLiveTime() > 0.3f)
				{
					Collision->Off();
				}

				if (ph3_beam_top->IsAnimationEnd())
				{
					ph3_beam_top->Off();
					ph3_laser_warning_aura_top->Off();
					ph3_laser_warning_particle_top->Off();
					ph3_laser_warning_top->Off();
					ph3_laser_warning_ring_top->Off();
					Collision->Off();
					LaserCheck = true;

				}
				
			}
			break;
		case LaserDir::Right_Mid:

			if (LaserCheck == false)
			{
				if (dirCheck == false)
				{
					ph3_beam_mid->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_laser_warning_mid->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_laser_warning_particle_mid->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_laser_warning_electric_mid->GetTransform()->SetLocalRotation({ 0,180,0 });

					ph3_beam_mid->GetTransform()->SetLocalPosition({ -30,0,-50 });
					ph3_laser_warning_mid->GetTransform()->SetLocalPosition({ 0,-190,-50 });
					ph3_laser_warning_particle_mid->GetTransform()->SetLocalPosition({ 320,60,0 });
					ph3_laser_warning_electric_mid->GetTransform()->SetLocalPosition({ 327,67,0 });


					ph3_beam_mid->Off();
					ph3_laser_warning_mid->On();
					ph3_laser_warning_particle_mid->On();
					ph3_laser_warning_electric_mid->On();
					dirCheck = true;


				}
				if (ph3_laser_warning_electric_mid->IsAnimationEnd())
				{
					ph3_laser_warning_mid->Off();
					ph3_laser_warning_particle_mid->Off();
					ph3_laser_warning_electric_mid->Off();
					ph3_beam_mid->On();
				}

				if (ph3_laser_warning_electric_mid->IsAnimationEnd())
				{
					Collision->On();
					Collision->GetTransform()->SetLocalScale({ 1200.0f, 25.0f, 300.0f });
					Collision->GetTransform()->SetLocalRotation({ 0.0f, 0.0f, -135.0f });
					Collision->GetTransform()->SetLocalPosition({ ph3_beam_top->GetTransform()->GetLocalPosition().x,ph3_beam_top->GetTransform()->GetLocalPosition().y-220.0f, ph3_beam_top->GetTransform()->GetLocalPosition().z });
					ResetLiveTime();
				}

				if (GetLiveTime() > 0.3f)
				{
					Collision->Off();
				}

				if (ph3_beam_mid->IsAnimationEnd())
				{
					ph3_beam_mid->Off();
					ph3_laser_warning_mid->Off();
					ph3_laser_warning_particle_mid->Off();
					ph3_laser_warning_electric_mid->Off();
					LaserCheck = true;
					Collision->Off();
				}
				
			}
			break;
		case LaserDir::Right_Low:




			break;
		case LaserDir::Left_Top_Reverse:
			if (LaserCheck == false)
			{
				if (dirCheck == false)
				{
					ph3_laser_warning_ring_top->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_laser_warning_aura_top->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_laser_warning_particle_top->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_laser_warning_top->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_beam_top->GetTransform()->SetLocalRotation({ 0,180,0 });

					ph3_laser_warning_ring_top->GetTransform()->SetLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x + 180,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y + 190,0 });
					ph3_laser_warning_aura_top->GetTransform()->SetLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x + 180,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y + 190,0 });
					ph3_laser_warning_particle_top->GetTransform()->SetLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x + 180,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y + 190,0 });
					ph3_laser_warning_top->GetTransform()->SetLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x - 160,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y - 115,-10 });
					ph3_beam_top->GetTransform()->SetLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x - 60,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y - 10,-10 });



					ph3_laser_warning_ring_top->On();
					ph3_laser_warning_aura_top->On();
					ph3_laser_warning_particle_top->On();
					ph3_laser_warning_top->On();
				}

				if (ph3_laser_warning_aura_top->IsAnimationEnd())
				{
					ph3_laser_warning_ring_top->Off();
					ph3_laser_warning_aura_top->Off();
					ph3_laser_warning_particle_top->Off();
					ph3_laser_warning_top->Off();
					ph3_beam_top->On();
				}

				if (ph3_laser_warning_aura_top->IsAnimationEnd())
				{
					Collision->On();
					Collision->GetTransform()->SetLocalScale({ 1200.0f, 25.0f, 300.0f });
					Collision->GetTransform()->SetLocalRotation({ 0.0f, 0.0f, -135.0f });
					Collision->GetTransform()->SetLocalPosition({ ph3_beam_top->GetTransform()->GetLocalPosition() });
					ResetLiveTime();
				}

				if (GetLiveTime() > 0.3f)
				{
					Collision->Off();
				}

				if (ph3_beam_top->IsAnimationEnd())
				{
					ph3_beam_top->Off();
					ph3_laser_warning_aura_top->Off();
					ph3_laser_warning_particle_top->Off();
					ph3_laser_warning_top->Off();
					ph3_laser_warning_ring_top->Off();
					LaserCheck = true;
					Collision->Off();
				}

			}
			break;
		case LaserDir::Right_Top_Reverse:
			if (LaserCheck == false)
			{
				if (dirCheck == false)
				{



					GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition();
					ph3_laser_warning_ring_top->GetTransform()->AddLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y,0 });
					ph3_laser_warning_aura_top->GetTransform()->AddLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y,0 });
					ph3_laser_warning_particle_top->GetTransform()->AddLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y,0 });
					ph3_laser_warning_top->GetTransform()->AddLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y,-10 });
					ph3_beam_top->GetTransform()->AddLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y,-10 });




					ph3_laser_warning_ring_top->On();
					ph3_laser_warning_aura_top->On();
					ph3_laser_warning_particle_top->On();
					ph3_laser_warning_top->On();


					dirCheck = true;
				}

				if (ph3_laser_warning_aura_top->IsAnimationEnd())
				{
					ph3_laser_warning_ring_top->Off();
					ph3_laser_warning_aura_top->Off();
					ph3_laser_warning_particle_top->Off();
					ph3_laser_warning_top->Off();
					ph3_beam_top->On();
				}


				if (ph3_laser_warning_aura_top->IsAnimationEnd())
				{
					Collision->On();
					Collision->GetTransform()->SetLocalScale({ 1200.0f, 25.0f, 300.0f });
					Collision->GetTransform()->SetLocalRotation({ 0.0f, 0.0f, -45.0f });
					Collision->GetTransform()->SetLocalPosition({ ph3_beam_top->GetTransform()->GetLocalPosition() });
					ResetLiveTime();
				}

				if (GetLiveTime() > 0.3f)
				{
					Collision->Off();
				}

				if (ph3_beam_top->IsAnimationEnd())
				{
					ph3_beam_top->Off();
					ph3_laser_warning_aura_top->Off();
					ph3_laser_warning_particle_top->Off();
					ph3_laser_warning_top->Off();
					ph3_laser_warning_ring_top->Off();
					Collision->Off();
					LaserCheck = true;
				}
			}
			break;
		case LaserDir::Left_Mid_Reverse:

			if (LaserCheck == false)
			{
				if (dirCheck == false)
				{
					ph3_beam_mid->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_laser_warning_mid->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_laser_warning_particle_mid->GetTransform()->SetLocalRotation({ 0,180,0 });
					ph3_laser_warning_electric_mid->GetTransform()->SetLocalRotation({ 0,180,0 });

					ph3_beam_mid->GetTransform()->SetLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x - 13,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y + 5,-50 });
					ph3_laser_warning_mid->GetTransform()->SetLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x + 17,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y - 185,-50 });
					ph3_laser_warning_particle_mid->GetTransform()->SetLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x + 339,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y + 84,0 });
					ph3_laser_warning_electric_mid->GetTransform()->SetLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x + 339,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y + 77,0 });



					ph3_beam_mid->Off();
					ph3_laser_warning_mid->On();
					ph3_laser_warning_particle_mid->On();
					ph3_laser_warning_electric_mid->On();
					dirCheck = true;


				}
				if (ph3_laser_warning_electric_mid->IsAnimationEnd())
				{
					ph3_laser_warning_mid->Off();
					ph3_laser_warning_particle_mid->Off();
					ph3_laser_warning_electric_mid->Off();
					ph3_beam_mid->On();
				}

				if (ph3_laser_warning_electric_mid->IsAnimationEnd())
				{
					Collision->On();
					Collision->GetTransform()->SetLocalScale({ 1200.0f, 25.0f, 300.0f });
					Collision->GetTransform()->SetLocalRotation({ 0.0f, 0.0f, -135.0f });
					Collision->GetTransform()->SetLocalPosition({ ph3_beam_top->GetTransform()->GetLocalPosition().x,ph3_beam_top->GetTransform()->GetLocalPosition().y - 240.0f, ph3_beam_top->GetTransform()->GetLocalPosition().z });
					ResetLiveTime();
				}

				if (GetLiveTime() > 0.3f)
				{
					Collision->Off();
				}
				if (ph3_beam_mid->IsAnimationEnd())
				{
					ph3_beam_mid->Off();
					ph3_laser_warning_mid->Off();
					ph3_laser_warning_particle_mid->Off();
					ph3_laser_warning_electric_mid->Off();
					LaserCheck = true;
					Collision->Off();
				}
			}
			


			break;
		case LaserDir::Low_Reverse:
			if (LaserCheck == false)
			{
				if (dirCheck == false)
				{
					ph3_laser_Right_warning_aura_low->GetTransform()->AddLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y,-10 });
					ph3_laser_Left__warning_aura_low->GetTransform()->AddLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y,-10 });
					ph3_laser_warning_low->GetTransform()->AddLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y,-10 });
					ph3_beam_low->GetTransform()->AddLocalPosition({ GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x,GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().y,-10 });


					ph3_laser_warning_low->On();
					ph3_laser_Left__warning_aura_low->On();
					ph3_laser_Right_warning_aura_low->On();
					dirCheck = true;
				}

				if (ph3_laser_Right_warning_aura_low->IsAnimationEnd())
				{
					ph3_laser_warning_low->Off();
					ph3_laser_Left__warning_aura_low->Off();
					ph3_laser_Right_warning_aura_low->Off();
					ph3_beam_low->On();
				}
				if (ph3_laser_Right_warning_aura_low->IsAnimationEnd())
				{
					PinkCollision->On();
					PinkCollision->GetTransform()->SetLocalScale({ 1000.0f, 50.0f, 300.0f });
					PinkCollision->GetTransform()->SetLocalPosition({ ph3_beam_top->GetTransform()->GetLocalPosition().x,ph3_beam_top->GetTransform()->GetLocalPosition().y - 220.0f,ph3_beam_top->GetTransform()->GetLocalPosition().z });
					ResetLiveTime();

				}

				if (GetLiveTime() > 0.3f)
				{
					PinkCollision->Off();
				}
				if (ph3_beam_low->IsAnimationEnd())
				{
					ph3_beam_low->Off();
					ph3_laser_Right_warning_aura_low->Off();
					ph3_laser_Right_warning_aura_low->Off();
					ph3_laser_warning_low->Off();
					PinkCollision->Off();
					LaserCheck = true;
				}
			}


			break;
		default:
			break;
		}
	if(ParryEffect->IsAnimationEnd())
	{
		ParryEffect->Off(); 
	}
}
