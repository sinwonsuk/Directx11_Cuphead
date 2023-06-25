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
	std::shared_ptr<class GameEngineSpriteRenderer> Render1;
	std::shared_ptr<class GameEngineSpriteRenderer> Render2;
	std::shared_ptr<class GameEngineCollision> Collision;
	bool test = false;

	bool RightMove = false;
	bool LeftMove = false;
	int GravityCheck = 0;
	int RightCheck = 0;
	int LeftCheck = 0;
};

