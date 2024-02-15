#include "Casern.h"

Casern::Casern(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path)
	: Removable(_name, _position, ENTITY_CASERN, _size, _path, true)
{
}

void Casern::Update()
{
}

void Casern::Attack(const Entity& _entityDamaged)
{
}
