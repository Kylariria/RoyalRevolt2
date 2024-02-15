#include "TowerDefenseBuilding.h"

TowerDefenseBuilding::TowerDefenseBuilding()
    : Building("", Vector2f(), ENTITY_NONE, nullptr)
    , Stat(0, 0)
{
    type = TDB_TOWER;
}

TowerDefenseBuilding::TowerDefenseBuilding(const string& _name, const Vector2f& _position, const EntityType& _type, const function<void()> _callback, const int _health, const int _attack, const TowerDefenseBuildingType& _typeBuilding, const Vector2f& _size, const string& _path, const int _tileAround, const bool _isBuildable)
    :Building(_name, _position, _type, _callback, _size, _path, _tileAround, _isBuildable)
    , Stat(_health, _attack)
{
    type = _typeBuilding;

}

void TowerDefenseBuilding::Update()
{
}

