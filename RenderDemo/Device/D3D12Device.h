#pragma once
#include "Device.h"
#include <windows.h>
#include <dxgi1_6.h>
#include <d3d12.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

#include <string>
#include <wrl.h>
#include <shellapi.h>

using namespace DirectX;
using Microsoft::WRL::ComPtr;

const int FrameCount = 2;

class D3D12RenderDevice : public IDevice
{
public:
	D3D12RenderDevice();
	~D3D12RenderDevice();

	virtual void InitRenderDevice()override;

	virtual D3D12RenderDevice* CasttoD3DDevice()override;

	ComPtr<IDXGISwapChain3> CreateSwapChain(DXGI_SWAP_CHAIN_DESC1& SwapChainDesc,int Hwnd);

	ComPtr<ID3D12Device>& GetDevice();
	ComPtr<IDXGIFactory4>& GetDXFactory();
private:


	ComPtr<ID3D12Device>	m_pDevice;
	ComPtr<IDXGIFactory4>	m_pFactory;
	ComPtr<IDXGISwapChain3> m_swapChain;
	ComPtr<ID3D12CommandQueue> m_pCommandQueue;

	ComPtr<ID3D12Resource> m_renderTargets[FrameCount];

	ComPtr<ID3D12CommandAllocator> m_commandAllocator;

	ComPtr<ID3D12RootSignature> m_rootSignature;
	ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
	ComPtr<ID3D12PipelineState> m_pipelineState;
	ComPtr<ID3D12GraphicsCommandList> m_commandList;


	// Synchronization objects.
	UINT m_frameIndex;
	HANDLE m_fenceEvent;
	ComPtr<ID3D12Fence> m_fence;
	UINT64 m_fenceValue;
};