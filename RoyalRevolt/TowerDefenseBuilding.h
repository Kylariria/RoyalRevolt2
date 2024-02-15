#pragma once
#include "Building.h"

enum TowerDefenseBuildingType
{
	TDB_TOWER, TDB_FENCE, TDB_CASTLE, TDB_TRAP
};

class TowerDefenseBuilding : public Building
{
	TowerDefenseBuildingType type;
};

