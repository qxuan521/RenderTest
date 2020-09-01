#pragma once



class DX12WinApplication
{
public:
	DX12WinApplication();
	~DX12WinApplication();

	void Update();
	void Initializa(void* pActWin);

private:
	void* m_pActWindows;
};