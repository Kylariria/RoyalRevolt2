#include "Troop.h"

Troop::Troop(const string& _name, const EntityType& _type, const Vector2f& _position, const Vector2f& _size, const string& _path, const int _tileAround)
	: MovingEntity(EntityData(_name,ENTITY_TROOP,_position,_size, _tileAround,_path))
{
	
}

void Troop::Update()
{

}
