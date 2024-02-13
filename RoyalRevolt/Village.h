#pragma once
#include "Map.h"
#include "Interface.h"

class Village : public Map
{
	vector<BasicElement*> buttons;

public:
	Village(const string& _name,const Vector2f& _mapSize);

public:
	void Launch();

	void Update();

	void Display();
};

