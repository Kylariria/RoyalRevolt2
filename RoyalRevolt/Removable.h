#pragma once
#include "Entity.h"

enum RemovableType
{
	R_ROCK, R_TREE, R_GRASS
};

class Removable : public Entity
{
	RemovableType type;

public :
	Removable(const string& _name, const Vector2f& _position, const EntityType& _type, const Vector2f& _size = Vector2f(0.0f, 0.0f),
		const string& _path = "", bool _isRemovable = false);
};

