#include "Barbarian.h"

Barbarian::Barbarian(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path) : Troop({ _name, ENTITY_BARBARIAN, _position, _size, _path,1})
{
	const vector<CollisionReaction>& _reactions = {
		CollisionReaction(ENTITY_GRASS, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); }),
		CollisionReaction(ENTITY_FENCE, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); /*_shape->Attack();*/}),
		CollisionReaction(ENTITY_TOWER, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); /*_shape->Attack();*/ }),
		CollisionReaction(ENTITY_CASERN, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); }),
	};

	reactions = _reactions;
}

void Barbarian::Update()
{
	Troop::Update();
}
