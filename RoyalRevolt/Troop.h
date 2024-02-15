#pragma once
#include "MovingEntity.h"

enum TroopType
{
	TROOP_NONE, TROOP_ARCHER, TROOP_BARBARIAN
};

class Troop : public MovingEntity
{
	TroopType type;

public:
	Troop(const string& _name,const EntityType& _type, const Vector2f& _position,const Vector2f& _size, const string& _path, const int _tileAround);

public:
	virtual void Update() override;
};

