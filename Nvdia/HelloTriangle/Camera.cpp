#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include "d3dx12.h"

#include <string>
#include <wrl.h>
#include <shellapi.h>
#include "Camera.h"

Camera::Camera(float fWidth, float fHeight)
	: m_rWorldToCamera(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f)
	, m_fNear(15.f)
	, m_fFar(100000.f)
	, m_rCameraToView(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f)
	, m_fWidth(fWidth)
	, m_fHeight(fHeight)
{
	m_rCameraToView = DirectX::XMMatrixPerspectiveRH(m_fWidth, m_fHeight, m_fNear, m_fFar);
	DirectX::FXMVECTOR rCenter = { 0.f,0.f,10.f,1.f };
	DirectX::FXMVECTOR rFocusPosition = { 0.f,0.f,0.f,1.f };
	DirectX::FXMVECTOR rUp = { 0.f,1.f,0.f,0.f };
	m_rWorldToCamera = m_rWorldToCamera * DirectX::XMMatrixScaling(1.f, 1.f, 1.f) *
		DirectX::XMMatrixRotationRollPitchYaw(0.f, 0.f, 0.f) *
		DirectX::XMMatrixTranslation(0.f, 0.f, 10.f);
}

void Camera::Transform(Vector3& rTrans, Vector3& rRot, Vector3& rScale)
{
	
}

int Camera::GetD3DResourceBytesSize()
{
	int size = sizeof(DirectX::XMMATRIX);
	return (size/256 + (size % 256 > 0?1:0))*256;
}

void* Camera::GetD3DResourceData()
{
	Update();
	return (void*)&(m_rWorldToCamera);
}

void Camera::Update()
{
	m_rWorldToView =  m_rWorldToCamera* m_rCameraToView;
}

void Camera::Rotation(Vector3& rVec)
{
	DirectX::XMVECTORF32 rRight;
	rRight.f[0] = rVec.X;
	rRight.f[1] = rVec.Y;
	rRight.f[2] = rVec.Z;
	rRight.f[3] = 0.f; 
	DirectX::XMMATRIX rRotMat1 =DirectX::XMMatrixRotationRollPitchYaw(rVec.Y /*/ 720.f*/, rVec.X/* /720.f*/, 0);
	DirectX::XMVECTOR rAxis = DirectX::XMVector3Cross(rRight, { 0.f,0.f,1.f,0.f });
	DirectX::XMVECTOR rLength = DirectX::XMVector3Length(rRight);
	DirectX::XMMATRIX rRotMat = DirectX::XMMatrixRotationAxis(rAxis, rLength.m128_f32[0] * 360.f);
	//DirectX::FXMVECTOR rQuaterion = DirectX::XMQuaternionRotationAxis(rAxis, rLength.m128_f32[0] * 360.f);
	m_rWorldToCamera = m_rWorldToCamera *rRotMat1;

}
