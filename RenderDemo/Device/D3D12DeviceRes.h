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


class D3D12DeviceResFactory : public DeviceResFactory
{
public:
	D3D12DeviceResFactory();
	~D3D12DeviceResFactory();
	//Create D3D12Resource 
	virtual DeviceSwapChain* CreateSwapChain(IDevice*, SwapChainInfo* )override;
};