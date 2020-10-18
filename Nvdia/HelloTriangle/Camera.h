#pragma once
#include <DirectXMath.h>
#include "MathHelper.h"
class Camera
{
public:
	Camera(float fWidth,float fHeight);

	~Camera()
	{

	}
	void Transform(MTransform& rTrans);
private:
	DirectX::XMFLOAT4X4 m_rWorldToCamera;
	DirectX::XMFLOAT4X4 m_rCameraToView;
	float m_fNear;
	float m_fFar;
	float m_fWidth;
	float m_fHeight;
};