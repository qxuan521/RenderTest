#pragma once



class D3D12RenderDevice;

class IDevice
{
public:
// 	IDevice();
// 	~IDevice();
	virtual void InitRenderDevice() = 0;
	virtual D3D12RenderDevice* CasttoD3DDevice();

	static IDevice* CreateDevice();

private:

};