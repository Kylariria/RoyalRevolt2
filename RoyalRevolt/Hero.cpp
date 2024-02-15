#include "Hero.h"
#include "EntityManager.h"

Hero::Hero(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path, const int _health, const int _damage)
    : MovingEntity(EntityData(_name, ENTITY_NONE, _position, _size, 1, _path, 150, 40), Stat(_health, _damage), 1, 1)
{
    const vector<CollisionReaction>& _reactions = {
        //CollisionReaction(ENTITY_DESTROYABLE, [&](Entity* _entity) { movement->SetCanMove(false); }),
        CollisionReaction(ENTITY_MOB, [&](Entity* _entity) { movement->SetCanMove(false); }),
    };

    reactions = _reactions;
    collision = new CollisionComponent();
}   