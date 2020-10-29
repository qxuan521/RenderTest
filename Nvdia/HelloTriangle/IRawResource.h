#pragma once
enum ResourceType
{
	Res_Mesh,
};
class IResource
{
public:
	virtual ResourceType GetType() = 0;

};