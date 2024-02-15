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
    Troop(const string& _name, const EntityType& _type, const TroopType _troopType, const Vector2f& _position, const Vector2f& _size, const string& _path, const int _tileAround, const int _health, const int _damage);

public:
    virtual void Update() override;
    virtual void Attack(const Entity& _entityDamaged);

};
