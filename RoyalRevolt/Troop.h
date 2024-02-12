#pragma once
#include "Entity.h"

class Troop : public Entity
{

public:
	Troop(const string& _name, const EntityType& _type, const Vector2f& _position, const Vector2f& _size, const string& _path = "", const int _tileAround = 0);

public:
	virtual void Update();
};

