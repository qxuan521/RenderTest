
class IDeviceRes
{
public:

};

class IDevice;
class DeviceSwapChain;

struct SwapChainInfo;


class DeviceResFactory
{
public:
	virtual DeviceSwapChain* CreateSwapChain(IDevice*, SwapChainInfo* ) = 0;

	static DeviceResFactory* GetInstancePtr();

private:
	static DeviceResFactory* m_pInstancePtr;
};

class DeviceSwapChain : public IDeviceRes
{

};