#include "Tavern.h"

Tavern::Tavern(const string& _name, const Vector2f& _position, const Vector2f& _size,
	const string& _path, const int& _tileAround, const function<void()>& _callback) : Building(_name, _position, _callback, _size, _path, _tileAround, true)
{

}

