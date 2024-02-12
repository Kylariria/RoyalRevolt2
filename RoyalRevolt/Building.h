#pragma once
#include "Entity.h"

class Building : public Entity
{
public :
    Building(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path, const int& _tileAround);
};

