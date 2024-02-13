#pragma once
#include "Removable.h"

class Tree : public Removable
{
public :
	Tree(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path);
};

