#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineSound.h>
// Ό³Έν :
class TutorialObject : public GameEngineActor
{
public:
	static TutorialObject* Object;
	// constrcuter destructer
	TutorialObject();
	~TutorialObject();

	// delete Function
	TutorialObject(const TutorialObject& _Other) = delete;
	TutorialObject(TutorialObject&& _Other) noexcept = delete;
	TutorialObject& operator=(const TutorialObject& _Other) = delete;
	TutorialObject& operator=(TutorialObject&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineSpriteRenderer> GetPyramid_Topper()
	{
		return Pyramid_Topper;
	}
	std::shared_ptr<class GameEngineSpriteRenderer> Gettutorial_target()
	{
		return tutorial_target;
	}
	int TargetHp = 10;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	GameEngineSoundPlayer Destory;
	
	std::shared_ptr<class GameEngineSpriteRenderer> Render1;
	std::shared_ptr<class GameEngineSpriteRenderer> Render2;
	std::shared_ptr<class GameEngineSpriteRenderer> Render3;

	std::shared_ptr<class GameEngineSpriteRenderer> Pyramid_Topper;
	std::shared_ptr<class GameEngineSpriteRenderer> tutorial_target;
	std::shared_ptr<class GameEngineSpriteRenderer> Explosion;

	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffect;
	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffect2;
	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffect3;

	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffectIntro;
	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffectIntro2;
	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffectIntro3;

	std::shared_ptr<class GameEngineCollision> Collision1;
	std::shared_ptr<class GameEngineCollision> Collision2;
	std::shared_ptr<class GameEngineCollision> Collision3;
	std::shared_ptr<class GameEngineCollision> Collision4;
	std::shared_ptr<class GameEngineCollision> Door;
	std::shared_ptr<class GameEngineSpriteRenderer> Exit;
	std::shared_ptr<class GameEngineCollision> tutorial_target_Collision;




	bool Destory_Check = false;

	bool LeftCollisionCheck = false;
	bool MiddleCollisionCheck = false;
	bool RightCollisionCheck = false;

	bool TargetCollisionCheck = false;
	bool RightMove = false;
	bool LeftMove = false;
	
	int GravityCheck = 0;
	int RightCheck = 0;
	int LeftCheck = 0;
};

