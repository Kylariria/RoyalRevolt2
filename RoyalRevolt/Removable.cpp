#include "Removable.h"
#include "Macro.h"

Removable::Removable(const string& _name, const Vector2f& _position,
	const Vector2f& _size,const string& _path, bool _isRemovable)
	: Entity(EntityData(_name, ENTITY_REMOVABLE, _position, _size))
{
	
}
