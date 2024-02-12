#include "Archer.h"

#define PATH_ARCHER "Assets/Textures/Archer.png"

Archer::Archer(const string& _name, const Vector2f& _position, const Vector2f& _size) : Troop(_name,ENTITY_ARCHER, _position, _size, PATH_ARCHER, 2)
{

}

void Archer::Update()
{
	Troop::Update();
}
