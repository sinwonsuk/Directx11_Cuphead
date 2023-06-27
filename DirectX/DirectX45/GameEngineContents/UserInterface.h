#pragma once
#include <GameEngineCore/GameEngineActor.h>

class UserInterface : public GameEngineActor
{
public:
	UserInterface();
	~UserInterface();

	// delete Function
	UserInterface(const UserInterface& _Other) = delete;
	UserInterface(UserInterface&& _Other) noexcept = delete;
	UserInterface& operator=(const UserInterface& _Other) = delete;
	UserInterface& operator=(UserInterface&& _Other) noexcept = delete;
	static float Cut;
	static int CardNumber;

protected:
	void Start();
	void Update(float _Delta) override;

private:

	std::shared_ptr<class GameEngineCollision> Collision;

	std::shared_ptr<class GameEngineSpriteRenderer> Hp3;
	std::shared_ptr<class GameEngineSpriteRenderer> Hp2;
	std::shared_ptr<class GameEngineSpriteRenderer> Hp1;

	
	std::shared_ptr<class GameEngineSpriteRenderer> BackCard;
	std::shared_ptr<class GameEngineSpriteRenderer> BackCard2;
	std::shared_ptr<class GameEngineSpriteRenderer> BackCard3;
	std::shared_ptr<class GameEngineSpriteRenderer> BackCard4;
	std::shared_ptr<class GameEngineSpriteRenderer> BackCard5;

	std::shared_ptr<class GameEngineSpriteRenderer> FlipCard;
	std::shared_ptr<class GameEngineSpriteRenderer> FlipCard2;
	std::shared_ptr<class GameEngineSpriteRenderer> FlipCard3;
	std::shared_ptr<class GameEngineSpriteRenderer> FlipCard4;
	std::shared_ptr<class GameEngineSpriteRenderer> FlipCard5;



	//std::shared_ptr<class GameEngineSpriteRenderer> FlipCard;

	std::shared_ptr<class GameEngineSpriteRenderer> FrontCard;
	int	ConsumeCard = 0;
	int PrevConsumeCard = 0;
	int PlusCard = 0;
};









