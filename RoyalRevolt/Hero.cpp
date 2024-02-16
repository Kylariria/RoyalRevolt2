#include "Hero.h"
#include "EntityManager.h"
#include "Macro.h"
#include "Removable.h"
Hero::Hero(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path, const float _health, const float _damage)
	: MovingEntity(EntityData(_name, ENTITY_NONE, _position, _size, 1, _path, 150, 40), Stat(_health, _damage), 1, 1)
{
	const vector<CollisionReaction>& _reactions = {
		CollisionReaction(ENTITY_DESTROYABLE, [&](Entity* _entity) {
				if (Removable* _removable = dynamic_cast<Removable*>(_entity))
				{
					if (_removable->GetType() == R_GRASS)
					{
						movement->Move(false);
					}
				}
		}),
		CollisionReaction(ENTITY_MOB, [&](Entity* _entity) { /*Attack();*/ }),
	};
	reactions = _reactions;
	collision = new CollisionComponent();
}

void Hero::Attack(const Entity& _entityDamaged)
{
	//MovingEntity::Attack(_entityDamaged);
}

