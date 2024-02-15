#include "Troop.h"

Troop::Troop(const string& _name, const EntityType& _type, const TroopType _troopType, const Vector2f& _position, const Vector2f& _size, const string& _path, const int _tileAround, const int _health, const int _damage) : MovingEntity(EntityData(_name, _type, _position, _size, _tileAround, _path, 150, 40), Stat(_health, _damage), 1, 1)
{
    type = _troopType;
}

void Troop::Update()
{
}

void Troop::Attack(const Entity& _entityDamaged)
{
}
