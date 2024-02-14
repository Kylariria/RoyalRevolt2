#pragma once
#include "SFML/Graphics.hpp"
#include "CollisionComponent.h"

class MovingEntity;

using namespace sf;

class MovementComponent
{
	MovingEntity* owner;
	bool canMove;
	int speed;
	int cooldown;
	int currentCooldown;
	Vector2f* destination;
	Shape* shape;
	CollisionComponent* collision;

public:
	void SetCanMove(const bool _status)
	{
		canMove = _status;
		//TODO : crash a certain moment
	}
	void SetDestination(const Vector2f& _destination)
	{
		if (destination)
		{
			delete destination;
		}

		destination = new Vector2f(_destination);
	}
	MovingEntity* GetOwner() const
	{
		return owner;
	}
	bool HasDestination() const
	{
		return destination;
	}
	int GetSpeed() const
	{
		owner;
		return speed;
	}

	bool CanMove() const
	{
		return canMove;
	}

public:
	MovementComponent(MovingEntity* _owner, Shape* _shape, const int _speed = 0, const int _cooldown = 0);

public:
	bool IsAtLocation() const
	{
		return shape->getPosition() == *destination;
	}

public:
	void Move();
};

