#pragma once



class D3D12RenderDevice;
class IDeviceRes;
class DeviceResourceFactory;
struct SwapChainInfo;

class IDevice
{
public:
// 	IDevice();
// 	~IDevice();
	virtual void InitRenderDevice() = 0;
	virtual D3D12RenderDevice* CasttoD3DDevice();

	static IDevice* CreateDevice();
	IDeviceRes* CreateSwapChain(SwapChainInfo*);
private:
	DeviceResourceFactory* m_pResFactory;
};