#include "MovementComponent.h"
#include "MovingEntity.h"
#include "InputManager.h"
#include "CollisionComponent.h"
#include "Macro.h"
#include "EntityManager.h"
#include "Player.h"
#include <vector>

using namespace std;

MovementComponent::MovementComponent(MovingEntity* _owner, Shape* _shape, const int _speed, const int _cooldown)
{
	owner = _owner;
	canMove = true;
	speed = _speed;
	cooldown = _cooldown;
	currentCooldown = 0;
	destination = nullptr;
	shape = _shape;
	reactions = vector<CollisionReaction>();
}

void MovementComponent::Move()
{
	Vector2f _direction = *destination - shape->getPosition();
	Normalize(_direction);
	const float _x = (_direction.x * speed) * 0.5f;
	const float _y = (_direction.y * speed) * 0.5f;
	shape->move(_x, _y);
}
