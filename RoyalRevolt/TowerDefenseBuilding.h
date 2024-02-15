#pragma once
#include "Building.h"
#include "Stat.h"

enum TowerDefenseBuildingType
{
	TDB_TOWER, TDB_FENCE, TDB_CASTLE, TDB_TRAP
};

class TowerDefenseBuilding : public Building, public Stat
{
	TowerDefenseBuildingType type;
};

