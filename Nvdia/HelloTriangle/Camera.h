#pragma once
#include "MyMath.h"
class Camera
{
public:
	Camera(float fWidth,float fHeight);

	~Camera()
	{

	}
	void Transform(Vector3& rTrans, Vector3& rRot, Vector3& rScale);

	int GetD3DResourceBytesSize();
	void* GetD3DResourceData();
	void Update();
	void Rotation(Vector3& rVec);
public:
	DirectX::XMMATRIX m_rWorldToCamera;
	DirectX::XMMATRIX m_rCameraToView;
	DirectX::XMMATRIX m_rWorldToView;
	float m_fNear;
	float m_fFar;
	float m_fWidth;
	float m_fHeight;


};