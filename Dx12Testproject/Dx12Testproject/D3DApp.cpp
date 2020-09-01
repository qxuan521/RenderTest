#include "D3DApp.h"

void D3DSupport::Initialize()
{
	ComPtr<ID3D12Debug> pDebugController;
	D3D12GetDebugInterface(IID_PPV_ARGS(pDebugController));
}
