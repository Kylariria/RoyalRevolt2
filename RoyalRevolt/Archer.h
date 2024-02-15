#pragma once
#include "MovingEntity.h"
class Archer : public MovingEntity
{

public: 
	Archer(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path);

public:
	virtual void Update() override;
	virtual void Attack(const Entity& _entityDamaged) override;
};

