#include "Castle.h"

Castle::Castle(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path)
	: Removable(_name, _position, ENTITY_CASTLE, _size, _path, true)
{
}

void Castle::Update()
{
}

void Castle::Attack(const Entity& _entityDamaged)
{

}
