#include "PrecompileHeader.h"
#include "GameEngineCore.h"
#include <GameEngineBase\GameEngineDebug.h>
#include <GameEnginePlatform\GameEngineWindow.h>
#include <GameEnginePlatform\GameEngineSound.h>
#include "GameEngineResource.h"
#include "GameEngineShaderResHelper.h"

#include "GameEngineVertex.h"

#include "GameEngineMesh.h"
#include "GameEngineBlend.h"
#include "GameEngineTexture.h"
#include "GameEngineDepthState.h"
#include "GameEngineRasterizer.h"
#include "GameEngineIndexBuffer.h"
#include "GameEnginePixelShader.h"
#include "GameEngineVertexShader.h"
#include "GameEngineVertexBuffer.h"
#include "GameEngineRenderTarget.h"
#include "GameEngineConstantBuffer.h"
#include "GameEngineRenderingPipeLine.h"



void GameEngineCore::CoreResourcesInit()
{
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("EngineResources");
		NewDir.Move("EngineResources");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });


		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}
	}


	// 버텍스 버퍼의 내용과 인풋 레이아웃의 내용이 더 중요하다.
	GameEngineVertex::LayOut.AddInputLayOut("POSITION", DXGI_FORMAT_R32G32B32A32_FLOAT);
	GameEngineVertex::LayOut.AddInputLayOut("TEXCOORD", DXGI_FORMAT_R32G32B32A32_FLOAT);
	GameEngineVertex::LayOut.AddInputLayOut("NORMAL", DXGI_FORMAT_R32G32B32A32_FLOAT);

	//typedef struct D3D11_INPUT_ELEMENT_DESC
	//{
	//	LPCSTR SemanticName; = "POSITION"
	//	UINT SemanticIndex; = 0
	//	DXGI_FORMAT Format; 
	//	UINT InputSlot;
	//	UINT AlignedByteOffset;
	//	D3D11_INPUT_CLASSIFICATION InputSlotClass;
	//	UINT InstanceDataStepRate; 
	//} 	


	//const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
	//UINT NumElements, // 
	//const void* pShaderBytecodeWithInputSignature,  // 쉐이더의 바이너리 코드를 내놔
	//SIZE_T BytecodeLength,
	//ID3D11InputLayout** ppInputLayout // 만들어져 나오는 포인터

	{
		D3D11_SAMPLER_DESC SamperData = {};

		// 

		SamperData.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
		SamperData.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
		SamperData.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
		// 텍스처가 멀리있을때 뭉갤꺼냐
		// 안뭉갠다.
		SamperData.MipLODBias = 0.0f;
		SamperData.MaxAnisotropy = 1;
		SamperData.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
		SamperData.MinLOD = -FLT_MAX;
		SamperData.MaxLOD = FLT_MAX;

		GameEngineSampler::Create("CLAMPSAMPLER", SamperData);
	}

	{
		D3D11_SAMPLER_DESC SamperData = {};

		SamperData.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		SamperData.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		SamperData.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		// 텍스처가 멀리있을때 뭉갤꺼냐
		// 안뭉갠다.
		SamperData.MipLODBias = 0.0f;
		SamperData.MaxAnisotropy = 1;
		SamperData.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
		SamperData.MinLOD = -FLT_MAX;
		SamperData.MaxLOD = FLT_MAX;

		GameEngineSampler::Create("WRAPSAMPLER", SamperData);
	}

	{
		std::vector<GameEngineVertex> ArrVertex;
		ArrVertex.resize(4);

		// 0   1
		// 3   2
		// 앞면
		ArrVertex[0] = { { -0.5f, 0.5f, 0.0f }, {0.0f, 0.0f} };
		ArrVertex[1] = { { 0.5f, 0.5f, 0.0f }, {1.0f, 0.0f} };
		ArrVertex[2] = { { 0.5f, -0.5f, 0.0f }, {1.0f, 1.0f} };
		ArrVertex[3] = { { -0.5f, -0.5f, 0.0f }, {0.0f, 1.0f} };

		std::vector<UINT> ArrIndex = {0, 1, 2, 0, 2, 3};

		GameEngineVertexBuffer::Create("Rect", ArrVertex);
		GameEngineIndexBuffer::Create("Rect", ArrIndex);

	}

	{
		// 블랜드
		D3D11_BLEND_DESC Desc = {0,};

		// 자동으로 알파부분을 제거해서 출력해주는 건데
		// 졸라느립니다.
		Desc.AlphaToCoverageEnable = false;
		// 블랜드를 여러개 넣을거냐
		// TRUE면 블랜드를 여러개 넣습니다.
		// false면 몇개의 랜더타겟이 있건 0번에 세팅된 걸로 전부다 블랜드.
		Desc.IndependentBlendEnable = false;

		Desc.RenderTarget[0].BlendEnable = true;
		Desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		Desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		Desc.RenderTarget[0].DestBlend = D3D11_BLEND_SRC_ALPHA;

		Desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		Desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_SRC_ALPHA;
		Desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_INV_SRC_ALPHA;

		GameEngineBlend::Create("AlphaBlend", Desc);
	}



	{
		D3D11_DEPTH_STENCIL_DESC Desc = { 0, };
		//BOOL DepthEnable;
		//D3D11_DEPTH_WRITE_MASK DepthWriteMask;
		//D3D11_COMPARISON_FUNC DepthFunc;
		//BOOL StencilEnable;
		//UINT8 StencilReadMask;
		//UINT8 StencilWriteMask;
		//D3D11_DEPTH_STENCILOP_DESC FrontFace;
		//D3D11_DEPTH_STENCILOP_DESC BackFace;

		Desc.DepthEnable = true;
		Desc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS_EQUAL;
		Desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK::D3D11_DEPTH_WRITE_MASK_ALL;
		Desc.StencilEnable = false;

		GameEngineDepthState::Create("EngineDepth", Desc);
	}


	{
		// 최초의 버텍스의 위치를 로컬공간이라고 부릅니다.
		std::vector<float4> ArrVertex;
		ArrVertex.resize(24);
		// 앞면
		ArrVertex[0] = { -0.5f, -0.5f, 0.5f };
		ArrVertex[1] = { 0.5f, -0.5f,0.5f };
		ArrVertex[2] = { 0.5f, 0.5f,0.5f };
		ArrVertex[3] = { -0.5f, 0.5f,0.5f };

		// 뒷면
		ArrVertex[4] = ArrVertex[0].RotaitonXDegReturn(180.0f);
		ArrVertex[5] = ArrVertex[1].RotaitonXDegReturn(180.0f);
		ArrVertex[6] = ArrVertex[2].RotaitonXDegReturn(180.0f);
		ArrVertex[7] = ArrVertex[3].RotaitonXDegReturn(180.0f);

		// 왼쪽면
		ArrVertex[8] = ArrVertex[0].RotaitonYDegReturn(90.0f);
		ArrVertex[9] = ArrVertex[1].RotaitonYDegReturn(90.0f);
		ArrVertex[10] = ArrVertex[2].RotaitonYDegReturn(90.0f);
		ArrVertex[11] = ArrVertex[3].RotaitonYDegReturn(90.0f);

		// 오른쪽
		ArrVertex[12] = ArrVertex[0].RotaitonYDegReturn(-90.0f);
		ArrVertex[13] = ArrVertex[1].RotaitonYDegReturn(-90.0f);
		ArrVertex[14] = ArrVertex[2].RotaitonYDegReturn(-90.0f);
		ArrVertex[15] = ArrVertex[3].RotaitonYDegReturn(-90.0f);

		ArrVertex[16] = ArrVertex[0].RotaitonXDegReturn(90.0f);
		ArrVertex[17] = ArrVertex[1].RotaitonXDegReturn(90.0f);
		ArrVertex[18] = ArrVertex[2].RotaitonXDegReturn(90.0f);
		ArrVertex[19] = ArrVertex[3].RotaitonXDegReturn(90.0f);

		ArrVertex[20] = ArrVertex[0].RotaitonXDegReturn(-90.0f);
		ArrVertex[21] = ArrVertex[1].RotaitonXDegReturn(-90.0f);
		ArrVertex[22] = ArrVertex[2].RotaitonXDegReturn(-90.0f);
		ArrVertex[23] = ArrVertex[3].RotaitonXDegReturn(-90.0f);

	}

	// 버텍스 쉐이더 컴파일
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("EngineResources");
		NewDir.Move("EngineResources");
		NewDir.Move("Shader");

		std::vector<GameEngineFile> Files = NewDir.GetAllFile({ ".hlsl", ".fx"});

		std::shared_ptr<GameEngineVertexShader> VertexShader = GameEngineVertexShader::Load(Files[0].GetFullPath(), "Texture_VS");


		GameEnginePixelShader::Load(Files[0].GetFullPath(), "Texture_PS");

		//for (size_t i = 0; i < Files.size(); i++)
		//{
		//}

	}


	{
		D3D11_RASTERIZER_DESC Desc = {};

		//D3D11_FILL_MODE FillMode;
		// 렌더링할 때 사용할 채우기 모드를 결정합니다( D3D11_FILL_MODE 참조 ).
		//D3D11_CULL_MODE CullMode;
		// 지정된 방향을 향하는 삼각형이 그려지지 않음을 나타냅니다( D3D11_CULL_MODE 참조 ).
		//BOOL FrontCounterClockwise;
		// 삼각형이 앞면인지 뒷면인지 결정합니다. 
		// 이 매개변수가 TRUE 이면 정점 이 렌더 대상에서 
		// 시계 반대 방향이면 삼각형이 전면을 향하는 것으로 
		// 간주되고 시계 방향이면 후면을 향하는 것으로 간주됩니다. 
		// 이 매개변수가 FALSE 이면 그 반대입니다.
		//INT DepthBias;
		// 지정된 픽셀에 추가된 깊이 값입니다. 깊이 편향에 대한 정보는 깊이 편향 을 참조하십시오 .
		//FLOAT DepthBiasClamp;
		// 픽셀의 최대 깊이 편향. 깊이 편향에 대한 정보는 깊이 편향 을 참조하십시오 .
		//FLOAT SlopeScaledDepthBias;
		// 주어진 픽셀의 기울기에 대한 스칼라. 깊이 편향에 대한 정보는 깊이 편향 을 참조하십시오 .
		//BOOL DepthClipEnable;
		// 거리에 따라 클리핑을 활성화합니다.
		// 하드웨어는 항상 래스터화된 좌표의 x 및 y 클리핑을 수행합니다.
		// DepthClipEnable이 기본값인 TRUE 로 설정 되면 하드웨어도 z 
		// 값을 자릅니다(즉, 하드웨어는 다음 알고리즘의 마지막 단계를 수행합니다).
		//BOOL ScissorEnable;
		// 가위 사각형 컬링을 활성화합니다. 활성 가위 사각형 외부의 모든 픽셀이 추려집니다.
		//BOOL MultisampleEnable;
		// 다중 샘플 앤티앨리어싱(MSAA) 렌더 대상에서 사변형 또는 알파 라인 앤티앨리어싱 
		// 알고리즘을 사용할지 여부를 지정합니다. 사변형 라인 앤티 앨리어싱 알고리즘을 
		// 사용하려면 TRUE 로 설정 하고 알파 라인 앤티 앨리어싱 알고리즘을 사용하려면 
		// FALSE 로 설정합니다. 이 멤버에 대한 자세한 내용은 비고를 참조하세요.
		//BOOL AntialiasedLineEnable;
		// 선 앤티앨리어싱을 활성화할지 여부를 지정합니다. 선 그리기를 수행하고 MultisampleEnable이 
		// FALSE 인 경우에만 적용됩니다 . 이 멤버에 대한 자세한 내용은 비고를 참조하세요.

		// 와이어 프레임은 선으로 표현하는 겁니다. 
		// Desc.FillMode = D3D11_FILL_MODE::D3D11_FILL_WIREFRAME;
		Desc.CullMode = D3D11_CULL_MODE::D3D11_CULL_NONE;
		Desc.FrontCounterClockwise = FALSE;

		std::shared_ptr<GameEngineRasterizer> Res = GameEngineRasterizer::Create("Engine2DBase", Desc);
	}


	{
		{
			std::shared_ptr<GameEngineRenderingPipeLine> Pipe = GameEngineRenderingPipeLine::Create("2DTexture");

			Pipe->SetVertexBuffer("Rect");
			Pipe->SetIndexBuffer("Rect");
			Pipe->SetVertexShader("TextureShader.hlsl");
			Pipe->SetRasterizer("Engine2DBase");
			Pipe->SetPixelShader("TextureShader.hlsl");
			Pipe->SetBlend("AlphaBlend");
		}
	}
}

void GameEngineCore::CoreResourcesEnd()
{
	GameEngineMesh::ResourcesClear();
	GameEngineBlend::ResourcesClear();
	GameEngineTexture::ResourcesClear();
	GameEngineRasterizer::ResourcesClear();
	GameEngineIndexBuffer::ResourcesClear();
	GameEnginePixelShader::ResourcesClear();
	GameEngineVertexShader::ResourcesClear();
	GameEngineVertexBuffer::ResourcesClear();
	GameEngineRenderTarget::ResourcesClear();
	GameEngineConstantBuffer::ResourcesClear();
	GameEngineRenderingPipeLine::ResourcesClear();
}
