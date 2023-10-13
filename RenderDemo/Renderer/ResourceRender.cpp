#include "ResourceRender.h"
#include "Device/DeviceRes.h"


RSViewPortRender::RSViewPortRender()
{

}

RSViewPortRender::~RSViewPortRender()
{

}

bool RSViewPortRender::InitializeDeviceResource(IDeviceRes* DeviceRes, SwapChainInfo* pInfo)
{
	m_pSwapChainInfo = pInfo;
	return  nullptr != (m_pDeviceSwapChain = DeviceRes->CastToSwapChain());
}

void RSViewPortRender::FlipFrameBuffer()
{
	if (nullptr == m_pDeviceSwapChain)
		return;
	m_pDeviceSwapChain->Persent();
}



RSRenderTarget::RSRenderTarget()
{
}

RSRenderTarget::~RSRenderTarget()
{
}
