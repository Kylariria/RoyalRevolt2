#pragma once
#include "Entity.h"
#include "MovementComponent.h"
#include "CollisionComponent.h"

class MovingEntity : public Entity
{
protected:
	MovementComponent* movement;
	CollisionComponent* collision;

	Vector2f destination;

public:
	MovementComponent* GetMovementComponent()const
	{
		return movement;
	}
public:
	MovingEntity(const string& _name, const EntityType& _type, const Vector2f& _position,
		const Vector2f& _size, const string& _path, const int _tileAround,
		const int _speed = 0, const int _cooldown = 0);
	~MovingEntity();

public:
	virtual void Update() override;
};

