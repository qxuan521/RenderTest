#pragma once
#include <d3d12.h>
#include <memory>
#include <dxgi1_6.h>

class YD3D12RenderContext
{
public:
	YD3D12RenderContext();
	~YD3D12RenderContext();

	void Initialize();

private:
	std::shared_ptr<ID3D12Device> m_rDevice;
	std::shared_ptr<IDXGISwapChain3> m_rSwapChain;
};

