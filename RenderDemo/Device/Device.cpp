#include "Device.h"
#include "D3D12Device.h"
#include "DeviceRes.h"

D3D12RenderDevice* IDevice::CasttoD3DDevice()
{
	return nullptr;
}

IDevice* IDevice::CreateDevice()
{
	return new D3D12RenderDevice;
}

IDeviceRes* IDevice::CreateSwapChain(SwapChainInfo* info)
{
	if(nullptr == m_pResFactory)
		return nullptr;
	return m_pResFactory->CreateSwapChain(this, info);
}
