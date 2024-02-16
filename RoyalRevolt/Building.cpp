#include "Building.h"

Building::Building(const string& _name, const Vector2f& _position, const EntityType& _type, const function<void()>& _callback,
	const Vector2f& _size, const string& _path, const int& _tileAround, const bool& _isBuildable)
	: Entity(EntityData(_name, ENTITY_NONE, _position, _size, _tileAround,_path))
{
	callback = _callback;
}

void Building::Update()
{

}
