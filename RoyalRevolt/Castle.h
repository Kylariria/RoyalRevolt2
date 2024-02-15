#pragma once
#include "Removable.h"
class Castle : public Removable
{
public:
	Castle(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path);

public:
	virtual void Update() override;
	virtual void Attack(const Entity& _entityDamaged) override;

};


