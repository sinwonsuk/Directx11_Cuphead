#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Ph3_Bepi_Weapon : public GameEngineActor
{
public:
	// constrcuter destructer
	Ph3_Bepi_Weapon();
	~Ph3_Bepi_Weapon();

	// delete Function
	Ph3_Bepi_Weapon(const Ph3_Bepi_Weapon& _Other) = delete;
	Ph3_Bepi_Weapon(Ph3_Bepi_Weapon&& _Other) noexcept = delete;
	Ph3_Bepi_Weapon& operator=(const Ph3_Bepi_Weapon& _Other) = delete;
	Ph3_Bepi_Weapon& operator=(Ph3_Bepi_Weapon&& _Other) noexcept = delete;
	float SetStopPos(float _StopPos)
	{
		StopPos = _StopPos;
		return StopPos;
	}


	bool DownCheck = false;

	int YellowPattern = 0;
protected:
	void Start();
	void Update(float _Delta) override;

private:

	
	float StopPos = 200;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;
	
	

	float Speed = 1200;

	bool Stop = false;
};

