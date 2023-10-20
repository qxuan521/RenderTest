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
#include <vector>

using namespace DirectX;
using Microsoft::WRL::ComPtr;
class D3D12DeviceRenderTarget;

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
	std::vector<D3D12DeviceRenderTarget*> RTVResource;
};

class D3D12DeviceRenderTarget : public DeviceRenderTarget
{
public:
	D3D12DeviceRenderTarget();
	~D3D12DeviceRenderTarget();

	void SetD3D12Resource(ComPtr<ID3D12Resource> D3D12Resource);
	void SetD3D12Descriptor(ComPtr<ID3D12DescriptorHeap> RTVHeap, D3D12_CPU_DESCRIPTOR_HANDLE RTVHandle);
private:
	ComPtr<ID3D12Resource> m_rRenderTargetResource;
	ComPtr<ID3D12DescriptorHeap> m_RTVHeap;
	D3D12_CPU_DESCRIPTOR_HANDLE RTVDesc;

};

class D3D12VertexBufferResource : public DeviceVertexBuffer
{
public:
	D3D12VertexBufferResource() {};
	~D3D12VertexBufferResource() {};
private:

	ComPtr<ID3D12Resource> m_rVertexBufferResource;

};

//need heap manager
