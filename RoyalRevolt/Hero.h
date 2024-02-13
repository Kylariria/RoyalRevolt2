#pragma once

#include "MovingEntity.h"

class Hero : public MovingEntity
{

public:
	Hero(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path, const EntityType _type);
};
