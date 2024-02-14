#include "MovementComponent.h"
#include "MovingEntity.h"
#include "InputManager.h"
#include "CollisionComponent.h"
#include "Macro.h"
#include "EntityManager.h"

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
	collision = new CollisionComponent();
}

void MovementComponent::Move()
{
	SetDestination(InputManager::GetInstance().GetMousePosition());

	if (!canMove || !destination) return;

	// On récup la position de la souris
	Vector2f _mousePosition = InputManager::GetInstance().GetMousePosition();

	// La shape se déplace à la position de la souris
	Normalize(_mousePosition);

	shape->move(_mousePosition);
	const vector<Entity*> _allEntities = EntityManager::GetInstance().GetAllValues();

	//si shape rencontre obstacle >> STOP
	CollisionReaction _reaction = CollisionReaction(ENTITY_REMOVABLE, [&](Shape* _shape) { /*shape->getGlobalBounds().contains();*/ });
	vector<CollisionReaction> _reactions;
	_reactions.push_back(_reaction);
	collision->CheckCollision(owner, _allEntities, _reactions);


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
