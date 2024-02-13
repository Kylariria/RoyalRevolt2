
#include "Fence.h"

Fence::Fence(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path)
	: Removable(_name, _position, _size, _path, true)
{
}

void Fence::Update()
{
}
