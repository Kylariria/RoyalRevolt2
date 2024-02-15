#pragma once
#include "Building.h"
#include "Timer.h"

enum VillageBuildingType
{
	VB_TAVERN, VB_FARM, VB_CASERN
};

class VillageBuilding : public Building
{
	VillageBuildingType type;
	Timer* timer;
	int level;

public:
	VillageBuilding();
	VillageBuilding(const string& _name, const Vector2f& _position, const EntityType& _type,
		const function<void()> _callback,const VillageBuildingType& _typeBuilding,
		const Vector2f& _size = Vector2f(), const string& _path = "",
		const int _tileAround = 0, const bool _isBuildable = false);
};

