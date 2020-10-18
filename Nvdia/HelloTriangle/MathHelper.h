#pragma once

struct Vector3
{
	float x;
	float y;
	float z;
};
struct Eular
{
	float yaw;
	float pitch;
	float roll;
};

struct MTransform
{
	Vector3 Translation;
	Eular Rotation;

	void ToMatrix4x4(float* pMat)
	{
		
	}
};