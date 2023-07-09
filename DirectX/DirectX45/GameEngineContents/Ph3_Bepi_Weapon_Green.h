#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class Ph3_Bepi_Weapon_Color
{
	Green,
	Red
};

class Ph3_Bepi_Weapon_Green : public GameEngineActor
{
public:
	// constrcuter destructer
	Ph3_Bepi_Weapon_Green();
	~Ph3_Bepi_Weapon_Green();

	// delete Function
	Ph3_Bepi_Weapon_Green(const Ph3_Bepi_Weapon_Green& _Other) = delete;
	Ph3_Bepi_Weapon_Green(Ph3_Bepi_Weapon_Green&& _Other) noexcept = delete;
	Ph3_Bepi_Weapon_Green& operator=(const Ph3_Bepi_Weapon_Green& _Other) = delete;
	Ph3_Bepi_Weapon_Green& operator=(Ph3_Bepi_Weapon_Green&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineSpriteRenderer> GetBullet()
	{
		return Pink_Bullet;
	}

	std::shared_ptr<class GameEngineSpriteRenderer> GetParryEffect()
	{
		return ParryEffect;
	}

	std::shared_ptr<class GameEngineCollision> GetPinkCollision()
	{
		return Pink_Collision;
	}

	std::shared_ptr<class GameEngineCollision> GetPinkCollision2()
	{
		return Pink_Collision2;
	}

	Ph3_Bepi_Weapon_Color color = Ph3_Bepi_Weapon_Color::Green;
	int MoveDir = 0; 
protected:
	void Start();
	void Update(float _Delta) override;

private:
	bool ColorCheck = false;

	bool DownCheck = false;

	int YellowPattern = 0;

	bool test = 0;
	float StopPos = 200;
	std::shared_ptr<class GameEngineSpriteRenderer> Bullet;
	std::shared_ptr<class GameEngineSpriteRenderer> Pink_Bullet;
	std::shared_ptr<class GameEngineSpriteRenderer> ParryEffect;
	std::shared_ptr<class GameEngineCollision> Pink_Collision;
	std::shared_ptr<class GameEngineCollision> Pink_Collision2;
	std::shared_ptr<class GameEngineCollision> Collision;
	float Pos_x = 0; 
	float Pos_y = 0;
	float AccTime = 0.0f;
	float Speed = 1200;
	bool Stop = false;


	
};

