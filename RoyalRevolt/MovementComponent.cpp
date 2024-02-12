#include "MovementComponent.h"
#include "MovingEntity.h"
#include "Macro.h"

MovementComponent::MovementComponent(MovingEntity* _owner, Shape* _shape, const int _speed, const int _cooldown)
{
	owner = _owner;
	canMove = true;
	speed = _speed;
	cooldown = _cooldown;
	currentCooldown = 0;
	destination = nullptr;
	shape = _shape;
}

void MovementComponent::Move()
{
	if (!canMove || !destination) return;



	/*if (currentCooldown < cooldown)
	{
		currentCooldown++;
		return;
	}

	Vector2f _direction = *destination - shape->getPosition();
	Vector2i _intDirection;
	Normalize(_direction, _intDirection);

	const Vector2f _cellSize = MapManager::GetInstance().GetCurrent()->GetCellSize();
	const int _directionX = _intDirection.x * speed * static_cast<int>(_cellSize.x);
	const int _directionY = _intDirection.y * speed * static_cast<int>(_cellSize.y);
	const Vector2f& _position = shape->getPosition() + Vector2f(_directionX, _directionY);
	shape->setPosition(_position);

	currentCooldown = 0;*/
}
