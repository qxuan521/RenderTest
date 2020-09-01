#pragma once

#include "RenderDevice.h"
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl\client.h>

using Microsoft::WRL::ComPtr;

class DX12RenderDevice : public RenderDevice
{
public:
	DX12RenderDevice();
	~DX12RenderDevice();

	void Initialize(void* pHWND, int nWidth, int nHeight);
private:
	void GetHardwareAdapter(
		bool requestHighPerformanceAdapter = false
	);



	ComPtr<IDXGIFactory4> m_rFactory;
	ComPtr<IDXGIAdapter1> m_rAdapter;

	ComPtr<ID3D12Device> m_rDevice;
	ComPtr<ID3D12CommandQueue> m_rCommandQueue;
	ComPtr<ID3D12CommandAllocator> m_rCommandAllocator;

	ComPtr<IDXGISwapChain3> m_rSwapChain;
	ComPtr<ID3D12DescriptorHeap> m_rRtvHeap;
	ComPtr<ID3D12Resource> m_rRenderTargets[2];
	unsigned int m_nFrameIndex;
	unsigned int m_nRtvDescriptorSize;
};