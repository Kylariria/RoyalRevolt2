#include "Grass.h"

Grass::Grass(const string& _name, const Vector2f& _position, const Vector2f& _size,
	const string& _path) : Removable(_name, _position, _size, _path, false)
{
	//shape->setFillColor(Color(255, 255, 255, 0));
}

void Grass::Update()
{
}
