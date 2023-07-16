#include "PrecompileHeader.h"
#include "OldTVEffect.h"
#include <GameEnginePlatform/GameEngineInput.h>

OldTVEffect::OldTVEffect()
{
}

OldTVEffect::~OldTVEffect() 
{
}

void OldTVEffect::Start(GameEngineRenderTarget* _Target)
{
	BlurUnit = std::make_shared<GameEngineRenderUnit>();
	BlurUnit->SetMesh("FullRect");
	BlurUnit->SetPipeLine("OldTV");

	BaseValue.ScreenScale = GameEngineWindow::GetScreenSize();

	BlurUnit->ShaderResHelper.SetConstantBufferLink("RenderBaseValue", BaseValue);

	ResultTarget = GameEngineRenderTarget::Create(DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT, GameEngineWindow::GetScreenSize(), float4::Null);

}

void OldTVEffect::Effect(GameEngineRenderTarget* _Target, float _DeltaTime)
{
	BaseValue.Mouse = GameEngineWindow::GetMousePosition();
	BaseValue.Mouse.z = GameEngineInput::IsPress("EngineMouseLeft");
	BaseValue.Mouse.w = GameEngineInput::IsPress("EngineMouseLeft");

	BaseValue.Time.x += _DeltaTime;
	BaseValue.Time.y = _DeltaTime;

	ResultTarget->Clear();
	BlurUnit->ShaderResHelper.SetTexture("DiffuseTex", _Target->GetTexture(0));
	ResultTarget->Setting();
	BlurUnit->Render(_DeltaTime);
	BlurUnit->ShaderResHelper.AllResourcesReset();

	_Target->Clear();
	_Target->Merge(ResultTarget);

}

