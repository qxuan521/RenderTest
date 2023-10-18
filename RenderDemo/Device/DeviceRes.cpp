#include "DeviceRes.h"
#include "D3D12DeviceRes.h"
#include "Renderer/DefineRender.h"


DeviceResourceFactory* DeviceResourceFactory::m_pInstancePtr = nullptr;

DeviceResourceFactory* DeviceResourceFactory::GetInstancePtr()
{
    if (nullptr == m_pInstancePtr)
    {
        m_pInstancePtr = new D3D12DeviceResFactory;
    }
    return m_pInstancePtr;
}

//resource interface 


DeviceSwapChain* IDeviceRes::CastToSwapChain()
{
	return nullptr;
}



//resource 
DeviceSwapChain::DeviceSwapChain()
{

}
DeviceSwapChain::~DeviceSwapChain()
{

}

DeviceSwapChain* DeviceSwapChain::CastToSwapChain()
{
    return this;
}

