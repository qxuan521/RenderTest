#include "Device.h"
#include "D3D12Device.h"


D3D12RenderDevice* IDevice::CasttoD3DDevice()
{
	return nullptr;
}

IDevice* IDevice::CreateDevice()
{
	return new D3D12RenderDevice;
}
