#include "FrameRender.h"
#include "Device/Device.h"

FrameRenderer* FrameRenderer::m_rRenderer = new FrameRenderer;

void FrameRenderer::PreRender()
{
}

void FrameRenderer::Render()
{
}

void FrameRenderer::PostRender()
{
}

void FrameRenderer::InitializeDevice()
{
	m_pDevice = IDevice::CreateDevice();
	m_pDevice->InitRenderDevice();
}

FrameRenderer& FrameRenderer::Instance()
{
	return *m_rRenderer;
}

FrameRenderer* FrameRenderer::InstancePtr()
{
	return m_rRenderer;
}
