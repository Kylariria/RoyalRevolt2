#pragma once
#include "Troop.h"
#include "EntityType.h"

class Barbarian : public Troop
{

public:
	Barbarian(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path);

public:
	virtual void Update() override;

};