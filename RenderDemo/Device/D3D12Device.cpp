#include "D3D12Device.h"

#define DEBUG

D3D12RenderDevice::D3D12RenderDevice()
{
}

D3D12RenderDevice::~D3D12RenderDevice()
{
}


void D3D12RenderDevice::InitRenderDevice()
{
	UINT dxgiFactoryFlags = 0;

#if defined(DEBUG)
	// Enable the debug layer (requires the Graphics Tools "optional feature").
	// NOTE: Enabling the debug layer after device creation will invalidate the active device.
	{
		ComPtr<ID3D12Debug> debugController;
		if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
		{
			debugController->EnableDebugLayer();

			// Enable additional debug layers.
			dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
		}
	}
#endif

	ComPtr<IDXGIFactory4> factory;
	CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&m_pFactory));


	ComPtr<IDXGIAdapter1> hardwareAdapter;
	
	ComPtr<IDXGIAdapter1> adapter;

	ComPtr<IDXGIFactory6> factory6;
	if (SUCCEEDED(factory->QueryInterface(IID_PPV_ARGS(&factory6))))
	{
		bool requestHighPerformanceAdapter = false;
		for (
			UINT adapterIndex = 0;
			SUCCEEDED(factory6->EnumAdapterByGpuPreference(
				adapterIndex,
				requestHighPerformanceAdapter == true ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED,
				IID_PPV_ARGS(&adapter)));
			++adapterIndex)
		{
			DXGI_ADAPTER_DESC1 desc;
			adapter->GetDesc1(&desc);

			if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
			{
				// Don't select the Basic Render Driver adapter.
				// If you want a software adapter, pass in "/warp" on the command line.
				continue;
			}

			D3D12CreateDevice(
				hardwareAdapter.Get(),
				D3D_FEATURE_LEVEL_11_0,
				IID_PPV_ARGS(&m_pDevice)
			);

		}
	}
	// Describe and create the command queue.
	D3D12_COMMAND_QUEUE_DESC queueDesc = {};
	queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
	queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

	m_pDevice->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue));




}

D3D12RenderDevice* D3D12RenderDevice::CasttoD3DDevice()
{
	return this;
}

ComPtr<IDXGISwapChain3> D3D12RenderDevice::CreateSwapChain(DXGI_SWAP_CHAIN_DESC1& SwapChainDesc, int Hwnd)
{
	ComPtr<IDXGISwapChain1> SwapChain1;
	if (m_pFactory->CreateSwapChainForHwnd(
		m_commandQueue.Get(),        // Swap chain needs the queue so that it can force a flush on it.
		HWND(Hwnd),
		&SwapChainDesc,
		nullptr,
		nullptr,
		&SwapChain1
	) < 0)
	{
		return ComPtr<IDXGISwapChain3>(nullptr);
	}
	ComPtr<IDXGISwapChain3> SwapChain;
	SwapChain1.As(&SwapChain);
	return SwapChain;
}

ComPtr<ID3D12Device>& D3D12RenderDevice::GetDevice()
{
	return m_pDevice;
}

ComPtr<IDXGIFactory4>& D3D12RenderDevice::GetDXFactory()
{
	return m_pFactory;
}