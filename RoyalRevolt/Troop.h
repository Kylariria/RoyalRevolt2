#pragma once
#include "MovingEntity.h"

class Troop : public MovingEntity
{

public:
	Troop(const string& _name,const EntityType& _type, const Vector2f& _position,const Vector2f& _size, const string& _path, const int _tileAround);

public:
	virtual void Update() override;
};

