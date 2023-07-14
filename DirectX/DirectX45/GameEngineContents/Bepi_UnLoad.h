#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Bepi_UnLoad : public GameEngineActor
{
public:
	// constrcuter destructer
	Bepi_UnLoad();
	~Bepi_UnLoad();

	// delete Function
	Bepi_UnLoad(const Bepi_UnLoad& _Other) = delete;
	Bepi_UnLoad(Bepi_UnLoad&& _Other) noexcept = delete;
	Bepi_UnLoad& operator=(const Bepi_UnLoad& _Other) = delete;
	Bepi_UnLoad& operator=(Bepi_UnLoad&& _Other) noexcept = delete;

	static bool Check;





protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;



private:



	std::shared_ptr<class GameEngineSpriteRenderer> Loading;






};

