#include "Hero.h"
#include "EntityManager.h"
Hero::Hero(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path)
	: MovingEntity(EntityData(_name, ENTITY_NONE, _position, _size, 1, _path, 150, 40),1 ,1)
{
	const vector<CollisionReaction>& _reactions = {
		CollisionReaction(ENTITY_NONE, [&](Entity* _entity) { movement->SetCanMove(false); }),
		CollisionReaction(ENTITY_NONE, [&](Entity* _entity) { movement->SetCanMove(false); }),
		CollisionReaction(ENTITY_NONE, [&](Entity* _entity) { movement->SetCanMove(false); }),
		CollisionReaction(ENTITY_NONE, [&](Entity* _entity) { movement->SetCanMove(false); Attack(*_entity); }),
		CollisionReaction(ENTITY_NONE, [&](Entity* _entity) {  movement->SetCanMove(false); Attack(*_entity); }),
	};

	reactions = _reactions;
}

void Hero::Attack(const Entity& _entityDamaged)
{
	//MovingEntity::Attack(_entityDamaged);
}
