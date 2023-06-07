#include "PrecompileHeader.h"
#include "ph3_Laser.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>

ph3_Laser::ph3_Laser()
{
}

ph3_Laser::~ph3_Laser()
{
}

void ph3_Laser::Start()
{
	if (nullptr == GameEngineSprite::Find("ph3_beam_top"))
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

	}


	//Top
	//{
	//	ph3_laser_warning_top = CreateComponent<GameEngineSpriteRenderer>();
	//	ph3_laser_warning_top->CreateAnimation({ .AnimationName = "ph3_laser_warning_top", .SpriteName = "ph3_laser_warning_top", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	//	ph3_laser_warning_top->ChangeAnimation("ph3_laser_warning_top");
	//	ph3_laser_warning_top->On();
	//	ph3_laser_warning_top->GetTransform()->AddLocalPosition({ 160,-115 });

	//	ph3_beam_top = CreateComponent<GameEngineSpriteRenderer>();
	//	ph3_beam_top->CreateAnimation({ .AnimationName = "ph3_beam_top", .SpriteName = "ph3_beam_top", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
	//	ph3_beam_top->ChangeAnimation("ph3_beam_top");
	//	ph3_beam_top->GetTransform()->AddLocalPosition({ 30,0,0 });
	//	ph3_beam_top->Off();


	//	ph3_laser_warning_aura_top = CreateComponent<GameEngineSpriteRenderer>();
	//	ph3_laser_warning_aura_top->CreateAnimation({ .AnimationName = "ph3_laser_warning_aura_top", .SpriteName = "ph3_laser_warning_aura_top", .FrameInter = 0.08f,.Loop = false, .ScaleToTexture = true });
	//	ph3_laser_warning_aura_top->ChangeAnimation("ph3_laser_warning_aura_top");
	//	ph3_laser_warning_aura_top->GetTransform()->AddLocalPosition({ -180, 190 });
	//	//ph3_laser_warning_aura_top->Off(); 


	//	ph3_laser_warning_particle_top = CreateComponent<GameEngineSpriteRenderer>();
	//	ph3_laser_warning_particle_top->CreateAnimation({ .AnimationName = "ph3_laser_warning_particle_top", .SpriteName = "ph3_laser_warning_particle_top", .FrameInter = 0.08f,.Loop = false, .ScaleToTexture = true });
	//	ph3_laser_warning_particle_top->ChangeAnimation("ph3_laser_warning_particle_top");

	//	ph3_laser_warning_particle_top->GetTransform()->AddLocalPosition({ -180,190 });
	//	//ph3_laser_warning_particle_top->Off();

	//	ph3_laser_warning_ring_top = CreateComponent<GameEngineSpriteRenderer>();
	//	ph3_laser_warning_ring_top->CreateAnimation({ .AnimationName = "ph3_laser_warning_ring_top", .SpriteName = "ph3_laser_warning_ring_top", .FrameInter = 0.08f,.Loop = false, .ScaleToTexture = true });
	//	ph3_laser_warning_ring_top->ChangeAnimation("ph3_laser_warning_ring_top");
	//	//ph3_laser_warning_ring_top->Off();

	//	ph3_laser_warning_ring_top->GetTransform()->AddLocalPosition({ -180,190 });		
	//}
	// mid
	{
		ph3_laser_warning_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_warning_mid->CreateAnimation({ .AnimationName = "ph3_laser_warning_mid", .SpriteName = "ph3_laser_warning_mid", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
		ph3_laser_warning_mid->ChangeAnimation("ph3_laser_warning_mid");
		
		ph3_laser_warning_particle_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_warning_particle_mid->CreateAnimation({ .AnimationName = "ph3_laser_warning_particle_mid", .SpriteName = "ph3_laser_warning_particle_mid", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
		ph3_laser_warning_particle_mid->ChangeAnimation("ph3_laser_warning_particle_mid");

		ph3_beam_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_beam_mid->CreateAnimation({ .AnimationName = "ph3_beam_mid", .SpriteName = "ph3_beam_mid", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
		ph3_beam_mid->ChangeAnimation("ph3_beam_mid");

		ph3_laser_warning_electric_mid = CreateComponent<GameEngineSpriteRenderer>();
		ph3_laser_warning_electric_mid->CreateAnimation({ .AnimationName = "ph3_laser_warning_electric_mid", .SpriteName = "ph3_laser_warning_electric_mid", .FrameInter = 0.1f,.Loop = false, .ScaleToTexture = true });
		ph3_laser_warning_electric_mid->ChangeAnimation("ph3_laser_warning_electric_mid");




	}






}

void ph3_Laser::Update(float _Delta)
{
		switch (laserDir)
		{
		case LaserDir::Left_Top:
		{
			if (ph3_laser_warning_aura_top->IsAnimationEnd())
			{
				ph3_laser_warning_ring_top->Off(); 
				ph3_laser_warning_aura_top->Off();
				ph3_laser_warning_particle_top->Off();
				ph3_laser_warning_top->Off();

				ph3_beam_top->On();
			}


			if (ph3_beam_top->IsAnimationEnd())
			{
				ph3_beam_top->Off();
				ph3_laser_warning_aura_top->Off();
				ph3_laser_warning_particle_top->Off();
				ph3_laser_warning_top->Off();
				ph3_laser_warning_ring_top->Off();
			}

		}
			break;
		case LaserDir::Left_Mid:



			break;
		case LaserDir::Left_Low:



			break;
		case LaserDir::Right_Top:



			break;
		case LaserDir::Right_Mid:



			break;
		case LaserDir::Right_Low:




			break;
		default:
			break;
		}
	
}
