#include "Device.h"
#include "D3D12Device.h"


IDevice* IDevice::CreateDevice()
{
	return new D3D12RenderDevice;
}
