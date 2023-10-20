#include "D3D12DeviceRes.h"
#include "D3D12Device.h"
#include "Renderer/DefineRender.h"

#define DEBUG

D3D12DeviceResFactory::D3D12DeviceResFactory()
{

}
D3D12DeviceResFactory::~D3D12DeviceResFactory()
{

}

DeviceSwapChain* D3D12DeviceResFactory::CreateSwapChain(IDevice* pDevice, SwapChainInfo* pSwapchainInfo)
{
	D3D12RenderDevice* pD3D12Device = pDevice->CasttoD3DDevice();
	if (nullptr == pD3D12Device)
		return nullptr;
	ComPtr<ID3D12Device>& pOriDevice = pD3D12Device->GetDevice();

	DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
	swapChainDesc.BufferCount = FrameCount;
	swapChainDesc.Width = pSwapchainInfo->Width;
	swapChainDesc.Height = pSwapchainInfo->height;
	swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.SampleDesc.Count = 1;


	D3D12DeviceSwapChain* pDx12DeviceChain = new D3D12DeviceSwapChain;
	ComPtr<IDXGISwapChain3> pD3D12SwapChain = pD3D12Device->CreateSwapChain(swapChainDesc, pSwapchainInfo->Hwnd);
	pDx12DeviceChain->Initizlize(pD3D12SwapChain);

	ComPtr<ID3D12DescriptorHeap> pRTVHeap;

	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
	rtvHeapDesc.NumDescriptors = FrameCount;
	rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
	rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
	pOriDevice->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&pRTVHeap));

	D3D12_CPU_DESCRIPTOR_HANDLE pHeap = pRTVHeap->GetCPUDescriptorHandleForHeapStart();
	int RTVDescSize = pOriDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);


	for (UINT n = 0; n < FrameCount; n++)
	{
		ComPtr< ID3D12Resource> pD3D12Resource;
		pD3D12SwapChain->GetBuffer(n, IID_PPV_ARGS(&pD3D12Resource));
		pOriDevice->CreateRenderTargetView(pD3D12Resource.Get(), nullptr, pHeap);
		pHeap.ptr = (int)pHeap.ptr + RTVDescSize;
	}


	return pDx12DeviceChain;
}


D3D12DeviceSwapChain::D3D12DeviceSwapChain()
{

}
D3D12DeviceSwapChain::~D3D12DeviceSwapChain()
{

}

void D3D12DeviceSwapChain::Persent()
{
}

void D3D12DeviceSwapChain::Initizlize(ComPtr<IDXGISwapChain3> SwapChain)
{
	m_pSwapChain = SwapChain;
}

D3D12DeviceRenderTarget::D3D12DeviceRenderTarget()
{
}

D3D12DeviceRenderTarget::~D3D12DeviceRenderTarget()
{
}

void D3D12DeviceRenderTarget::SetD3D12Resource(ComPtr<ID3D12Resource> D3D12Resource)
{
}

void D3D12DeviceRenderTarget::SetD3D12Descriptor(ComPtr<ID3D12DescriptorHeap> RTVHeap, D3D12_CPU_DESCRIPTOR_HANDLE RTVHandle)
{
}
