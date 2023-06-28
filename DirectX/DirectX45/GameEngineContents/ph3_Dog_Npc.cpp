#include "PrecompileHeader.h"
#include "ph3_Dog_Npc.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ph3_DogAirPlane.h"
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"


ph3_Dog_Npc* ph3_Dog_Npc::ph3_Npc;

ph3_Dog_Npc::ph3_Dog_Npc()
{
}

ph3_Dog_Npc::~ph3_Dog_Npc()
{
}

void ph3_Dog_Npc::Start()
{
	ph3_Npc = this;


	if (nullptr == GameEngineSprite::Find("ph3_tongue_rotate_camera"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_tongue_rotate_camera").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_arms").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_body").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_body_Attack").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_arms_backer").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_arms_backer").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_tongue_rotate_camera_tongue").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_leader_sideways_body_Finish").GetFullPath());
	}

	ph3_leader_sideways_body_Finish = CreateComponent<GameEngineSpriteRenderer>();
	ph3_leader_sideways_body_Finish->CreateAnimation({ .AnimationName = "ph3_leader_sideways_body_Finish", .SpriteName = "ph3_leader_sideways_body_Finish", .FrameInter = 0.08f,.Loop = true, .ScaleToTexture = true });
	ph3_leader_sideways_body_Finish->ChangeAnimation("ph3_leader_sideways_body_Finish");
	ph3_leader_sideways_body_Finish->Off();

	ph3_leader_sideways_body_Finish_0 = CreateComponent<GameEngineSpriteRenderer>();
	ph3_leader_sideways_body_Finish_0->CreateAnimation({ .AnimationName = "ph3_leader_sideways_body_Finish_0", .SpriteName = "ph3_leader_sideways_body_Finish_0", .FrameInter = 0.08f,.Loop = false, .ScaleToTexture = true });
	ph3_leader_sideways_body_Finish_0->ChangeAnimation("ph3_leader_sideways_body_Finish_0");
	ph3_leader_sideways_body_Finish_0->Off();



	ph3_leader_sideways_body = CreateComponent<GameEngineSpriteRenderer>();
	ph3_leader_sideways_body->CreateAnimation({ .AnimationName = "ph3_leader_sideways_body", .SpriteName = "ph3_leader_sideways_body", .FrameInter = 0.08f,.Loop = false, .ScaleToTexture = true });
	ph3_leader_sideways_body->ChangeAnimation("ph3_leader_sideways_body");
	ph3_leader_sideways_body->On();

	ph3_leader_sideways_arms_backer = CreateComponent<GameEngineSpriteRenderer>();
	ph3_leader_sideways_arms_backer->CreateAnimation({ .AnimationName = "ph3_leader_sideways_arms_backer", .SpriteName = "ph3_leader_sideways_arms_backer", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	ph3_leader_sideways_arms_backer->ChangeAnimation("ph3_leader_sideways_arms_backer");
	ph3_leader_sideways_arms_backer->GetTransform()->AddLocalPosition({ 0,0,0 });
	ph3_leader_sideways_arms_backer->Off();

	ph3_leader_sideways_body_Attack = CreateComponent<GameEngineSpriteRenderer>();
	ph3_leader_sideways_body_Attack->CreateAnimation({ .AnimationName = "ph3_leader_sideways_body_Attack", .SpriteName = "ph3_leader_sideways_body_Attack", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	ph3_leader_sideways_body_Attack->ChangeAnimation("ph3_leader_sideways_body_Attack");
	ph3_leader_sideways_body_Attack->Off();
	ph3_leader_sideways_body_Attack->GetTransform()->AddLocalPosition({ 0,0,0 });


	ph3_tongue_rotate_camera = CreateComponent<GameEngineSpriteRenderer>();
	ph3_tongue_rotate_camera->CreateAnimation({ .AnimationName = "ph3_tongue_rotate_camera", .SpriteName = "ph3_tongue_rotate_camera", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true ,.FrameIndex = {0,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1} });
	ph3_tongue_rotate_camera->ChangeAnimation("ph3_tongue_rotate_camera");
	ph3_tongue_rotate_camera->Off();

	ph3_leader_sideways_arms = CreateComponent<GameEngineSpriteRenderer>();
	ph3_leader_sideways_arms->CreateAnimation({ .AnimationName = "ph3_leader_sideways_arms", .SpriteName = "ph3_leader_sideways_arms", .FrameInter = 0.05f,.Loop = true, .ScaleToTexture = true });
	ph3_leader_sideways_arms->ChangeAnimation("ph3_leader_sideways_arms");
	ph3_leader_sideways_arms->GetTransform()->AddLocalPosition({ 0,0,0 });
	ph3_leader_sideways_arms->Off();

	ph3_tongue_rotate_camera_tongue = CreateComponent<GameEngineSpriteRenderer>();
	ph3_tongue_rotate_camera_tongue->CreateAnimation({ .AnimationName = "ph3_tongue_rotate_camera_tongue", .SpriteName = "ph3_tongue_rotate_camera_tongue", .FrameInter = 0.08f,.Loop = false, .ScaleToTexture = true });
	ph3_tongue_rotate_camera_tongue->ChangeAnimation("ph3_tongue_rotate_camera_tongue");
	ph3_tongue_rotate_camera_tongue->On();


	ph3_leader_sideways_death = CreateComponent<GameEngineSpriteRenderer>();
	ph3_leader_sideways_death->CreateAnimation({ .AnimationName = "ph3_leader_sideways_death", .SpriteName = "ph3_leader_sideways_death", .FrameInter = 0.08f,.Loop = true, .ScaleToTexture = true ,.FrameIndex = {0,1,2,3,4,5,4,3,2,1} });
	ph3_leader_sideways_death->ChangeAnimation("ph3_leader_sideways_death");
	ph3_leader_sideways_death->Off();

	ph3_leader_sideways_death_tears = CreateComponent<GameEngineSpriteRenderer>();
	ph3_leader_sideways_death_tears->CreateAnimation({ .AnimationName = "ph3_leader_sideways_death_tears", .SpriteName = "ph3_leader_sideways_death_tears", .FrameInter = 0.08f,.Loop = true, .ScaleToTexture = true });
	ph3_leader_sideways_death_tears->ChangeAnimation("ph3_leader_sideways_death_tears");
	ph3_leader_sideways_death_tears->Off();


	ph3_dogcopter_sideways_death_tongue = CreateComponent<GameEngineSpriteRenderer>();
	ph3_dogcopter_sideways_death_tongue->CreateAnimation({ .AnimationName = "ph3_dogcopter_sideways_death_tongue", .SpriteName = "ph3_dogcopter_sideways_death_tongue", .FrameInter = 0.08f,.Loop = true, .ScaleToTexture = true /*,.FrameIndex = {0,1,2,3,4,5,6,5,4,3,2,1}*/ });
	ph3_dogcopter_sideways_death_tongue->ChangeAnimation("ph3_dogcopter_sideways_death_tongue");
	ph3_dogcopter_sideways_death_tongue->Off();


	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({ 300.0f, 250.0f, 300.0f });
	Collision->SetOrder((int)CollisionType::BossBody);
	


}

void ph3_Dog_Npc::Update(float _Delta)
{

	





	if (Ph3_DogAirplane::ph3_mainBoss->Get_ph3_dogcopter_rotate_camera()->GetCurrentFrame() == 15)
	{
		ph3_main_boss_Check = true;
	}
	if (ph3_main_boss_Check == true)
	{
		switch (Ph3_DogAirplane::ph3_mainBoss->GetRotationCheck())
		{
		case 0:
		{
			if (Collision->Collision((int)CollisionType::Bullet))
			{
				if (CollisonCheck == false)
				{

					ph3_leader_sideways_body->ColorOptionValue.PlusColor = { 1,1,1,0 };
					ph3_leader_sideways_arms_backer->ColorOptionValue.PlusColor = { 1,1,1,0 };
					ph3_leader_sideways_body_Attack->ColorOptionValue.PlusColor = { 1,1,1,0 };
					ph3_leader_sideways_arms->ColorOptionValue.PlusColor = { 1,1,1,0 };
					ResetLiveTime();
					CollisonCheck = true;

				}

				Ph3_DogAirplane::Hp -= 1;

				std::shared_ptr<GameEngineCollision> collision = Collision->Collision((int)CollisionType::Bullet);

				if (collision != nullptr)
				{
					collision->Off();
				}
			}

			if (CollisonCheck == true && GetLiveTime() > 0.03f)
			{

				ph3_leader_sideways_body->ColorOptionValue.PlusColor = { 0,0,0,0 };
				ph3_leader_sideways_arms_backer->ColorOptionValue.PlusColor = { 0,0,0,0 };
				ph3_leader_sideways_body_Attack->ColorOptionValue.PlusColor = { 0,0,0,0 };
				ph3_leader_sideways_arms->ColorOptionValue.PlusColor = { 0,0,0,0 };

				CollisonCheck = false;
			}


			if (ph3_tongue_rotate_camera_tongue->IsAnimationEnd())
			{
				ph3_tongue_rotate_camera_tongue->Off();
				ph3_tongue_rotate_camera->On();
			}

			if (ph3_leader_sideways_body->IsAnimationEnd())
			{
				ph3_leader_sideways_body->Off();
				ph3_leader_sideways_arms_backer->On();
				ph3_leader_sideways_body_Attack->On();
				ph3_leader_sideways_arms->On();
			}
			if (Ph3_DogAirplane::ph3_mainBoss->GetBowlCheck() == 8)
			{
				ph3_leader_sideways_arms_backer->Off();
				ph3_leader_sideways_body_Attack->Off();
				ph3_leader_sideways_arms->Off();
				ph3_leader_sideways_body_Finish_0->On();
				Collision->Off();
			}

			if (ph3_leader_sideways_body_Finish_0->IsAnimationEnd())
			{
				ph3_leader_sideways_body_Finish_0->Off();
				ph3_leader_sideways_body_Finish->On();
			}

			

		}
		break;
		case 1:
		{

			Collision->Off(); 
			

			ph3_leader_sideways_body->Off(); 
			ph3_leader_sideways_arms_backer->Off(); 
			ph3_leader_sideways_body_Attack->Off(); 
			ph3_tongue_rotate_camera->Off();
			ph3_tongue_rotate_camera_tongue->Off(); 
			ph3_leader_sideways_body_Finish->Off(); 
			ph3_leader_sideways_body_Finish_0->Off();
			ph3_leader_sideways_arms->Off();         
		}
		break;
		case 2:
		{
			Collision->On();
			if (Ph3_DogAirplane::Hp < 0)
			{
				
				ph3_leader_sideways_body_Finish->Off();
				ph3_leader_sideways_body_Finish_0->Off();
				ph3_leader_sideways_arms->Off();
				ph3_leader_sideways_body_Attack->Off();
				ph3_leader_sideways_arms_backer->Off();
				ph3_leader_sideways_body->Off();
				ph3_tongue_rotate_camera_tongue->Off(); 
				ph3_dogcopter_sideways_death_tongue->On();
				ph3_leader_sideways_death->On();
				ph3_leader_sideways_death_tears->On(); 
				return; 
			}
			if (Collision->Collision((int)CollisionType::Bullet))
			{
				if (CollisonCheck == false)
				{

					ph3_leader_sideways_body->ColorOptionValue.PlusColor = { 1,1,1,0 };
					ph3_leader_sideways_arms_backer->ColorOptionValue.PlusColor = { 1,1,1,0 };
					ph3_leader_sideways_body_Attack->ColorOptionValue.PlusColor = { 1,1,1,0 };
					ph3_leader_sideways_arms->ColorOptionValue.PlusColor = { 1,1,1,0 };
					ResetLiveTime();
					CollisonCheck = true;

				}

				Ph3_DogAirplane::Hp -= 1;

				std::shared_ptr<GameEngineCollision> collision = Collision->Collision((int)CollisionType::Bullet);

				if (collision != nullptr)
				{
					collision->Off();
				}
			}

			if (CollisonCheck == true && GetLiveTime() > 0.03f)
			{

				ph3_leader_sideways_body->ColorOptionValue.PlusColor = { 0,0,0,0 };
				ph3_leader_sideways_arms_backer->ColorOptionValue.PlusColor = { 0,0,0,0 };
				ph3_leader_sideways_body_Attack->ColorOptionValue.PlusColor = { 0,0,0,0 };
				ph3_leader_sideways_arms->ColorOptionValue.PlusColor = { 0,0,0,0 };

				CollisonCheck = false;
			}

			if (test == false)
			{
				ph3_leader_sideways_body_Finish->Off(); 
				ph3_tongue_rotate_camera_tongue->On();
				ph3_leader_sideways_body->On();

				ph3_tongue_rotate_camera_tongue->ChangeAnimation("ph3_tongue_rotate_camera_tongue");
				ph3_leader_sideways_body->ChangeAnimation("ph3_leader_sideways_body");
				ph3_leader_sideways_body_Finish_0->ChangeAnimation("ph3_leader_sideways_body_Finish_0");
				ph3_leader_sideways_body_Finish->ChangeAnimation("ph3_leader_sideways_body_Finish");

				test = true;
			}

			if (ph3_tongue_rotate_camera_tongue->IsAnimationEnd())
			{
				ph3_tongue_rotate_camera_tongue->Off();
				ph3_tongue_rotate_camera->On();
			}

			if (ph3_leader_sideways_body->IsAnimationEnd())
			{
				ph3_leader_sideways_body->Off();
				ph3_leader_sideways_arms_backer->On();
				ph3_leader_sideways_body_Attack->On();
				ph3_leader_sideways_arms->On();
			}
		/*	if (Ph3_DogAirplane::ph3_mainBoss->GetBowlCheck() == 8)
			{
				ph3_leader_sideways_arms_backer->Off();
				ph3_leader_sideways_body_Attack->Off();
				ph3_leader_sideways_arms->Off();
				ph3_leader_sideways_body_Finish_0->On();
			}

			if (ph3_leader_sideways_body_Finish_0->IsAnimationEnd())
			{
				ph3_leader_sideways_body_Finish_0->Off();
				ph3_leader_sideways_body_Finish->On();
			}*/
			
		}
		break;
		case 3:
		{
			



			//if (GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef().Rotation.z > 360)
			//{
			//	GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,-1 });
			//	GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ -3,0,0 });
			//	//GetTransform()->SetLocalPosition({ 0,0 });
			//	RotationCheck = 0;
			//}
			//GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,1 });
			//GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ 3,0,0 });

		}
		break;

		default:
			break;
		}
	}
	/*if (GetLevel()->GetMainCamera()->GetTransform()->GetTransDataRef().Rotation.z > 360)
	{
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalRotation({ 0,0,0});
		GetLevel()->GetMainCamera()->GetTransform()->AddLocalPosition({ 0,0,0 });
		RotationCheck = 0;
		TransformData data = GetTransform()->GetTransDataRef();
		int a = 0;
	}*/

	


}

void ph3_Dog_Npc::Render(float _Delta)
{
}
