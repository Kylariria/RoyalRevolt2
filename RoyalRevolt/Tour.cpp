#include "Tour.h"

Tour::Tour(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path,
	const int& _tileAround) : Building(_name, _position,nullptr, _size, _path, _tileAround, false)
{
}
