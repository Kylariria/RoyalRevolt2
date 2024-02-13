#include "Hero.h"

Hero::Hero(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path, const EntityType _type)
	: MovingEntity(EntityData(_name, _type, _position, _size,0, _path))
{

}