#include "stdafx.h"
#include "Camera.h"

Camera::Camera(float fWidth, float fHeight)
	: m_rWorldToCamera(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f)
	, m_fNear(100.f)
	, m_fFar(100000.f)
	, m_rCameraToView(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f)
	, m_fWidth(fWidth)
	, m_fHeight(fHeight)
{

}

void Camera::Transform(MTransform& rTrans)
{
}
