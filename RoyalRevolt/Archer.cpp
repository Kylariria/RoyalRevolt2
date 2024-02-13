#include "Archer.h"

Archer::Archer(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path) : Troop(_name,ENTITY_ARCHER, _position, _size, _path, 2)
{

}

void Archer::Update()
{
	Troop::Update();
}
