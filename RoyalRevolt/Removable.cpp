#include "Removable.h"
#include "Macro.h"

Removable::Removable(const string& _name, const Vector2f& _position, const EntityType& _type, const Vector2f& _size, const string& _path, bool _isRemovable)
	: Entity(EntityData(_name, _type, _position, _size,0, _path))
{
	
}

