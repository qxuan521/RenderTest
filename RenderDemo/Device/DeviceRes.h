

class IDevice;
class DeviceSwapChain;

struct SwapChainInfo;

class IDeviceRes
{
public:
	virtual DeviceSwapChain* CastToSwapChain();
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