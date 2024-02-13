#include "Barbarian.h"

#define PATH_BARBARIAN "Assets/Textures/Barbarian.png"

Barbarian::Barbarian(const string& _name, const Vector2f& _position, const Vector2f& _size) : Troop(_name, ENTITY_BARBARIAN, _position, _size, PATH_BARBARIAN, 1)
{

}

void Barbarian::Update()
{
	Troop::Update();
}
