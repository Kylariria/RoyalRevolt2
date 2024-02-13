#pragma once
#include "Removable.h"

class Path : public Removable
{
public:
	Path(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path);
};

