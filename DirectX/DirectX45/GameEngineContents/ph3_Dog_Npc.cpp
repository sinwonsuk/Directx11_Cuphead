#include "PrecompileHeader.h"
#include "ph3_Dog_Npc.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineCamera.h>
ph3_Dog_Npc::ph3_Dog_Npc()
{
}

ph3_Dog_Npc::~ph3_Dog_Npc()
{
}

void ph3_Dog_Npc::Start()
{
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
	}
	


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


}

void ph3_Dog_Npc::Update(float _Delta)
{
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


}

void ph3_Dog_Npc::Render(float _Delta)
{
}
