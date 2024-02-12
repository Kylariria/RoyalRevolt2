#pragma once
#include "Entity.h"

class Building : public Entity
{
public :
    Building(const string _name, const EntityType& _type, const Vector2f& _position, const string& _path,
        const int& _tileAround);
};

