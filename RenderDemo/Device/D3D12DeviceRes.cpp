#include "D3D12DeviceRes.h"

#define DEBUG

D3D12DeviceResFactory::D3D12DeviceResFactory()
{

}
D3D12DeviceResFactory::~D3D12DeviceResFactory()
{

}

DeviceSwapChain* D3D12DeviceResFactory::CreateSwapChain(IDevice* pDevice, SwapChainInfo* pSwapchainInfo)
{
	return nullptr;
}
