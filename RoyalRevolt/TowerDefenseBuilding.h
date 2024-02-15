#pragma once
#include "Building.h"
#include "Stat.h"

enum TowerDefenseBuildingType
{
	TDB_TOWER, TDB_FENCE, TDB_CASTLE, TDB_TRAP, TDB_CASERN
};

class TowerDefenseBuilding : public Building, public Stat
{
	TowerDefenseBuildingType type;

public:
	TowerDefenseBuilding();
	TowerDefenseBuilding(const string& _name, const Vector2f& _position, const EntityType& _type,
		const function<void()> _callback,const int _health, const int _attack,const TowerDefenseBuildingType& _typeBuilding,
		const Vector2f& _size = Vector2f(), const string& _path = "",
		const int _tileAround = 0,const bool _isBuildable = false);

	virtual void Update() override;
};

