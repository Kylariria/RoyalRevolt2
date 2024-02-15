#include "Archer.h"

Archer::Archer(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path) : MovingEntity(EntityData(_name, ENTITY_ARCHER, _position, _size, 2, _path, 50, 30),1,1)
{
	const vector<CollisionReaction>& _reactions = {
		CollisionReaction(ENTITY_GRASS, [&](Entity* _entity) { movement->SetCanMove(false); }),
		CollisionReaction(ENTITY_FENCE, [&](Entity* _entity) { movement->SetCanMove(false); Attack(*_entity); }),
		CollisionReaction(ENTITY_TOWER, [&](Entity* _entity) { movement->SetCanMove(false); Attack(*_entity); }),
		CollisionReaction(ENTITY_CASERN, [&](Entity* _entity) { movement->SetCanMove(false); }),
	};

	reactions = _reactions;
}

void Archer::Update()
{
	MovingEntity::Update();
}

void Archer::Attack(const Entity& _entityDamaged)
{
	
}
