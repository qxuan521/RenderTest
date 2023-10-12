#pragma once

class IDevice
{
public:
// 	IDevice();
// 	~IDevice();
	virtual void InitRenderDevice() = 0;

	static IDevice* CreateDevice();
private:

};