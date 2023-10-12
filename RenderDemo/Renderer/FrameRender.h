#pragma once
#include <memory>
class IDevice;

class FrameRenderer
{
public:
	void PreRender();
	void Render();
	void PostRender();

	void InitializeDevice();


	static FrameRenderer& Instance();
	static FrameRenderer* InstancePtr();
private:
	static FrameRenderer* m_rRenderer;
	IDevice* m_pDevice;
};