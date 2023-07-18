#pragma once
#include <GameEngineCore/GameEngineActor.h>

class OverWorldLoading : public GameEngineActor
{
public:
	// constrcuter destructer
	OverWorldLoading();
	~OverWorldLoading();

	// delete Function
	OverWorldLoading(const OverWorldLoading& _Other) = delete;
	OverWorldLoading(OverWorldLoading&& _Other) noexcept = delete;
	OverWorldLoading& operator=(const OverWorldLoading& _Other) = delete;
	OverWorldLoading& operator=(OverWorldLoading&& _Other) noexcept = delete;



	



protected:

	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;



private:
	bool Check = false;

	std::shared_ptr<class GameEngineSpriteRenderer> BG;

	std::shared_ptr<class GameEngineSpriteRenderer> Loading;






};

