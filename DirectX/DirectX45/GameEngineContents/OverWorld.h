
#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class OverWorld : public GameEngineLevel
{
public:
	// constrcuter destructer
	OverWorld();
	~OverWorld();

	// delete Function
	OverWorld(const OverWorld& _Other) = delete;
	OverWorld(OverWorld&& _Other) noexcept = delete;
	OverWorld& operator=(const OverWorld& _Other) = delete;
	OverWorld& operator=(OverWorld&& _Other) noexcept = delete;

	

protected:
	void Update(float _DeltaTime) override;
	void Start() override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;


private:
	


};