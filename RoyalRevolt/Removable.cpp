#include "Removable.h"
#include "Macro.h"

Removable::Removable(const string& _name, const Vector2f& _position, const EntityType& _type, RemovableType _RType, const Vector2f& _size, const string& _path)
	: Entity(EntityData(_name, ENTITY_DESTROYABLE, _position, _size,0, _path))
{
	type = _RType;
	if (type== R_GRASS)
	{
		shape->setFillColor(Color::Transparent);
	}
}

void Removable::Update()
{

}