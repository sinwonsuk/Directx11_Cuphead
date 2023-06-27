#pragma once
#include <GameEngineCore/GameEngineActor.h>


class TimeFlow : public GameEngineActor
{
public:
	static float Time;
	// constrcuter destructer
	TimeFlow();
	~TimeFlow();

	// delete Function
	TimeFlow(const TimeFlow& _Other) = delete;
	TimeFlow(TimeFlow&& _Other) noexcept = delete;
	TimeFlow& operator=(const TimeFlow& _Other) = delete;
	TimeFlow& operator=(TimeFlow&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;

private:

	
	
};;

