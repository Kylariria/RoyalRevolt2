#include "Path.h"

Path::Path(const string& _name, const Vector2f& _position, const Vector2f& _size,
	const string& _path)
	: Removable(_name, _position, ENTITY_PATH, _size, _path, true)
{
}

void Path::Update()
{
}
