#pragma once
#include <vector>
#include <memory>



class FrameData;
class FrameDataOperator;
class FrameRenderer;

class EngineLogical
{
public:
	EngineLogical();
	~EngineLogical();

	void Initialize();


	void SetCurrentWnd(int HWnd);
	void InitView();

	void FrameLoop(float DeltaTime);
	std::shared_ptr<FrameData> GetCurrentBackFrameData();
	void Destroy();
private:
	std::vector< std::shared_ptr<FrameData>> m_rFrameDataArray;
	int m_nCurrentFrameDataIndex = 0;

	std::unique_ptr<FrameDataOperator> m_pFrameOperator;
	std::unique_ptr<FrameRenderer> m_pFrameRenderer;


	int m_nCurrentHWnd = -1;
};