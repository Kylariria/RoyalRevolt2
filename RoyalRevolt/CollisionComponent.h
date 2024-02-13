#pragma once
#include "EntityType.h"

#include <vector>
#include <SFML/Graphics.hpp>
#include <functional>

using namespace std;
using namespace sf;

class Entity;


struct CollisionReaction
{
	EntityType type;

	function<void(Shape* _shape)> callbacks;

	CollisionReaction(const EntityType& _type, const function<void(Shape*)>& _callbacks)
	{
		type = _type;
		callbacks = _callbacks;
	}
};

class CollisionComponent
{
	Shape* currentShape;

public:
	bool CheckCollision(Entity* _currentEntity, const vector<Entity*>& _allEntities,
		const vector<CollisionReaction>& _reactions);
};
