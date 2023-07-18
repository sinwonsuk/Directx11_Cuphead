#include "PrecompileHeader.h"
#include "Ph3_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Ph3_Bepi_Weapon.h"
#include "Ph3_Bepi_Weapon_Green.h"
#include "Crown_Bepi_Level.h"

void Ph3_Bepi::ChangeState(Ph3_Bepi_State _State)
{
	Ph3_Bepi_State NextState = _State;
	Ph3_Bepi_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Ph3_Bepi_State::BossIntro:

		break;


	case Ph3_Bepi_State::BossIdle:

		break;
	case Ph3_Bepi_State::BossRightAttack:

		break;
	case Ph3_Bepi_State::BossLeftAttack:

		break;
	case Ph3_Bepi_State::Left_Green_Finish:
		
		break;
	case Ph3_Bepi_State::Right_Green_Finish:

		break;
	case Ph3_Bepi_State::Left_Yellow_Finish:

		break;
	case Ph3_Bepi_State::Right_Yellow_Finish:

		break;
	case Ph3_Bepi_State::BossFinish_Finish:

		break;
	default:
		break;
	}


}


void Ph3_Bepi::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Ph3_Bepi_State::BossIntro:
		BossIntroUpdate(_Time);
		break;
	case Ph3_Bepi_State::BossIdle:
		BossIdleUpdate(_Time);
		break;
	case Ph3_Bepi_State::BossRightAttack:
		RightAttackUpdate(_Time);
		break;
	case Ph3_Bepi_State::BossLeftAttack:
		LeftAttackUpdate(_Time);
		break;
	case Ph3_Bepi_State::BossFinish:
		BossFinishUpdate(_Time);
		break;
	case Ph3_Bepi_State::BossFinish_Finish:
		BossFinish_Finish_Update(_Time);
		break;

	default:
		break;
	}


}


void Ph3_Bepi::BossIdleUpdate(float _Time)
{
	if (GetTransform()->GetLocalPosition().y > 400.0f)
	{
		GetTransform()->AddLocalPosition({ 0,-1.0f * _Time * 400.0f });
	}

	if (GetTransform()->GetLocalPosition().y <= 400.0f)
	{
		if (YellowORGreenCheck == 0)
		{
			Yellow_Horse_Head->Off();
			Yellow_Horse_Attack->On();
			YellowPattern = GameEngineRandom::MainRandom.RandomInt(0, 2);

			
			if (LeftORRightCheck == 0)
			{
				for (size_t i = 0; i < 7; i++)
				{
					std::shared_ptr<Ph3_Bepi_Weapon> Object = GetLevel()->CreateActor<Ph3_Bepi_Weapon>();
					Object->Off();
					Bullets.push_back(Object);
				
				}
				ResetLiveTime();
				ChangeState(Ph3_Bepi_State::BossLeftAttack);
				return;
			}
			if (LeftORRightCheck == 1)
			{
				for (size_t i = 0; i < 7; i++)
				{
					std::shared_ptr<Ph3_Bepi_Weapon> Object = GetLevel()->CreateActor<Ph3_Bepi_Weapon>();
					Object->Off();
					Bullets.push_back(Object);
		
				}
				ResetLiveTime();
				ChangeState(Ph3_Bepi_State::BossRightAttack);
				return;
			}
		}
	
		if (YellowORGreenCheck == 1)
		{
			Green_Horse_Head->Off();
			Green_Horse_Attack->On();
			YellowPattern = GameEngineRandom::MainRandom.RandomInt(0, 2);

		
			if (LeftORRightCheck == 0)
			{
				
				ResetLiveTime();
				ChangeState(Ph3_Bepi_State::BossLeftAttack);
				return;
			}
			if (LeftORRightCheck == 1)
			{
				
				ResetLiveTime();
				ChangeState(Ph3_Bepi_State::BossRightAttack);
				return;
			}
		}
		
	}

	

}
void Ph3_Bepi::BossIntroUpdate(float _Time)
{







	if (GetTransform()->GetLocalPosition().y > 400.0f)
	{
		GetTransform()->AddLocalPosition({ 0,-1.0f* _Time * 400.0f });
	}
	
	
	if (GetTransform()->GetLocalPosition().y <= 400.0f)
	{	
		Yellow_Horse_Head->Off();
		Yellow_Horse_Attack->On(); 

		YellowPattern = GameEngineRandom::MainRandom.RandomInt(0, 2); 

		for (size_t i = 0; i < 7; i++)
		{
			std::shared_ptr<Ph3_Bepi_Weapon> Object = GetLevel()->CreateActor<Ph3_Bepi_Weapon>();
			Bullets.push_back(Object);
			Bullets[i].get()->Off(); 
		}
		ChangeState(Ph3_Bepi_State::BossRightAttack);
		return; 
	}

}

void Ph3_Bepi::LeftAttackUpdate(float _Time)
{
	Time += _Time;
	Time2 += _Time;
	if (YellowORGreenCheck == 0)
	{
		clown_ph3_horse_spit->GetTransform()->SetWorldPosition({ -220.0f,100.0f });
		clown_ph3_horse_spit->GetTransform()->SetLocalRotation({ 0.0f,180.0f,0.0f }); 
		if (BulletCheck == 3)
		{
			clown_ph3_horse_spit->On();

			
		}


		switch (YellowPattern)
		{
		case 0:
		{
			if (GetLiveTime() > 0.1 && BulletCheck < 7)
			{
				Bullets[BulletNumber]->YellowPattern = 1;
				Bullets[BulletNumber]->On();
				Bullets[BulletNumber]->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
				Bullets[BulletNumber]->SetStopPos(Left_BulletStopPos);
				Left_BulletStopPos += 100;
				++BulletNumber;
				++BulletCheck;
				ResetLiveTime();
			}

			if (GetLiveTime() > 1.0)
			{
				Yellow_Horse_Attack->Off();
				Yellow_Horse_Head->On();
			}

			if (GetLiveTime() > 3.0)
			{
				

				for (size_t i = 0; i < Bullets.size(); i++)
				{
					Bullets[i].get()->DownCheck = true;
				}
			}
		}
		break;
		case 1:
		{
			if (GetLiveTime() > 0.1 && BulletCheck < 4)
			{
				Bullets[BulletNumber]->YellowPattern = 1;
				Bullets[BulletNumber]->On();
				Bullets[BulletNumber]->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
				Bullets[BulletNumber]->SetStopPos(Left_BulletStopPos);
				Left_BulletStopPos += 100;
				++BulletCheck;
				++BulletNumber;
				ResetLiveTime();
			}

			if (BulletCheck == 4)
			{
				Left_BulletStopPos = 400;
			}
			if (GetLiveTime() > 1.0 && BulletCheck < 7)
			{
				if (Time > 0.1)
				{
					Bullets[BulletNumber]->YellowPattern = 1;
					Bullets[BulletNumber]->On();
					Bullets[BulletNumber]->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
					Bullets[BulletNumber]->SetStopPos(Left_BulletStopPos);
					Left_BulletStopPos += 100;
					++BulletNumber;
					++BulletCheck;
					Time = 0;
				}
			}

			if (GetLiveTime() > 1.8)
			{
				Yellow_Horse_Attack->Off();
				Yellow_Horse_Head->On();
			}

			if (GetLiveTime() > 3.0)
			{
				for (size_t i = 0; i < Bullets.size(); i++)
				{
					Bullets[i].get()->DownCheck = true;
				}
			}
		}
		break;
		case 2:
		{
			if (GetLiveTime() > 0.1 && BulletCheck < 2)
			{
				Bullets[BulletNumber]->YellowPattern = 1;
				Bullets[BulletNumber]->On();
				Bullets[BulletNumber]->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
				Bullets[BulletNumber]->SetStopPos(Left_BulletStopPos);
				Left_BulletStopPos += 100;
				++BulletCheck;
				++BulletNumber;
				ResetLiveTime();
			}

			if (BulletCheck == 2)
			{
				Left_BulletStopPos = 200;
			}
			if (GetLiveTime() > 1.0 && BulletCheck < 7)
			{
				if (Time > 0.1)
				{
					Bullets[BulletNumber]->YellowPattern = 1;
					Bullets[BulletNumber]->On();
					Bullets[BulletNumber]->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
					Bullets[BulletNumber]->SetStopPos(Left_BulletStopPos);
					Left_BulletStopPos += 100;
					++BulletNumber;
					++BulletCheck;
					Time = 0;
				}
			}

			if (GetLiveTime() > 1.8)
			{
				Yellow_Horse_Attack->Off();
				Yellow_Horse_Head->On();
			}

			if (GetLiveTime() > 3.0)
			{
				for (size_t i = 0; i < Bullets.size(); i++)
				{
					Bullets[i].get()->DownCheck = true;
				}
			}
		}
		break;
		default:
			break;
		}



		if (Hp < 0)
		{
			if (YellowORGreenCheck == 0)
			{
				Yellow_Horse_Attack->Off();
				Yellow_Horse_Head->Off();
				Yellow_Horse_Body->ChangeAnimation("Yellow_Horse_End");
				Yellow_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,100.0f });
				Phase3_Idle->GetTransform()->AddLocalPosition({ 150.0f,-150.0f });
				Phase3_Idle->ChangeAnimation("Phase3_End");
			}

			if (YellowORGreenCheck == 1)
			{
				Green_Horse_Attack->Off(); 
				Green_Horse_Head->Off();
				Green_Horse_Body->ChangeAnimation("Green_Horse_End");
				Green_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,-40.0f });
				Phase3_Idle->GetTransform()->AddLocalPosition({ 130.0f,-130.0f });
				Phase3_Idle->ChangeAnimation("Phase3_End");
			}

			for (size_t i = 0; i < Bullets.size(); i++)
			{
				Bullets[i].get()->Death();
			}
			Bullets.clear();
			ChangeState(Ph3_Bepi_State::BossFinish);
		}

		/*if (GetLiveTime() > 3.2)
		{
			if (Hp <= 0)
			{
				if (YellowORGreenCheck == 0)
				{
					Yellow_Horse_Head->Off(); 
					Yellow_Horse_Body->ChangeAnimation("Yellow_Horse_End");
					Yellow_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,100.0f });
					Phase3_Idle->GetTransform()->AddLocalPosition({ 150.0f,-150.0f });
					Phase3_Idle->ChangeAnimation("Phase3_End");
				}

				if (YellowORGreenCheck == 1)
				{
					Green_Horse_Head->Off(); 
					Green_Horse_Body->ChangeAnimation("Green_Horse_End");
					Green_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,-40.0f });
					Phase3_Idle->GetTransform()->AddLocalPosition({ 130.0f,-130.0f });
					Phase3_Idle->ChangeAnimation("Phase3_End");
				}
				ChangeState(Ph3_Bepi_State::BossFinish);
				return;
			}
		}*/
		if (GetLiveTime() > 4.0)
		{

			

			clown_ph3_horse_spit->ChangeAnimation("clown_ph3_horse_spit");
			clown_ph3_horse_spit->Off();
			clown_ph3_horse_spit->GetTransform()->SetLocalRotation({ 0.0f,0.0f,0.0f });

			if (GetTransform()->GetLocalPosition().y < 1000.0f)
			{
				GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 400.0f });
			}

			if (GetTransform()->GetLocalPosition().y > 1000.0f)
			{

				

				YellowORGreenCheck = GameEngineRandom::MainRandom.RandomInt(1, 1);
				LeftORRightCheck = GameEngineRandom::MainRandom.RandomInt(0, 1);

				BulletStopPos = 200;
				Left_BulletStopPos = -200;
				BulletCheck = 0;
				// left
				if (LeftORRightCheck == 0)
				{
					GetTransform()->SetLocalNegativeScaleX();
					GetTransform()->SetLocalPosition({ -500.0f,700.0f });
				}
				// right

				if (LeftORRightCheck == 1)
				{
					GetTransform()->SetLocalPositiveScaleX();
					GetTransform()->SetLocalPosition({ 500.0f,700.0f });
				}
				// Yellow

				if (YellowORGreenCheck == 0)
				{
					Yellow_Horse_Body->On();
					Yellow_Horse_Head->On();
					Yellow_Horse_Attack->Off();
					Green_Horse_Attack->Off();
					Green_Horse_Body->Off();
					Green_Horse_Head->Off();
				}
				// Green 

				if (YellowORGreenCheck == 1)
				{
					Yellow_Horse_Body->Off();
					Yellow_Horse_Head->Off();
					Yellow_Horse_Attack->Off();
					Green_Horse_Attack->Off();
					Green_Horse_Body->On();
					Green_Horse_Head->On();
				}
				ResetLiveTime();
				ChangeState(Ph3_Bepi_State::BossIdle);

				return;
			}



		}
	}


	if (YellowORGreenCheck == 1)
	{
		clown_ph3_horse_spit->GetTransform()->SetWorldPosition({ -220.0f,100.0f });
		clown_ph3_horse_spit->GetTransform()->SetLocalRotation({ 0.0f,180.0f,0.0f });
		
		
		
			if (GreenBulletCheck == 1)
			{
				clown_ph3_horse_spit->On();
			}
	


		if (GetLiveTime() > 0.2  && GreenBulletCheck < 3)
		{
			if (GreenBulletCheck == 1)
			{
				std::shared_ptr<Ph3_Bepi_Weapon_Green> Object = GetLevel()->CreateActor<Ph3_Bepi_Weapon_Green>();
				Object->MoveDir = 1;
				Object->color = Ph3_Bepi_Weapon_Color::Red;
				TransformData date = GetTransform()->GetTransDataRef();

				Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
			}
			else
			{
				std::shared_ptr<Ph3_Bepi_Weapon_Green> Object = GetLevel()->CreateActor<Ph3_Bepi_Weapon_Green>();
				Object->MoveDir = 1;
				TransformData date = GetTransform()->GetTransDataRef();
				Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
			}
		
			++GreenBulletCheck;
			ResetLiveTime();
		}

		if (GreenBulletCheck ==2)
		{
			Time2 = 0;
		
		}
		if (GetLiveTime() > 1.0)
		{
			if (Time2 > 0.2 && GreenBulletCheck < 5)
			{
				std::shared_ptr<Ph3_Bepi_Weapon_Green> Object = GetLevel()->CreateActor<Ph3_Bepi_Weapon_Green>();
				Object->MoveDir = 1;
				Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
				++GreenBulletCheck;
				Time2 = 0;
			}
		}

		if (GetLiveTime() > 1.6)
		{
			Green_Horse_Attack->Off();
			Green_Horse_Head->On();
		}



		if (Hp < 0)
		{
			if (YellowORGreenCheck == 0)
			{
				Yellow_Horse_Attack->Off();
				Yellow_Horse_Head->Off();
				Yellow_Horse_Body->ChangeAnimation("Yellow_Horse_End");
				Yellow_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,100.0f });
				Phase3_Idle->GetTransform()->AddLocalPosition({ 150.0f,-150.0f });
				Phase3_Idle->ChangeAnimation("Phase3_End");
			}

			if (YellowORGreenCheck == 1)
			{
				Green_Horse_Attack->Off();
				Green_Horse_Head->Off();
				Green_Horse_Body->ChangeAnimation("Green_Horse_End");
				Green_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,-40.0f });
				Phase3_Idle->GetTransform()->AddLocalPosition({ 130.0f,-130.0f });
				Phase3_Idle->ChangeAnimation("Phase3_End");
			}

			for (size_t i = 0; i < Bullets.size(); i++)
			{
				Bullets[i].get()->Death();
			}
			Bullets.clear();
			ChangeState(Ph3_Bepi_State::BossFinish);
		}
		/*if (GetLiveTime() > 3.2)
		{
			if (Hp <= 0)
			{

				if (YellowORGreenCheck == 0)
				{
					Yellow_Horse_Head->Off();
					Yellow_Horse_Body->ChangeAnimation("Yellow_Horse_End");
					Yellow_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,100.0f });
					Phase3_Idle->GetTransform()->AddLocalPosition({ 150.0f,-150.0f });
					Phase3_Idle->ChangeAnimation("Phase3_End");
				}

				if (YellowORGreenCheck == 1)
				{
					Green_Horse_Head->Off();
					Green_Horse_Body->ChangeAnimation("Green_Horse_End");
					Green_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,-40.0f });
					Phase3_Idle->GetTransform()->AddLocalPosition({ 130.0f,-130.0f });
					Phase3_Idle->ChangeAnimation("Phase3_End");
				}
				ChangeState(Ph3_Bepi_State::BossFinish);
				return;
			}
		}*/

		if (GetLiveTime() > 4.0)
		{

			

			clown_ph3_horse_spit->ChangeAnimation("clown_ph3_horse_spit");
			clown_ph3_horse_spit->GetTransform()->SetLocalRotation({ 0.0f,0.0f,0.0f });
			clown_ph3_horse_spit->Off();

			if (GetTransform()->GetLocalPosition().y < 1000.0f)
			{
				GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 400.0f });
			}

			if (GetTransform()->GetLocalPosition().y > 1000.0f)
			{

			

				YellowORGreenCheck = GameEngineRandom::MainRandom.RandomInt(1, 1);
				LeftORRightCheck = GameEngineRandom::MainRandom.RandomInt(0, 1);

				GreenBulletCheck = 0;
				BulletStopPos = 200;
				BulletCheck = 0;
				Left_BulletStopPos = -200;
				// left
				if (LeftORRightCheck == 0)
				{
					GetTransform()->SetLocalNegativeScaleX();
					GetTransform()->SetLocalPosition({ -500.0f,700.0f });
				}
				// right

				if (LeftORRightCheck == 1)
				{
					GetTransform()->SetLocalPositiveScaleX();
					GetTransform()->SetLocalPosition({ 500.0f,700.0f });
				}
				// Yellow

				if (YellowORGreenCheck == 0)
				{
					Yellow_Horse_Body->On();
					Yellow_Horse_Head->On();
					Yellow_Horse_Attack->Off();
					Green_Horse_Attack->Off();
					Green_Horse_Body->Off();
					Green_Horse_Head->Off();
				}
				// Green 

				if (YellowORGreenCheck == 1)
				{
					Yellow_Horse_Body->Off();
					Yellow_Horse_Head->Off();
					Yellow_Horse_Attack->Off();
					Green_Horse_Attack->Off();
					Green_Horse_Body->On();
					Green_Horse_Head->On();
				}
				ResetLiveTime();
				ChangeState(Ph3_Bepi_State::BossIdle);

				return;
			}



		}
	}


	if (clown_ph3_horse_spit->IsAnimationEnd())
	{
		clown_ph3_horse_spit->Off(); 
	}
}


void Ph3_Bepi::RightAttackUpdate(float _Time)
{
	Time += _Time;
	Time2 += _Time;


	if (YellowORGreenCheck == 0)
	{

		clown_ph3_horse_spit->GetTransform()->SetWorldPosition({ 220.0f,100.0f });

		if (BulletCheck == 3)
		{
			clown_ph3_horse_spit->On();
		}

		switch (YellowPattern)
		{
			
		case 0:
		{
			if (GetLiveTime() > 0.1 && BulletCheck < 7)
			{
				Bullets[BulletNumber]->On();
				Bullets[BulletNumber]->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
				Bullets[BulletNumber]->SetStopPos(BulletStopPos);
				BulletStopPos -= 100;
				++BulletNumber;
				++BulletCheck;
				ResetLiveTime();
			}

			if (GetLiveTime() > 1)
			{
				Yellow_Horse_Attack->Off();
				Yellow_Horse_Head->On(); 
			}



			if (GetLiveTime() > 3.0)
			{
				for (size_t i = 0; i < Bullets.size(); i++)
				{
					Bullets[i].get()->DownCheck = true;
				}
			}
		}
		break;
		case 1:
		{
			if (GetLiveTime() > 0.1 && BulletCheck < 4)
			{
				Bullets[BulletNumber]->On();
				Bullets[BulletNumber]->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
				Bullets[BulletNumber]->SetStopPos(BulletStopPos);
				BulletStopPos -= 100;
				++BulletCheck;
				++BulletNumber;
				ResetLiveTime();
			}

			if (BulletCheck == 4)
			{
				BulletStopPos = -400;
			}
			if (GetLiveTime() > 1.0 && BulletCheck < 7)
			{
				if (Time > 0.1)
				{
					Bullets[BulletNumber]->On();
					Bullets[BulletNumber]->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
					Bullets[BulletNumber]->SetStopPos(BulletStopPos);
					BulletStopPos -= 100;
					++BulletNumber;
					++BulletCheck;
					Time = 0;
				}
			}

			if (GetLiveTime() > 1.8)
			{
				Yellow_Horse_Attack->Off();
				Yellow_Horse_Head->On();
			}



			if (GetLiveTime() > 3.0)
			{
				for (size_t i = 0; i < Bullets.size(); i++)
				{
					Bullets[i].get()->DownCheck = true;
				}
			}
		}
		break;
		case 2:
		{
			if (GetLiveTime() > 0.1 && BulletCheck < 2)
			{
				Bullets[BulletNumber]->On();
				Bullets[BulletNumber]->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
				Bullets[BulletNumber]->SetStopPos(BulletStopPos);
				BulletStopPos -= 100;
				++BulletCheck;
				++BulletNumber;
				ResetLiveTime();
			}

			if (BulletCheck == 2)
			{
				BulletStopPos = -200;
			}


			if (GetLiveTime() > 1.0 && BulletCheck < 7)
			{
				if (Time > 0.1)
				{
					Bullets[BulletNumber]->On();
					Bullets[BulletNumber]->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
					Bullets[BulletNumber]->SetStopPos(BulletStopPos);
					BulletStopPos -= 100;
					++BulletNumber;
					++BulletCheck;
					Time = 0;
				}
			}

			if (GetLiveTime() > 1.8)
			{
				Yellow_Horse_Attack->Off();
				Yellow_Horse_Head->On();
			}

			if (GetLiveTime() > 3.0)
			{
				for (size_t i = 0; i < Bullets.size(); i++)
				{
					Bullets[i].get()->DownCheck = true;
				}
			}
		}
		break;
		default:
			break;
		}



		if (Hp < 0)
		{
			if (YellowORGreenCheck == 0)
			{
				Yellow_Horse_Attack->Off();
				Yellow_Horse_Head->Off();
				Yellow_Horse_Body->ChangeAnimation("Yellow_Horse_End");
				Yellow_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,100.0f });
				Phase3_Idle->GetTransform()->AddLocalPosition({ 150.0f,-150.0f });
				Phase3_Idle->ChangeAnimation("Phase3_End");

			}

			if (YellowORGreenCheck == 1)
			{
				Green_Horse_Attack->Off();
				Green_Horse_Head->Off();
				Green_Horse_Body->ChangeAnimation("Green_Horse_End");
				Green_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,-100.0f });
				Phase3_Idle->GetTransform()->AddLocalPosition({ 130.0f,-130.0f });
				Phase3_Idle->ChangeAnimation("Phase3_End");
			}

			for (size_t i = 0; i < Bullets.size(); i++)
			{
				Bullets[i].get()->Death();
			}
			Bullets.clear();
			ChangeState(Ph3_Bepi_State::BossFinish);
		}


		/*if (GetLiveTime() > 3.2)
		{
			if (Hp <= 0)
			{
				if (YellowORGreenCheck == 0)
				{
					Yellow_Horse_Head->Off();
					Yellow_Horse_Body->ChangeAnimation("Yellow_Horse_End");
					Yellow_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,100.0f});
					Phase3_Idle->GetTransform()->AddLocalPosition({ 150.0f,-150.0f });
					Phase3_Idle->ChangeAnimation("Phase3_End");
					
				}

				if (YellowORGreenCheck == 1)
				{
					Green_Horse_Head->Off();
					Green_Horse_Body->ChangeAnimation("Green_Horse_End");
					Green_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,-100.0f });
					Phase3_Idle->GetTransform()->AddLocalPosition({ 130.0f,-130.0f });
					Phase3_Idle->ChangeAnimation("Phase3_End");
				}
				ChangeState(Ph3_Bepi_State::BossFinish);
				return; 
			}
		}*/


		if (GetLiveTime() > 4.0)
		{
			

			clown_ph3_horse_spit->ChangeAnimation("clown_ph3_horse_spit");
			clown_ph3_horse_spit->Off();

			if (GetTransform()->GetLocalPosition().y < 1000.0f)
			{
				GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 400.0f });
			}

			if (GetTransform()->GetLocalPosition().y > 1000.0f)
			{
				

				YellowORGreenCheck = GameEngineRandom::MainRandom.RandomInt(1, 1);
				LeftORRightCheck = GameEngineRandom::MainRandom.RandomInt(0, 1);

				BulletStopPos = 200;
				BulletCheck = 0;
				// left
				if (LeftORRightCheck == 0)
				{
					GetTransform()->SetLocalNegativeScaleX();
					GetTransform()->SetLocalPosition({ -500.0f,700.0f });
				}
				// right

				if (LeftORRightCheck == 1)
				{
					GetTransform()->SetLocalPositiveScaleX();
					GetTransform()->SetLocalPosition({ 500.0f,700.0f });
				}
				// Yellow

				if (YellowORGreenCheck == 0)
				{
					Yellow_Horse_Body->On();
					Yellow_Horse_Head->On();
					Yellow_Horse_Attack->Off();
					Green_Horse_Attack->Off();
					Green_Horse_Body->Off();
					Green_Horse_Head->Off();
				}
				// Green 

				if (YellowORGreenCheck == 1)
				{
					Yellow_Horse_Body->Off();
					Yellow_Horse_Head->Off();
					Yellow_Horse_Attack->Off();
					Green_Horse_Attack->Off();
					Green_Horse_Body->On();
					Green_Horse_Head->On();
				}
				ResetLiveTime();
				ChangeState(Ph3_Bepi_State::BossIdle);

				return;
			}



		}
	}


	if (YellowORGreenCheck == 1)
	{
		clown_ph3_horse_spit->GetTransform()->SetWorldPosition({ 220.0f,100.0f });


		
			if (GreenBulletCheck == 1)
			{
				clown_ph3_horse_spit->On();
			}
		
			if (GetLiveTime() > 0.2 && GreenBulletCheck < 3)
			{
				if (GreenBulletCheck == 1)
				{
					std::shared_ptr<Ph3_Bepi_Weapon_Green> Object = GetLevel()->CreateActor<Ph3_Bepi_Weapon_Green>();
					//Object->MoveDir = 1;
					Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
					Object->color = Ph3_Bepi_Weapon_Color::Red;
				}
				else
				{
					std::shared_ptr<Ph3_Bepi_Weapon_Green> Object = GetLevel()->CreateActor<Ph3_Bepi_Weapon_Green>();
					//Object->MoveDir = 1;
					Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
				}
				
				++GreenBulletCheck;
				ResetLiveTime();
			}

			if (GreenBulletCheck == 2)
			{
				Time2 = 0;
			}
			if (GetLiveTime() > 1.0)
			{
				if (Time2 > 0.2 && GreenBulletCheck < 5)
				{
					std::shared_ptr<Ph3_Bepi_Weapon_Green> Object = GetLevel()->CreateActor<Ph3_Bepi_Weapon_Green>();
					//	Object->MoveDir = 1;
					Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
					++GreenBulletCheck;
					Time2 = 0;
				}
			}
			if (GetLiveTime() > 1.6)
			{
				Green_Horse_Attack->Off();
				Green_Horse_Head->On(); 
			}

			if (Hp < 0)
			{
				if (YellowORGreenCheck == 0)
				{
					Yellow_Horse_Attack->Off(); 
					Yellow_Horse_Head->Off();
					Yellow_Horse_Body->ChangeAnimation("Yellow_Horse_End");
					Yellow_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,100.0f });
					Phase3_Idle->GetTransform()->AddLocalPosition({ 150.0f,-150.0f });
					Phase3_Idle->ChangeAnimation("Phase3_End");
				}

				else if (YellowORGreenCheck == 1)
				{
					Green_Horse_Attack->Off();
					Green_Horse_Head->Off();
					Green_Horse_Body->ChangeAnimation("Green_Horse_End");
					Green_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,-40.0f });
					Phase3_Idle->GetTransform()->AddLocalPosition({ 130.0f,-130.0f });
					Phase3_Idle->ChangeAnimation("Phase3_End");

				}

				for (size_t i = 0; i < Bullets.size(); i++)
				{
					Bullets[i].get()->Death();
				}
				Bullets.clear();
				ChangeState(Ph3_Bepi_State::BossFinish);
			}
		/*	if (GetLiveTime() > 3.2)
			{
				if (Hp <= 0)
				{
					if (YellowORGreenCheck == 0)
					{
						Yellow_Horse_Head->Off();
						Yellow_Horse_Body->ChangeAnimation("Yellow_Horse_End");
						Yellow_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,100.0f });
						Phase3_Idle->GetTransform()->AddLocalPosition({ 150.0f,-150.0f });
						Phase3_Idle->ChangeAnimation("Phase3_End");
					}

					else if (YellowORGreenCheck == 1)
					{
						Green_Horse_Head->Off();
						Green_Horse_Body->ChangeAnimation("Green_Horse_End");
						Green_Horse_Body->GetTransform()->AddLocalPosition({ -60.0f,-40.0f });
						Phase3_Idle->GetTransform()->AddLocalPosition({ 130.0f,-130.0f });
						Phase3_Idle->ChangeAnimation("Phase3_End");

					}
					ChangeState(Ph3_Bepi_State::BossFinish);
					return; 
				}
			}*/

			if (GetLiveTime() > 4.0)
			{
				

				clown_ph3_horse_spit->ChangeAnimation("clown_ph3_horse_spit");
				clown_ph3_horse_spit->Off();

				if (GetTransform()->GetLocalPosition().y < 1000.0f)
				{
					GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 400.0f });
				}

				if (GetTransform()->GetLocalPosition().y > 1000.0f)
				{
					

					YellowORGreenCheck = GameEngineRandom::MainRandom.RandomInt(1, 1);
					LeftORRightCheck = GameEngineRandom::MainRandom.RandomInt(0, 1);

					BulletStopPos = 200;
					GreenBulletCheck = 0;
					BulletCheck = 0;
					// left
					if (LeftORRightCheck == 0)
					{
						GetTransform()->SetLocalNegativeScaleX();
						GetTransform()->SetLocalPosition({ -500.0f,700.0f });
					}
					// right

					if (LeftORRightCheck == 1)
					{
						GetTransform()->SetLocalPositiveScaleX();
						GetTransform()->SetLocalPosition({ 500.0f,700.0f });
					}
					// Yellow

					if (YellowORGreenCheck == 0)
					{
						Yellow_Horse_Body->On();
						Yellow_Horse_Head->On();
						Yellow_Horse_Attack->Off();
						Green_Horse_Attack->Off();
						Green_Horse_Body->Off();
						Green_Horse_Head->Off();
					}
					// Green 

					if (YellowORGreenCheck == 1)
					{
						Yellow_Horse_Body->Off();
						Yellow_Horse_Head->Off();
						Yellow_Horse_Attack->Off();
						Green_Horse_Attack->Off();
						Green_Horse_Body->On();
						Green_Horse_Head->On();
					}
					ResetLiveTime();
					ChangeState(Ph3_Bepi_State::BossIdle);

					return;
				}



			}
		
	}

	if (clown_ph3_horse_spit->IsAnimationEnd())
	{
		clown_ph3_horse_spit->Off();
	}
}

void Ph3_Bepi::BossFinishUpdate(float _Time)
{
	Green_Horse_Head->Off();
	Yellow_Horse_Attack->Off(); 
	Green_Horse_Attack->Off(); 

	
		if (Phase3_Idle->GetLiveTime() > 0.03f)
		{
			Boss_Exploision_Pos.x = GameEngineRandom::MainRandom.RandomFloat(-100.0f, 100.0f);
			Boss_Exploision_Pos.y = GameEngineRandom::MainRandom.RandomFloat(-100.0f, 100.0f);

			if (Boss_Exploision_Check == false)
			{
				Bepi_boss_explosion->ChangeAnimation("Bepi_boss_explosion");
				Bepi_boss_explosion->On();
				Bepi_boss_explosion->GetTransform()->SetLocalPosition({ Phase3_Idle->GetTransform()->GetLocalPosition().x -80.0f+ Boss_Exploision_Pos.x , Phase3_Idle->GetTransform()->GetLocalPosition().y+Boss_Exploision_Pos.y+80.0f });
				Boss_Exploision_Check = true;
			}


			if (Bepi_boss_explosion->IsAnimationEnd())
			{
				++Boss_Exploision_Number;
				Boss_Exploision_Check = false;
				Bepi_boss_explosion->Off();
				Phase3_Idle->ResetLiveTime();
			}
		}
		if (Boss_Exploision_Number > 5)
		{
			GetTransform()->AddLocalPosition({ float4::Up * 400.0f * _Time });
		}

		if (GetTransform()->GetLocalPosition().y > 1000.0f)
		{
			

			GetTransform()->SetLocalPosition({ 0.0f,1000.0f }); 
			ResetLiveTime(); 
			Collision->Off(); 
			ChangeState(Ph3_Bepi_State::BossFinish_Finish);
			return; 
		}

	
}

void Ph3_Bepi::BossFinish_Finish_Update(float _Time)
{

	if (Phase3_Idle->GetLiveTime() > 0.03f)
	{
		Boss_Exploision_Pos.x = GameEngineRandom::MainRandom.RandomFloat(-100.0f, 100.0f);
		Boss_Exploision_Pos.y = GameEngineRandom::MainRandom.RandomFloat(-100.0f, 100.0f);

		if (Boss_Exploision_Check == false)
		{
			Bepi_boss_explosion->ChangeAnimation("Bepi_boss_explosion");
			Bepi_boss_explosion->On();
			Bepi_boss_explosion->GetTransform()->SetLocalPosition({ Phase3_Idle->GetTransform()->GetLocalPosition().x - 80.0f + Boss_Exploision_Pos.x , Phase3_Idle->GetTransform()->GetLocalPosition().y + Boss_Exploision_Pos.y + 80.0f });
			Boss_Exploision_Check = true;
		}
		if (Bepi_boss_explosion->IsAnimationEnd())
		{
			++Boss_Exploision_Number;
			Boss_Exploision_Check = false;
			Bepi_boss_explosion->Off();
			Phase3_Idle->ResetLiveTime();
		}
	}

	GetTransform()->AddLocalPosition({ 0, -1.0f * _Time * 400.0f });


	if (GetTransform()->GetLocalPosition().y < 400.0f)
	{
		GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 400.0f });
	}

	
	if (GetLiveTime() > 2 && FinishCheck ==false)
	{
		Phase3_Idle->GetTransform()->AddLocalPosition({ 0.0f,50.0f });
		Phase3_Idle->ChangeAnimation("Phase3_End_Finish");
		FinishCheck = true; 
	}
	if (FinishCheck == true)
	{
		if (Phase3_Idle->GetCurrentFrame() > 4)
		{
			Phase3_Idle->GetTransform()->AddLocalPosition({ 0, -1.0f * _Time * 700.0f });
		}
	}

	if (Phase3_Idle->GetCurrentFrame() > 6)
	{
		Yellow_Horse_Head->GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 600.0f });
		Yellow_Horse_Body->GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 600.0f });

		Green_Horse_Head->GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 600.0f });
		Green_Horse_Body->GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 600.0f });
	}
	if (GetLiveTime() > 5)
	{
		Crown_Bepi_Level* Level = (Crown_Bepi_Level*)GetLevel();
		Level->PaseCheck = Pase::Pase4;
	}
	
}



