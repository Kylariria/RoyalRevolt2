#pragma once
#include "Building.h"

class Farm : public Building
{

public :
	Farm(const string& _name, const Vector2f& _position, const Vector2f& _size,
		const string& _path, const int& _tileAround,const function<void()>& _callback);
};

