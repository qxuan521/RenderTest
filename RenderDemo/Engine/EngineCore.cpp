#include "EngineCore.h"
#include "CommunicationData/FrameData.h"
#include "FrameDataOperator.h"
#include "Renderer/FrameRender.h"


EngineLogical::EngineLogical()
{

}
EngineLogical::~EngineLogical()
{

}

void EngineLogical::Initialize()
{
	m_pFrameOperator.reset(new FrameDataOperator);
	m_pFrameRenderer.reset(FrameRenderer::InstancePtr());
	m_rFrameDataArray.push_back(std::make_shared<FrameData>());
	m_rFrameDataArray.push_back(std::make_shared<FrameData>());
	m_pFrameRenderer->InitializeDevice();

}

void EngineLogical::SetCurrentWnd(int HWnd)
{
	m_nCurrentHWnd = HWnd;

}

void EngineLogical::InitView()
{
	if (-1 == m_nCurrentHWnd)
		return;

}

void EngineLogical::FrameLoop(float DeltaTime)
{
	std::shared_ptr<FrameData> rCurrentFrameData = GetCurrentBackFrameData();

	m_pFrameRenderer->PreRender();
	m_pFrameRenderer->Render();
	m_pFrameRenderer->PostRender();

	m_nCurrentFrameDataIndex = (m_nCurrentFrameDataIndex + 1) % m_rFrameDataArray.size();
}

std::shared_ptr<FrameData> EngineLogical::GetCurrentBackFrameData()
{
	return m_rFrameDataArray[(m_nCurrentFrameDataIndex + 1) % m_rFrameDataArray.size() ];
}

void EngineLogical::Destroy()
{

}