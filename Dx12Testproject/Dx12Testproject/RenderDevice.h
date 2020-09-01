#pragma once

class RenderDevice
{
public:
	RenderDevice() {};
	~RenderDevice() {};
	
	virtual void Initialize(void* pHWND,int nWidth,int nHeight) = 0;
	virtual void BeginDraw() = 0;
	virtual void EndDraw() = 0;
private:

};

