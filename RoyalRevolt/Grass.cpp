#include "Grass.h"

Grass::Grass(const string& _name, const Vector2f& _position, const Vector2f& _size,
	const string& _path) : Removable(_name, _position, _size, _path, false)
{
}

void Grass::Update()
{
}
