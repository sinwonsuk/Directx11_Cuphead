#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TutorialMap : public GameEngineActor
{
public:
	// constrcuter destructer
	TutorialMap();
	~TutorialMap();

	// delete Function
	TutorialMap(const TutorialMap& _Other) = delete;
	TutorialMap(TutorialMap&& _Other) noexcept = delete;
	TutorialMap& operator=(const TutorialMap& _Other) = delete;
	TutorialMap& operator=(TutorialMap&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> Render1;
	std::shared_ptr<class GameEngineSpriteRenderer> Render2;
	bool test = false;

	bool RightMove = false; 
	bool LeftMove = false;

	int GravityCheck = 0;
	int RightCheck = 0;
	int LeftCheck = 0;
};

