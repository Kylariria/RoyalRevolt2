#include "Hero.h"
#include "EntityManager.h"
Hero::Hero(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path)
	: MovingEntity(EntityData(_name, ENTITY_HERO, _position, _size, 1, _path), 1)
{
	const vector<CollisionReaction>& _reactions = {
		CollisionReaction(ENTITY_GRASS, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); }),
		CollisionReaction(ENTITY_FENCE, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); }),
		CollisionReaction(ENTITY_CASERN, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); }),
		CollisionReaction(ENTITY_TOWER, [&](Shape* _shape) { _shape->move(0.0f, 0.0f); /*_shape->Attack();*/ }),
		CollisionReaction(ENTITY_TRAP, [&](Shape* _shape) {  _shape->move(0.0f, 0.0f); /*_shape->Attack();*/ }),
	};

	reactions = _reactions;
}