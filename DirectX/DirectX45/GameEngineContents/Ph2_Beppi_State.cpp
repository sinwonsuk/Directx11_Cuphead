#include "PrecompileHeader.h"
#include "Ph2_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Ph2_Bepi_Weapon.h"
void Ph2_Bepi::ChangeState(Ph2_Bepi_State _State)
{
	Ph2_Bepi_State NextState = _State;
	Ph2_Bepi_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Ph2_Bepi_State::BossIntro:

		break;
	case Ph2_Bepi_State::BossIntro2:
	
		break;
	case Ph2_Bepi_State::BossIntro3:
		
		break;
	case Ph2_Bepi_State::BossIdle:
	
		break;
	case Ph2_Bepi_State::BossLeftStartAttack:
	
		break;
	case Ph2_Bepi_State::BossLeftRunAttack:
		
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


	default:
		break;
	}



}



void Ph2_Bepi::BossIntroUpdate(float _Time)
{
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

void Ph2_Bepi::BossIdleUpdate(float _Time)
{
	if (GetLiveTime() > 2)
	{
		AttackCheck = GameEngineRandom::MainRandom.RandomInt(0, 5);

		switch (AttackCheck)
		{
		case 0:
		{
			std::shared_ptr<Ph2_Bepi_Weapon> Object = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
			Object->GetTransform()->AddLocalPosition({ -560.0f,-20.0f });
		}
		break;
		case 1:
		{
			std::shared_ptr<Ph2_Bepi_Weapon> Object1 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
			Object1->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
			Object1->directon = Dir::Left;
			Object1->GetTransform()->AddLocalPosition({ 560.0f,-20.0f });
		}
		break;
		case 2:
		{
			std::shared_ptr<Ph2_Bepi_Weapon> Object3 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
			Object3->GetTransform()->AddLocalPosition({ -520.0f,245.0f });
		}
		break;
		case 3:
		{
			std::shared_ptr<Ph2_Bepi_Weapon> Object4 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
			Object4->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
			Object4->directon = Dir::Left;
			Object4->GetTransform()->AddLocalPosition({ 520.0f,245.0f });
		}
		break;
		case 4:
		{
			std::shared_ptr<Ph2_Bepi_Weapon> Object5 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
			Object5->GetTransform()->AddLocalPosition({ -300.0f,250.0f });
		}
		break;
		case 5:
		{

			std::shared_ptr<Ph2_Bepi_Weapon> Object6 = GetLevel()->CreateActor<Ph2_Bepi_Weapon>();
			Object6->GetTransform()->AddLocalRotation({ 0.0f,180.0f });
			Object6->directon = Dir::Left;
			Object6->GetTransform()->AddLocalPosition({ 300.0f,250.0f });
		}
		break;
	
		default:
			break;
		}		
		ResetLiveTime(); 
	}





}