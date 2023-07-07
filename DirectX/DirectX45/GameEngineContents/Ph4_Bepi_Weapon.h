#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Ph4_Bepi_Weapon : public GameEngineActor
{
public:
	// constrcuter destructer
	Ph4_Bepi_Weapon();
	~Ph4_Bepi_Weapon();

	// delete Function
	Ph4_Bepi_Weapon(const Ph4_Bepi_Weapon& _Other) = delete;
	Ph4_Bepi_Weapon(Ph4_Bepi_Weapon&& _Other) noexcept = delete;
	Ph4_Bepi_Weapon& operator=(const Ph4_Bepi_Weapon& _Other) = delete;
	Ph4_Bepi_Weapon& operator=(Ph4_Bepi_Weapon&& _Other) noexcept = delete;
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


