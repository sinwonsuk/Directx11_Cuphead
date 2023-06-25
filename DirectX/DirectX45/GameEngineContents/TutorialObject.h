#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TutorialObject : public GameEngineActor
{
public:
	// constrcuter destructer
	TutorialObject();
	~TutorialObject();

	// delete Function
	TutorialObject(const TutorialObject& _Other) = delete;
	TutorialObject(TutorialObject&& _Other) noexcept = delete;
	TutorialObject& operator=(const TutorialObject& _Other) = delete;
	TutorialObject& operator=(TutorialObject&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> Render5;
	std::shared_ptr<class GameEngineSpriteRenderer> Render1;
	std::shared_ptr<class GameEngineSpriteRenderer> Render2;
	std::shared_ptr<class GameEngineSpriteRenderer> Render3;

	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffect;
	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffect2;
	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffect3;

	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffectIntro;
	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffectIntro2;
	std::shared_ptr<class GameEngineSpriteRenderer> CollisionEffectIntro3;

	std::shared_ptr<class GameEngineCollision> Collision1;
	std::shared_ptr<class GameEngineCollision> Collision2;
	std::shared_ptr<class GameEngineCollision> Collision3;
	bool test = false;

	bool LeftCollisionCheck = false;
	bool MiddleCollisionCheck = false;
	bool RightCollisionCheck = false;

	bool RightMove = false;
	bool LeftMove = false;
	int GravityCheck = 0;
	int RightCheck = 0;
	int LeftCheck = 0;
};

