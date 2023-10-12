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

}

void EngineLogical::Destroy()
{

}