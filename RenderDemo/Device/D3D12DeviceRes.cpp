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
	pDx12DeviceChain->Initizlize(pD3D12Device->CreateSwapChain(swapChainDesc, pSwapchainInfo->Hwnd));
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
