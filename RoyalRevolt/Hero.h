#pragma once
#include "Entity.h"

class Hero : public Entity
{

public:
	Hero(const string& _name, const EntityType _type, const Vector2f& _position, const Vector2f& _size, const string& _path);
};

