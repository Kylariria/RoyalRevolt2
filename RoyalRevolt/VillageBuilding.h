#pragma once
#include "Building.h"

enum VillageBuildingType
{
	VB_TAVERN, VB_FARM, VB_CASERN
};

class VillageBuilding : public Building
{
	VillageBuildingType type;
};

