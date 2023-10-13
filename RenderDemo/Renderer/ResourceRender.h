//Resource for render stage
#pragma once


class IDeviceRes;
class DeviceSwapChain;
struct SwapChainInfo;


class IRSRenderResource
{
public:
	virtual bool InitializeDeviceResource(IDeviceRes*,SwapChainInfo*) = 0;

};

class RSViewPortRender : public IRSRenderResource
{
public:
	RSViewPortRender();
	~RSViewPortRender();

	virtual bool InitializeDeviceResource(IDeviceRes* DeviceRes, SwapChainInfo* pInfo)override;

	void FlipFrameBuffer();
private:
	DeviceSwapChain* m_pDeviceSwapChain;
	SwapChainInfo* m_pSwapChainInfo;
	int m_nCurrentFrameIndex = 0;
};

class RSRenderTarget
{
public:
	RSRenderTarget();
	~RSRenderTarget();




};