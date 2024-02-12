#pragma once
#include "Building.h"

class Trap : public Building
{

public:
	Trap(const string& _name, const Vector2f& _position, const Vector2f& _size,
		const string& _path, const int& _tileAround);
};

