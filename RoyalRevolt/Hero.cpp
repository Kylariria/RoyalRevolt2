#include "Hero.h"

Hero::Hero(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path)
	: MovingEntity(EntityData(_name, ENTITY_HERO, _position, _size, 1, _path), 1)
{

}