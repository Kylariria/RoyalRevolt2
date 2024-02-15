#include "Barbarian.h"

Barbarian::Barbarian(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path) : MovingEntity(EntityData(_name, ENTITY_BARBARIAN, _position, _size, 2, _path, 100, 15), 1, 1)
{
	const vector<CollisionReaction>& _reactions = {
		CollisionReaction(ENTITY_GRASS, [&](Entity* _entity) { movement->SetCanMove(false); }),
		CollisionReaction(ENTITY_FENCE, [&](Entity* _entity) { movement->SetCanMove(false); Attack(*_entity); }),
		CollisionReaction(ENTITY_TOWER, [&](Entity* _entity) { movement->SetCanMove(false); Attack(*_entity); }),
		CollisionReaction(ENTITY_CASERN, [&](Entity* _entity) { movement->SetCanMove(false); }),
	};

	reactions = _reactions;
}

void Barbarian::Update()
{
	MovingEntity::Update();
}

void Barbarian::Attack(const Entity& _entityDamaged)
{
	Entity::Attack(_entityDamaged);
}
