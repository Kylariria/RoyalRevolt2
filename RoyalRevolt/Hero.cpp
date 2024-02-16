#include "Hero.h"
#include "EntityManager.h"
#include "Player.h"
#include "Macro.h"

Hero::Hero(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path, const int _health, const int _damage)
	: MovingEntity(EntityData(_name, ENTITY_NONE, _position, _size, 1, _path, 150, 40), Stat(_health, _damage), 1, 1)
{
	const vector<CollisionReaction>& _reactions = {
		CollisionReaction(ENTITY_DESTROYABLE, [&](Entity* _entity) {
			if (IsSameName(_entity->GetEntityData()->name,"Grass"))
			{
				WallCollide(_entity->GetShape());
			}

		}),
		CollisionReaction(ENTITY_MOB, [&](Entity* _entity) { /*movement->SetCanMove(false);*/ }),
	};
	reactions = _reactions;
	collision = new CollisionComponent();
}

void Hero::Attack(const Entity& _entityDamaged)
{
	//MovingEntity::Attack(_entityDamaged);
}

void Hero::WallCollide(Shape* _shape)
{
	const FloatRect& _currentRect = shape->getGlobalBounds();
	const FloatRect& _rectShap = _shape->getGlobalBounds();

	const float _rectWidth = _currentRect.left + _currentRect.width;
	const float _shapeWidth = _rectShap.left + _rectShap.width;
	const float _shapeHeight = _rectShap.top + _rectShap.height;

	if (((_currentRect.left > _rectShap.left && _rectWidth > _shapeWidth)) ||
		(_currentRect.left < _rectShap.left && _rectWidth < _shapeWidth))
	{
		movement->SetDestination(_currentRect.getPosition());
	}

	else if (((_currentRect.top < _shapeHeight && _currentRect.top + _currentRect.height > _rectShap.top)) ||
		((_currentRect.top < _shapeHeight && _currentRect.top + _currentRect.height < _rectShap.top)))
	{
		movement->SetDestination(_currentRect.getPosition());
	}
}
