#pragma once
#include "Entity.h"

class Building : public Entity
{
public :
    Building(const string& _name, const Vector2f& _position, const Vector2f& _size = Vector2f(0.0f, 0.0f), const string& _path = "", const int& _tileAround = 0);
};

