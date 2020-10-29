#pragma once
#include "DirectXMath.h"

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	Vector2(Vector2& rValue);
	~Vector2();

	Vector2&& operator*(float rValue);
	Vector2&& operator*(Vector2& rValue);

	Vector2&& operator+(Vector2& rValue);
	Vector2&& operator-(Vector2& rValue);

	float X;
	float Y;
};

class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	Vector3(Vector2& rVec2, float z);
	Vector3(Vector3& rValue);
	~Vector3();

	Vector3&& operator*(float rValue);
	Vector3&& operator*(Vector3& rValue);

	Vector3&& operator+(Vector3& rValue);
	Vector3&& operator-(Vector3& rValue);

	float X;
	float Y;
	float Z;
};

class Vector4
{
public:
	Vector4();
	Vector4(float x, float y, float z,float w);
	Vector4(Vector2& rVec2, float z,float w);
	Vector4(Vector3& rVec2, float w);
	Vector4(Vector4& rValue);
	~Vector4();

	Vector4&& operator*(float rValue);
	Vector4&& operator*(Vector4& rValue);

	Vector4&& operator+(Vector4& rValue);
	Vector4&& operator-(Vector4& rValue);

	float X;
	float Y;
	float Z;
	float W;
};

class Matrix4x4
{
public:
	Matrix4x4();
	Matrix4x4(Matrix4x4& rValue);
	Matrix4x4(DirectX::XMMATRIX& rValue);
	Matrix4x4(float  m11,float  m12,float  m13,float  m14,
			  float  m21,float  m22,float  m23,float  m24,
		      float  m31,float  m32,float  m33,float  m34,
		      float  m41,float  m42,float  m43,float  m44);
	Matrix4x4(Vector4& rVec1, Vector4& rVec2, Vector4& rVec3, Vector4& rVec4);
	Matrix4x4(Vector3& rVec1, Vector3& rVec2, Vector3& rVec3, Vector3& rVec4);

	Matrix4x4(Vector3& rTranslate, Vector3& rRotation, Vector3& rScale);

	Matrix4x4&& Multiply(Matrix4x4& rValue);

	Vector4&& TransformV4(Vector4& rValue);
	Vector3&& TransformV3(Vector4& rValue);

	DirectX::XMMATRIX& GetDXMat() { return m_rMat; };
private:
	float m11, m12, m13, m14;
	float m21, m22, m23, m24;
	float m31, m32, m33, m34;
	float m41, m42, m43, m44;

	DirectX::XMMATRIX m_rMat;
};


class Quaternion
{
	Quaternion();
	~Quaternion();

	void FromEular(Vector3 rEular);
	Vector3&& ToEular();

	void FromAxisAngle(Vector3 rAxis, float fAngle);
};

class Math
{
public:
	Math() {};
	~Math() {};

	Matrix4x4&& MakeProjection(float near, float far, float width, float height , bool isPerspective);

};

extern Math* g_pMath;