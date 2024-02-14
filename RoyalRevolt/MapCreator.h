#pragma once
#include "Map.h"

class MapCreator : public Map
{

public:
	MapCreator(const string& _name, const Vector2f& _mapSize);

public:
	void Launch();

};
