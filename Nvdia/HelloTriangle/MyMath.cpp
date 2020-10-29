#include "MyMath.h"


Math* g_pMath = new Math();

Vector2::Vector2()
	:X(0.f)
	,Y(0.f)
{
}

Vector2::Vector2(float x, float y)
	:X(x)
	,Y(y)
{
}

Vector2::Vector2(Vector2& rValue)
{
	this->X = rValue.X;
	this->Y = rValue.Y;
}

Vector2::~Vector2()
{
}

Vector2&& Vector2::operator*(float rValue)
{
	return Vector2(X* rValue,Y* rValue);
}

Vector2&& Vector2::operator*(Vector2& rValue)
{
	return Vector2(X * rValue.X, Y * rValue.Y);
}

Vector2&& Vector2::operator+(Vector2& rValue)
{
	return Vector2(X + rValue.X, Y + rValue.Y);
}

Vector2&& Vector2::operator-(Vector2& rValue)
{
	return Vector2(X - rValue.X, Y - rValue.Y);
}

Vector3::Vector3()
	: X(0.f)
	, Y(0.f)
	, Z(0.f)
{
}

Vector3::Vector3(float x, float y, float z)
	:X(x)
	,Y(y)
	,Z(z)
{
}

Vector3::Vector3(Vector2& rVec2, float z)
	:X(rVec2.X)
	,Y(rVec2.Y)
	,Z(z)
{
}

Vector3::Vector3(Vector3& rValue)
	:X(rValue.X)
	,Y(rValue.Y)
	,Z(rValue.Z)
{
}

Vector3::~Vector3()
{
}

Vector3&& Vector3::operator*(float rValue)
{
	return Vector3(X * rValue, Y * rValue, Z * rValue);
}

Vector3&& Vector3::operator*(Vector3& rValue)
{
	return Vector3(X * rValue.X, Y * rValue.Y, Z * rValue.Z);
}

Vector3&& Vector3::operator+(Vector3& rValue)
{
	return Vector3(X + rValue.X, Y + rValue.Y, Z + rValue.Z);
}

Vector3&& Vector3::operator-(Vector3& rValue)
{
	return Vector3(X - rValue.X, Y - rValue.Y, Z - rValue.Z);
}

Vector4::Vector4()
	: X(0.f)
	, Y(0.f)
	, Z(0.f)
	, W(0.f)
{
}

Vector4::Vector4(float x, float y, float z, float w)
	: X(x)
	, Y(y)
	, Z(z)
	, W(w)
{
}

Vector4::Vector4(Vector2& rVec2, float z, float w)
	: X(rVec2.X)
	, Y(rVec2.Y)
	, Z(z)
	, W(w)
{
}

Vector4::Vector4(Vector3& rVec2, float w)
	: X(rVec2.X)
	, Y(rVec2.Y)
	, Z(rVec2.Z)
	, W(w)
{
}

Vector4::Vector4(Vector4& rValue)
	: X(rValue.X)
	, Y(rValue.Y)
	, Z(rValue.Z)
	, W(rValue.W)
{
}

Vector4::~Vector4()
{
}

Vector4&& Vector4::operator*(float rValue)
{
	return Vector4(X * rValue, Y * rValue, Z * rValue, W * rValue);
}

Vector4&& Vector4::operator*(Vector4& rValue)
{
	return Vector4(X * rValue.X, Y * rValue.Y, Z * rValue.Z, W * rValue.W);

}

Vector4&& Vector4::operator+(Vector4& rValue)
{
	return Vector4(X + rValue.X, Y + rValue.Y, Z + rValue.Z, W + rValue.W);
}

Vector4&& Vector4::operator-(Vector4& rValue)
{
	return Vector4(X - rValue.X, Y - rValue.Y, Z - rValue.Z, W - rValue.W);
}


Matrix4x4::Matrix4x4()
{

}
Matrix4x4::Matrix4x4(Matrix4x4& rValue)
{
	m_rMat = rValue.GetDXMat();
}
Matrix4x4::Matrix4x4(DirectX::XMMATRIX& rValue)
{
	m_rMat = rValue;
}
Matrix4x4::Matrix4x4(
	float  m11, float  m12, float  m13, float  m14,
	float  m21, float  m22, float  m23, float  m24,
	float  m31, float  m32, float  m33, float  m34,
	float  m41, float  m42, float  m43, float  m44)
{
	m_rMat = DirectX::XMMATRIX(
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44);

}
Matrix4x4::Matrix4x4(Vector4& rVec1, Vector4& rVec2, Vector4& rVec3, Vector4& rVec4)
{
	m_rMat = DirectX::XMMATRIX(
		rVec1.X, rVec1.Y, rVec1.Z, rVec1.W,
		rVec2.X, rVec1.Y, rVec1.Z, rVec1.W,
		rVec3.X, rVec1.Y, rVec1.Z, rVec1.W,
		rVec4.X, rVec1.Y, rVec1.Z, rVec1.W);
}

Matrix4x4::Matrix4x4(Vector3& rVec1, Vector3& rVec2, Vector3& rVec3, Vector3& rVec4)
{

}

Matrix4x4::Matrix4x4(Vector3& rTranslate, Vector3& rRotation, Vector3& rScale)
{
	m_rMat = DirectX::XMMatrixRotationRollPitchYaw(rRotation.Y, rRotation.X, rRotation.Z)
		* DirectX::XMMatrixTranslation(rTranslate.X, rTranslate.Y, rTranslate.Z) 
		* DirectX::XMMatrixScaling(rScale.X, rScale.Y, rScale.Z);
}

Matrix4x4&& Matrix4x4::Multiply(Matrix4x4& rValue)
{
	return Matrix4x4();
}

Vector4&& Matrix4x4::TransformV4(Vector4& rValue)
{
	return Vector4();

}
Vector3&& Matrix4x4::TransformV3(Vector4& rValue)
{
	return Vector3();

}



Quaternion::Quaternion()
{

}
Quaternion::~Quaternion()
{

}

void Quaternion::FromEular(Vector3 rEular)
{

}
Vector3&& Quaternion::ToEular()
{
	return Vector3();
}

void Quaternion::FromAxisAngle(Vector3 rAxis, float fAngle)
{

}



Matrix4x4&& Math::MakeProjection(float near, float far, float width, float height, bool isPerspective)
{
	return Matrix4x4( DirectX::XMMatrixPerspectiveFovRH(width, height, near, far));
}