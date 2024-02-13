#include "Troop.h"

Troop::Troop(const string& _name, const EntityType& _type, const Vector2f& _position, const Vector2f& _size, const string& _path, const int _tileAround) : MovingEntity(_name,_type, _position, _size,_path,  _tileAround)

Troop::Troop(const EntityData& _data) : Entity(_data)
{

}
