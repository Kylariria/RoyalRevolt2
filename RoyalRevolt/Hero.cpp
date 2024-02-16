#include "Hero.h"
#include "EntityManager.h"
#include "Macro.h"

Hero::Hero(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path, const float _health, const float _damage)
	: MovingEntity(EntityData(_name, ENTITY_NONE, _position, _size, 1, _path, 150.0f, 40.0f), Stat(_health, _damage), 1, 1)

{
	const vector<CollisionReaction>& _reactions = {
		CollisionReaction(ENTITY_GRASS, [&](Entity* _entity) {  }),
		CollisionReaction(ENTITY_MOB, [&](Entity* _entity) { /*movement->SetCanMove(false);*/ }),
	};
	reactions = _reactions;
	collision = new CollisionComponent();
}

void Hero::Attack(const Entity& _entityDamaged)
{
	//MovingEntity::Attack(_entityDamaged);
}

