#pragma once

#include "IRawResource.h"
#include <vector>

class RawStaticMesh : public IResource
{
public:
	RawStaticMesh() {};
	~RawStaticMesh() {};
	ResourceType GetType()
	{
		return Res_Mesh;
	}
private:
	std::vector<>
};