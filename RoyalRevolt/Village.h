#pragma once
#include "Map.h"

class Village : public Map
{

public:
	Village(const string& _name,const Vector2f& _mapSize);

public:
	void Launch();
};

