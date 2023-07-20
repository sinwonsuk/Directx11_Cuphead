#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineSound.h>
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
	std::shared_ptr<class GameEngineSpriteRenderer> Render3;
	static GameEngineSoundPlayer BG;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	float Angle = 0.0f;
	
	std::shared_ptr<class GameEngineSpriteRenderer> Loading;
	std::shared_ptr<class GameEngineSpriteRenderer> Render1;
	std::shared_ptr<class GameEngineSpriteRenderer> Render2;
	
	

	bool Sound_Check = false;

	bool RightMove = false; 
	bool LeftMove = false;
	int fdf = 0;
	int GravityCheck = 0;
	int RightCheck = 0;
	int LeftCheck = 0;
};

