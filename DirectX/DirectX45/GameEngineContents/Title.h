#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Title : public GameEngineActor
{
public:

	// constrcuter destructer
	Title();
	~Title();

	// delete Function
	Title(const Title& _Other) = delete;
	Title(Title&& _Other) noexcept = delete;
	Title& operator=(const Title& _Other) = delete;
	Title& operator=(Title&& _Other) noexcept = delete;

	
	

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:

	bool Check = false;

	std::shared_ptr<class GameEngineSpriteRenderer> TitleRoge;
	std::shared_ptr<class GameEngineSpriteRenderer> cuphead_title_screen;
	std::shared_ptr<class GameEngineSpriteRenderer> title_screen_background;

	std::shared_ptr<class GameEngineSpriteRenderer> Exit;
	



	
};

