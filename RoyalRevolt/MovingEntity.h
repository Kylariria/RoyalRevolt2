#pragma once
#include "Entity.h"
#include "MovementComponent.h"
#include "CollisionComponent.h"
#include "Stat.h"

class MovingEntity : public Entity, public Stat
{
protected:
	MovementComponent* movement;
	CollisionComponent* collision;
	vector<CollisionReaction> reactions;
	Vector2f destination;
public:
	MovementComponent* GetMovementComponent()const
	{
		return movement;
	}
public:
	MovingEntity(const EntityData& _data,
		const int _speed = 0, const int _cooldown = 0);
	~MovingEntity();

public:
	virtual void Update() override;
};

