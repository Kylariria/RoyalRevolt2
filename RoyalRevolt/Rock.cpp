#include "Rock.h"

Rock::Rock(const string& _name, const Vector2f& _position, const Vector2f& _size,
	const string& _path) : Removable(_name, _position, ENTITY_ROCK, _size, _path, true)
{
}

void Rock::Update()
{
}
