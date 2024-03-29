#pragma once

#include "MovingEntity.h"

class Hero : public MovingEntity
{
    CollisionComponent* collision;

public:
	EntityType GetType() const
    { 
        return ENTITY_NONE; 
    }

public:
    Hero(const string& _name, const Vector2f& _position,
        const Vector2f& _size, const string& _path,
        const float _health, const float _damage);
public:
    void Attack(const Entity& _entityDamaged);

};
