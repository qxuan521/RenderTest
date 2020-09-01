#include "DX12Support.h"
#include "DX12Helper.h"


DX12RenderDevice::DX12RenderDevice()
{
}

DX12RenderDevice::~DX12RenderDevice()
{
}

void DX12RenderDevice::GetHardwareAdapter
(
	bool requestHighPerformanceAdapter
)
{
	m_rAdapter = nullptr;

	ComPtr<IDXGIAdapter1> adapter;

	ComPtr<IDXGIFactory6> factory6;
	if (m_rFactory->QueryInterface(IID_PPV_ARGS(&factory6)) >= 0)
	{
		for (
			UINT adapterIndex = 0;
			DXGI_ERROR_NOT_FOUND != factory6->EnumAdapterByGpuPreference(
				adapterIndex,
				requestHighPerformanceAdapter == true ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED,
				IID_PPV_ARGS(&adapter));
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

			// Check to see whether the adapter supports Direct3D 12, but don't create the
			// actual device yet.
			if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
			{
				break;
			}
		}
	}
	else
	{
		for (UINT adapterIndex = 0; DXGI_ERROR_NOT_FOUND != m_rFactory->EnumAdapters1(adapterIndex, &adapter); ++adapterIndex)
		{
			DXGI_ADAPTER_DESC1 desc;
			adapter->GetDesc1(&desc);

			if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
			{
				// Don't select the Basic Render Driver adapter.
				// If you want a software adapter, pass in "/warp" on the command line.
				continue;
			}

			// Check to see whether the adapter supports Direct3D 12, but don't create the
			// actual device yet.
			if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
			{
				break;
			}
		}
	}

	m_rAdapter = adapter.Detach();
}
void DX12RenderDevice::Initialize(void* pHWND, int nWidth, int nHeight)
{
	unsigned int dxgiFactoryFlags = 0;
	HRESULT nResult = 0;
	//GIFactory
	nResult = CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&m_rFactory));
#if 0 
	if (m_useWarpDevice)
	{
		ComPtr<IDXGIAdapter> warpAdapter;
		ThrowIfFailed(factory->EnumWarpAdapter(IID_PPV_ARGS(&warpAdapter)));

		ThrowIfFailed(D3D12CreateDevice(
			warpAdapter.Get(),
			D3D_FEATURE_LEVEL_11_0,
			IID_PPV_ARGS(&m_device)
		));
	}
	else
	{
#endif
	//获取支持DX12的硬件适配器
	GetHardwareAdapter();

	//关联适配器创建一个绘制设备
	nResult = D3D12CreateDevice(
		m_rAdapter.Get(),
		D3D_FEATURE_LEVEL_11_0,
		IID_PPV_ARGS(&m_rDevice)
	);
//}
	//CommandQueue Desc
	D3D12_COMMAND_QUEUE_DESC queueDesc = {};
	queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
	queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

	nResult = m_rDevice->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_rCommandQueue));

	// Describe and create the swap chain.
	DXGI_SWAP_CHAIN_DESC1 rSwapChainDesc = {};
	rSwapChainDesc.BufferCount = 2;
	rSwapChainDesc.Width = nWidth;
	rSwapChainDesc.Height = nHeight;
	rSwapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	rSwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	rSwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	rSwapChainDesc.SampleDesc.Count = 1;


	ComPtr<IDXGISwapChain1> swapChain;
	m_rFactory->CreateSwapChainForHwnd(
		m_rCommandQueue.Get(),        // Swap chain needs the queue so that it can force a flush on it.
		(HWND)pHWND,
		&rSwapChainDesc,
		nullptr,
		nullptr,
		&swapChain
	);

	// !!!??? This sample does not support fullscreen transitions. !!!???
	//ThrowIfFailed(factory->MakeWindowAssociation(Win32Application::GetHwnd(), DXGI_MWA_NO_ALT_ENTER));

	swapChain.As(&m_rSwapChain);
	m_nFrameIndex = m_rSwapChain->GetCurrentBackBufferIndex();

	// Create descriptor heaps.
	{
		// Describe and create a render target view (RTV) descriptor heap.
		D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
		rtvHeapDesc.NumDescriptors = 2;
		rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
		rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
		m_rDevice->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rRtvHeap));

		m_nRtvDescriptorSize = m_rDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
	}


	// Create frame resources.
	//为每一个framebuffer 创建 RenderTarget
	{
		CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rRtvHeap->GetCPUDescriptorHandleForHeapStart());

		// Create a RTV for each frame.
		for (UINT n = 0; n < 2; n++)
		{
			m_rSwapChain->GetBuffer(n, IID_PPV_ARGS(&m_rRenderTargets[n]));
			m_rDevice->CreateRenderTargetView(m_rRenderTargets[n].Get(), nullptr, rtvHandle);
			rtvHandle.Offset(1, m_nRtvDescriptorSize);
		}
	}


	m_rDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_rCommandAllocator));
}
