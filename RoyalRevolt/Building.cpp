#include "Building.h"

Building::Building(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path, const int& _tileAround)
	: Entity(EntityData(_name, _position, _size, _path))
{
}
	