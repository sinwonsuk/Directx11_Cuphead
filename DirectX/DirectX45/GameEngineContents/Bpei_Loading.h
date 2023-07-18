#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Bpei_Loading : public GameEngineActor
{
public:
	// constrcuter destructer
	Bpei_Loading();
	~Bpei_Loading();

	// delete Function
	Bpei_Loading(const Bpei_Loading& _Other) = delete;
	Bpei_Loading(Bpei_Loading&& _Other) noexcept = delete;
	Bpei_Loading& operator=(const Bpei_Loading& _Other) = delete;
	Bpei_Loading& operator=(Bpei_Loading&& _Other) noexcept = delete;



	//static bool Finish;
	static bool Check;



protected:

	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;



private:



	std::shared_ptr<class GameEngineSpriteRenderer> Loading;

	std::shared_ptr<class GameEngineSpriteRenderer> BG;




};

