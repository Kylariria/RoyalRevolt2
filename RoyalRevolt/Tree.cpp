#include "Tree.h"

Tree::Tree(const string& _name, const Vector2f& _position, const Vector2f& _size,
	const string& _path) : Removable(_name, _position, ENTITY_TREE,  _size, _path, true)
{
}

void Tree::Update()
{
}
