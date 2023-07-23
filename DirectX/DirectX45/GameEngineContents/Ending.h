#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineSound.h>

class Ending : public GameEngineActor
{
public:

	// constrcuter destructer
	Ending();
	~Ending();

	// delete Function
	Ending(const Ending& _Other) = delete;
	Ending(Ending&& _Other) noexcept = delete;
	Ending& operator=(const Ending& _Other) = delete;
	Ending& operator=(Ending&& _Other) noexcept = delete;




protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:
	GameEngineSoundPlayer End;
	bool Sound_End_Check = false;
	bool Check = false;

	std::shared_ptr<class GameEngineSpriteRenderer> TitleRoge;
	std::shared_ptr<class GameEngineSpriteRenderer> cuphead_End_screen;
	
	std::shared_ptr<class GameEngineSpriteRenderer> ending;
	std::shared_ptr<class GameEngineSpriteRenderer> start;





};

