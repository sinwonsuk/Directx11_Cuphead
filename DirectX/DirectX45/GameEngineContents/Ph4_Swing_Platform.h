#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class Choice
{
	Intro,
	Idle,

};


class Ph4_Swing_Platform : public GameEngineActor
{
public:

	static bool Ph4_Platform_Check;
	// constrcuter destructer
	Ph4_Swing_Platform();
	~Ph4_Swing_Platform();

	// delete Function
	Ph4_Swing_Platform(const Ph4_Swing_Platform& _Other) = delete;
	Ph4_Swing_Platform(Ph4_Swing_Platform&& _Other) noexcept = delete;
	Ph4_Swing_Platform& operator=(const Ph4_Swing_Platform& _Other) = delete;
	Ph4_Swing_Platform& operator=(Ph4_Swing_Platform&& _Other) noexcept = delete;


	Choice choic = Choice::Intro;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;



private:
	float Time = 0;

	float Speed = 300;

	bool CollisionCheck = false; 
	std::shared_ptr<class GameEngineSpriteRenderer> Swing_Platform;

	std::shared_ptr<class GameEngineSpriteRenderer> Swing_Rope;

	std::shared_ptr<class GameEngineCollision> Collision;
//	bool Ph4_Platform_Check = false;
	float4 CurPos = {};
	int Check = 0;

};
