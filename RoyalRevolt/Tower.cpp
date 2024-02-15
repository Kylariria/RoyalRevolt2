#include "Tower.h"

Tower::Tower(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path,
	const int& _tileAround) : Building(_name, _position, ENTITY_TOWER, nullptr, _size, _path, _tileAround, false)
{
}
