#pragma once
#include "Device.h"
#include <windows.h>
#include <dxgi1_6.h>
#include <d3d12.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

#include <string>
#include <wrl.h>
#include <shellapi.h>

#include "DeviceRes.h"


using namespace DirectX;
using Microsoft::WRL::ComPtr;


class D3D12DeviceResFactory : public DeviceResourceFactory
{
public:
	D3D12DeviceResFactory();
	~D3D12DeviceResFactory();
	//Create D3D12Resource 
	virtual DeviceSwapChain* CreateSwapChain(IDevice*, SwapChainInfo* )override;
};

class D3D12DeviceSwapChain : public DeviceSwapChain
{
public:
	D3D12DeviceSwapChain();
	~D3D12DeviceSwapChain();
	virtual void Persent()override;
	void Initizlize(ComPtr<IDXGISwapChain3> SwapChain);


private:
	ComPtr<IDXGISwapChain3> m_pSwapChain;
};
//need heap manager
