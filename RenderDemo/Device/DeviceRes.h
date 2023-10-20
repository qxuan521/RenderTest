#pragma once

class IDevice;
class DeviceSwapChain;
class DeviceRenderTarget;


struct SwapChainInfo;



class IDeviceRes
{
public:
	virtual DeviceSwapChain* CastToSwapChain();
	virtual DeviceRenderTarget* CastToRenderTargetRes();
	virtual DeviceVertexBuffer* CastToVertexBuffer();
};

class DeviceResourceFactory
{
public:
	virtual DeviceSwapChain* CreateSwapChain(IDevice*, SwapChainInfo* ) = 0;

	static DeviceResourceFactory* GetInstancePtr();

private:
	static DeviceResourceFactory* m_pInstancePtr;
};

class DeviceSwapChain : public IDeviceRes
{
public:
	DeviceSwapChain();
	~DeviceSwapChain();

	virtual void Persent() = 0;
	virtual DeviceSwapChain* CastToSwapChain()override;
};

class DeviceBufferResource : public IDeviceRes
{
public:
	virtual ~DeviceBufferResource() {};


};


class DeviceRenderTarget : public DeviceBufferResource
{
public:
	DeviceRenderTarget();
	~DeviceRenderTarget();

	virtual DeviceRenderTarget* CastToRenderTargetRes()override;
};



class DeviceVertexBuffer : public DeviceBufferResource
{
public:
	DeviceVertexBuffer();
	~DeviceVertexBuffer();

	virtual DeviceVertexBuffer* CastToVertexBuffer()override;
};