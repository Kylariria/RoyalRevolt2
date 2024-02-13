#include "Barbarian.h"

Barbarian::Barbarian(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path) : Troop(_name, ENTITY_BARBARIAN, _position, _size, _path, 1)
{

}

void Barbarian::Update()
{
	Troop::Update();
}
