#pragma once
#include "Map.h"

class TowerDefense : public Map
{

public:
	TowerDefense(const string& _name);

public:
	void Launch();
};

