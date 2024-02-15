#include "Archer.h"

Archer::Archer(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path) : Troop({ _name, ENTITY_ARCHER, _position, _size, _path,2})
{
	const vector<CollisionReaction>& _reactions = {
		CollisionReaction(ENTITY_GRASS, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); }),
		CollisionReaction(ENTITY_FENCE, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); /*_shape->Attack();*/ }),
		CollisionReaction(ENTITY_TOWER, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); /*_shape->Attack();*/ }),
		CollisionReaction(ENTITY_CASERN, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); }),
	};

	reactions = _reactions;

}

void Archer::Update()
{
	Troop::Update();
}
