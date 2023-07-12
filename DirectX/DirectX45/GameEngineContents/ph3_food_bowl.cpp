#include "PrecompileHeader.h"
#include "ph3_food_bowl.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "EnumClass.h"

ph3_food_bowl::ph3_food_bowl()
{

}

ph3_food_bowl::~ph3_food_bowl()
{

}

void ph3_food_bowl::Start()
{
	if (nullptr == GameEngineSprite::Find("ph3_dog_bowl_drop_red"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("DogAirplane");


		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dog_bowl_drop_red").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dog_bowl_drop_yellow").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dog_bowl_launch").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dog_bowl_shoot_lines").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dog_bowl_shoot_yellow").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ph3_dog_bowl_shoot_red").GetFullPath());
	}

	Bullet = CreateComponent<GameEngineSpriteRenderer>(101);
	Bullet->CreateAnimation({ .AnimationName = "ph3_dog_bowl_drop_red", .SpriteName = "ph3_dog_bowl_drop_red", .FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true, });

	Bullet->CreateAnimation({ .AnimationName = "ph3_dog_bowl_drop_yellow", .SpriteName = "ph3_dog_bowl_drop_yellow", .FrameInter = 0.05f, .Loop = true,.ScaleToTexture = true, });
	Bullet->CreateAnimation({ .AnimationName = "ph3_dog_bowl_shoot_yellow", .SpriteName = "ph3_dog_bowl_drop_yellow", .FrameInter = 0.05f, .Loop = true,.ScaleToTexture = true, });
	Bullet->CreateAnimation({ .AnimationName = "ph3_dog_bowl_shoot_red", .SpriteName = "ph3_dog_bowl_shoot_red", .FrameInter = 0.05f, .Loop = true,.ScaleToTexture = true, });
	Bullet->ChangeAnimation("ph3_dog_bowl_drop_red");

	Bullet->GetTransform()->AddLocalPosition({ 0,0,0 }); 

	Sfx = CreateComponent<GameEngineSpriteRenderer>();
	Sfx->CreateAnimation({ .AnimationName = "ph3_dog_bowl_launch", .SpriteName = "ph3_dog_bowl_launch", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	Sfx->ChangeAnimation("ph3_dog_bowl_launch");
	Sfx->GetTransform()->AddLocalPosition({ 0,0,0 });

	ph3_dog_bowl_shoot_lines = CreateComponent<GameEngineSpriteRenderer>();
	ph3_dog_bowl_shoot_lines->CreateAnimation({ .AnimationName = "ph3_dog_bowl_shoot_lines", .SpriteName = "ph3_dog_bowl_shoot_lines", .FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true, });
	ph3_dog_bowl_shoot_lines->ChangeAnimation("ph3_dog_bowl_shoot_lines");
	ph3_dog_bowl_shoot_lines->Off(); 

	ColorCheck = GameEngineRandom::MainRandom.RandomInt(0, 1);

	if (ColorCheck == 0)
	{
		Bullet->ChangeAnimation("ph3_dog_bowl_drop_red");
	}
	else if (ColorCheck == 1)
	{
		Bullet->ChangeAnimation("ph3_dog_bowl_drop_yellow");
	}

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform()->SetLocalScale({30.0f, 30.0f, 300.0f });
	Collision->SetOrder((int)CollisionType::BossAttack);

}

void ph3_food_bowl::Update(float _Delta)
{
	

	if (HeightCheck == false)
	{
		Bullet->GetTransform()->AddLocalRotation({ 0,0 ,200 * _Delta });
	}
	
	if (Sfx->IsAnimationEnd())
	{
		Sfx->Off(); 
	}
	if (ph3_dog_bowl_shoot_lines->IsAnimationEnd())
	{
		ph3_dog_bowl_shoot_lines->Off(); 
	}

	switch (DirCheck)
	{
	case 0:



		if (Gravity.y > -8)
		{
			Gravity += float4::Down * 20.0f * _Delta;
			Bullet->GetTransform()->AddLocalPosition({ float4::Down * 20.0f * _Delta });
			Bullet->GetTransform()->AddLocalPosition(LeftMoveDir * _Delta * 650);

		}
		if (Gravity.y < -8)
		{		

			Bullet->GetTransform()->AddLocalPosition({ 0,-600 * _Delta,0 });
			TransformData data = GetTransform()->GetTransDataRef(); 

			if (Bullet->GetTransform()->GetLocalPosition().y < -170 && ColorCheck == 0)
			{
				if (HeightCheck == false )
				{
					Bullet->ChangeAnimation("ph3_dog_bowl_shoot_red");
					ph3_dog_bowl_shoot_lines->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });
					ph3_dog_bowl_shoot_lines->On(); 
					HeightCheck = true;
				}
				Bullet->GetTransform()->AddLocalPosition({ 600 * _Delta,600* _Delta,-1 });
				Bullet->GetTransform()->SetLocalRotation({ 0,0,0});
			}

			else if (Bullet->GetTransform()->GetLocalPosition().y < -40 && ColorCheck == 1)
			{
				if (HeightCheck == false )
				{
					Bullet->ChangeAnimation("ph3_dog_bowl_shoot_yellow");
					ph3_dog_bowl_shoot_lines->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });
					ph3_dog_bowl_shoot_lines->On();
					HeightCheck = true;

				}
				Bullet->GetTransform()->AddLocalPosition({ 600 * _Delta,600 * _Delta,-1 });
				Bullet->GetTransform()->SetLocalRotation({ 0,0,0 });
			}


		}		
		break;
	case 1:

		Sfx->GetTransform()->SetLocalRotation({ 0,180,0 });
		ph3_dog_bowl_shoot_lines->GetTransform()->SetLocalRotation({ 0,180,0 });


		if (Gravity.y > -8)
		{
			Gravity += float4::Down * 20.0f * _Delta;
			Bullet->GetTransform()->AddLocalPosition({ float4::Down * 20.0f * _Delta });
			Bullet->GetTransform()->AddLocalPosition(RightMoveDir * _Delta * 650);

		}
		if (Gravity.y < -8)
		{

			Bullet->GetTransform()->AddLocalPosition({ 0,-600 * _Delta,0 });
			TransformData data = GetTransform()->GetTransDataRef();

			if (Bullet->GetTransform()->GetLocalPosition().y < -170 && ColorCheck == 0)
			{
				if (HeightCheck == false)
				{
					Bullet->ChangeAnimation("ph3_dog_bowl_shoot_red");
					ph3_dog_bowl_shoot_lines->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });
					ph3_dog_bowl_shoot_lines->On();
					HeightCheck = true;
				}
				Bullet->GetTransform()->AddLocalPosition({ -600 * _Delta,600 * _Delta,0 });
				Bullet->GetTransform()->SetLocalRotation({ 0,0,0 });
			}

			else if (Bullet->GetTransform()->GetLocalPosition().y < -40 && ColorCheck == 1)
			{
				if (HeightCheck == false)
				{
					Bullet->ChangeAnimation("ph3_dog_bowl_shoot_yellow");
					ph3_dog_bowl_shoot_lines->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });
					ph3_dog_bowl_shoot_lines->On();
					HeightCheck = true;
				}
				Bullet->GetTransform()->AddLocalPosition({ -600 * _Delta,600 * _Delta,0 });
				Bullet->GetTransform()->SetLocalRotation({ 0,0,0 });
			}
		}
		break;
	case 2:

		if (Gravity.y > -8)
		{
			Gravity += float4::Down * 20.0f * _Delta;
			Bullet->GetTransform()->AddLocalPosition({ Gravity });
			Bullet->GetTransform()->AddLocalPosition(LeftMoveDir * _Delta * 650);

		}
		if (Gravity.y < -8)
		{

			Bullet->GetTransform()->AddLocalPosition({ 0,-600 * _Delta,0 });
			TransformData data = GetTransform()->GetTransDataRef();

			if (Bullet->GetTransform()->GetLocalPosition().y < -170 && ColorCheck == 0)
			{
				if (HeightCheck == false)
				{
					Bullet->ChangeAnimation("ph3_dog_bowl_shoot_red");
					ph3_dog_bowl_shoot_lines->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });
					ph3_dog_bowl_shoot_lines->On();
					HeightCheck = true;
				}
				Bullet->GetTransform()->AddLocalPosition({ 600 * _Delta,600 * _Delta,-1 });
				Bullet->GetTransform()->SetLocalRotation({ 0,0,0 });
			}

			else if (Bullet->GetTransform()->GetLocalPosition().y < -40 && ColorCheck == 1)
			{
				if (HeightCheck == false)
				{
					Bullet->ChangeAnimation("ph3_dog_bowl_shoot_yellow");
					ph3_dog_bowl_shoot_lines->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });
					ph3_dog_bowl_shoot_lines->On();
					HeightCheck = true;

				}
				Bullet->GetTransform()->AddLocalPosition({ 600 * _Delta,600 * _Delta,-1 });
				Bullet->GetTransform()->SetLocalRotation({ 0,180,0 });
			}


		}
		break;
	case 3:

		Sfx->GetTransform()->SetLocalRotation({ 0,180,0 });
		ph3_dog_bowl_shoot_lines->GetTransform()->SetLocalRotation({ 0,180,0 });


		if (Gravity.y > -8)
		{
			Gravity += float4::Down * 20.0f * _Delta;
			Bullet->GetTransform()->AddLocalPosition({ Gravity });
			Bullet->GetTransform()->AddLocalPosition(RightMoveDir * _Delta * 650);

		}
		if (Gravity.y < -8)
		{

			Bullet->GetTransform()->AddLocalPosition({ 0,-600 * _Delta,0 });
			TransformData data = GetTransform()->GetTransDataRef();

			if (Bullet->GetTransform()->GetLocalPosition().y < -170 && ColorCheck == 0)
			{
				if (HeightCheck == false)
				{
					Bullet->ChangeAnimation("ph3_dog_bowl_shoot_red");
					ph3_dog_bowl_shoot_lines->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });
					ph3_dog_bowl_shoot_lines->On();
					HeightCheck = true;
				}
				Bullet->GetTransform()->AddLocalPosition({ -600 * _Delta,600 * _Delta,0 });
				Bullet->GetTransform()->SetLocalRotation({ 0,0,0 });
			}

			else if (Bullet->GetTransform()->GetLocalPosition().y < -40 && ColorCheck == 1)
			{
				if (HeightCheck == false)
				{
					Bullet->ChangeAnimation("ph3_dog_bowl_shoot_yellow");
					ph3_dog_bowl_shoot_lines->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });
					ph3_dog_bowl_shoot_lines->On();
					HeightCheck = true;
				}
				Bullet->GetTransform()->AddLocalPosition({ -600 * _Delta,600 * _Delta,0 });
				Bullet->GetTransform()->SetLocalRotation({ 0,360,0 });
			}
		}
		break;
	default:
		break;
	}

	Collision->GetTransform()->SetLocalPosition({ Bullet->GetTransform()->GetLocalPosition() });
	if (GetLiveTime() > 5)
	{
		this->Death(); 
	}


}
