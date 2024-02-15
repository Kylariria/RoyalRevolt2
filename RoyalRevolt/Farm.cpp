#include "Farm.h"

Farm::Farm(const string& _name, const Vector2f& _position, const Vector2f& _size,
	const string& _path, const int& _tileAround, const function<void()>& _callback) : Building(_name, _position, ENTITY_FARM, _callback, _size, _path, _tileAround, true)
{

}
