#include "PrecompileHeader.h"
#include "Ph2_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Ph2_Bepi_Weapon.h"
#include "Crown_Bepi_Level.h"
void Ph2_Bepi::ChangeState(Ph2_Bepi_State _State)
{
	Ph2_Bepi_State NextState = _State;
	Ph2_Bepi_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Ph2_Bepi_State::BossIntro:

		break;
	
	case Ph2_Bepi_State::BossIdle:
	
		break;
	
	case Ph2_Bepi_State::BossFinish:
		AnimationCheck("Phase2_End");
		break;

	default:
		break;
	}


}






void Ph2_Bepi::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Ph2_Bepi_State::BossIntro:
		BossIntroUpdate(_Time);
		break;
	case Ph2_Bepi_State::BossIdle:
		BossIdleUpdate(_Time);
		break;
	case Ph2_Bepi_State::BossFinish:
		BossFinishUpdate(_Time);
		break;

	default:
		break;
	}



}



void Ph2_Bepi::BossIntroUpdate(float _Time)
{
	Collision->Off(); 

	if (GetTransform()->GetLocalPosition().y < -300.0f)
	{
		GetTransform()->AddLocalPosition({ 0,1.0f* _Time* 500 });
	}
	TransformData date = GetTransform()->GetTransDataRef();
	//GetTransform()->AddLocalPosition({ 0,1.0f });

	if (GetTransform()->GetLocalPosition().y >= -300.0f)
	{
		LeftHeliumBottle_Texture->Off();
		RightHeliumBottle_Texture->Off();
		Phase2_Intro_Texture->Off();

		LeftHeliumPipes_Intro->On();
		RightHeliumPipes_Intro->On();
		Phase2_Intro->On();
		RightHeliumBottle->On();
		LeftHeliumBottle->On();

		if (Sound_Intro_Check == false)
		{
			Intro = GameEngineSound::Play("clown_helium_intro_continue_01.wav");
			Intro.SetVolume(5.0f);
			Sound_Intro_Check = true;
		}

	}

	if (Phase2_Intro->IsAnimationEnd())
	{
		Phase2_Intro->GetTransform()->AddLocalPosition({ 0.0f,-150.0f,0.0f });
		Phase2_Body_Front->GetTransform()->AddLocalPosition({ 0.0f,-150.0f,0.0f });
		Phase2_Idle_Head->GetTransform()->AddLocalPosition({ 0.0f,-150.0f,0.0f });
		Phase2_Intro->ChangeAnimation("Phase2_Body_Back");
		Phase2_Body_Front->On();

		Phase2_Idle_Head->On();
	

	}


	if (RightHeliumPipes_Intro->IsAnimationEnd())
	{
		RightHeliumPipes_Intro->ChangeAnimation("HeliumPipes_Idle");
		
	}
	if (LeftHeliumPipes_Intro->IsAnimationEnd())
	{
		LeftHeliumPipes_Intro->ChangeAnimation("HeliumPipes_Idle");
		ResetLiveTime(); 
		ChangeState(Ph2_Bepi_State::BossIdle);
		return;

	}


}

void Ph2_Bepi::BossFinishUpdate(float _Time)
{
	Phase2_Idle_Head->GetTransform()->AddLocalPosition({ float4::Up * 500.0f * _Time });
	GetTransform()->AddLocalPosition({ float4::Down * 500.0f * _Time });

	//Phase2_Idle_Head
	if (Boss_Exploision_Number < 5)
	{
		if (Phase2_Idle_Head->GetLiveTime() > 0.03f)
		{
			Boss_Exploision_Pos.x = GameEngineRandom::MainRandom.RandomFloat(-100.0f, 100.0f);
			Boss_Exploision_Pos.y = GameEngineRandom::MainRandom.RandomFloat(100.0f, 200.0f);

			if (Boss_Exploision_Check == false)
			{
				BossExploision->ChangeAnimation("Bepi_boss_explosion");
				BossExploision->On();
				BossExploision->GetTransform()->SetWorldPosition({ Boss_Exploision_Pos.x,Boss_Exploision_Pos.y });
				Boss_Exploision_Check = true;
			}


			if (BossExploision->IsAnimationEnd())
			{
				++Boss_Exploision_Number;
				Boss_Exploision_Check = false;
				BossExploision->Off();
				Phase2_Idle_Head->ResetLiveTime();
			}

		}
	}
	if (Boss_Exploision_Number > 4)
	{
		Phase2_Idle_Head->GetTransform()->AddLocalPosition({ float4::Up * 500.0f * _Time });
	}
	
	if (Phase2_Idle_Head->GetTransform()->GetLocalRotation().y > 500.0f)
	{
	
		
	}

	if (GetLiveTime() > 5)
	{
		Crown_Bepi_Level* Level = (Crown_Bepi_Level*)GetLevel();
		Level->PaseCheck = Pase::Pase3;
		this->Death();
	}
}

void Ph2_Bepi::BossIdleUpdate(float _Time)
{

	helium_pipe_puff_Time += _Time; 


	Collision->On(); 
	



	if (GetLiveTime() > 2)
	{
	
		AttackCheck = GameEngineRandom::MainRandom.RandomInt(0, 5);
		AttackColor = GameEngineRandom::MainRandom.RandomInt(0, 3);

		if (Sound_Attack_Check == false)
		{
			Attack = GameEngineSound::Play("clown_dog_balloon_regular_intro_01.wav");
			Attack.SetVolume(1.5f);
			Sound_Attack_Check = true;
		}


		switch (AttackCheck)
		{
		case 0:
		{
			if (AttackColor == 1)
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object->GetTransform()->AddLocalPosition({ -560.0f,-20.0f });
				Object->color = Color::Pink;
			}
			else
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object->GetTransform()->AddLocalPosition({ -560.0f,-20.0f });
			}
			
		}
		break;
		case 1:
		{
			if (AttackColor == 1)
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object1 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object1->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
				Object1->directon = Dir::Left;
				Object1->color = Color::Pink;
				Object1->GetTransform()->AddLocalPosition({ 560.0f,-20.0f });

			}
			else
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object1 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object1->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
				Object1->directon = Dir::Left;
				Object1->GetTransform()->AddLocalPosition({ 560.0f,-20.0f });
			}
		
		}
		break;
		case 2:
		{
			if (AttackColor == 1)
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object3 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object3->GetTransform()->AddLocalPosition({ -520.0f,245.0f });
				Object3->color = Color::Pink;
			}
			else
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object3 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object3->GetTransform()->AddLocalPosition({ -520.0f,245.0f });
			}
		
		}
		break;
		case 3:
		{
			if (AttackColor == 1)
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object4 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object4->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
				Object4->directon = Dir::Left;
				Object4->color = Color::Pink;
				Object4->GetTransform()->AddLocalPosition({ 520.0f,245.0f });

			}
			else
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object4 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object4->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
				Object4->directon = Dir::Left;
				Object4->GetTransform()->AddLocalPosition({ 520.0f,245.0f });
			}
		
		}
		break;
		case 4:
		{
			if (AttackColor == 1)
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object5 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object5->GetTransform()->AddLocalPosition({ -300.0f,250.0f });
				Object5->color = Color::Pink;
			}
			else
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object5 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object5->GetTransform()->AddLocalPosition({ -300.0f,250.0f });
			}
		
		}
		break;
		case 5:
		{
			if (AttackColor == 1)
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object6 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object6->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
				Object6->color = Color::Pink;
				Object6->directon = Dir::Left;
				Object6->GetTransform()->AddLocalPosition({ 300.0f,250.0f });

			}
			else
			{
				std::shared_ptr<Ph2_Bepi_Weapon> Object6 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
				Object6->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
				Object6->directon = Dir::Left;
				Object6->GetTransform()->AddLocalPosition({ 300.0f,250.0f });
			}
		}
		break;
	
		default:
			break;
		}	
		Sound_Attack_Check = false;
		ResetLiveTime(); 
	}

	if (helium_pipe_puff_Time > 1)
	{
		helium_pipe_puff_location = GameEngineRandom::MainRandom.RandomInt(0, 5);

		
		

		switch (helium_pipe_puff_location)
		{
			

		case 0:
		{
			
			if (helium_pipe_puff_Cehck == false)
			{
				helium_pipe_puff->ChangeAnimation("helium_pipe_puff");
				helium_pipe_puff->On(); 
				helium_pipe_puff->GetTransform()->SetWorldPosition({ -580.0f,-10.0f });
				helium_pipe_puff_Cehck = true;
			}
		

			if (helium_pipe_puff->IsAnimationEnd())
			{
				helium_pipe_puff_Cehck = false;
				helium_pipe_puff->Off(); 
				helium_pipe_puff_Time = 0; 
			
			}

		}
		break;
		case 1:
		{

			if (helium_pipe_puff_Cehck == false)
			{
				helium_pipe_puff->ChangeAnimation("helium_pipe_puff");
				helium_pipe_puff->On();
				helium_pipe_puff->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
				helium_pipe_puff->GetTransform()->SetWorldPosition({ -580.0f,-10.0f });
				helium_pipe_puff_Cehck = true; 
			}

			if (helium_pipe_puff->IsAnimationEnd())
			{
				helium_pipe_puff_Cehck = false;
				helium_pipe_puff->Off();
				helium_pipe_puff_Time = 0;
			}

		}
		break;
		case 2:
		{
		

			if (helium_pipe_puff_Cehck == false)
			{
				helium_pipe_puff->ChangeAnimation("helium_pipe_puff");
				helium_pipe_puff->On();

				helium_pipe_puff->GetTransform()->SetWorldPosition({ -520.0f,245.0f });
				helium_pipe_puff_Cehck = true;
			}

			if (helium_pipe_puff->IsAnimationEnd())
			{
				helium_pipe_puff_Cehck = false;
				helium_pipe_puff->Off();
				helium_pipe_puff_Time = 0;
			}

		}
		break;
		case 3:
		{
		

			if (helium_pipe_puff_Cehck == false)
			{
				helium_pipe_puff->ChangeAnimation("helium_pipe_puff");
				helium_pipe_puff->On();

				helium_pipe_puff->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
				helium_pipe_puff->GetTransform()->AddLocalPosition({ 520.0f,245.0f });
				helium_pipe_puff_Cehck = true;
			}

			if (helium_pipe_puff->IsAnimationEnd())
			{
				helium_pipe_puff_Cehck = false;
				helium_pipe_puff->Off();
				helium_pipe_puff_Time = 0;
			}

		}
		break;
		case 4:
		{
			

			if (helium_pipe_puff_Cehck == false)
			{
				helium_pipe_puff->ChangeAnimation("helium_pipe_puff");
				helium_pipe_puff->On();

				helium_pipe_puff->GetTransform()->SetWorldPosition({ -300.0f,250.0f });
				helium_pipe_puff_Cehck = true;
			}

			if (helium_pipe_puff->IsAnimationEnd())
			{
				helium_pipe_puff_Cehck = false;
				helium_pipe_puff->Off();
				helium_pipe_puff_Time = 0;
			}

		}
		break;
		case 5:
		{
			

			if (helium_pipe_puff_Cehck == false)
			{
				helium_pipe_puff->ChangeAnimation("helium_pipe_puff");
				helium_pipe_puff->On();
				helium_pipe_puff->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
				helium_pipe_puff->GetTransform()->AddLocalPosition({ 300.0f,250.0f });
				helium_pipe_puff_Cehck = true;
			}

			if (helium_pipe_puff->IsAnimationEnd())
			{
				helium_pipe_puff_Cehck = false;
				helium_pipe_puff->Off();
				helium_pipe_puff_Time = 0;
			}
		}
		break;

		default:
			break;
		}
	}

	if (Hp <= 0)
	{
		Collision->Off(); 
		helium_pipe_puff->Off(); 
		ResetLiveTime(); 
		ChangeState(Ph2_Bepi_State::BossFinish);

		//Phase2_Idle_Head->ResetLiveTime(); 
		return; 
	}
}