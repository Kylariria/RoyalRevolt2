#include "VillageBuilding.h"

VillageBuilding::VillageBuilding() : Building("",Vector2f(),ENTITY_NONE,nullptr)
{
	name = "";
	type = VB_TAVERN;
	timer = nullptr;
	level = 0;
}

VillageBuilding::VillageBuilding(const string& _name, const Vector2f& _position, const EntityType& _type, const function<void()> _callback, const VillageBuildingType& _typeBuilding, const string& _structureName, const Vector2f& _size, const string& _path, const int _tileAround, const bool _isBuildable)
	: Building(_name, _position, _type, _callback,_size,_path,_tileAround,_isBuildable)
{
	name = _structureName;
	type = _typeBuilding;
	timer = nullptr;
	level = 0;
}
