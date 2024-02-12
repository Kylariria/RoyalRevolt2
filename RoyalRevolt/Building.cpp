#include "Building.h"

Building::Building(const string _name, const EntityType& _type, const Vector2f& _position, const string& _path, const int& _tileAround)
	: Entity(_name, _type, _position, _path, _tileAround)
{
}
	