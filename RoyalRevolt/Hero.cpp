#include "Hero.h"

Hero::Hero(const string& _name, const EntityType _type, const Vector2f& _position, const Vector2f& _size, const string& _path) : Entity(EntityData(_name, _type, _position, _size, _path))
{
}
