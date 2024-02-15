#include "Hero.h"
#include "EntityManager.h"
Hero::Hero(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path)
	: MovingEntity(EntityData(_name, ENTITY_HERO, _position, _size, 1, _path, 150, 40),1 ,1)
{
	const vector<CollisionReaction>& _reactions = {
		CollisionReaction(ENTITY_GRASS, [&](Entity* _entity) { movement->SetCanMove(false); }),
		CollisionReaction(ENTITY_FENCE, [&](Entity* _entity) { movement->SetCanMove(false); }),
		CollisionReaction(ENTITY_CASERN, [&](Entity* _entity) { movement->SetCanMove(false); }),
		CollisionReaction(ENTITY_TOWER, [&](Entity* _entity) { movement->SetCanMove(false); Attack(*_entity); }),
		CollisionReaction(ENTITY_TRAP, [&](Entity* _entity) {  movement->SetCanMove(false); Attack(*_entity); }),
	};

	reactions = _reactions;
}

void Hero::Attack(const Entity& _entityDamaged)
{
	MovingEntity::Attack(_entityDamaged);
}
