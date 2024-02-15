#pragma once
#include "Building.h"

class Tower : public Building
{
public :
	Tower(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path,
		const int& _tileAround);
};

