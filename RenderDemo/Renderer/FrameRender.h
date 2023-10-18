#pragma once
#include <memory>
class IDevice;
class RSViewPortRender;


class FrameRenderer
{
public:
	void PreRender();
	void Render();
	void PostRender();

	void InitializeDevice();


	static FrameRenderer& Instance();
	static FrameRenderer* InstancePtr();


	void SetCurrentViewport(RSViewPortRender*);
private:
	static FrameRenderer* m_rRenderer;
	IDevice* m_pDevice;
	RSViewPortRender* m_pCurrentViewPort;
};