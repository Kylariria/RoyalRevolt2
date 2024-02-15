#pragma once
#include "MovingEntity.h"
#include "EntityType.h"

class Barbarian : public MovingEntity
{

public:
	Barbarian(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path);

public:
	virtual void Update() override;
	virtual void Attack(const Entity& _entityDamaged) override;
};