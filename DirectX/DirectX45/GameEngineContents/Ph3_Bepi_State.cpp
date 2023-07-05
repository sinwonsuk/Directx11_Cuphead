#include "PrecompileHeader.h"
#include "Ph3_Bepi.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "Ph3_Bepi_Weapon.h"
#include "Ph3_Bepi_Weapon_Green.h"
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

		if (GetLiveTime() > 4.0)
		{
			if (GetTransform()->GetLocalPosition().y < 1000.0f)
			{
				GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 400.0f });
			}

			if (GetTransform()->GetLocalPosition().y > 1000.0f)
			{
				YellowORGreenCheck = GameEngineRandom::MainRandom.RandomInt(0, 1);
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
		if (GetLiveTime() > 0.2  && GreenBulletCheck < 3)
		{
			std::shared_ptr<Ph3_Bepi_Weapon_Green> Object = GetLevel()->CreateActor<Ph3_Bepi_Weapon_Green>();
			Object->MoveDir = 1;
			TransformData date = GetTransform()->GetTransDataRef();

			Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x + 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
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

		if (GetLiveTime() > 4.0)
		{
			if (GetTransform()->GetLocalPosition().y < 1000.0f)
			{
				GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 400.0f });
			}

			if (GetTransform()->GetLocalPosition().y > 1000.0f)
			{
				YellowORGreenCheck = GameEngineRandom::MainRandom.RandomInt(0, 1);
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
}

void Ph3_Bepi::RightAttackUpdate(float _Time)
{
	Time += _Time;
	Time2 += _Time;


	if (YellowORGreenCheck == 0)
	{
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

		if (GetLiveTime() > 4.0)
		{
			if (GetTransform()->GetLocalPosition().y < 1000.0f)
			{
				GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 400.0f });
			}

			if (GetTransform()->GetLocalPosition().y > 1000.0f)
			{
				YellowORGreenCheck = GameEngineRandom::MainRandom.RandomInt(0, 1);
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
		if (YellowORGreenCheck == 1)
		{
			if (GetLiveTime() > 0.2 && GreenBulletCheck < 3)
			{
				std::shared_ptr<Ph3_Bepi_Weapon_Green> Object = GetLevel()->CreateActor<Ph3_Bepi_Weapon_Green>();
				//Object->MoveDir = 1;
				Object->GetTransform()->SetLocalPosition({ GetTransform()->GetLocalPosition().x - 230.0f,GetTransform()->GetLocalPosition().y - 300.0f });
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


			if (GetLiveTime() > 4.0)
			{
				if (GetTransform()->GetLocalPosition().y < 1000.0f)
				{
					GetTransform()->AddLocalPosition({ 0, 1.0f * _Time * 400.0f });
				}

				if (GetTransform()->GetLocalPosition().y > 1000.0f)
				{
					YellowORGreenCheck = GameEngineRandom::MainRandom.RandomInt(0, 1);
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






	}


}
