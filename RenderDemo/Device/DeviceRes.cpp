#include "D3D12DeviceRes.h"
#include "DeviceRes.h"



DeviceResFactory* DeviceResFactory::m_pInstancePtr = nullptr;

DeviceResFactory* DeviceResFactory::GetInstancePtr()
{
    if (nullptr == m_pInstancePtr)
    {
        m_pInstancePtr = new D3D12DeviceResFactory;
    }
    return m_pInstancePtr;
}
